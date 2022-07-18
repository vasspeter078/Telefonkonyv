#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "listakezeles.h"
#include "debugmalloc.h"

void nevMasol(Nev *np, Nev n){
    strcpy(np->vezetek, n.vezetek);
    strcpy(np->kereszt, n.kereszt);
    return;
}

void cimMasol(Cim *cp, Cim c){
    strcpy(cp->varos, c.varos);
    strcpy(cp->utca, c.utca);
    strcpy(cp->hazszam, c.hazszam);
    return;
}

void rekordMasol(Rekord *rp, Rekord r){
    rp->azonosito = r.azonosito;
    nevMasol(&(rp->nev), r.nev);
    strcpy(rp->telefonszam, r.telefonszam);
    cimMasol(&(rp->cim), r.cim);
    strcpy(rp->foglalkozas, r.foglalkozas);
    rp->kov = r.kov;
}

bool azonositoLetezik(Rekord *lista, int azonosito){
    for (Rekord *iter = lista; iter != NULL; iter = iter->kov){
        if (iter->azonosito == azonosito)
            return true;
    }
    return false;
}

int azonositoGeneral(Rekord *lista){
    int azonosito = rand() % 1000 + 1;
    while (azonositoLetezik(lista, azonosito)){
        azonosito = rand() % 1000 + 1;
    }
    return azonosito;
}

Rekord rekordBeolvas(Rekord *lista){
    Rekord r;
    scanf("%s %s %s %s %s %s %s", r.nev.vezetek, r.nev.kereszt, r.telefonszam, r.cim.varos, r.cim.utca, r.cim.hazszam, r.foglalkozas);
    r.azonosito = azonositoGeneral(lista);
    return r;
}

void hozzaAd(Rekord **lista, Rekord r){
    Rekord *uj = (Rekord*) malloc(sizeof(Rekord));
    rekordMasol(uj, r);
    uj->kov = NULL;
    if (*lista == NULL){
        *lista = uj;
    }
    else{
        Rekord *iter = *lista;
        while (iter->kov != NULL){
            iter = iter->kov;
        }
        iter->kov = uj;
    }
    return;
}

void torol(Rekord **lista, int azonosito){
    if ((*lista)->azonosito == azonosito){
        Rekord *temp = *lista;
        *lista = (*lista)->kov;
        free(temp);
        return;
    }
    Rekord *iter = *lista;
    Rekord *lemarado;
    while (azonosito != iter->azonosito && iter->kov != NULL){
        lemarado = iter;
        iter = iter->kov;
    }
    lemarado->kov = iter->kov;
    free(iter);
    return;
}

bool rekordUgyanaz(Rekord r1, Rekord r2){
    if (strcmp(r1.nev.vezetek, r2.nev.vezetek) != 0)
        return false;
    if (strcmp(r1.nev.kereszt, r2.nev.kereszt) != 0)
        return false;
    if (strcmp(r1.telefonszam, r2.telefonszam) != 0)
        return false;
    if (strcmp(r1.cim.varos, r2.cim.varos) != 0)
        return false;
    if (strcmp(r1.cim.utca, r2.cim.utca) != 0)
        return false;
    if (strcmp(r1.cim.hazszam, r2.cim.hazszam) != 0)
        return false;
    if (strcmp(r1.foglalkozas, r2.foglalkozas) != 0)
        return false;
    return true;
}

void modosit(Rekord *lista, int azonosito, Rekord r){
    Rekord *iter = lista;
    while (azonosito != lista->azonosito){
        iter = iter->kov;
    }
    Rekord *kov = iter->kov;
    rekordMasol(iter, r);
    iter->kov = kov;
    return;
}

bool keresCsillaggal(char *input, char *adat){
    char *elejeInput = input;
    char *vegeInput = input + strlen(input) - 1;
    char *elejeAdat = adat;
    char *vegeAdat = adat + strlen(adat) - 1;
    while (*elejeInput != '*'){
        if (*elejeInput != *elejeAdat){
            return false;
        }
        ++elejeInput;
        ++elejeAdat;
    }
    while (*vegeInput != '*'){
        if (*vegeInput != *vegeAdat){
            return false;
        }
        --vegeInput;
        --vegeAdat;
    }
    return true;
}

