#include <stdio.h>
#include <math.h>
#include <locale.h>


//fuggveny egy szam negyzetenek szamolasara
double Negyzet(int szam)
{
    return szam * szam;
}

// ket koordinata felezopontjanak kiszamolasa
int Felezopont()
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

    //konzolablak nyitva tartasa (windows miatt fontos)
    puts("Nyomj <enter>-t a kilépéshez\n");
    getchar();
    return 0;
}

//ket vektor kozbezart szoge
int Kozbezart()
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

    //konzolablak nyitva tartasa (windows miatt fontos)
    puts("Nyomj <enter>-t a kilépéshez\n");
    getchar();
    return 0;
}

//ket vektor n-edelo pontja
int Sokadolopont()
{
    int arany1, arany2;
    double a1, a2, b1, b2, f1, f2;

    //adatbevitel

    printf("Írd be a pont es a vektorok arányát ':'-al elválasztva (pl AS:SB 1:3 amiben 'S' az n-edelo pont, negyedelo pont eseten)\n");
    scanf("%i:%i", &arany1, &arany2);
    printf("Ird be az 'A' pont koordinatait ','-vel elvalasztva, tizedesjel: '.'\n");
    scanf("%lf,%lf", &a1, &a2);
    printf("Ird be a 'B' pont koordinatait ','-vel elvalasztva, tizedesjel: '.'\n");
    scanf("%lf,%lf", &b1, &b2);

    //szamolas

    f1 = (arany2 * a1 + arany1 * b1) / (arany1 + arany2);
    f2 = (arany2 * a2 + arany1 * b2) / (arany1 + arany2);

    //kiiras

    printf("Az n-edelo pont ket koordinataja: %lf, %lf\n", f1, f2);

    //konzolablak nyitva tartasa (windows miatt fontos)
    puts("Nyomj <enter>-t a kilepeshez\n");
    getchar();
    return 0;
}

//koordinatakban megadott haromszog: K, s, T, szogek, r, R, oldalhosszak, oldalvektorok, m, sulypont

int Haromszog()
{
    //adatbevitel

    double a1, a2, b1, b2, c1, c2, K, s, T, alfa, beta, gamma, cosalfa, cosbeta, cosgamma, hosszA, hosszB, hosszC, ma, mb, mc, oldalA1, oldalA2, oldalB1, oldalB2, oldalC1, oldalC2, s1, s2, r, R;
    const double PI =  3.1415926;

    printf("Add meg az 'A' pont elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' pont masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a 'B' pont elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a 'B' pont masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b2);
    printf("Add meg a 'C' pont elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &c1);
    printf("Add meg a 'C' pont masodik koordinatajat, tizedesjel: '.'\n");
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

    //beirhato kor sugara
    r = T / s;

    //korulirhato kor sugara
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

    printf("Az 'a' oldal koordinatai: %lf, %lf\n", oldalA1, oldalA2);
    printf("A 'b' oldal koordinatai: %lf, %lf\n", oldalB1, oldalB2);
    printf("A 'c' oldal koordinatai: %lf, %lf\n", oldalC1, oldalC2);
    printf("Az 'a' oldal hossza: %lf\n", hosszA);
    printf("A 'b' oldal hossza: %lf\n", hosszB);
    printf("A 'c' oldal hossza: %lf\n", hosszC);
    printf("A haromszog kerulete: %lf, es keruletenek fele: %lf\n", K, s);
    printf("A haromszog terulete: %lf\n", T);
    printf("A haromszogbe beirhato kor sugara: %lf, es a koreirhato kor sugara: %lf\n", r, R);
    printf("Az 'a' oldalhoz tartozo magassag: %lf\n", ma);
    printf("A 'b' oldalhoz tartozo magassag: %lf\n", mb);
    printf("A 'c' oldalhoz tartozo magassag: %lf\n", mc);
    printf("A haromszog sulypontjanak koordinatai: %lf, %lf\n", s1, s2);
    printf("A haromszog szogei, alfa: %lf fok, beta: %lf fok, gamma: %lf fok\n", alfa, beta, gamma);

    //konzolablak nyitva tartasa (windows miatt fontos)
    puts("Nyomj <enter>-t a kilepeshez\n");
    getchar();
    return 0;
}

//osszeadas
int Osszeadas()
{
    //adatbevitel
    double a1, a2, b1, b2, osszeg1, osszeg2;
    printf("Add meg az 'A' vektor elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' vektor masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a 'B' vektor elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a 'B' vektor masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b2);

    //szamolas
    osszeg1 = a1 + b1;
    osszeg2 = a2 + b2;

    //kiiras
    printf("Az osszeg elso koordinataja: %lf, masodik koordinataja: %lf\n", osszeg1, osszeg2);

    //konzolablak nyitva tartasa (windows miatt fontos)
    puts("Nyomj <enter>-t a kilepeshez\n");
    getchar();
    return 0;
}

//kivonas
int Kivonas()
{
    //adatbevitel
    double a1, a2, b1, b2, kulonbseg1, kulonbseg2;
    printf("Add meg a kissebbitendo vektor elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg a kissebbitendo vektor masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a kivonando vektor elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a kivonando vektor masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b2);

    //szamolas
    kulonbseg1 = a1 - b1;
    kulonbseg2 = a2 - b2;

    //kiiras
    printf("Az kulonbseg elso koordinataja: %lf, masodik koordinataja: %lf\n", kulonbseg1, kulonbseg2);

    //konzolablak nyitva tartasa (windows miatt fontos)
    puts("Nyomj <enter>-t a kilepeshez\n");
    getchar();
    return 0;
}


int main()
{
    //ekezetekhez windows terminalban
    setlocale(LC_ALL, "");
    //funkcio kivalasztasa

    int valasz;
    printf("Milyen tipusu feladatot szeretnel megoldani?\n");
    printf("1. Ket vektor osszeadasa\n2. Ket vektor kulonbsege\n3. Ket vektor felezopontja\n4. Ket vektor n-edelo pontja (pl negyedelo)\n5. Ket vektor kozbezart szoge\n6. Egy koordinatakban megadott haromszog K, s, T, oldalvektorai, oldalhosszai, beirhato es korulirhato kor sugara, oldalhoz tartozo magassagai, sulypontjanak koordinatai, szogei\n");
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
            printf("Nem jo szamot adtal meg.");

}

    //konzolablak nyitva tartasa (windows miatt fontos)
    getchar();
    return 0;
}

