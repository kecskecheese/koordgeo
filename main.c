#include <stdio.h>
#include <math.h>

double Negyzet(int szam)
{
    return szam * szam;
}

int main()
{
    double a1, a2, b1, b2, c1, c2;
    
    //adatbevitel

    printf("Add meg az 'A' pont elso koordinatajat, ha tizedes '.'-al valaszd el\n");
    scanf("%lf", &a1);
    printf("Add meg az 'A' pont masodik koordinatajat, ha tizedes '.'-al valaszd el\n");
    scanf("%lf", &a2);
    printf("Add meg az 'B' pont elso koordinatajat, ha tizedes '.'-al valaszd el\n");
    scanf("%lf", &b1);
    printf("Add meg az 'B' pont masodik koordinatajat, ha tizedes '.'-al valaszd el\n");
    scanf("%lf", &b2);
    printf("Add meg az 'C' pont elso koordinatajat, ha tizedes '.'-al valaszd el\n");
    scanf("%lf", &c1);
    printf("Add meg az 'C' pont masodik koordinatajat, ha tizedes '.'-al valaszd el\n");
    scanf("%lf", &c2);
    

    //szamolas

    double hosszA, hosszB, hosszC, K, s;

    hosszA = sqrt(Negyzet(a1) + Negyzet(a2));
    hosszB = sqrt(Negyzet(b1) + Negyzet(b2));
    hosszC = sqrt(Negyzet(c1) + Negyzet(c2));

    K = hosszA + hosszB + hosszC;
    s = K / 2;
    //kiiras

    printf("A haromszog kerulete: %lf a keruletenek fele: %lf\n", K, s);

    return 0;
}