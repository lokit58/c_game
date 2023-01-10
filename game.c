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

void classKnight (PLAYER * );
void classHeavyKnight (PLAYER * );
void classArcher (PLAYER * );

/*
printf("\033[0;31m"); //Set the text to the color red
printf("Hello\n"); //Display Hello in red
printf("\033[0m"); //Resets the text to default color

system("cls");
*/

int main(void){

    int turn = 0;
    PLAYER p1, p2;
    //printf("Class selected: %d\n",classSelector());
    
    setUpNames(&p1, &p2, &turn);
    //printf("Jmeno 1: %s\nJmeno 2: %s\n", p1.name ,p2.name);
    setUpClasses(&p1,&p2);
    printf("dmg1: %d dmg2: %d",p1.attack,p2.attack);

    free(p1.name);
    free(p2.name);
    
    return 0;
}

//Function to get players name from console (max 20)
char * getName(int * turn){
    char * name;
    name = (char *)malloc(21);

    if (*turn)
    {
        printf("\nWrite name of second player (max. 20 chars):\n");
    }
    else
    {
        printf("Write name of first player (max. 20 chars):\n");
    }

    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0;

    return name;
}

//Function to write player names to memory
void setUpNames(PLAYER * p1, PLAYER * p2, int * turn ){
    p1->name = getName(turn);
    * turn = 1;

    p2->name = getName(turn);
    * turn = 2;
}
//List of all playable classes
//TODO: Colors, more classes?
void showClassList(){
    printf("Knight (maybe hollow):\n");
    printf("Jack of all trades, medium attack, health, defence and energy regeneration\n\n");

    printf("Archer:\n");
    printf("Strong attacks exchange for lower healt and defence, good energy regeneration\n\n");

    printf("Heavy knight:\n");
    printf("Weak attacks, but huge ammount of health and defence, low energy regeneration\n\n");

    printf("For more info look into the source code xd\n\n");
}

//Function to return class number 
//TODO: Input controll
int classFromConsole(){
    int c = 0;
    printf("Pick one of the classes listed below, by typing respective number starting with 1:\n\n");
    showClassList();
    /*
    do
    {
        if (scanf("%d",&c) != 1)
        {
            printf("Wrong intput, try again!\n");
        }
        
    } while (c < 1 || c > 3);
    */
    scanf("%d",&c);
    return   c;
}

//Assign correct class to number
void setClass(PLAYER * p){
    int c = classFromConsole();

    switch (c)
    {
    case 1:
        classKnight(p);
        break;
    case 2:
        classArcher(p);
        break;
    case 3:
        classHeavyKnight(p);
        break;
    default:
        break;
    }
}

//Setup for knight
void classKnight (PLAYER * p){
    p->maxHealt = 200;
    p->health = 200;
    
    p->maxEnergy = 200;
    p->energy = 200;
    p->energyRegen = 20;

    p->shield = 100;
    p->blockAddition = 50;

    p->attack = 50;
}

//Setup for heavyknight
void classHeavyKnight (PLAYER * p){
    p->maxHealt = 500;
    p->health = 500;
    
    p->maxEnergy = 150;
    p->energy = 150;
    p->energyRegen = 10;

    p->shield = 200;
    p->blockAddition = 70;

    p->attack = 30;
}

//Setup for archer
void classArcher (PLAYER * p){
    p->maxHealt = 100;
    p->health = 100;
    
    p->maxEnergy = 300;
    p->energy = 300;
    p->energyRegen = 70;

    p->shield = 150;
    p->blockAddition = 30;

    p->attack = 100;
}

//Function to assign class to player info
void setUpClasses(PLAYER * p1, PLAYER *p2){
    printf("\n%s is picking:\n",p1->name);
    setClass(p1);

    printf("\n%s is picking:\n",p2->name);
    setClass(p2);
}