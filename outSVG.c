#include "outSVG.h"

void criarArqSaida(char **nameOut, char nameIn[]){
    int i = 0;

    *nameOut = (char *)malloc((strlen(nameIn) + 1) * sizeof(char));

    while(nameIn[i] != '.'){
        (*nameOut)[i] = nameIn[i];
        i++;
    }
}

void criarArqSaida2(char **nameOut, char nameIn[], char nameConsulta[]){
    int i = 0, j = 0;

    *nameOut = (char *)malloc((strlen(nameIn) + strlen(nameConsulta)) * sizeof(char));
    while(nameIn[i] != '.'){
        (*nameOut)[i] = nameIn[i];
        i++;
        j++;
    }
    strcat(*nameOut, "-");
    i = 0;
    j++;
    while(nameConsulta[i] != '.'){
        (*nameOut)[j] = nameConsulta[i];
        i++;
        j++;
    }
}

void criarArqSaida3(char **nameOut, char nameIn[], char nameConsulta[], char sufixo[]){
    int i = 0, j = 0;

    *nameOut = (char *)malloc((strlen(nameIn) + strlen(nameConsulta) + strlen(sufixo)) * sizeof(char));
    while(nameIn[i] != '.'){
        (*nameOut)[i] = nameIn[i];
        i++;
        j++;
    }
    strcat(*nameOut, "-");
    i = 0;
    j++;
    while(nameConsulta[i] != '.'){
        (*nameOut)[j] = nameConsulta[i];
        i++;
        j++;
    }
    strcat(*nameOut, "-");
    i = 0;
    j++;
    while(sufixo[i] != '\0'){
        (*nameOut)[j] = sufixo[i];
        i++;
        j++;
    }
}

/*Printa as informacoes de circulo armazenadas no vetor de struct e formatadas para SVG no arquivo SVG*/
void printarCirculo(FILE *arqOut, Form circulo){
    fprintf(arqOut, "\n<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\"/>\n", getFormX(circulo),
     getFormY(circulo), getFormR(circulo), getFormStrokeCollor(circulo), getFormFillCollor(circulo), getFormSw(circulo));
}

/*Printa as informacoes de retangulo armazenadas no vetor de struct e formatadas para SVG no arquivo SVG*/
void printarRetangulo(FILE *arqOut, Form rect){

    fprintf(arqOut, "\n<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-dasharray=\"%d\" stroke-width=\"%s\"/>\n",
    getFormX(rect), getFormY(rect), getFormW(rect), getFormH(rect), getFormStrokeCollor(rect), getFormFillCollor(rect), getFormStroke(rect), getFormSw(rect));
}

/*Printa as informacoes de texto armazenadas em variaveis locais no vetor de struct e formatadas para SVG no arquivo SVG*/
void printarTexto(FILE *arqOut, double x, double y, char text[], char fillCollor[]){

    fprintf(arqOut, "\n<text x=\"%lf\" y=\"%lf\" fill=\"%s\">%s</text>\n", x, y, fillCollor, text);
}

void printarLinha(FILE *arqOut, double x1, double y1, double x2, double y2, char color[]){

    fprintf(arqOut, "\n<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, color);
}

void printarElipse(FILE *arqOut, double xC, double yC, double rX, double rY, char cor[]){

    fprintf(arqOut, "\n<ellipse cx=\"%lf\" cy=\"%lf\" rx=\"%lf\" ry=\"%lf\" fill=\"none\" stroke=\"%s\"/>\n", xC, yC, rX, rY, cor);
}

void printarQuadra(FILE *arqOut, Block block){

    fprintf(arqOut, "\n<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-dasharray=\"0\" stroke-width=\"%s\"/>\n",
    getBlockX(block), getBlockY(block), getBlockW(block), getBlockH(block), getBlockStrokeCollor(block), 
    getBlockFillCollor(block), getBlockSw(block));
}

void printarHidrante(FILE *arqOut, Hydrant hydrant){
    fprintf(arqOut, "\n<circle cx=\"%lf\" cy=\"%lf\" r=\"6\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\"/>\n", getHydrantX(hydrant), 
    getHydrantY(hydrant), getHydrantStrokeCollor(hydrant), getHydrantFillCollor(hydrant), getHydrantSw(hydrant));

    printarTexto(arqOut, getHydrantX(hydrant) - 4.5, getHydrantY(hydrant) + 4, "H", getHydrantStrokeCollor(hydrant));
}

void printarSemaforo(FILE *arqOut, Semaphore semaphore){
    fprintf(arqOut, "\n<rect x=\"%lf\" y=\"%lf\" width=\"10\" height=\"10\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\"/>\n", 
    getSemaphoreX(semaphore) - 5, getSemaphoreY(semaphore) - 5, getSemaphoreStrokeCollor(semaphore), getSemaphoreFillCollor(semaphore), getSemaphoreSw(semaphore));

    printarTexto(arqOut, getSemaphoreX(semaphore) - 3.5, getSemaphoreY(semaphore) + 4, "S", getSemaphoreStrokeCollor(semaphore));
}

void printarRadio(FILE *arqOut, Radio radio){
    fprintf(arqOut, "\n<circle cx=\"%lf\" cy=\"%lf\" r=\"9\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\"/>\n", 
    getRadioX(radio), getRadioY(radio), getRadioStrokeCollor(radio), getRadioFillCollor(radio), getRadioSw(radio));

    printarTexto(arqOut, getRadioX(radio) - 7.5, getRadioY(radio) + 4, "RB", getRadioStrokeCollor(radio));
}