#ifndef LISTAKEZELES_H_INCLUDED
#define LISTAKEZELES_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

#include "vezerles.h"

void nevMasol(Nev *np, Nev n);

void cimMasol(Cim *cp, Cim c);

void rekordMasol(Rekord *rp, Rekord r);

bool azonositoLetezik(Rekord *lista, int azonosito);

int azonositoGeneral(Rekord *lista);

Rekord rekordBeolvas(Rekord *lista);

void hozzaAd(Rekord **lista, Rekord r);

void torol(Rekord **lista, int azonosito);

bool rekordUgyanaz(Rekord r1, Rekord r2);

void modosit(Rekord *lista, int azonosito, Rekord r);

bool keresCsillaggal(char *input, char *adat);

bool keres(Rekord r, char *input);

Rekord *azonositoKeres(Rekord *lista, int azonosito);

void listaFelszabadit(Rekord *lista);

void rekordKiir(Rekord r);

void listaz(Rekord *lista);

void ment(Rekord *lista);

void fajlbaIr(FILE *fp, Rekord r);

bool nevInput(char *input);

bool telefonszamInput(char *input);

bool cimInput(char *input);

bool foglalkozasInput(char *input);

void nevHozzaad(char *input, Rekord *rp);

void telefonszamHozzaad(char *input, Rekord *rp);

void cimHozzaad(char *input, Rekord *rp);

void foglalkozasHozzaad(char *input, Rekord *rp);

void vcardDekodol(char *input, Rekord *rp);

void fajlbolOlvas(FILE *fp, Rekord *rp);

#endif // LISTAKEZELES_H_INCLUDED
