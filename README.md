# Koordgeo
Egyszerű koordináta geometria feladatok megoldása.
### Eddigi tudás:
- Két vektor felezőpontjának megadása
- Koordinátákban megadott háromszög
    - Kerület, kerület fele
    - Terület
    - Oldalai vektorban
    - Oldalak hossza
    - Oldalakhoz tartozó magasságok
    - Beírható és köréírható kör sugarai
    - Szögek fokban
- Két vektor közbezárt szögének megadása
- Két vektor n-edelő (pl: negyedelő) pontjának megadása
- Két vektor összeadása, kivonása
### Még sok mindent tervezek, elég kezdetleges a program
## Telepítés
### Windows
1. Töltsd le a `koordgeo-win64.exe` file-t [innen](https://github.com/kecskecheese/koordgeo/releases/tag/v0.2.1)
2. Futtasd
3. Az antivirus lehet jelezni fog, de nem vírus, fent láthatod a forráskódot.
### Linux
1. Töltsd le a `koordgeo-linux64.bin` filet [innen](https://github.com/kecskecheese/koordgeo/releases/tag/v0.2.1)
2. Nyisd meg a terminált
3. Írd be a következőt: `sudo chmod +x út_a_filehoz/koordgeo-linux64.bin` (ezzel futtathatóvá teszed a filet)
4. Majd a következőt a futtatáshoz: `út_a_filehoz/koordgeo-linux64.bin`
### Android (Termux)
Ez kicsit bonyolultabb, de szükséges az androidon való futtatáshoz.
1. Telepítsd a [Termux-ot](https://github.com/termux/termux-app/releases/download/v0.118.0/termux-app_v0.118.0+github-debug_universal.apk) Fontos, hogy ne a Play storeból telepítsd, mert ott régi verzió van.
2. Futtasd a következőket:
3. `pkg install git gcc make`
4. `git clone https://github.com/kecskecheese/koordgeo`
5. `cd koordgeo`
6. `make linux`
7. Ha futtatsz egy `ls`-t elvileg látni fogod a következő fájlt: `koordgeo-linux64.bin`
8. `~/koordgeo/koordgeo-linux64.bin`-el tudod futtatni

### Ha valahol elakadsz nyiss egy [hibát](https://github.com/kecskecheese/koordgeo/issues) és segítek.

### Compile
Ha nincs az architektúrádra futtatható program (pl.: 32-bites operációs rendszert használsz) saját magadnak kell összeállítani a programot
<br>
Szükséged lesz `git`-re és `gcc`-re
#### Debian/Ubuntu alapú linux
1. `sudo apt install gcc git make`<br>
2. `git clone https://github.com/kecskecheese/koordgeo`<br>
3. `cd koordgeo`<br>
4. `make linux`<br>
5. `./koordgeo-linux64.bin`
#### Arch alapú linux
1. `sudo pacman -S gcc git make`
2. `git clone https://github.com/kecskecheese/koordgeo`<br>
3. `cd koordgeo`<br>
4. `make linux`<br>
5. `./koordgeo-linux64.bin`
#### Fedora/Redhat alapú linux
1. `sudo dnf install gcc git make`
2. `git clone https://github.com/kecskecheese/koordgeo`<br>
3. `cd koordgeo`<br>
4. `make linux`<br>
5. `./koordgeo-linux64.bin`
#### Android (Termux)
1. `pkg install git gcc make`
2. `git clone https://github.com/kecskecheese/koordgeo`<br>
3. `cd koordgeo`<br>
4. `make linux`<br>
5. `./koordgeo-linux64.bin`
