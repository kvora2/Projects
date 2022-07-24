// This program is game which you will be playing with computer. You have to enter one of the given options and computer with select it's option and the result of who won will be displayed on screen. 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int snak_water_gun(char you, char comp)
{
    int num;
    if (you == comp)
    {
        num = 0;
    }
    else if ((you == 's' && comp == 'w') || (you == 'w' && comp == 'g') || (you == 'w' && comp == 'g'))
    {
        num = 1;
    }
    return num;
}

int main()
{
    char you, comp;
    srand(time(0));
    int num = rand() % 100 + 1;
    int select = 1;

    if (num < 33)
    {
        comp = 's';
    }
    else if (num < 66)
    {
        comp = 'g';
    }
    else
    {
        comp = 'w';
    }
    printf("Enter 's' for snake, 'w' for water, and 'g' for gun: ");
    scanf("%c", &you);
    int result = snak_water_gun(you, comp);
    if (result == 0)
    {
        printf("Game Drawn\n");
    }
    else if (result == 1)
    {
        printf("You win\n");
    }
    else
    {
        printf("You lose\n");
    }
    printf("You choose %c and computer choose %c\n", you, comp);
}
