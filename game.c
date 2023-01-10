#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    char * name;
    int maxHealt;
    int health;

    int maxEnergy;
    int energy;

    int shield;
}PLAYER;

char * getName(int *);
void setUpNames(PLAYER *, PLAYER *, int *);

int main(void){
    int turn = 0;
    PLAYER p1, p2;

    setUpNames(&p1, &p2, &turn);

    printf("Jmeno 1: %s\nJmeno 2: %s\n", p1.name ,p2.name);

    return 0;
}

//Function to get players name from console
char * getName(int * turn){
    char * name;
    name = (char *)malloc(21);

    if (*turn)
    {
        printf("Zadej jmeno druheho hrace (max. 20 znaku):\n");
    }
    else
    {
        printf("Zadej jmeno prvniho hrace (max. 20 znaku):\n");
    }

    fgets(name, 20, stdin);

    return name;
}
//Function to write player names to memory
void setUpNames(PLAYER * p1, PLAYER * p2, int * turn ){
    p1->name = getName(turn);
    * turn = 1;

    p2->name = getName(turn);
    * turn = 2;
}
