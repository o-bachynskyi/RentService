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

struct ApartmentsInfo {
    char type[50];
    char address[100];
    char city[50];
    int rooms, floor, area;
    float price;
};

struct ApartmentsInfo availableApartments[10];

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

setAvailableApartments(struct ApartmentsInfo *availableApartments, char *type, char *address, char *city, int rooms, int area, float price, int floor) {
    strcpy(availableApartments->type, type);
    strcpy(availableApartments->address, address);
    strcpy(availableApartments->city, city);
    availableApartments->rooms = rooms;
    availableApartments->area = area;
    availableApartments->price = price;
    availableApartments->floor = floor;
}

void allAvailableApartments() {
    int i = 0;
    setAvailableApartments(&availableApartments[i], "Flat", "4 Lipska st.", "Kyiv", 2, 55, 14000.0, 6);
    setAvailableApartments(&availableApartments[++i], "House", "13 Jukovskogo st.", "Lviv", 3, 137, 97350.0, 0);
    setAvailableApartments(&availableApartments[++i], "House", "25 Antonovycha st.", "Lviv", 2, 96, 79450.0, 0);
    setAvailableApartments(&availableApartments[++i], "Flat", "7 Rozumovska st.", "Odesa", 3, 70, 25500.0, 3);
    setAvailableApartments(&availableApartments[++i], "Flat", "10 Shyroka st.", "Kyiv", 1, 40, 7500.0, 8);
    setAvailableApartments(&availableApartments[++i], "House", "26 Kovalska st.", "Kharkiv", 5, 148, 110500.0, 0);
    setAvailableApartments(&availableApartments[++i], "Flat", "17 Yasna st.", "Lviv", 2, 62, 13500.0, 1);
    setAvailableApartments(&availableApartments[++i], "House", "26 Dmytrivska st.", "Kharkiv", 3, 108, 88500.0, 0);
    setAvailableApartments(&availableApartments[++i], "House", "44 Narodna st.", "Kyiv", 3, 98, 86500.0, 0);
    setAvailableApartments(&availableApartments[++i], "Flat", "32 Zelena st.", "Lviv", 2, 59, 12350.0, 5);
}

void displayAvailableProperties() {
    // Вивести доступні житла
    printf("\n<=== AVAILABLE PROPERTIES ===>\n\n");
    for (int i = 0; i < sizeof(availableProperties) / sizeof(availableProperties[0]); i++){
        printf("Property %d\n", i + 1);
        printf("Type: %s\n", availableProperties[i].type);
        printf("Address: %s\n", availableProperties[i].address);
        printf("City: %s\n", availableProperties[i].city);
        printf("Floor: %d\n", availableProperties[i].floor);
        printf("Rooms: %d\n", availableProperties[i].rooms);
        printf("Area: %d\n", availableProperties[i].area);
        printf("Price for month: %.2f\n", availableProperties[i].price);
        printf("\n");
    }
}

void searchProperty() {

}

void viewPropertyDetails(struct Property availableProperties) {

}

void rentProperty() {

}

int main() {
    int choice;
    allAvailableApartments();
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