bool keres(Rekord r, char *input){
    char azonosito[20 + 1];
    itoa(r.azonosito, azonosito, 10);
    if (strchr(input, '*') == NULL){
        if (strcmp(azonosito, input) == 0){
            return true;
        }
        if (strcmp(r.nev.vezetek, input) == 0){
            return true;
        }
        if (strcmp(r.nev.kereszt, input) == 0){
            return true;
        }
        if (strcmp(r.telefonszam, input) == 0){
            return true;
        }
        if (strcmp(r.cim.varos, input) == 0){
            return true;
        }
        if (strcmp(r.cim.utca, input) == 0){
            return true;
        }
        if (strcmp(r.cim.hazszam, input) == 0){
            return true;
        }
        if (strcmp(r.foglalkozas, input) == 0){
            return true;
        }
    }
    else{
        if (keresCsillaggal(input, azonosito)){
            return true;
        }
        if (keresCsillaggal(input, r.nev.vezetek)){
            return true;
        }
        if (keresCsillaggal(input, r.nev.kereszt)){
            return true;
        }
        if (keresCsillaggal(input, r.telefonszam)){
            return true;
        }
        if (keresCsillaggal(input, r.cim.varos)){
            return true;
        }
        if (keresCsillaggal(input, r.cim.utca)){
            return true;
        }
        if (keresCsillaggal(input, r.cim.hazszam)){
            return true;
        }
        if (keresCsillaggal(input, r.foglalkozas)){
            return true;
        }
    }
    return false;
}

Rekord *azonositoKeres(Rekord *lista, int azonosito){
    for (Rekord *iter = lista; iter != NULL; iter = iter->kov){
        if (iter->azonosito == azonosito){
            return iter;
        }
    }
    return NULL;
}

void listaFelszabadit(Rekord *lista){
    Rekord *temp;
    for (Rekord *iter = lista; iter != NULL; iter = temp){
        temp = iter->kov;
        free(iter);
    }
    return;
}

void rekordKiir(Rekord r){
    printf("%d ", r.azonosito);
    printf("%s ", r.nev.vezetek);
    printf("%s ", r.nev.kereszt);
    printf("%s ", r.telefonszam);
    printf("%s ", r.cim.varos);
    printf("%s ", r.cim.utca);
    printf("%s ", r.cim.hazszam);
    printf("%s ", r.foglalkozas);
    printf("\n");
    return;
}

void listaz(Rekord *lista){
    for (Rekord *iter = lista; iter != NULL; iter = iter -> kov){
        rekordKiir(*iter);
    }
    return;
}

void ment(Rekord *lista){
    FILE *fp = fopen("telefonkonyv.txt", "w");
    for (Rekord *iter = lista; iter != NULL; iter = iter->kov){
        fprintf(fp, "%d %s %s %s %s %s %s %s\n", iter->azonosito, iter->nev.vezetek, iter->nev.kereszt, iter->telefonszam, iter->cim.varos, iter->cim.utca, iter->cim.hazszam, iter->foglalkozas);
    }
    fclose(fp);
    return;
}

void fajlbaIr(FILE *fp, Rekord r){
    fprintf(fp, "BEGIN:VCARD\n");
    fprintf(fp, "VERSION:4.0\n");
    fprintf(fp, "FN:%s %s\n", r.nev.vezetek, r.nev.kereszt);
    fprintf(fp, "TEL:%s\n", r.telefonszam);
    fprintf(fp, "ADR:%s %s %s\n", r.cim.varos, r.cim.utca, r.cim.hazszam);
    fprintf(fp, "TITLE:%s\n", r.foglalkozas);
    fprintf(fp, "END:VCARD\n");
    return;
}

