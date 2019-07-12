#ifndef FORMS__H
#define FORMS__H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *Form;

/*Coloca os dados de circulo em uma estrutura e retorna a estrutura*/
Form criarCirculo(char id[], double x, double y, double r, char strokeCollor[], char fillCollor[], char sw[]);

/*Coloca os dados de retangulo em uma estrutura e retorna a estrutura*/
Form criarRect(char id[], double x, double y, double w, double h, char strokeCollor[], char fillCollor[], int stroke, char sw[]);

/*Getters e setters para a forma*/
char *getFormId(Form f);

int getFormStroke(Form f);

double getFormX(Form f);

double getFormY(Form f);

double getFormR(Form f);

double getFormW(Form f);

double getFormH(Form f);

char *getFormStrokeCollor(Form f);

char *getFormFillCollor(Form f);

char *getFormSw(Form f);
/*Fim getters e setters*/

/*Libera memoria de uma forma*/
void freeForm(Form f);

#endif