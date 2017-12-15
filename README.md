# Proiect-Radio-FM
<h2><strong>Descrierea proiectului</strong></h2>
<p>Proiectul constă în crearea unui radio controlat de o placă de dezvoltare Arduino. Componentele care stau la baza acestui proiect sunt modulul FM RDA5807M și amplificatorul audio PAM8403. Placa de dezvoltare are rolul de a seta parametri de funcționare a modulului FM.  De asemenea, aceasta este folosită și de un ecran LCD 1602 pentru a afișa informații utile, cum ar fi frecvența de recepție sau volumul. Datorită diferenței tensiunii de funcționare a plăcii de dezvoltare și modulul FM, trebuie să utilizați un translator de nivel logic.</p>
<h2><strong>Componente necesare</strong></h2>
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
<p><img src="https://www.optimusdigital.ro/img/cms/Instructiuni%20Sorin/componente%20proiect%20.jpg" alt="" width="1117" height="745" /></p>
<h2><strong>Pregătirea componentelor</strong></h2>
<p></p>
<p>Înainte de a conecta piesele între ele, trebuie să le pregătiți pentru a putea fi utilizate. De exemplu, trebuie să lipiți pinii pe amplificatorul audio, pe translatorul de nivel logic, dar și pe modulul FM.</p>
<p><strong>ATENȚIE! Distanța dintre pinii modulului FM nu este standard (2.54cm). În loc de pini puteți să lipiți direct fire.</strong></p>
<p>De asemenea, modulul FM necesită și o antenă pentru a funcționa corespunzător. Lungimea firului utilizat drept antenă variază în funcție de frecventă pe care doriți să o ascultați. Pentru a recepționa frecvența 107 MHz, optim ar fi să utilizați o antenă cu lungimea de 66.7 cm. Dacă doriți să recepționați cât mai multe frecvențe puteți să utilizați o valoare mediana, cum ar fi lungimea de ~73 cm. <span id="docs-internal-guid-e9fbae9b-560b-95c8-fe8d-2dc07c422043"><span>Puteți consulta un </span><a href="http://www.csgnetwork.com/antennaevcalc.html"><span>calculator online</span></a><span> pentru a afla și alte lungimi specifice anumitor frecvențe. Lungimea de bandă este ¼.</span></span></p>
<h2></h2>
<h2></h2>
<h2><strong><span id="docs-internal-guid-b5b72b52-560d-bc0b-f777-95d3c9c0d15f">Realizați conexiunile hardware</span></strong></h2>
<p></p>
<p>Modulul FM și LCD-ul comunică prin protocolul I<sup>2</sup>C. Ținând cont că cele două componente au adrese diferite, utilizarea lor în cadrul aceluiași proiect este posibilă. Adresa la care poate fi accesat LCD-ul este, de obicei, 0x3F. În cazul în care această adresă nu este corectă, accesați următorul <a href="https://playground.arduino.cc/Main/I2cScanner">link</a> pentru a afla cum să o descoperiți pe cea corectă.</p>
<p><img src="https://www.optimusdigital.ro/img/cms/Instructiuni%20Sorin/radio/Schema-de-conectare%20.png" alt="" width="1117" height="854" /></p>
<p></p>
<p dir="ltr"><span>Alimentarea plăcii de dezvoltare se poate face în mai multe moduri, prin USB, prin mufa de alimentare sau chiar prin intermediul pinilor 5 V și GND.</span></p>
<p>Amplificatorul audio PAM 8403 se alimentează cu o tensiune cuprinsă între 2.5 V și 5 V. Este recomandat să utilizați o sursă externă pentru amplificatorul audio deoarece o placă de dezvoltare Arduino nu poate alimenta toate aceste componente simultan.</p>
<p dir="ltr"></p>
<p dir="ltr">Cele patru butoane (volumeDown, volumeUp, frequencyDown, frequencyUp) se conectează astfel:</p>
<p></p>
<p dir="ltr"><span><img src="https://lh5.googleusercontent.com/BLAZdusgEh23-6egSusrNDvKUPrGKg0E7dKHSnA9ze0mOKypw7G7I8Gr2sqxGJX_qS7YytvuvDXRJuGZR1SVdzW4uAvd8KDXmFZ-B5F1eQkEu9sLTrveLj7h77FZqmdu3_XUlFSq" width="1117" height="501" alt="BLAZdusgEh23-6egSusrNDvKUPrGKg0E7dKHSnA9" /></span></p>
<h3 dir="ltr"></h3>
<h2 dir="ltr"></h2>
<h2 dir="ltr"><strong>Încărcarea codului pe placa de dezvoltare</strong></h2>
<p></p>
<p dir="ltr"><span>Pentru a utiliza toate componentele, trebuie să aveți următoarele biblioteci:</span></p>
<ul>
<li dir="ltr">
<p dir="ltr"><strong>Wire:</strong><span> </span></p>
<ul>
<li dir="ltr">
<p dir="ltr"><span>Bibliotecă utilizată pentru comunicarea I2C;</span></p>
</li>
<li dir="ltr">
<p dir="ltr"><span>Este inclusă în mediul de dezvoltare Arduino IDE.</span></p>
</li>
</ul>
</li>
<li dir="ltr">
<p dir="ltr"><strong>Radio: </strong></p>
<ul>
<li dir="ltr">
<p dir="ltr"><span>Bibliotecă utilă pentru a facilitata utilizarea modulului FM;</span></p>
</li>
<li dir="ltr">
<p dir="ltr"><span>Dezvoltată de </span><strong>Matthias Hertel </strong><span>și este disponibilă în </span><span><strong>Library Manager</strong>.</span></p>
</li>
</ul>
</li>
<li dir="ltr">
<p dir="ltr"><strong>LiquidCrystal_I2C:</strong><span> </span></p>
<ul>
<li dir="ltr">
<p dir="ltr"><span>Creată special pentru utilizarea unui ecran <strong> LCD 1602</strong> prin protocolul I2C;</span></p>
</li>
<li dir="ltr">
<p dir="ltr"><span>Dezvoltată de </span><strong>Frank de Brabander </strong><span>și este inclusă în </span><strong>Library Manager.</strong></p>
</li>
</ul>
</li>
</ul>
<p>Pentru a afla mai multe detalii despre cum să instalați o bibliotecă în mediul de dezvoltare <strong>Arduino IDE</strong>, accesăți urmatorul <a href="https://www.optimusdigital.ro/content/10-tutorial-instalare-biblioteca"><span style="text-decoration: underline;">link</span>.</a></p>
<p></p>
<p></p>
<p dir="ltr"></p>
<p></p>
<p><span><span id="docs-internal-guid-e9fbae9b-5615-8f3a-70f0-d9d220a9b1cb"></span><br /></span></p>
<p><span id="docs-internal-guid-e9fbae9b-5614-6772-87f0-6a0159e93d05"><span id="docs-internal-guid-2796c614-5615-28b0-61ae-7359ce78c713"></span><br /></span></p>










