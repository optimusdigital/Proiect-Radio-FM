# Proiect-Radio-FM

<b><h3>Descrierea proiectului </h3> </b>

Proiectul constă în crearea unui radio controlat de o placă de dezvoltare Arduino. Componentele care stau la baza acestui proiect sunt modulul FM RDA5807M și amplificatorul audio PAM8403. Placa de dezvoltare are rolul de a seta parametri de funcționare a modulului FM.  De asemenea, aceasta este folosită și de un ecran LCD 1602 pentru a afișa informații utile, cum ar fi frecvența de recepție sau volumul. Datorită diferenței tensiunii de funcționare a plăcii de dezvoltare și modulul FM, trebuie să utilizați un translator de nivel logic.

<b> <h3> Componente necesare </h3> </b>

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

<ul>
<li><span style="text-decoration: underline;"><a href="https://www.optimusdigital.ro/placi-avr/656-clona-arduino-uno-r3-atmega328p-atmega16u2-cablu.html">Placă de dezvoltare: Arduino Uno;</a></span></li>
<li><span style="text-decoration: underline;"><a href="https://www.optimusdigital.ro/wireless-radio-fm/745-modul-radio-fm-rda5807m.html">Modul FM RDA5807M;</a></span></li>
<li><span style="text-decoration: underline;"><a href="https://www.optimusdigital.ro/interfata-convertoare-de-niveluri/181-translator-de-nivel-bidirectional-cu-4-canale.html">Translator de nivel logic;</a></span></li>
<li><span style="text-decoration: underline;"><a href="https://www.optimusdigital.ro/audio-amplificatoare-audio/614-modul-mini-amplificator-pam8403-in-clasa-d-stereo-3-w.html">Mini amplificator audio PAM8403;</a></span></li>
<li><span style="text-decoration: underline;"><a href="https://www.optimusdigital.ro/optoelectronice-lcd-uri/2894-lcd-cu-interfata-i2c-si-backlight-albastru.html">Modul LCD 1602 I2C cu backlight albastru;</a></span></li>
<li><span style="text-decoration: underline;">4 x <a href="https://www.optimusdigital.ro/butoane-i-comutatoare/1119-buton-6x6x6.html">butoane</a>;</span></li>
<li><span style="text-decoration: underline;">2 x <a href="https://www.optimusdigital.ro/audio-difuzoare/2147-difuzor-de-1-w.html">difuzoare 1 W</a>;</span></li>
<li><span style="text-decoration: underline;"><a href="https://www.optimusdigital.ro/kituri/2222-kit-breadboard-hq-830-p.html">Kit breadboard HQ</a>;</span></li>
<li><span style="text-decoration: underline;"><a href="https://www.optimusdigital.ro/fire-fire-nemufate/388-fir-albastru-cu-diametru-de-1-mm-la-metru.html">Fir</a></span><span> cu lungimea de cel puțin 2 metri;*</span></li>
</ul>
<p>*puteți să luați mai multe fire de culori diferite pentru a vă facilita realizarea conexiunilor hardware</p>
<p>Unelte necesare:</p>
<ul>
<li dir="ltr">
<p dir="ltr"><span style="text-decoration: underline;"><a href="https://www.optimusdigital.ro/letcon-uri/3019-letcon-velleman-60-w-230-v.html">letcon</a></span> și <span style="text-decoration: underline;"><a href="https://www.optimusdigital.ro/fludor/23-fludor-la-tub-1mm-10-gr.html">fludor</a></span>;</p>
</li>
</ul>

<b><h3> Pregătirea componentelor </h3></b>



Înainte de a conecta piesele între ele, trebuie să le pregătiți pentru a putea fi utilizate. De exemplu, trebuie să lipiți pinii pe amplificatorul audio, pe translatorul de nivel logic, dar și pe modulul FM.

ATENȚIE! Distanța dintre pinii modulului FM nu este standard (2.54cm). În loc de pini puteți să lipiți direct fire.

De asemenea, modulul FM necesită și o antenă pentru a funcționa corespunzător. Lungimea firului utilizat drept antenă variază în funcție de frecventă pe care doriți să o ascultați. Pentru a recepționa frecvența 107 MHz, optim ar fi să utilizați o antenă cu lungimea de 66.7 cm. Dacă doriți să recepționați cât mai multe frecvențe puteți să utilizați o valoare mediana, cum ar fi lungimea de ~73 cm. Puteți consulta un calculator online pentru a afla și alte lungimi specifice anumitor frecvențe. Lungimea de bandă este ¼.


<b> <h3> Realizați conexiunile hardware </h3> </b>



Modulul FM și LCD-ul comunică prin protocolul I2C. Ținând cont că cele două componente au adrese diferite, utilizarea lor în cadrul aceluiași proiect este posibilă. Adresa la care poate fi accesat LCD-ul este, de obicei, 0x3F. În cazul în care această adresă nu este corectă, accesați următorul <a href="https://playground.arduino.cc/Main/I2cScanner">link</a> pentru a afla cum să o descoperiți pe cea corectă.

<img src="https://www.optimusdigital.ro/img/cms/Instructiuni%20Sorin/radio/Schema-de-conectare%20.png" alt="" width="1117" height="854" />



Alimentarea plăcii de dezvoltare se poate face în mai multe moduri, prin USB, prin mufa de alimentare sau chiar prin intermediul pinilor 5 V și GND.

Amplificatorul audio PAM 8403 se alimentează cu o tensiune cuprinsă între 2.5 V și 5 V. Este recomandat să utilizați o sursă externă pentru amplificatorul audio deoarece o placă de dezvoltare Arduino nu poate alimenta toate aceste componente simultan.

Cele patru butoane (volumeDown, volumeUp, frequencyDown, frequencyUp) se conectează astfel:
<img src="https://lh5.googleusercontent.com/BLAZdusgEh23-6egSusrNDvKUPrGKg0E7dKHSnA9ze0mOKypw7G7I8Gr2sqxGJX_qS7YytvuvDXRJuGZR1SVdzW4uAvd8KDXmFZ-B5F1eQkEu9sLTrveLj7h77FZqmdu3_XUlFSq" width="1117" height="501" alt="BLAZdusgEh23-6egSusrNDvKUPrGKg0E7dKHSnA9" />


<b> <h3> Încărcarea codului pe placa de dezvoltare </h3> </b>



Pentru a utiliza toate componentele, trebuie să aveți următoarele biblioteci instalate în mediul de dezvoltare Arduino IDE:

<h4>Wire:</h4>

<li>Bibliotecă utilizată pentru comunicarea I2C; </li>

<li>Este inclusă în mediul de dezvoltare Arduino IDE. </li>

<h4>Radio:</h4>

<li>Bibliotecă utilă pentru a facilitata utilizarea modulului FM;</li>

<li>Dezvoltată de Matthias Hertel și este disponibilă în Library Manager.</li>

<h4>LiquidCrystal_I2C:</h4>

<li>Creată special pentru utilizarea unui ecran  LCD 1602 prin protocolul I2C;</li>

<li>Dezvoltată de Frank de Brabander și este inclusă în Library Manager.</li>


Pentru a afla mai multe detalii despre cum să instalați o bibliotecă în mediul de dezvoltare Arduino IDE, accesăți urmatorul <a href="https://www.optimusdigital.ro/content/10-tutorial-instalare-biblioteca"><span style="text-decoration: underline;">link</span>.</a>












