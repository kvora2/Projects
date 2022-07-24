#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, guess, numof_guesses = 1;
    srand(time(0));
    num = rand() % 100 + 1;

    do {
        printf("Guess the number between 1 to 100: ");
        scanf("%d", &guess);
        if (guess > num) {
            printf("Try a bit lower number please!\n");
        }
        else if (guess < num) {
            printf("Try a bit higher number please!\n");
        }
        else {
            printf("Woww! you guessed the perfect number. It took %d attempts\n", numof_guesses);
        }
        numof_guesses++;
    }while (guess != num);

    return 0;
}