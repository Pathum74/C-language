
#include <stdio.h>
#include <string.h>

//Maximum number of each food item
#define MAX_ITEMS 10
#define NAME_LENGTH 50

struct MenuItem {
    char name[NAME_LENGTH];
    float price;
};

struct MenuItem menu[MAX_ITEMS];

void initializeMenu() {
    strcpy(menu[0].name, "\nBurger");
    menu[0].price = 5.99;
    strcpy(menu[1].name, "Pizza");
    menu[1].price = 8.99;
    strcpy(menu[2].name, "Fries");
    menu[2].price = 2.49;
    strcpy(menu[3].name, "Popcorn");
    menu[3].price = 2.20;
    strcpy(menu[4].name, "Donuts");
    menu[4].price = 2.40;
    strcpy(menu[5].name, "Subway");
    menu[5].price = 5.70;
    // Add more items as needed
}

void displayMenu() {
    printf("Menu:\n");
    printf("Item\t\tPrice\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strlen(menu[i].name) > 0) {
            printf("%s\t\t$%.2f\n", menu[i].name, menu[i].price);
        }
    }
}

float placeOrder(char itemName[], int quantity) {
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(menu[i].name, itemName) == 0) {
            float total = menu[i].price * quantity;
            return total;
        }
    }
    return -1; // Item not found
}

int main() {
    int choice, quantity;
    char itemName[NAME_LENGTH];
    float totalPrice;

    initializeMenu();

    do {
        printf("\n-Online Food Ordering System-\n");
        printf("\n1. Display Menu\n");
        printf("2. Place Order\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                totalPrice = placeOrder(itemName, quantity);
                if (totalPrice == -1) {
                    printf("Item not found.\n");
                } else {
                    printf("Total price: $%.2f\n", totalPrice);
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
