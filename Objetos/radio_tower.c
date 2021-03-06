#include "radio_tower.h"

typedef struct stRadioTower{
    char id[32], strokeColor[24], fillColor[24], sw[12];
    double x, y;    
}*RadioTowerImp;

RadioTower createRadioTower(char id[], double x, double y, char strokeColor[], char fillColor[], char sw[]){
    RadioTowerImp rTower = (RadioTowerImp) malloc(sizeof(struct stRadioTower));

    strcpy(rTower->id, id);
    rTower->x = x;
    rTower->y = y;
    strcpy(rTower->strokeColor, strokeColor);
    strcpy(rTower->fillColor, fillColor);
    strcpy(rTower->sw, sw);

    return rTower;
}

char *getRadioTowerId(RadioTower r){
    RadioTowerImp rTower = (RadioTowerImp) r;

    return rTower->id;
}

double getRadioTowerX(RadioTower r){
    RadioTowerImp rTower = (RadioTowerImp) r;

    return rTower->x;
}

double getRadioTowerY(RadioTower r){
    RadioTowerImp rTower = (RadioTowerImp) r;

    return rTower->y;
}

char *getRadioTowerStrokeColor(RadioTower r){
    RadioTowerImp rTower = (RadioTowerImp) r;

    return rTower->strokeColor;
}

char *getRadioTowerFillColor(RadioTower r){
    RadioTowerImp rTower = (RadioTowerImp) r;

    return rTower->fillColor;
}

char *getRadioTowerSw(RadioTower r){
    RadioTowerImp rTower = (RadioTowerImp) r;

    return rTower->sw;
}

void setRadioTowerX(RadioTower r, double x){
    RadioTowerImp rTower = (RadioTowerImp) r;

    rTower->x = x;
}

void setRadioTowerY(RadioTower r, double y){
    RadioTowerImp rTower = (RadioTowerImp) r;

    rTower->y = y;
}

void freeRadioTower(RadioTower r){
    RadioTowerImp rTower = (RadioTowerImp) r;

    free(rTower);
}