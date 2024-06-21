#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 7
#define NAME_LENGTH 50

struct Booking {
    int roomNumber;
    char guestName[NAME_LENGTH];
    int isOccupied;
};

struct Booking bookings[MAX_ROOMS];

// Initialize all rooms as available
void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        bookings[i].roomNumber = i + 1;
        strcpy(bookings[i].guestName, "Available");
        bookings[i].isOccupied = 0;
    }
}

// Display available rooms
void displayAvailableRooms() {
    printf("Available Rooms:\n");
    printf("Room Number\tGuest Name\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (!bookings[i].isOccupied) {
            printf("%d\t\t%s\n", bookings[i].roomNumber, bookings[i].guestName);
        }
    }
}

// Book a room
void bookRoom(int roomNumber, char guestName[]) {
    bookings[roomNumber - 1].isOccupied = 1;
    strcpy(bookings[roomNumber - 1].guestName, guestName);
    printf("Room %d has been booked for %s.\n", roomNumber, guestName);
}

int main() {
    int choice;
    int roomNumber;
    char guestName[NAME_LENGTH];

    initializeRooms();

    do {
        printf("\n -Hotel Booking System-\n");
        printf("\n 1. Display available rooms\n");
        printf(" 2. Book a room\n");
        printf(" 3. Exit\n");
        printf(" Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAvailableRooms();
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                printf("Enter guest name: ");
                scanf("%s", guestName);
                bookRoom(roomNumber, guestName);
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
