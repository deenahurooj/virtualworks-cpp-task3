#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void bookRoom() {
    int roomNumber;
    string name, phone;
    int days;
    double bill;

    cout << "\n===== ROOM BOOKING =====" << endl;

    cout << "Enter room number: ";
    cin >> roomNumber;

    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter phone number: ";
    getline(cin, phone);

    cout << "Enter number of days: ";
    cin >> days;

    bill = days * 1000;

    // Store booking details in a file
    ofstream file("hotel_data.txt", ios::app);

    if (file.is_open()) {
        file << roomNumber << endl;
        file << name << endl;
        file << phone << endl;
        file << days << endl;
        file << bill << endl;
        file.close();

        cout << "\nRoom booked successfully!" << endl;
        cout << "Total Bill = Rs. " << bill << endl;
    } else {
        cout << "Error: Unable to open file." << endl;
    }
}

void viewBookings() {
    int roomNumber, days;
    string name, phone;
    double bill;

    cout << "\n===== BOOKING DETAILS =====" << endl;

    ifstream file("hotel_data.txt");

    if (!file.is_open()) {
        cout << "No booking records found." << endl;
        return;
    }

    bool found = false;

    while (file >> roomNumber) {
        file.ignore();
        getline(file, name);
        getline(file, phone);
        file >> days;
        file >> bill;

        found = true;

        cout << "\nRoom Number : " << roomNumber << endl;
        cout << "Customer    : " << name << endl;
        cout << "Phone       : " << phone << endl;
        cout << "Days        : " << days << endl;
        cout << "Bill        : Rs. " << bill << endl;
        cout << "-----------------------------" << endl;
    }

    file.close();

    if (!found) {
        cout << "No booking records found." << endl;
    }
}

void searchBooking() {
    int searchRoom;
    int roomNumber, days;
    string name, phone;
    double bill;
    bool found = false;

    cout << "\nEnter room number to search: ";
    cin >> searchRoom;

    ifstream file("hotel_data.txt");

    while (file >> roomNumber) {
        file.ignore();
        getline(file, name);
        getline(file, phone);
        file >> days;
        file >> bill;

        if (roomNumber == searchRoom) {
            cout << "\n===== CUSTOMER DETAILS =====" << endl;
            cout << "Room Number : " << roomNumber << endl;
            cout << "Customer    : " << name << endl;
            cout << "Phone       : " << phone << endl;
            cout << "Days        : " << days << endl;
            cout << "Total Bill  : Rs. " << bill << endl;

            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "No booking found for this room." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n================================" << endl;
        cout << "     HOTEL MANAGEMENT SYSTEM" << endl;
        cout << "================================" << endl;
        cout << "1. Book a Room" << endl;
        cout << "2. View All Bookings" << endl;
        cout << "3. Search Booking" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookRoom();
                break;

            case 2:
                viewBookings();
                break;

            case 3:
                searchBooking();
                break;

            case 4:
                cout << "Thank you for using the Hotel Management System!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}