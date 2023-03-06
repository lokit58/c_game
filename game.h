#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char * name;

    int maxHealt;
    int health;

    int maxEnergy;
    int energy;
    int energyRegen;

    int shield;
    int blockAddition;

    int attack;
}PLAYER;

char * getName(int *);
void setUpNames(PLAYER *, PLAYER *, int *);
void setClass(PLAYER *);
void showClassList(void);
int classFromConsole(void);
void setUpClasses(PLAYER *, PLAYER *);

int combat (PLAYER *, PLAYER *, int *);
void action(PLAYER *, PLAYER *, int *);
void printHUD(PLAYER *, PLAYER *, int *);
int actionSelection(void);
void printActionSelection(void);
int chechkEnergy(PLAYER *, int);
void pressEnter(void);


void classKnight (PLAYER * );
void classHeavyKnight (PLAYER * );
void classArcher (PLAYER * );