#include <stdio.h>
#include <stdbool.h>

#define TOTAL_ROOMS 10

bool rooms[TOTAL_ROOMS] = {false}; // Array to represent room status (false = vacant, true = occupied)

// Function to display room status
void displayRooms() {
    printf("Room Status:\n");
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        printf("Room %d: %s\n", i + 1, rooms[i] ? "Occupied" : "Vacant");
    }
}

// Function to book a room
void bookRoom() {
    int roomNumber;
    printf("Enter room number to book (1-%d): ", TOTAL_ROOMS);
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > TOTAL_ROOMS) {
        printf("Invalid room number! Please choose a room between 1 and %d.\n", TOTAL_ROOMS);
    } else if (rooms[roomNumber - 1]) {
        printf("Room %d is already occupied.\n", roomNumber);
    } else {
        rooms[roomNumber - 1] = true;
        printf("Room %d has been booked successfully.\n", roomNumber);
    }
}

// Function to checkout a room
void checkoutRoom() {
    int roomNumber;
    printf("Enter room number to checkout (1-%d): ", TOTAL_ROOMS);
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > TOTAL_ROOMS) {
        printf("Invalid room number! Please choose a room between 1 and %d.\n", TOTAL_ROOMS);
    } else if (!rooms[roomNumber - 1]) {
        printf("Room %d is already vacant.\n", roomNumber);
    } else {
        rooms[roomNumber - 1] = false;
        printf("Room %d has been checked out successfully.\n", roomNumber);
    }
}

int main() {
    int choice;

    printf("Welcome to Hotel Management System\n");
    do {
        printf("\nMenu:\n");
        printf("1. Display Room Status\n");
        printf("2. Book a Room\n");
        printf("3. Checkout a Room\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                checkoutRoom();
                break;
            case 4:
                printf("Thank you for using the Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
