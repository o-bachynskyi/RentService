#include <stdio.h>
#include <string.h>

struct UserInfo {
    char username[100];
    char password[100];
    char name[100];
    char email[100];
    int age;
    char number[50];
};

struct Order {

};

struct Property {

};

struct Property availableProperties[100];

struct UserInfo currentUser;

void displayMenu() {
    printf("\n<===== MENU =====>\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. View Account Info\n");
    printf("4. View Order History\n");
    printf("5. View Current Orders\n");
    printf("6. Search Property\n");
    printf("7. Display All Available Properties\n");
    printf("8. Rent Property\n");
    printf("9. Exit\n");
    printf("<================>\n");
}

void createAccount() {
    printf("\nEnter your username: ");
    scanf("%s", currentUser.username);
    printf("Enter your password: ");
    int i = 0;
    while (1) {
        currentUser.password[i] = getch();
        if(currentUser.password[i] == 13) {
            break;
        }
        else if (currentUser.password[i] == 8){
            if (i > 0){
                i--;
                printf("\b \b");
            }
        }
        else {
            printf("*");
        }
        i++;
    }
    currentUser.password[i] = '\0';
    printf("\nEnter your name: ");
    scanf("%s", currentUser.name);
    printf("Enter your email: ");
    scanf("%s", currentUser.email);
    printf("Enter your age: ");
    scanf("%d", currentUser.age);
    printf("Enter your phone number: ");
    scanf("%s", currentUser.number);
    printf("\nAccount created successfully!\n");
}

void login() {

}

void viewAccountInfo() {

}

void viewOrderHistory() {

}

void viewCurrentOrders() {

}

void allAvailableProperties() {

}

void displayAvailableProperties() {

}

void searchProperty() {

}

void viewPropertyDetails(struct Property availableProperties) {

}

void rentProperty() {

}

int main() {
    int choice;
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                viewAccountInfo();
                break;
            case 4:
                viewOrderHistory();
                break;
            case 5:
                viewCurrentOrders();
                break;
            case 6:
                displayAvailableApartments();
                break;
            case 7:
                searchApartment();
                break;
            case 8:
                rentApartment();
                break;
            case 9:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 9);
    return 0;
}
