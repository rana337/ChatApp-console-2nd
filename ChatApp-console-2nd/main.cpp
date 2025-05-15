#include <iostream>
#include <limits>
#include <algorithm>
#include "ChatApplication.h"
using namespace std;
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pressEnterToContinue() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void displayMainMenu() {
    clearScreen();
    cout << "\nChat App\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

void displayUserMenu(const User* user) {
    clearScreen();
    cout << "\nWelcome, " << user->getFirstName() << " " << user->getLastName() << "!\n";
    cout << "1. View Contacts\n";
    cout << "2. Add Contact\n";
    cout << "3. Remove Contact\n";
    cout << "4. View Chat Rooms\n";
    cout << "5. Open Chat Room\n";
    cout << "6. Start New Chat\n";
    cout << "7. Create Group Chat\n";
    cout << "8. View Stories\n";
    cout << "9. Create Story\n";
    cout << "10. View Profile\n";
    cout << "11. Update Profile\n";
    cout << "12. Logout\n";
    cout << "Choose an option: ";
}


int main() {
    int choice;

    while (true) {
        displayMainMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 3) break;

        if (choice == 1) {
            string mobile, password, firstName, lastName;

            cout << "Enter mobile number: ";
            getline(cin, mobile);

            cout << "Enter password: ";
            getline(cin, password);

            cout << "Enter first name: ";
            getline(cin, firstName);

            cout << "Enter last name: ";
            getline(cin, lastName);

            if (app.registerUser(mobile, password, firstName, lastName)) {
                cout << "Registration successful!\n";
            }
            else {
                cout << "Registration failed. Mobile number may already exist.\n";
            }
            pressEnterToContinue();
        }
        else if (choice == 2) {
            string mobile, password;

            cout << "Enter mobile number: ";
            getline(cin, mobile);

            cout << "Enter password: ";
            getline(cin, password);

            if (app.login(mobile, password)) {
                const User* user = app.getCurrentUser();

                while (user) {
                    displayUserMenu(user);
                    cin >> choice;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    switch (choice) {
                    case 1: ; break;
                    case 2: ; break;
                    case 3: ; break;
                    case 4: ; break;
                    case 5: ; break;
                    case 6: ; break;
                    case 7: ; break;
                    case 8: ; break;
                    case 9: ; break;
                    case 10:; break;
                    case 11:; break;
                    case 12: app.logout(); user = nullptr; break;
                    default: cout << "Invalid option.\n"; pressEnterToContinue();
                    }
                }
            }
            else {
                cout << "Login failed. Invalid mobile or password.\n";
                pressEnterToContinue();
            }
        }
    }

    return 0;
}