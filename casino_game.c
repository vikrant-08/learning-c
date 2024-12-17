#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    char name[50];
    int amt, betAmt, guess, dice,n=60;
    char choice;

    srand(time(0)); // Seed the random number generator
    printf("\n");

     for (int i = 0; i < n; i++) {
        printf("%c", '_');
    }
    printf("\n\n\t\tCASINO GAME\n\n");
     for (int i = 0; i < n; i++) {
        printf("%c", '_');
    }
    printf("\n");

    printf("Enter Your Name: ");
    fgets(name, sizeof(name), stdin);
    
    printf("Enter Deposit Amount to Play: $");
    scanf("%d", &amt);

    // Main game loop
    while (1) {
    
    printf("Rules of the Game:\n");
    printf("1. Bet on a number between 1 and 10.\n");
    printf("2. If you guess correctly, you win 10 times your bet.\n");
    printf("3. If you guess incorrectly, you lose your bet amount.\n");
        printf("\nYour current balance is $%d\n", amt);

        // Betting amount input
        while (1) {
            printf("%s, enter money to bet: $", name);
            scanf("%d", &betAmt);
            if (betAmt > amt) {
                printf("Your betting amount exceeds your current balance\nRe-enter data\n");
            } else {
                break; // Valid betting amount
            }
        }

        // Guess input
        while (1) {
            printf("Guess your number to bet (1-10): ");
            scanf("%d", &guess);
            if (guess < 1 || guess > 10) {
                printf("Invalid number! Please choose between 1 and 10.\n");
            } else {
                break; // Valid guess
            }
        }

        dice = rand() % 10 + 1; // Generate winning number
        printf("Winning number is: %d\n", dice);

        if (guess == dice) {
            amt += betAmt * 10; // Win
            printf("Congratulations! You won $%d\n", betAmt * 10);
        } else {
            amt -= betAmt; // Lose
            printf("Sorry! You lost $%d\n", betAmt);
        }

        if (amt <= 0) {
            printf("You have no money left to play!\n");
            break;
        }

        printf("Do you want to play again? (y/n): ");
        getchar(); 
        scanf("%c", &choice);

        if (choice != 'y' && choice != 'Y') {
            break; // Exit the game loop if the player doesn't want to play again
        }
    }

    printf("Thank you for playing! Your final balance is $%d\n", amt);
    return 0;
}