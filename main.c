#include <stdio.h>
#include <math.h>

double Negyzet(int szam)
{
    return szam * szam;
}

int Kerulet()
{
    double a1, a2, b1, b2, c1, c2;

    //adatbevitel

    printf("Add meg az 'A' pont elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' pont masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg az 'B' pont elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg az 'B' pont masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b2);
    printf("Add meg az 'C' pont elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &c1);
    printf("Add meg az 'C' pont masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &c2);

    //szamolas

    double oldalA1, oldalA2, oldalB1, oldalB2, oldalC1, oldalC2, hosszA, hosszB, hosszC, K, s;

    oldalC1 = c1 - a1;
    oldalC2 = c2 - a2;
    oldalB1 = b1 - a1;
    oldalB2 = b2 - a2;
    oldalA1 = c1 - b1;
    oldalA2 = c2 - b2;

    hosszA = sqrt(Negyzet(oldalA1) + Negyzet(oldalA2));
    hosszB = sqrt(Negyzet(oldalB1) + Negyzet(oldalB2));
    hosszC = sqrt(Negyzet(oldalC1) + Negyzet(oldalC2));

    K = hosszA + hosszB + hosszC;
    s = K / 2;

    //kiiras

    printf("A haromszog kerulete: %lf a keruletenek fele: %lf\n", K, s);
    return 0;
}

int Felezopont()
{
    double a1, a2, b1, b2;

    //adatbevitel

    printf("Add meg az 'A' vektor elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' vektor masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg a 'B' vektor elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg a 'B' vektor masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b2);

    //szamolas

    double f1, f2;

    f1 = (a1 + b1) / 2;
    f2 = (a2 + b2) / 2;

    //kiiras

    printf("A felezopont elso koordinataja: %lf\nMasodik koordinataja: %lf\n", f1, f2);

    return 0;
}

int Sulypont()
{
    double a1, a2, b1, b2, c1, c2;
    
    //adatbevitel

    printf("Add meg az 'A' pont elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' pont masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg az 'B' pont elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg az 'B' pont masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b2);
    printf("Add meg az 'C' pont elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &c1);
    printf("Add meg az 'C' pont masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &c2);
    

    //szamolas

    double s1, s2;
    s1 = (a1 + b1 + c1) / 3;
    s2 = (a2 + b2 + c2) / 3;

    //kiiras

    printf("A sulypont elso koordinataja: %lf\nMasodik koordinataja: %lf\n", s1, s2);

    return 0;
}

int Kozbezart()
{
    double a1, a2, b1, b2;

    //adatbevitel

    printf("Add meg az 'A' vektor elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' vektor masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &a2);
    printf("Add meg az 'B' vektor elso koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b1);
    printf("Add meg az 'B' vektor masodik koordinatajat, tizedesjel: '.'\n");
    scanf("%lf", &b2);

    //szamolas

    double szog, cosSzog, hosszA, hosszB;
    const double PI =  3.1415926;

    hosszA = sqrt(Negyzet(a1) + Negyzet(a2));
    hosszB = sqrt(Negyzet(b1) + Negyzet(b2));

    cosSzog = ((a1 * b1) + (a2 * b2)) / (hosszA * hosszB);

    szog = acos(cosSzog) * 180 / PI;

    //kiiras

    printf("A ket vektor kozbezart szoge %lf fok.\n", szog);

    return 0;
}

int Sokadolopont()
{
    int arany1, arany2;
    double a1, a2, b1, b2, f1, f2;

    //adatbevitel

    printf("Ird be a pont es a vektorok aranyat ':'-al elvalasztva (pl AS:SB 1:3 amiben 'S' az n-edelo pont, negyedelo pont eseten)\n");
    scanf("%i:%i", &arany1, &arany2);
    printf("Ird be az 'A' pont koordinatait ','-vel elvalasztva, tizedesjel: '.'\n");
    scanf("%lf,%lf", &a1, &a2);
    printf("Ird be az 'B' pont koordinatait ','-vel elvalasztva, tizedesjel: '.'\n");
    scanf("%lf,%lf", &b1, &b2);

    //szamolas
    
    f1 = (arany2 * a1 + arany1 * b1) / (arany1 + arany2);
    f2 = (arany2 * a2 + arany1 * b2) / (arany1 + arany2);

    //kiiras

    printf("Az n-edelo pont ket koordinataja: %lf, %lf\n", f1, f2);

    return 0;
}

int main()
{
    //funkcio kivalasztasa

    int valasz;
    printf("Milyen tipusu feladatot szeretnel megoldani?\n");
    printf("1. Ket vektor felezopontja\n2. Egy koordinatakban megadott haromszog kerulete\n3. Egy koordinatakban megadott haromszog sulypontja\n4. Ket vektor kozbezart szoge\n5. Ket vektor n-edelo pontja (pl negyedelo)\n");
    scanf("%i", &valasz);
    printf("%i\n", valasz);

    //valasztott funkcio futtatasa (tokeletes megvalositas xD)
    if(valasz == 1)
    {
        Felezopont();
    }else if(valasz == 2)
    {
        Kerulet();
    }else if(valasz == 3)
    {
        Sulypont();
    }else if(valasz == 4)
    {
        Kozbezart();
    }else if(valasz == 5)
    {
        Sokadolopont();
    }
    
    return 0;
}

