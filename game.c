#include"game.h"

/*
printf("\033[0;31m"); //Set the text to the color red
printf("Hello\n"); //Display Hello in red
printf("\033[0m"); //Resets the text to default color

system("cls");
*/

int main(void){

    int turn = 0;
    PLAYER p1, p2;
    setUpNames(&p1, &p2, &turn);
    setUpClasses(&p1,&p2);

    //printf("Class selected: %d\n",classSelector());
    //printf("Jmeno 1: %s\nJmeno 2: %s\n", p1.name ,p2.name);
    //printf("dmg1: %d dmg2: %d",p1.attack,p2.attack);
    //turn = 1;

    //printHUD(&p1,&p2,&turn);

    //printActionSelection();

    int win = combat(&p1, &p2, &turn);

    if (win == 0)
    {
        printf("%s wins the game\n",p1.name);
    }
    else if (win == 2)
    {
        printf("%s wins the game\n",p1.name);
    }
    else
        printf("Draw\n");   
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
        printf("Write name of second player (max. 20 chars):\n");
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
    system("cls");
    p1->name = getName(turn);
    * turn = 1;

    system("cls");
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
    return  c;
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
    system("cls");
    printf("%s is picking:\n\n",p1->name);
    setClass(p1);

    system("cls");
    printf("%s is picking:\n\n",p2->name);
    setClass(p2);
}

int combat (PLAYER * p1, PLAYER * p2, int * turn){
    do
    {
        printHUD(p1,p2,turn);
        action(p1, p2, turn);
        *turn = 1;

        pressEnter();
        
        printHUD(p1,p2,turn);
        action(p2, p1, turn);
        *turn = 0;

        pressEnter();

    } while (p1->health > 0 && p2->health > 0);
    printHUD(p1,p2,turn);
    if (p1->health <= 0 && p2->health > 0)
        return 1;
    if (p1->health > 0 && p2->health <= 0)
        return 0;   
    return 2;
}

void action(PLAYER * attacker, PLAYER * defender, int * turn){
    int c;
    tryagain:
    c = actionSelection();

    switch (c)
    {
    case 1:
        if (chechkEnergy(attacker, 30))
        {
            printf("%s deals %d dmg to %s\n",attacker->name, attacker->attack, defender->name);
            if (defender->shield > 0)
            {
                if(attacker->attack <= defender->shield)
                    defender->shield -= attacker->attack;
                else
                {
                    int tmp = attacker->attack - defender->shield;
                    defender->shield = 0;
                    defender->health -= tmp;
                } 
            }
            else
                defender->health  -= attacker->attack;  

            attacker->energy -= 30;
        }
        else
        {
            printf("Not enought energy, try again:");
            goto tryagain;
        }
        break;
    case 2:
        if (chechkEnergy(attacker, 20))
        {
            printf("%s shields for %d points\n",attacker->name, attacker->blockAddition);
            attacker->shield += attacker->blockAddition;
        }
        else
        {
            printf("Not enought energy, try again:");
            goto tryagain;
        }
        break;
    case 3:
        printf("%s rests for 10 armor and 50 energy \n",attacker->name);
        attacker->shield += 10;
        attacker->energy += 50;
        break;
    
    default:
        break;
    }
}

//Function to print player stats
void printHUD(PLAYER * p1, PLAYER * p2, int * turn){
    system("cls");
    if (*turn)
        printf("It's %s's move\n\n", p2->name);
    else
        printf("It's %s's move\n\n",p1->name);
    //Names
    printf("%s:\t\t\t\t\t\t%s:\n",p1->name,p2->name);
    //Health
    printf("Health: %d/%d\t\t\t\t\tHealth: %d/%d\n",p1->health, p1->maxHealt, p2->health, p2->maxHealt); 
    //Shield
    printf("Shield: %d + %d (per block action)\t\tShield: %d + %d (per block action)\n", p1->shield, p1->blockAddition, p2->shield, p2->blockAddition);
    //Energy
    printf("Energy: %d/%d + %d (per turn)\t\t\tEnergy: %d/%d + %d (per turn)\n",p1->energy, p1->maxEnergy, p1->energyRegen, p2->energy, p2->maxEnergy, p2->energyRegen);
    //Attack
    printf("Attack damage: %d\t\t\t\tAttack damage: %d\n",p1->attack, p2->attack);
}

//Function that returns number of selected action
//TODO: Input controll
int actionSelection(){
    int c;
    printActionSelection();
    printf("Enter here: ");
    scanf("%d",&c);
    return c;
}

//Function that prints selection menu
void printActionSelection(){
    printf("\nEnter respective number to select action:\n");
    printf("1.Attack\t\t2.Defend\t\t3.Rest\n");
}

int chechkEnergy(PLAYER * p, int energyReq){
    return (p->energy >= energyReq) ? 1 : 0;
}

void pressEnter(){
    printf("Press <Enter>  to countinue\n");
    while (getchar() != '\n');
    while (getchar() != '\n');
}