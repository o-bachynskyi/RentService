#include <stdio.h>
#include <string.h>

// Оголошення структур даних

struct User {
    // Дані користувача
};

struct Order {
    // Дані замовлення
};

struct Property {
    // Дані житла
    char type[50];
    char address[100];
    char city[50];
    int rooms, floor, area;
    float price;
};

struct Property availableProperties[10];
// Кількість доступних житла

// Оголошення функцій

void displayMenu() {
    // Користувацьке меню
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
    // Створення акаунта
}

void login() {
    // Вхід у систему
}

void viewAccountInfo() {
    // Виведення інформації про акаунт
}

void viewOrderHistory() {
    // Історія замовлень
}

void viewCurrentOrders() {
    // Поточні замовлення
}

void allAvailableProperties() {
    // Список всіх доступних для оренди житла
    strcpy(availableProperties[0].type, "Apartment");
    strcpy(availableProperties[0].address, "4 Lipska st.");
    strcpy(availableProperties[0].city, "Kyiv");
    availableProperties[0].rooms = 2;
    availableProperties[0].area = 55;
    availableProperties[0].price = 14000.0;
    availableProperties[0].floor = 6;
    
    strcpy(availableProperties[1].type, "House");
    strcpy(availableProperties[1].address, "13 Jukovskogo st.");
    strcpy(availableProperties[1].city, "Lviv");
    availableProperties[1].rooms = 3;
    availableProperties[1].area = 137;
    availableProperties[1].price = 97350.0;
    
    strcpy(availableProperties[2].type, "House");
    strcpy(availableProperties[2].address, "25 Antonovycha st.");
    strcpy(availableProperties[2].city, "Lviv");
    availableProperties[2].rooms = 2;
    availableProperties[2].area = 96;
    availableProperties[2].price = 79450.0;

    strcpy(availableProperties[3].type, "Apartment");
    strcpy(availableProperties[3].address, "7 Rozumovska st.");
    strcpy(availableProperties[3].city, "Odesa");
    availableProperties[3].rooms = 3;
    availableProperties[3].area = 70;
    availableProperties[3].price = 25500.0;
    availableProperties[3].floor = 3;
    
    strcpy(availableProperties[4].type, "Apartment");
    strcpy(availableProperties[4].address, "10 Shyroka st.");
    strcpy(availableProperties[4].city, "Kyiv");
    availableProperties[4].rooms = 1;
    availableProperties[4].area = 40;
    availableProperties[4].price = 7500.0;
    availableProperties[4].floor = 8;
    
    strcpy(availableProperties[5].type, "House");
    strcpy(availableProperties[5].address, "26 Kovalska st.");
    strcpy(availableProperties[5].city, "Kharkiv");
    availableProperties[5].rooms = 5;
    availableProperties[5].area = 148;
    availableProperties[5].price = 110500.0;
    
    strcpy(availableProperties[6].type, "Apartment");
    strcpy(availableProperties[6].address, "17 Yasna st.");
    strcpy(availableProperties[6].city, "Lviv");
    availableProperties[6].rooms = 2;
    availableProperties[6].area = 62;
    availableProperties[6].price = 13500.0;
    availableProperties[6].floor = 1;
    
    strcpy(availableProperties[7].type, "House");
    strcpy(availableProperties[7].address, "26 Dmytrivska st.");
    strcpy(availableProperties[7].city, "Kharkiv");
    availableProperties[7].rooms = 3;
    availableProperties[7].area = 108;
    availableProperties[7].price = 88500.0;

    strcpy(availableProperties[8].type, "House");
    strcpy(availableProperties[8].address, "44 Narodna st.");
    strcpy(availableProperties[8].city, "Kyiv");
    availableProperties[8].rooms = 3;
    availableProperties[8].area = 98;
    availableProperties[8].price = 86500.0;
    
    strcpy(availableProperties[9].type, "Apartment");
    strcpy(availableProperties[9].address, "32 Zelena st.");
    strcpy(availableProperties[9].city, "Odesa");
    availableProperties[9].rooms = 2;
    availableProperties[9].area = 59;
    availableProperties[9].price = 12350.0;
    availableProperties[9].floor = 5;
}

void displayAvailableProperties() {
    // Вивести доступні житла
}

void searchProperty() {
    // Пошук житла за певними характеристиками
}

void viewPropertyDetails(struct Property availableProperties) {
    // Виведення деталей про житло
}

void rentProperty() {
    // Оренда житла
}

// Головна функція

int main() {
    
    return 0;
}
