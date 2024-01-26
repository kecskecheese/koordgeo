# Koordgeo
Egyszerű koordináta geometria feladatok megoldása.
### Eddigi tudás:
    - Két vektor felezőpontjának megadása
    - Egy koordinátákban megadott háromszög súlypontjának megadása
    - Egy koordinátákban megadott háromszög kerületének megadása
    - Két vektor közbezárt szögének megadása
    - Két vektor n-edelő (pl: negyedelő) pontjának megadása
### Még sok mindent tervezek, elég kezdetleges a program
## Telepítés
### Windows
1. Töltsd le a `koordgeo-win64.exe` file-t [innen](https://github.com/kecskecheese/koordgeo/releases/tag/v0.1)
2. Futtasd
3. Az antivirus lehet jelezni fog, de nem vírus, fent láthatod a forráskódot.
### Linux
1. Töltsd le a `koordgeo-linux64` filet [innen](https://github.com/kecskecheese/koordgeo/releases/tag/v0.1)
2. Nyisd meg a terminált
3. Írd be a következőt: `sudo chmod +x út_a_filehoz/koordgeo-linux64` (ezzel futtathatóvá teszed a filet)
4. Majd a következőt a futtatáshoz: `út_a_filehoz/koordgeo-linux64`
### Android (Termux)
Ez kicsit bonyolultabb, de szükséges az androidon való futtatáshoz.
1. Töltsd le a `koordgeo-termux-arm64` filet [innen](https://github.com/kecskecheese/koordgeo/releases/tag/v0.1)
2. Telepítsd a [Termux-ot](https://f-droid.org/packages/com.termux/) Fontos, hogy ne a Play storeból telepítsd, mert ott régi verzió van.
3. Nyisd meg a Termux alkalmazást és írd be a következőt `termux-setup-storage`, majd engedélyezd a fájlok elérését
4. Engedélyezd a program futását: `chmod +x ~/storage/downloads/koordgeo-termux-arm64` (az elérési út lehet, hogy más de elég valószínű, hogy ez)
5. Futtasd a programot: `~/storage/downloads/koordgeo-termux-arm64` (az elérési út lehet, hogy más de elég valószínű, hogy ez)
### Compile
Ha nincs az architektúrádra futtatható program (pl.: 32-bites operációs rendszert használsz) saját magadnak kell összeállítani a programot
<br>
Szükséged lesz `git`-re és `gcc`-re
#### Debian/Ubuntu alapú linux
1. `sudo apt install gcc git`<br>
2. `git clone https://github.com/kecskecheese/koordgeo`<br>
3. `cd koordgeo`<br>
4. `gcc main.c -o koordgeo -lm`<br>
5. `./koordgeo`
#### Arch alaú linux
1. `sudo pacman -S gcc git`
2. `git clone https://github.com/kecskecheese/koordgeo`<br>
3. `cd koordgeo`<br>
4. `gcc main.c -o koordgeo -lm`<br>
5. `./koordgeo`
#### Fedora/Redhat alapú linux
1. `sudo dnf install gcc git`
2. `git clone https://github.com/kecskecheese/koordgeo`<br>
3. `cd koordgeo`<br>
4. `gcc main.c -o koordgeo -lm`<br>
5. `./koordgeo`
#### Android (Termux)
1. `pkg install git gcc`
2. `git clone https://github.com/kecskecheese/koordgeo`<br>
3. `cd koordgeo`<br>
4. `gcc main.c -o koordgeo -lm`<br>
5. `./koordgeo`
