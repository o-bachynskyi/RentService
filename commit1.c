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
