#include <stdio.h>

#include "megjelenites.h"
#include "listakezeles.h"
#include "debugmalloc.h"

void fomenuKiir(void){
    printf("Telefonkonyv\n");
    printf("\n");
    printf("1: Adatbazis listazasa\n");
    printf("2: Uj rekord rogzitese\n");
    printf("3: Rekord modositasa\n");
    printf("4: Rekord torlese\n");
    printf("5: Kereses\n");
    printf("6: Adatbazis elmentese\n");
    printf("7: vCard\n");
    printf("8: Sugo\n");
    printf("\n");
    printf("0: Kilepes\n");
    return;
}

void listazasKiir(Rekord *lista){
    printf("9: Vissza\n");
    printf("A rekordok:\n\n");
    listaz(lista);
    return;
}

void rogzitesKiir(void){
    printf("9: Vissza\n");
    printf("Add meg az uj rekord adatait\n");
    return;
}

void modositasKiir(void){
    printf("9: Vissza\n");
    printf("Add meg a modositando rekord azonositojat, majd azt, hogy mire szertned modositani\n");
    return;
}

void torlesKiir(void){
    printf("9: Vissza\n");
    printf("Add meg a torlendo rekord azonositojat\n");
    return;
}

void keresesKiir(void){
    printf("9: Vissza\n");
    printf("Add meg a keresoszot\n");
    return;
}

void mentesKiir(void){
    printf("9: Vissza\n");
    printf("Az adatbazis el lett mentve fajlba\n");
    return;
}

void vcardKiir(void){
    printf("9: Vissza\n");
    printf("1: vCard exportalasa\n");
    printf("2: vCard importalasa\n");
    return;
}

void vcardexportKiir(void){
    printf("9: Vissza\n");
    printf("Add meg a exportalando rekord azonositojat\n");
    return;
}

void vcardimportKiir(void){
    printf("9: Vissza\n");
    printf("Add meg az importalando fajl nevet\n");
    return;
}

void sugoKiir(void){
    printf("9: Vissza\n");
    return;
}
