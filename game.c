#include<stdio.h>
#include<stdlib.h>

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
}PLAYER;

char * getName(int *);
void setUpNames(PLAYER *, PLAYER *, int *);
void setClass(PLAYER *);
void showClassList(void);
int classSelector(void);

/*
printf("\033[0;31m"); //Set the text to the color red
printf("Hello\n"); //Display Hello in red
printf("\033[0m"); //Resets the text to default color

system("cls");
*/

int main(void){

    int turn = 0;
    PLAYER p1, p2;
    printf("Class selected: %d\n",classSelector());
    
    /*
    setUpNames(&p1, &p2, &turn);
    printf("Jmeno 1: %s\nJmeno 2: %s\n", p1.name ,p2.name);
    free(p1.name);
    free(p2.name);
    */
    return 0;
}

//Function to get players name from console (max 20)
char * getName(int * turn){
    char * name;
    name = (char *)malloc(21);

    if (*turn)
    {
        printf("Write name of second player (max. 20 chars):\n");
    }
    else
    {
        printf("Write name of first player (max. 20 chars):\n");
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
//List of all playable classes
//TODO: Colors, more classes?
void showClassList(){
    printf("Knight (maybe hollow):\n");
    printf("Jack of all trades, medium attack, health, defence and energy regeneration\n\n");

    printf("Archer:\n");
    printf("Strong attacks exchange for lower healt and defence, good energy regeneration\n\n");

    printf("Heavy knight\n");
    printf("Weak attacks, but huge ammount of health and defence, low energy regeneration\n\n");
}
//Function to return class number 
int classSelector(){
    int c = 0;
    printf("Pick one of the classes listed below, by typing respective number starting with 1:\n\n");
    showClassList();

    do
    {
        if (scanf("%d",&c) != 1)
        {
            printf("Wrong intput, try again!\n");
        }
        
    } while (c < 1 || c > 3);
    return   c;
}

void setClass(PLAYER * p){
    int c = classSelector();

    switch (c)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    default:
        break;
    }
}