bool nevInput(char *input){
    if (input[0] == 'F' && input[1] == 'N'){
        return true;
    }
    return false;
}

bool telefonszamInput(char *input){
    if (input[0] == 'T' && input[1] == 'E' && input[2] == 'L'){
        return true;
    }
    return false;
}

bool cimInput(char *input){
    if (input[0] == 'A' && input[1] == 'D' && input[2] == 'R'){
        return true;
    }
    return false;
}

bool foglalkozasInput(char *input){
    if (input[0] == 'T' && input[1] == 'I' && input[2] == 'T' && input[3] == 'L' && input[4] == 'E'){
        return true;
    }
    return false;
}

void nevHozzaad(char *input, Rekord *rp){
    char vezetek[20 + 1];
    char kereszt[20 + 1];
    int inputIndex = 3;
    int vezetekIndex = 0;
    while (input[inputIndex] != ' '){
        vezetek[vezetekIndex++] = input[inputIndex++];
    }
    vezetek[vezetekIndex] = '\0';
    strcpy(rp->nev.vezetek, vezetek);
    int keresztIndex = 0;
    ++inputIndex;
    while (input[inputIndex] != '\0'){
        kereszt[keresztIndex++] = input[inputIndex++];
    }
    kereszt[keresztIndex] = '\0';
    strcpy(rp->nev.kereszt, kereszt);
    return;
}

void telefonszamHozzaad(char *input, Rekord *rp){
    char telefonszam[20 + 1];
    int inputIndex = 4;
    int telefonszamIndex = 0;
    while (input[inputIndex] != '\0'){
        telefonszam[telefonszamIndex++] = input[inputIndex++];
    }
    telefonszam[telefonszamIndex] = '\0';
    strcpy(rp->telefonszam, telefonszam);
    return;
}

void cimHozzaad(char *input, Rekord *rp){
    char varos[20 + 1];
    char utca[20 + 1];
    char hazszam[20 + 1];
    int inputIndex = 4;
    int varosIndex = 0;
    while (input[inputIndex] != ' '){
        varos[varosIndex++] = input[inputIndex++];
    }
    varos[varosIndex] = '\0';
    strcpy(rp->cim.varos, varos);
    int utcaIndex = 0;
    ++inputIndex;
    while (input[inputIndex] != ' '){
        utca[utcaIndex++] = input[inputIndex++];
    }
    utca[utcaIndex] = '\0';
    strcpy(rp->cim.utca, utca);
    int hazszamIndex = 0;
    ++inputIndex;
    while (input[inputIndex] != '\0'){
        hazszam[hazszamIndex++] = input[inputIndex++];
    }
    hazszam[hazszamIndex] = '\0';
    strcpy(rp->cim.hazszam, hazszam);
    return;
}

void foglalkozasHozzaad(char *input, Rekord *rp){
    char foglalkozas[20 + 1];
    int inputIndex = 6;
    int foglalkozasIndex = 0;
    while (input[inputIndex] != '\0'){
        foglalkozas[foglalkozasIndex++] = input[inputIndex++];
    }
    foglalkozas[foglalkozasIndex] = '\0';
    strcpy(rp->foglalkozas, foglalkozas);
    return;
}

void vcardDekodol(char *input, Rekord *rp){
    char *iter = input;
    while (*iter != '\n'){
        ++iter;
    }
    *iter = '\0';
    if (nevInput(input)){
        nevHozzaad(input, rp);
        return;
    }
    if (telefonszamInput(input)){
        telefonszamHozzaad(input, rp);
        return;
    }
    if (cimInput(input)){
        cimHozzaad(input, rp);
        return;
    }
    if (foglalkozasInput(input)){
        foglalkozasHozzaad(input, rp);
        return;
    }
    return;
}

void fajlbolOlvas(FILE *fp, Rekord *rp){
    char input[100 + 1];
    while (fgets(input, 100, fp) != NULL){
        vcardDekodol(input, rp);
    }
}
