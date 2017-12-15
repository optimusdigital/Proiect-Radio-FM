//bibliotecă utilizată pentru comunicarea prin I2C
#include <Wire.h>

//bibliotecă utilizată pentru a facilita configurarea modulului FM
#include<RDA5807M.h>

//bibliotecă utilă pentru utilizarea modulului LCD prin intermediul protocolului I2C
#include <LiquidCrystal_I2C.h>

//crearea unei instanțe noi, numită  "lcd"

//schema de conectare a ecranului LCD
/*
 * | Arduino Uno | Ecran LCD |
 * |-------------|-----------|
 * |    GND      |    GND    |
 * |    5V       |    VCC    |
 * |    A4       |    SDA    |
 * |    A5       |    SCL    |
 * |-------------|-----------|
 */

//parametri: lcd(adresă, numărCaractere/Linie, numărLinii)
//pentru a afla adresa I2C a LCD-ului utilizat, consultați datasheet-ul acestuia

LiquidCrystal_I2C lcd(0x3F, 16, 2);

//configurați pinii utilizați de cele 4 butoane de control
//conectarea butoanelor se realizeaza astfel
/*
 *  Pin1    Pin2
 *   |       |       Cei patru pini ( Pin1, Pin2, Pin3, Pin4 ) reprezinta
 *   ----------      pinii unui buton simplu.
 *  |          |     Schema de conectare este urmatoarea:
 *  |   Buton  |     Pin1 <-> GND
 *  |          |     Pin4 <-> Pin Digital
 *   ----------
 *   |       |
 *   Pin3   Pin4
 *   
 */
//volumul se setează din butoanele conectate la pinii 7 și 8
#define volumeDown 7
#define volumeUp 8

//frecventa se seteaza prin intermediul butoanelor conectate la pinii 9 și 10
#define frequencyDown 9
#define frequencyUp 10

//parametri de configurare ale radioului

#define BAND RADIO_BAND_FM  // Banda va fi configurată pentru a receptiona undele FM

float frequency = 90.8;// Frecvența initiala de recepție este setata la 90.80 MHz
#define minFrequency 85.1
#define maxFrequency 108.0

int volume = 1; // volumul initial este 1, acesta putând fi setat între 0 și 15
#define maxVolume 15
#define minVolume 0
//crearea unei noi instanțe, numită "radio"

RDA5807M radio;

//utilizam funcția "refresh()" pentru a actualiza informatiiile de pe LCD

void refresh()
{ //stergem toate caractere scrise pe ecran cu metoda .clear()
  lcd.clear();

  //setam cursorul pe coloana 0, linia 0
  lcd.setCursor(0,0);

  //afișăm volumul si valoarea acestuia
  lcd.print("Volum: ");
  lcd.print(volume);

  //setam cursorul pe coloana 0, linia 1;
  lcd.setCursor(0,1);
  lcd.print("Frecventa: ");
  
  lcd.print(frequency,1.0f);
 

}

//Funcția "setup()" are rolul de a inițializa LCD-ul și radio-ul dar și pentru declararea
//pinilor 7,8,9,10 ca INPUT_PULL ( pinii sunt utilizați de 4 butoane, pentru a schimba 
//frecvența și volumul.
void setup()
{
  pinMode(volumeDown, INPUT_PULLUP);
  pinMode(volumeUp, INPUT_PULLUP);

  pinMode(frequencyDown, INPUT_PULLUP);
  pinMode(frequencyUp, INPUT_PULLUP);

  //initializarea instanței "radio
  radio.init();

  //pornirea radioului utilizând setarile predefinite
  radio.setBandFrequency( BAND, frequency * 100 );
  radio.setVolume( volume );

  //dacă utilizați un amplificator audio mono trebuie să setați acest lucru prin intermediul
  //comnezii "radio.setMono( true );"
  radio.setMono(false);

  //dezactivați modul mute prin intermediul metodei setMute
  radio.setMute(false);

  

  //pornim LCD-ul dar și lumina de backlight
  lcd.init();
  lcd.backlight();

  //asteptam 100ms pentru a ne asigura ca LCD-ul a pornit corespunzător
  delay(100);

  //afisam pe ecran setarile predefinite ale modulului FM
  refresh();
  
}


void loop()
{ //verificam dacă s-a apasat buton pentru micsorarea volumului
  if( digitalRead(volumeDown) == LOW )
     {
      if(volume > minVolume) //verificam ca volumul să nu fie minim
      {
          volume = volume - 1; // decrementăm volumul cu o unitate
          
          if(volume == minVolume)  //dacă volumul setat este 0, sunetul trebuie oprit
              radio.setMute(true);
           else
              radio.setVolume( volume ); //in caz contrar, setați volumul corespunzător

           delay(150); //asteptați ca să se trimită noua configurație către modulul radio

           refresh(); //actualizați informațiile afisate pe ecran 

           delay(100); //asteptați ca informatiile să se afiseze pe ecran
      }
     }

//verificam dacă s-a apasat buton pentru micsorarea volumului
if( digitalRead(volumeUp) == LOW )
     {
      if(volume < maxVolume) //verificam ca volumul să nu fie maxim
      {  
          if(volume == minVolume )
             radio.setMute( false );
             
          volume = volume + 1 ; // creștem volumul cu o unitatea
          radio.setVolume( volume ); //setam noul volum
          delay(150); //asteptam să se trimită noua configurație către modulul radio

          refresh(); //actualizam informațiile afisate pe ecran 
          delay(100); //asteptam ca informatiile să se afiseze pe ecran
      }
     }
     
//verificam daca s-a apăsat butonul corespunzător scăderii frecvenței
if( digitalRead(frequencyDown) == LOW )
     {
      if(frequency > minFrequency) 
      {
          frequency = frequency - 0.1; //decrementam frecventa cu 0.1Mhz
          radio.setBandFrequency(BAND, frequency * 100 ); //setam noua frecvență
          delay(150); //asteptam să se trimită noua configurație către modulul radio

          refresh(); //actualizam informațiile afisate pe ecran 
          delay(100); //asteptam ca informatiile să se afiseze pe ecran
      }
     }

//verificam dacă s-a apăsat butonul corespunzător creșterii frecvenței
if( digitalRead(frequencyUp) == LOW )
     {
      if(frequency < maxFrequency) 
       {
          frequency = frequency + 0.1; //decrementam frecventa cu 0.1Mhz
          radio.setBandFrequency(BAND, frequency * 100 ); //setam noua frecvență
          delay(150); //asteptam să se trimită noua configurație către modulul radio

          refresh(); //actualizam informațiile afisate pe ecran 
          delay(100); //asteptam ca informatiile să se afiseze pe ecran
       }
     }
 
}



