#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void playGame();
int getComputerChoice();
void determineWinner(int playerChoice, int computerChoice);

int main() {
    int choice;

    do {
        printf("Let's Play Rock-Paper-Scissors Game!\n");
        printf("Enter your choice:\n");
        printf("Rock    - 1\n");
        printf("Paper   - 2\n");
        printf("Scissors- 3\n");
        printf("Exit    - 4\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Thank you for playing!\n");
            printf("Come again!\n");
            break;
        }

        if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please choose again.\n");
            continue;
        }

        playGame(choice);
    } while (choice != 4);

    return 0;
}

void playGame(int playerChoice) {
    int computerChoice = getComputerChoice();

    printf("You chose: %s\n", (playerChoice == 1) ? "Rock" : (playerChoice == 2) ? "Paper" : "Scissors");
    printf("Computer chose: %s\n", (computerChoice == 1) ? "Rock" : (computerChoice == 2) ? "Paper" : "Scissors");

    determineWinner(playerChoice, computerChoice);
}

int getComputerChoice() {
    srand(time(NULL));
    return rand() % 3 + 1;
}

void determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((playerChoice == 1 && computerChoice == 3) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}
