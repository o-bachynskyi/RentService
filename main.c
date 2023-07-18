#include <stdio.h>
#include <string.h>
#include <conio.h>

struct UserInfo {
    char username[100];
    char password[100];
    char name[100];
    char email[100];
    int age;
    char number[50];
};

struct Order {
    char type[50];
    char address[100];
    char city[50];
    int rooms, floor, area;
    float price;
    int months;
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

struct Order orders[10];
int totalOrders = 0;

void displayMenu() {
    printf("\n<===== MENU =====>\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. View Account Info\n");
    printf("4. View Order History\n");
    printf("5. View Current Orders\n");
    printf("6. Display All Available Apartments\n");
    printf("7. Search And Rent Apartment\n");
    printf("8. Exit\n");
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
    scanf("%d", &currentUser.age);
    printf("Enter your phone number: ");
    scanf("%s", currentUser.number);
    printf("\nAccount created successfully!\n");
}

void login() {
    char username[100];
    char password[100];
    printf("\nEnter your username: ");
    scanf("%s", username);
    if (strcmp(username, currentUser.username) != 0) {
        printf("Invalid username.\n");
    } 
    else {
        printf("Enter your password: ");
        int i = 0;
        while (1) {
            password[i] = getch();
            if(password[i] == 13) {
                break;
            }
            else if (password[i] == 8){
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
        password[i] = '\0';
        printf("\n");
        if (strcmp(password, currentUser.password) != 0) {
            printf("Invalid password.\n");
        }
        else {
            printf("Logged in as %s.\n", username);
        }
    }
}

void viewAccountInfo(struct UserInfo currentUser) { 
    printf("Username: %s\n", currentUser.username);
    printf("Password: ");
    for (int i = 0; i < strlen(currentUser.password); i++) {
        printf("*");
    }
    printf("\nName: %s\n", currentUser.name);
    printf("E-mail: %s\n", currentUser.email);
    printf("Age: %d\n", currentUser.age);
    printf("Phone number: %s\n", currentUser.number);
    printf("<================>\n");
}

void viewOrderHistory() {
    printf("\n<=== ORDER HISTORY ===>\n\n");
    if (totalOrderHistory == 0) {
        printf("No order history found.\n");
        return;
    }
    for (int i = 0; i < totalOrderHistory; i++) {
        printf("Order %d\n", i + 1);
        printf("Type: %s\n", orderHistory[i].type);
        printf("Address: %s\n", orderHistory[i].address);
        printf("City: %s\n", orderHistory[i].city);
        printf("Floor: %d\n", orderHistory[i].floor);
        printf("Rooms: %d\n", orderHistory[i].rooms);
        printf("Area: %d\n", orderHistory[i].area);
        printf("Price for month: %.2f\n", orderHistory[i].price);
        printf("Months for rent: %d\n", orderHistory[i].months);
        float totalCost = orderHistory[i].price * orderHistory[i].months;
        printf("Total cost for %d months: %.2f\n", orderHistory[i].months, totalCost);
        printf("\n");
    }
}

void changeMonths() {
    printf("Enter order number to change months: ");
    int orderNumber;
    scanf("%d", &orderNumber);
    if (orderNumber >= 1 && orderNumber <= totalOrders) {
        int newMonths;
        printf("Enter new duration of rent: ");
        scanf("%d", &newMonths);
        float totalCost = orders[orderNumber - 1].price * newMonths;
        printf("\nTotal cost for %d months: %.2f\n", newMonths, totalCost);
        char confirm;
        printf("\nDo you want to confirm the change? (y/n): ");
        scanf(" %c", &confirm);
        if (confirm == 'y' || confirm == 'Y') {
            orders[orderNumber - 1].months = newMonths;
            printf("Rent duration changed.\n");
        } 
        else {
            printf("Changes canceled.\n");
        }
    }    
    else {
        printf("Invalid order number.\n");
    }
}

void cancelOrder() {
    printf("Enter order number to cancel: ");
    int cancelOrderNumber;
    scanf("%d", &cancelOrderNumber);
    if (cancelOrderNumber >= 1 && cancelOrderNumber <= totalOrders) {
        orderHistory[totalOrderHistory] = orders[cancelOrderNumber - 1];
        totalOrderHistory++;
        for (int j = cancelOrderNumber - 1; j < totalOrders - 1; j++) {
            orders[j] = orders[j + 1];
        }
        totalOrders--;
        char confirm;
        printf("\nDo you want to confirm the cancellation of the order? (y/n): ");
        scanf(" %c", &confirm);

        if (confirm == 'y' || confirm == 'Y') {
            printf("Order canceled.\n");
        } else {
            orders[totalOrders] = orderHistory[totalOrderHistory - 1];
            totalOrders++;
            totalOrderHistory--;
            printf("Going back to menu...\n");
        }
    } else {
        printf("Invalid order number.\n");
    }
}

void viewCurrentOrders() {
    printf("\n<=== CURRENT ORDERS ===>\n\n");
    if (totalOrders == 0) {
        printf("No current orders found.\n");
        return;
    }
    for (int i = 0; i < totalOrders; i++) {
        printf("Order %d\n", i + 1);
        printf("Type: %s\n", orders[i].type);
        printf("Address: %s\n", orders[i].address);
        printf("City: %s\n", orders[i].city);
        printf("Floor: %d\n", orders[i].floor);
        printf("Rooms: %d\n", orders[i].rooms);
        printf("Area: %d\n", orders[i].area);
        printf("Price for month: %.2f\n", orders[i].price);
        printf("Months for rent: %d\n", orders[i].months);
        float totalCost = orders[i].price * orders[i].months;
        printf("Total cost for %d months: %.2f\n", orders[i].months, totalCost);
        printf("\n");
    }
    printf("<==== ACTIONS ====>\n");
    printf("1. Change months\n");
    printf("2. Cancel order\n");
    printf("3. Back to menu\n");
    printf("<=================>\n");
    printf("\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            changeMonths();
            break;
        case 2:
            cancelOrder();
            break;
        case 3:
            printf("Going back to menu...\n");
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
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

void displayAvailableApartments() {
    printf("\n<=== AVAILABLE APARTMENTS ===>\n\n");
    for (int i = 0; i < sizeof(availableApartments) / sizeof(availableApartments[0]); i++){
        printf("Apartment %d\n", i + 1);
        printf("Type: %s\n", availableApartments[i].type);
        printf("Address: %s\n", availableApartments[i].address);
        printf("City: %s\n", availableApartments[i].city);
        printf("Floor: %d\n", availableApartments[i].floor);
        printf("Rooms: %d\n", availableApartments[i].rooms);
        printf("Area: %d\n", availableApartments[i].area);
        printf("Price for month: %.2f\n", availableApartments[i].price);
        printf("\n");
    }
}

int searchApartments(char searchCity[], char searchType[], struct ApartmentsInfo filteredApartments[]){
    int foundApartments = 0;
    for (int i = 0; i < sizeof(availableApartments) / sizeof(availableApartments[0]); i++) {
        if (strcmp(availableApartments[i].city, searchCity) == 0 && strcmp(availableApartments[i].type, searchType) == 0) {
            memcpy(&filteredApartments[foundApartments], &availableApartments[i], sizeof(struct ApartmentsInfo));
            foundApartments++;
        }
    }
    return foundApartments;
}

void displaySearchResults(struct ApartmentsInfo filteredApartments[], int foundApartments) {
    if (foundApartments == 0) {
        printf("\nNo apartments found matching the search criteria.\n");
        return;
    }
    for (int i = 0; i < foundApartments; i++) {
        printf("\nApartment %d\n", i + 1);
        printf("Type: %s\n", filteredApartments[i].type);
        printf("Address: %s\n", filteredApartments[i].address);
        printf("City: %s\n", filteredApartments[i].city);
        printf("Floor: %d\n", filteredApartments[i].floor);
        printf("Rooms: %d\n", filteredApartments[i].rooms);
        printf("Area: %d\n", filteredApartments[i].area);
        printf("Price for month: %.2f\n", filteredApartments[i].price);
    }
}

void rentApartment(struct ApartmentsInfo filteredApartments[], int foundApartments) {
    int selectedApartment;
    printf("\nEnter the number of the apartment you want to rent (0 to go back): ");
    scanf("%d", &selectedApartment);
    if (selectedApartment < 0 || selectedApartment > foundApartments) {
        printf("Invalid selection.\n");
        return;
    } else if (selectedApartment == 0) {
        printf("Going back to menu.\n");
        return;
    }
    int months;
    printf("Enter the number of months for rent: ");
    scanf("%d", &months);
    float totalCost = filteredApartments[selectedApartment - 1].price * months;
    printf("Total cost for %d months: %.2f\n", months, totalCost);
    char confirm;
    printf("\nDo you want to confirm the rental? (y/n): ");
    scanf(" %c", &confirm);
    
    if (confirm == 'y' || confirm == 'Y') {
        struct Order newOrder;
        strcpy(newOrder.type, filteredApartments[selectedApartment - 1].type);
        strcpy(newOrder.address, filteredApartments[selectedApartment - 1].address);
        strcpy(newOrder.city, filteredApartments[selectedApartment - 1].city);
        newOrder.floor = filteredApartments[selectedApartment - 1].floor;
        newOrder.rooms = filteredApartments[selectedApartment - 1].rooms;
        newOrder.area = filteredApartments[selectedApartment - 1].area;
        newOrder.price = filteredApartments[selectedApartment - 1].price;
        newOrder.months = months;
        orders[totalOrders] = newOrder;
        totalOrders++;
        printf("\nRental confirmed.\n");
    } else {
        printf("\nRental canceled.\n");
    }
}

void searchAndRentApartment() {
    printf("\n<=== SEARCH APARTMENT ===>\n");
    printf("\n<=== CITY ===>\n");
    printf("1. Kyiv\n");
    printf("2. Lviv\n");
    printf("3. Odesa\n");
    printf("4. Kharkiv\n");
    printf("<============>\n");
    printf("\nEnter your choice: ");
    int cityChoice;
    scanf("%d", &cityChoice);

    char searchCity[50];
    switch (cityChoice) {
        case 1:
            strcpy(searchCity, "Kyiv");
            break;
        case 2:
            strcpy(searchCity, "Lviv");
            break;
        case 3:
            strcpy(searchCity, "Odesa");
            break;
        case 4:
            strcpy(searchCity, "Kharkiv");
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    printf("\n<=== TYPE ===>\n");
    printf("1. Flat\n");
    printf("2. House\n");
    printf("<============>\n");
    printf("\nEnter your choice: ");
    int typeChoice;
    scanf("%d", &typeChoice);

    char searchType[50];
    switch (typeChoice) {
        case 1:
            strcpy(searchType, "Flat");
            break;
        case 2:
            strcpy(searchType, "House");
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    struct ApartmentsInfo filteredApartments[10];
    
    int foundApartments = searchApartments(searchCity, searchType, filteredApartments);
    
    displaySearchResults(filteredApartments, foundApartments);

    if (foundApartments > 0) {
        rentApartment(filteredApartments, foundApartments);
    }
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
                viewAccountInfo(currentUser);
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
                searchAndRentApartment();
                break;
            case 8:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);
    return 0;
}
