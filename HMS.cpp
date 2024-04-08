#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hotel Room Class
class Room {
public:
    int roomNumber;
    string roomType;

    Room(int number, string type) : roomNumber(number), roomType(type) {}
};

// Hotel Management System Class
class HotelManagementSystem {
private:
    vector<Room> rooms;

public:
    // Function to add a room to the system
    void addRoom(int roomNumber, string roomType) {
        Room newRoom(roomNumber, roomType);
        rooms.push_back(newRoom);
        cout << "Room added successfully!" << endl;
    }

    // Function to remove a room from the system
    void removeRoom(int roomNumber) {
        for (auto it = rooms.begin(); it != rooms.end(); ++it) {
            if (it->roomNumber == roomNumber) {
                rooms.erase(it);
                cout << "Room removed successfully!" << endl;
                return;
            }
        }
        cout << "Room not found!" << endl;
    }

    // Function to display the menu
    void displayMenu() {
        cout << "Welcome to the Hotel Management System" << endl;
        cout << "1. Add a room" << endl;
        cout << "2. Remove a room" << endl;
        cout << "3. Exit" << endl;
    }

    // Function to handle user input
    void handleInput(int choice) {
        switch (choice) {
            case 1: {
                int roomNumber;
                string roomType;
                cout << "Enter room number: ";
                cin >> roomNumber;
                cout << "Enter room type: ";
                cin >> roomType;
                addRoom(roomNumber, roomType);
                break;
            }
            case 2: {
                int roomNumber;
                cout << "Enter room number to remove: ";
                cin >> roomNumber;
                removeRoom(roomNumber);
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
};

int main() {
    HotelManagementSystem hms;
    int choice;

    do {
        hms.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        hms.handleInput(choice);
    } while (choice != 3);

    return 0;
}