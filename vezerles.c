#include <stdio.h>
#include <time.h>

#include "vezerles.h"
#include "megjelenites.h"
#include "listakezeles.h"
#include "debugmalloc.h"

void indit(void){
    srand(time(0));
    Rekord *lista = NULL;
    Allapot a = fomenu;
    allapotVegrehajt(a, &lista);
    char input = getch();
    while ((a = kovetkezoAllapot(a, input)) != kilepes){
        system("cls");
        allapotVegrehajt(a, &lista);
        input = getch();
    }
    system("cls");
    listaFelszabadit(lista);
    return;
}

Allapot kovetkezoAllapot(Allapot a, char input){
        switch (a){
        case fomenu:
            switch (input){
            case '1':
                return listazas;
            case '2':
                return rogzites;
            case '3':
                return modositas;
            case '4':
                return torles;
            case '5':
                return kereses;
            case '6':
                return mentes;
            case '7':
                return vcard;
            case '8':
                return sugo;
            case '0':
                return kilepes;
            default:
                return fomenu;
            }
        case listazas:
            switch (input){
            case '9':
                return fomenu;
            default:
                return listazas;
            }
        case rogzites:
            switch (input){
            case '9':
                return fomenu;
            default:
                return rogzites;
            }
        case modositas:
            switch (input){
            case '9':
                return fomenu;
            default:
                return modositas;
            }
        case torles:
            switch (input){
            case '9':
                return fomenu;
            default:
                return torles;
            }
        case kereses:
            switch (input){
            case '9':
                return fomenu;
            default:
                return kereses;
            }
        case mentes:
            switch (input){
            case '9':
                return fomenu;
            default:
                return mentes;
            }
        case vcard:
            switch (input){
            case '1':
                return vcardexport;
            case '2':
                return vcardimport;
            case '9':
                return fomenu;
            default:
                return vcard;
            }
        case vcardexport:
            switch (input){
            case '9':
                return fomenu;
            default:
                return vcardexport;
            }
        case vcardimport:
            switch (input){
            case '9':
                return fomenu;
            default:
                return vcardimport;
            }
        case sugo:
            switch (input){
            case '9':
                return fomenu;
            default:
                return sugo;
            }
        default:
            return fomenu;
    }
}

void allapotVegrehajt(Allapot a, Rekord **lista){
    switch (a){
    case fomenu:
        fomenuVegrehajt();
        break;
    case listazas:
        listazasVegrehajt(*lista);
        break;
    case rogzites:
        rogzitesVegrehajt(lista);
        break;
    case modositas:
        modositasVegrehajt(*lista);
        break;
    case torles:
        torlesVegrehajt(lista);
        break;
    case kereses:
        keresesVegrehajt(*lista);
        break;
    case mentes:
        mentesVegrehajt(*lista);
        break;
    case vcard:
        vcardVegrehajt();
        break;
    case vcardexport:
        vcardexportVegrehajt(*lista);
        break;
    case vcardimport:
        vcardimportVegrehajt(lista);
        break;
    case sugo:
        sugoVegrehajt();
        break;
    default:
        fomenuVegrehajt();
        break;
    }
}

void fomenuVegrehajt(void){
    fomenuKiir();
    return;
}

void listazasVegrehajt(Rekord *lista){
    listazasKiir(lista);
    return;
}

void rogzitesVegrehajt(Rekord **lista){
    rogzitesKiir();
    Rekord r = rekordBeolvas(*lista);
    hozzaAd(lista, r);
    return;
}

void modositasVegrehajt(Rekord *lista){
    modositasKiir();
    int azonosito;
    scanf("%d", &azonosito);
    Rekord r = rekordBeolvas(lista);
    modosit(lista, azonosito, r);
    return;
}

void torlesVegrehajt(Rekord **lista){
    torlesKiir();
    int azonosito;
    scanf("%d", &azonosito);
    torol(lista, azonosito);
    return;
}

void keresesVegrehajt(Rekord *lista){
    keresesKiir();
    char input[20 + 1];
    scanf("%s", input);
    for (Rekord *iter = lista; iter != NULL; iter = iter->kov){
        if (keres(*iter, input)){
            rekordKiir(*iter);
        }
    }
    return;
}

void mentesVegrehajt(Rekord *lista){
    mentesKiir();
    ment(lista);
    return;
}

void vcardVegrehajt(void){
    vcardKiir();
    return;
}

void vcardexportVegrehajt(Rekord *lista){
    vcardexportKiir();
    int azonosito;
    scanf("%d", &azonosito);
    Rekord *rp = azonositoKeres(lista, azonosito);
    FILE *fp = fopen("export.vcard", "w");
    fajlbaIr(fp, *rp);
    fclose(fp);
    return;
}

void vcardimportVegrehajt(Rekord **lista){
    vcardimportKiir();
    char fajlnev[20 + 1];
    scanf("%s", fajlnev);
    Rekord r;
    FILE *fp = fopen(fajlnev, "r");
    fajlbolOlvas(fp, &r);
    hozzaAd(lista, r);
    return;
}

void sugoVegrehajt(void){
    sugoKiir();
    FILE *fp = fopen("sugo.txt", "r");
    char input[400 + 1];
    while (fgets(input, 400, fp) != NULL){
        printf("%s", input);
    }
    fclose(fp);
    return;
}
