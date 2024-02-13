#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifdef _WIN32
#include <locale.h>
#endif

struct Vektor
{
    float x, y;
};

struct Haromadat
{
    float a, b, c;
};

//konzolba kiírtak törlése windowson és linuxon
void clrscr()
{
    system("cls||clear");
}

// két koordináta felezopontjanak kiszamolasa
void Felezopont()
{
    clrscr();
    struct Vektor felezo;
    float aVektor[2], bVektor[2]; // a beolvasás szépsége miatt így hagynám struct helyett, nemtudom mennyire hülyeség
    //adatbevitel

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a vektor 'A' végpontjának %i. koordinátáját\n", i + 1);
        scanf("%f", &aVektor[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a vektor 'B' végpontjának %i. koordinátáját\n", i + 1);
        scanf("%f", &bVektor[i]);
    }

    //szamolas

    felezo.x = (aVektor[0] + bVektor[0]) / 2;
    felezo.y = (aVektor[1] + bVektor[1]) / 2;

    //kiiras
    clrscr();
    printf("A felezőpont koordinátái: %f, %f", felezo.x, felezo.y);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}
//két vektor közbezárt szöge
void Kozbezart()
{
    clrscr();
    float aVektor[2], bVektor[2];

    //adatbevitel

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg az 'A' vektor %i. koordinátáját\n", i + 1);
        scanf("%f", &aVektor[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a 'B' vektor %i. koordinátáját\n", i + 1);
        scanf("%f", &bVektor[i]);
    }

    //szamolas

    struct Vektor hossz; //tudom, hogy vektor a struct neve, de ha már van használjuk
    float szog;
    const double PI =  3.1415926;

    hossz.x = sqrt(pow(aVektor[0], 2) + pow(aVektor[1], 2));
    hossz.y = sqrt(pow(bVektor[0], 2) + pow(bVektor[1], 2));

    szog = acos(((aVektor[0] * bVektor[0]) + (aVektor[1] * bVektor[1])) / (hossz.x * hossz.y)) * 180 / PI;

    //kiiras
    clrscr();
    printf("A két vektor közbezárt szöge %f fok.\n", szog);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}

//két vektor n-edelo pontja
void Sokadolopont()
{
    clrscr();
    struct Vektor sokadolo;
    
    int arany[2];
    float aVektor[2], bVektor[2];

    //adatbevitel

    printf("Írd be a pont es a vektorok végpontjainak és az n-edelő pont arányát ':'-al elválasztva (pl AS:SB 1:3 amiben 'S' az n-edelő pont, negyedelő pont esetén)\n");
    scanf("%i:%i", &arany[0], &arany[1]);
    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a vektor 'A' végpontjának %i. koordinátáját\n", i + 1);
        scanf("%f", &aVektor[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a vektor 'B' végpontjának %i. koordinátáját\n", i + 1);
        scanf("%f", &bVektor[i]);
    }

    //szamolas

    sokadolo.x = (arany[1] * aVektor[0] + arany[0] * bVektor[0]) / (arany[0] + arany[1]);
    sokadolo.y = (arany[1] * aVektor[1] + arany[0] * bVektor[1]) / (arany[0] + arany[1]);

    //kiiras
    clrscr();
    printf("Az n-edelő pont két koordinátája: %f, %f\n", sokadolo.x, sokadolo.y);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}

//koordinatakban megadott haromszog: K, s, T, szogek, r, R, oldalhosszak, oldalvektorok, m, sulypont, sulyvonalak, kozepvonalak

int Haromszog()
{
    clrscr();

    //adatbevitel

    float aVektor[2], bVektor[2], cVektor[2], K, s, T, r, R;
    const double PI =  3.1415926;

    struct Vektor oldalA, oldalB, oldalC, felezoA, felezoB, felezoC, sulypont, sulyvonalA, sulyvonalB, sulyvonalC, kVonalA, kVonalB, kVonalC;
    struct Haromadat oHossz, m, szog, sVonalHossz, kVonalHossz; //.a = a oldal, .b = b oldal, stb...
    

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg az 'A' pont %i. koordinátáját\n", i + 1);
        scanf("%f", &aVektor[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a 'B' pont %i. koordinátáját\n", i + 1);
        scanf("%f", &bVektor[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a 'C' pont %i. koordinátáját\n", i + 1);
        scanf("%f", &cVektor[i]);
    }

    //menu
    printf("Melyik adatát szeretnéd tudni a háromszögnek?\n");
    printf("1. ");

    //szamolas

    //oldalvektorok
    oldalC.x = bVektor[0] - aVektor[0];
    oldalC.y = bVektor[1] - aVektor[1];
    oldalB.x = cVektor[0] - aVektor[0];
    oldalB.y = cVektor[1] - aVektor[1];
    oldalA.x = cVektor[0] - bVektor[0];
    oldalA.y = cVektor[1] - bVektor[1];

    //oldalfelezok
    felezoC.x = (aVektor[0] + bVektor[0]) / 2;
    felezoC.y = (aVektor[1] + bVektor[1]) / 2;

    felezoB.x = (cVektor[0] + aVektor[0]) / 2;
    felezoB.y = (cVektor[1] + aVektor[1]) / 2;

    felezoA.x = (cVektor[0] + bVektor[0]) / 2;
    felezoA.y = (cVektor[1] + bVektor[1]) / 2;

    //oldalhosszak
    oHossz.a = sqrt(pow(oldalA.x, 2) + pow(oldalA.y, 2));
    oHossz.b = sqrt(pow(oldalB.x, 2) + pow(oldalB.y, 2));
    oHossz.c = sqrt(pow(oldalC.x, 2) + pow(oldalC.y, 2));

    //kerulet es kerulet fele
    K = oHossz.a + oHossz.b + oHossz.c;
    s = K / 2;

    //terulet
    T = sqrt(s * (s - oHossz.a) * (s - oHossz.b) * (s - oHossz.c));

    //beirható kor sugara
    r = T / s;

    //körülírható kor sugara
    R = (oHossz.a * oHossz.b * oHossz.c) / (4 * T);

    //oldalhoz tartozo magassagok
    m.a = (2 * T) / oHossz.a;
    m.b = (2 * T) / oHossz.b;
    m.c = (2 * T) / oHossz.c;

    //szogek
    szog.a = acos(((oldalB.x * oldalC.x) + (oldalB.y * oldalC.y)) / (oHossz.b * oHossz.c)) * 180 / PI;
    szog.b = acos(((oldalA.x * oldalC.x) + (oldalA.y * oldalC.y)) / (oHossz.a * oHossz.c)) * 180 / PI;
    szog.c = acos(((oldalB.x * oldalA.x) + (oldalB.y * oldalA.y)) / (oHossz.b * oHossz.a)) * 180 / PI;

    //sulypont
    sulypont.x = (aVektor[0] + bVektor[0] + cVektor[0]) / 3;
    sulypont.y = (aVektor[1] + bVektor[1] + cVektor[1]) / 3;

    //kozepvonal
    kVonalA.x = felezoC.x - felezoB.x;
    kVonalA.y = felezoC.y - felezoB.y;
    kVonalB.x = felezoC.x - felezoA.x;
    kVonalB.y = felezoC.y - felezoA.y;
    kVonalC.x = felezoA.x - felezoB.x;
    kVonalC.y = felezoA.y - felezoB.y;
    kVonalHossz.a = sqrt(pow(kVonalA.x, 2) + pow(kVonalA.y, 2));
    kVonalHossz.b = sqrt(pow(kVonalB.x, 2) + pow(kVonalB.y, 2));
    kVonalHossz.c = sqrt(pow(kVonalC.x, 2) + pow(kVonalC.y, 2));

    //sulyvonal
    sulyvonalA.x = aVektor[0] - felezoA.x;
    sulyvonalA.y = aVektor[1] - felezoA.y;
    sulyvonalB.x = bVektor[0] - felezoB.x;
    sulyvonalB.y = bVektor[1] - felezoB.y;
    sulyvonalC.x = cVektor[0] - felezoC.x;
    sulyvonalC.y = cVektor[1] - felezoC.y;
    sVonalHossz.a = sqrt(pow(sulyvonalA.x, 2) + pow(sulyvonalA.y, 2));
    sVonalHossz.b = sqrt(pow(sulyvonalB.x, 2) + pow(sulyvonalB.y, 2));
    sVonalHossz.c = sqrt(pow(sulyvonalC.x, 2) + pow(sulyvonalC.y, 2));

    for(;;)
    {
    clrscr();

    printf("Mit szeretnél tudni?\n");
    printf("1. Az oldalak hosszai és koordinátái\n");
    printf("2. Az oldalfelezők koordinátái\n");
    printf("3. A háromszög kerülete és területe\n");
    printf("4. A beírható és köréírható kör sugara\n");
    printf("5. A magasságvonalak hosszai\n");
    printf("6. A súlyvonalak és a súlypont\n");
    printf("7. A háromszög szögei\n");
    printf("8. A középvonalak\n");
    printf("9. Kilépés\n");

    int valasz;

    scanf("%i", &valasz);

    switch (valasz)
    {
    case 1:
        printf("Az 'a' oldal koordinátái: %f, %f\n", oldalA.x, oldalA.y);
        printf("A 'b' oldal koordinátái: %f, %f\n", oldalB.x, oldalB.y);
        printf("A 'c' oldal koordinátái: %f, %f\n", oldalC.x, oldalC.y);
        printf("Az 'a' oldal hossza: %f\n", oHossz.a);
        printf("A 'b' oldal hossza: %f\n", oHossz.b);
        printf("A 'c' oldal hossza: %f\n", oHossz.c);
        getchar();
        getchar(); //kettő kell mert c moment
        break;
    case 2:
        printf("Az 'a' oldal felezőjének koordinátái: %f, %f\n", felezoA.x, felezoA.y);
        printf("A 'b' oldal felezőjének koordinátái: %f, %f\n", felezoB.x, felezoB.y);
        printf("A 'c' oldal felezőjének koordinátái: %f, %f\n", felezoC.x, felezoC.y);
        getchar();
        getchar();
        break;
    case 3:
        printf("A háromszög kerülete: %f, es kerületének fele: %f\n", K, s);
        printf("A háromszög területe: %f\n", T);
        getchar();
        getchar();
        break;
    case 4:
        printf("A háromszögbe beírható kör sugara: %f, és a köréírható kör sugara: %f\n", r, R);
        getchar();
        getchar();
        break;
    case 5:
        printf("Az 'a' oldalhoz tartozó magasság: %f\n", m.a);
        printf("A 'b' oldalhoz tartozó magasság: %f\n", m.b);
        printf("A 'c' oldalhoz tartozó magasság: %f\n", m.c);
        getchar();
        getchar();
        break;
    case 6:
        printf("A háromszög súlypontjának koordinátái: %f, %f\n", sulypont.x, sulypont.y);
        printf("Az a oldalhoz tartozó súlyvonal: %f, %f\n", sulyvonalA.x, sulyvonalA.y);
        printf("A b oldalhoz tartozó súlyvonal: %f, %f\n", sulyvonalB.x, sulyvonalB.y);
        printf("A c oldalhoz tartozó súlyvonal: %f, %f\n", sulyvonalC.x, sulyvonalC.y);
        printf("Az a oldalhoz tartozó súlyvonal hossza: %f\n", sVonalHossz.a);
        printf("A b oldalhoz tartozó súlyvonal hossza: %f\n", sVonalHossz.b);
        printf("A c oldalhoz tartozó súlyvonal hossza: %f\n", sVonalHossz.c);
        getchar();
        getchar();
        break;
    case 7:
        printf("A háromszög szögei, alfa: %f fok, beta: %f fok, gamma: %f fok\n", szog.a, szog.b, szog.c);
        getchar();
        getchar();
        break;
    case 8:
        printf("Az a és a b oldalt összekötő középvonal: %f %f\n", kVonalC.x, kVonalC.y);
        printf("Az a és a c oldalt összekötő középvonal: %f %f\n", kVonalB.x, kVonalB.y);
        printf("A c és a b oldalt összekötő középvonal: %f %f\n", kVonalA.x, kVonalA.y);
        printf("Az a és a b oldalt összekötő középvonal hossza: %f\n", kVonalHossz.c);
        printf("Az a és a c oldalt összekötő középvonal hossza: %f\n", kVonalHossz.b);
        printf("A c és a b oldalt összekötő középvonal hossza: %f\n", kVonalHossz.a);
        getchar();
        getchar();
        break;
    case 9:
        return 0;
    default:
        printf("Nem jó számot adtál meg\n");
        break;
    }
    }

    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}

//osszeadas
void Osszeadas()
{
    clrscr();
    //adatbevitel
    struct Vektor osszeg;
    float aVektor[2], bVektor[2];
    for (int i = 0; i < 2; i++)
    {
        printf("Add meg az 'A' vektor %i. koordinátáját\n", i + 1);
        scanf("%f", &aVektor[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a 'B' vektor %i. koordinátáját\n", i + 1);
        scanf("%f", &bVektor[i]);
    }

    //szamolas
    osszeg.x = aVektor[0] + bVektor[0];
    osszeg.y = aVektor[1] + bVektor[1];

    //kiiras
    clrscr();
    printf("Az összeg koordinátái: %f, %f\n", osszeg.x, osszeg.y);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}

//kivonas
void Kivonas()
{
    clrscr();
    //adatbevitel
    struct Vektor kulonbseg;
    float aVektor[2], bVektor[2];
    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a kissebbítendő vektor %i. koordinátáját\n", i + 1);
        scanf("%f", &aVektor[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Add meg a kivonandó vektor %i. koordinátáját\n", i + 1);
        scanf("%f", &bVektor[i]);
    }

    //szamolas
    kulonbseg.x = aVektor[0] - bVektor[0];
    kulonbseg.y = aVektor[1] - bVektor[1];

    //kiiras
    clrscr();
    printf("Az összeg koordinátái: %f, %f\n", kulonbseg.x, kulonbseg.y);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}


int main() {

    //ekezetekhez a "nagyszeru" windows terminalban
    #ifdef _WIN32
    setlocale(LC_ALL, "hu_HU.UTF-8");
    #endif


    //funkcio kivalasztasa

    int valasz;
    clrscr();
    printf("Milyen típusú feladatot szeretnél megoldani?\n");
    printf("1. Két vektor összeadása\n2. Két vektor különbsége\n3. Két vektor felezőpontja\n4. Két vektor n-edelő pontja (pl negyedelő)\n5. Két vektor közbezárt szöge\n6. Egy koordinátákban megadott háromszög adatai.\n");
    scanf("%i", &valasz);
    printf("%i\n", valasz);

    switch (valasz) {
        case 1:
            Osszeadas();
            break;
        case 2:
            Kivonas();
            break;
        case 3:
            Felezopont();
            break;
        case 4:
            Sokadolopont();
            break;
        case 5:
            Kozbezart();
            break;
        case 6:
            Haromszog();
            break;
        default:
            printf("Nem jó számot adtál meg.\n");

}

    //konzolablak nyitva tartasa windowson
    #ifdef _WIN32
    printf("Nyomj <enter>-t a kilépéshez.\n");
    getchar();
    getchar();
    #endif
    return 0;
}

