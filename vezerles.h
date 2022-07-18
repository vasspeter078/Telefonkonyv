#ifndef VEZERLES_H_INCLUDED
#define VEZERLES_H_INCLUDED

typedef struct Nev{
    char vezetek[20 + 1];
    char kereszt[20 + 1];
}Nev;

typedef struct Cim{
    char varos[20 + 1];
    char utca[20 + 1];
    char hazszam[20 + 1];
}Cim;


typedef struct Rekord{
    int azonosito;
    Nev nev;
    char telefonszam[20 + 1];
    Cim cim;
    char foglalkozas[20 + 1];
    struct Rekord *kov;
}Rekord;

typedef enum Allapot{
    fomenu,
    listazas,
    rogzites,
    modositas,
    torles,
    kereses,
    mentes,
    vcard,
    vcardexport,
    vcardimport,
    sugo,
    kilepes
}Allapot;

void indit(void);

Allapot kovetkezoAllapot(Allapot a, char input);

void allapotVegrehajt(Allapot a, Rekord **lista);

void fomenuVegrehajt(void);

void listazasVegrehajt(Rekord *lista);

void rogzitesVegrehajt(Rekord **lista);

void modositasVegrehajt(Rekord *lista);

void torlesVegrehajt(Rekord **lista);

void keresesVegrehajt(Rekord *lista);

void mentesVegrehajt(Rekord *lista);

void vcardVegrehajt(void);

void vcardexportVegrehajt(Rekord *lista);

void vcardimportVegrehajt(Rekord **lista);

void sugoVegrehajt(void);

#endif // VEZERLES_H_INCLUDED
