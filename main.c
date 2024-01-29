#include <stdio.h>
#include <math.h>

#ifdef _WIN32
#include <locale.h>
#endif


//fuggveny egy szam negyzetenek szamolasara
double Negyzet(int szam)
{
    return szam * szam;
}

// két koordináta felezopontjanak kiszamolasa
void Felezopont()
{
    double a1, a2, b1, b2;

    //adatbevitel

    printf("Add meg az 'A' vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' vektor második koordinátájat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a 'B' vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a 'B' vektor második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b2);

    //szamolas

    double f1, f2;

    f1 = (a1 + b1) / 2;
    f2 = (a2 + b2) / 2;

    //kiiras

    printf("A felezőpont első koordinátája: %lf\nMásodik koordinátája: %lf\n", f1, f2);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}
//két vektor közbezárt szöge
void Kozbezart()
{
    double a1, a2, b1, b2;

    //adatbevitel

    printf("Add meg az 'A' vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' vektor második koordinátájat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a 'B' vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a 'B' vektor második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b2);

    //szamolas

    double szog, cosSzog, hosszA, hosszB;
    const double PI =  3.1415926;

    hosszA = sqrt(Negyzet(a1) + Negyzet(a2));
    hosszB = sqrt(Negyzet(b1) + Negyzet(b2));

    cosSzog = ((a1 * b1) + (a2 * b2)) / (hosszA * hosszB);

    szog = acos(cosSzog) * 180 / PI;

    //kiiras

    printf("A két vektor közbezárt szöge %lf fok.\n", szog);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}

//két vektor n-edelo pontja
void Sokadolopont()
{
    int arany1, arany2;
    double a1, a2, b1, b2, f1, f2;

    //adatbevitel

    printf("Írd be a pont es a vektorok arányát ':'-al elválasztva (pl AS:SB 1:3 amiben 'S' az n-edelő pont, negyedelő pont esetén)\n");
    scanf("%i:%i", &arany1, &arany2);
    printf("Add meg az 'A' vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' vektor második koordinátájat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a 'B' vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a 'B' vektor második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b2);

    //szamolas

    f1 = (arany2 * a1 + arany1 * b1) / (arany1 + arany2);
    f2 = (arany2 * a2 + arany1 * b2) / (arany1 + arany2);

    //kiiras

    printf("Az n-edelő pont két koordinátája: %lf, %lf\n", f1, f2);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}

//koordinatakban megadott haromszog: K, s, T, szogek, r, R, oldalhosszak, oldalvektorok, m, sulypont

void Haromszog()
{
    //adatbevitel

    double a1, a2, b1, b2, c1, c2, K, s, T, alfa, beta, gamma, cosalfa, cosbeta, cosgamma, hosszA, hosszB, hosszC, ma, mb, mc, oldalA1, oldalA2, oldalB1, oldalB2, oldalC1, oldalC2, s1, s2, r, R;
    const double PI =  3.1415926;

    printf("Add meg az 'A' pont első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' pont második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a 'B' pont első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a 'B' pont második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b2);
    printf("Add meg a 'C' pont első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &c1);
    printf("Add meg a 'C' pont második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &c2);

    //szamolas

    //oldalvektorok
    oldalC1 = b1 - a1;
    oldalC2 = b2 - a2;
    oldalB1 = c1 - a1;
    oldalB2 = c2 - a2;
    oldalA1 = c1 - b1;
    oldalA2 = c2 - b2;

    //oldalhosszak
    hosszA = sqrt(Negyzet(oldalA1) + Negyzet(oldalA2));
    hosszB = sqrt(Negyzet(oldalB1) + Negyzet(oldalB2));
    hosszC = sqrt(Negyzet(oldalC1) + Negyzet(oldalC2));

    //kerulet es kerulet fele
    K = hosszA + hosszB + hosszC;
    s = K / 2;

    //terulet
    T = sqrt(s * (s - hosszA) * (s - hosszB) * (s - hosszC));

    //beirható kor sugara
    r = T / s;

    //körülírható kor sugara
    R = (hosszA * hosszB * hosszC) / (4 * T);

    //oldalhoz tartozo magassagok
    ma = (2 * T) / hosszA;
    mb = (2 * T) / hosszB;
    mc = (2 * T) / hosszC;

    //szogek
    cosalfa = ((oldalB1 * oldalC1) + (oldalB2 * oldalC2)) / (hosszB * hosszC);
    alfa = acos(cosalfa) * 180 / PI;
    cosbeta = ((oldalA1 * oldalC1) + (oldalA2 * oldalC2)) / (hosszA * hosszC);
    beta = acos(cosbeta) * 180 / PI;
    cosgamma = ((oldalB1 * oldalA1) + (oldalB2 * oldalA2)) / (hosszB * hosszA);
    gamma = acos(cosgamma) * 180 / PI;

    //sulypont
    s1 = (a1 + b1 + c1) / 3;
    s2 = (a2 + b2 + c2) / 3;

    //kiiras

    printf("Az 'a' oldal koordinátái: %lf, %lf\n", oldalA1, oldalA2);
    printf("A 'b' oldal koordinátái: %lf, %lf\n", oldalB1, oldalB2);
    printf("A 'c' oldal koordinátái: %lf, %lf\n", oldalC1, oldalC2);
    printf("Az 'a' oldal hossza: %lf\n", hosszA);
    printf("A 'b' oldal hossza: %lf\n", hosszB);
    printf("A 'c' oldal hossza: %lf\n", hosszC);
    printf("A háromszög kerülete: %lf, es kerületének fele: %lf\n", K, s);
    printf("A háromszög területe: %lf\n", T);
    printf("A háromszögbe beírható kör sugara: %lf, és a köréírható kör sugara: %lf\n", r, R);
    printf("Az 'a' oldalhoz tartozó magasság: %lf\n", ma);
    printf("A 'b' oldalhoz tartozó magasság: %lf\n", mb);
    printf("A 'c' oldalhoz tartozó magasság: %lf\n", mc);
    printf("A háromszög súlypontjának koordinátái: %lf, %lf\n", s1, s2);
    printf("A háromszög szögei, alfa: %lf fok, beta: %lf fok, gamma: %lf fok\n", alfa, beta, gamma);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}

//osszeadas
void Osszeadas()
{
    //adatbevitel
    double a1, a2, b1, b2, osszeg1, osszeg2;
    printf("Add meg az 'A' vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' vektor második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a 'B' vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a 'B' vektor második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b2);

    //szamolas
    osszeg1 = a1 + b1;
    osszeg2 = a2 + b2;

    //kiiras
    printf("Az összeg első koordinátája: %lf, második koordinátája: %lf\n", osszeg1, osszeg2);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}

//kivonas
void Kivonas()
{
    //adatbevitel
    double a1, a2, b1, b2, kulonbseg1, kulonbseg2;
    printf("Add meg a kissebbítendő vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg a kissebbítendő vektor második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a kivonandó vektor első koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a kivonandó vektor második koordinátáját, tizedesjel: '.'\n");
    scanf("%lf", &b2);

    //szamolas
    kulonbseg1 = a1 - b1;
    kulonbseg2 = a2 - b2;

    //kiiras
    printf("Az különbség első koordinátája: %lf, második koordinátája: %lf\n", kulonbseg1, kulonbseg2);
    //konzolablak nyitvatartasa windowson
    #ifdef _WIN32
    getchar();
    #endif
}


int main() {

    //ekezetekhez windows terminalban
    #ifdef _WIN32
    setlocale(LC_ALL, "hu_HU.UTF-8");
    #endif


    //funkcio kivalasztasa

    int valasz;
    printf("Milyen típusú feladatot szeretnél megoldani?\n");
    printf("1. Két vektor összeadása\n2. Két vektor különbsége\n3. Két vektor felezőpontja\n4. Két vektor n-edelő pontja (pl negyedelő)\n5. Két vektor közbezárt szöge\n6. Egy koordinátákban megadott háromszög K, s, T, oldalvektorai, oldalhosszai, beírható és körülírható kör sugara, oldalhoz tartozó magasságai, súlypontjának koordinátái, szögei\n");
    scanf("%i", &valasz);
    printf("%i\n", valasz);

    //valasztott funkcio futtatasa (tokeletes megvalositas)


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
            printf("Nem jó számot adtál meg.");

}

    //konzolablak nyitva tartasa (windows miatt fontos)
    #ifdef _WIN32
    printf("Nyomj <enter>-t a kilépéshez.\n");
    getchar();
    #endif
    return 0;
}

