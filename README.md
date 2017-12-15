# Proiect-Radio-FM

<b><h3>Descrierea proiectului </h3> </b>

Proiectul constă în crearea unui radio controlat de o placă de dezvoltare Arduino. Componentele care stau la baza acestui proiect sunt modulul FM RDA5807M și amplificatorul audio PAM8403. Placa de dezvoltare are rolul de a seta parametri de funcționare a modulului FM.  De asemenea, aceasta este folosită și de un ecran LCD 1602 pentru a afișa informații utile, cum ar fi frecvența de recepție sau volumul. Datorită diferenței tensiunii de funcționare a plăcii de dezvoltare și modulul FM, trebuie să utilizați un translator de nivel logic.

<b> Componente necesare </b>

<li>Placă de dezvoltare: Arduino Uno; </li>
<li>Modul FM RDA5807M; </li>
<li>Translator de nivel logic;</li>
<li>Mini amplificator audio PAM8403;</li>
<li>Modul LCD 1602 I2C cu backlight albastru;</li>
<li>4 x butoane;</li>
<li>2 x difuzoare 1 W;</li>
<li>Kit breadboard HQ;</li>
<li>Fir cu lungimea de cel puțin 2 metri;*</li>

*puteți să luați mai multe fire de culori diferite pentru a vă facilita realizarea conexiunilor hardware


<b>Unelte necesare:</b>
<li>letcon și fludor;</li>



<b><h2> Pregătirea componentelor </h2><b>



Înainte de a conecta piesele între ele, trebuie să le pregătiți pentru a putea fi utilizate. De exemplu, trebuie să lipiți pinii pe amplificatorul audio, pe translatorul de nivel logic, dar și pe modulul FM.

ATENȚIE! Distanța dintre pinii modulului FM nu este standard (2.54cm). În loc de pini puteți să lipiți direct fire.

De asemenea, modulul FM necesită și o antenă pentru a funcționa corespunzător. Lungimea firului utilizat drept antenă variază în funcție de frecventă pe care doriți să o ascultați. Pentru a recepționa frecvența 107 MHz, optim ar fi să utilizați o antenă cu lungimea de 66.7 cm. Dacă doriți să recepționați cât mai multe frecvențe puteți să utilizați o valoare mediana, cum ar fi lungimea de ~73 cm. Puteți consulta un calculator online pentru a afla și alte lungimi specifice anumitor frecvențe. Lungimea de bandă este ¼.





Realizați conexiunile hardware



Modulul FM și LCD-ul comunică prin protocolul I2C. Ținând cont că cele două componente au adrese diferite, utilizarea lor în cadrul aceluiași proiect este posibilă. Adresa la care poate fi accesat LCD-ul este, de obicei, 0x3F. În cazul în care această adresă nu este corectă, accesați următorul link pentru a afla cum să o descoperiți pe cea corectă.





Alimentarea plăcii de dezvoltare se poate face în mai multe moduri, prin USB, prin mufa de alimentare sau chiar prin intermediul pinilor 5 V și GND.

Amplificatorul audio PAM 8403 se alimentează cu o tensiune cuprinsă între 2.5 V și 5 V. Este recomandat să utilizați o sursă externă pentru amplificatorul audio deoarece o placă de dezvoltare Arduino nu poate alimenta toate aceste componente simultan.



Încărcarea codului pe placa de dezvoltare



Pentru a utiliza toate componentele, trebuie să aveți următoarele biblioteci:

Wire:

Bibliotecă utilizată pentru comunicarea I2C;

Este inclusă în mediul de dezvoltare Arduino IDE.

Radio:

Bibliotecă utilă pentru a facilitata utilizarea modulului FM;

Dezvoltată de Matthias Hertel și este disponibilă în Library Manager.

LiquidCrystal_I2C:

Creată special pentru utilizarea unui ecran  LCD 1602 prin protocolul I2C;

Dezvoltată de Frank de Brabander și este inclusă în Library Manager.

Pentru a afla mai multe detalii despre cum să instalați o bibliotecă în mediul de dezvoltare Arduino IDE, accesăți urmatorul link.












