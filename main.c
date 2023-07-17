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
};

struct Property availableProperties[100];

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
