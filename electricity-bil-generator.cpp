#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ElectricityBill {
public:
    int customerID;
    string name;
    int units;
    double totalBill;

    void input() {
        cout << "\nEnter Customer ID: ";
        cin >> customerID;

        cin.ignore();
        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Units Consumed: ";
        cin >> units;

        calculateBill();
    }

    void calculateBill() {
        if (units <= 100)
            totalBill = units * 1.5;
        else if (units <= 200)
            totalBill = (100 * 1.5) + (units - 100) * 2.5;
        else if (units <= 300)
            totalBill = (100 * 1.5) + (100 * 2.5) + (units - 200) * 4.0;
        else
            totalBill = (100 * 1.5) + (100 * 2.5) + (100 * 4.0) + (units - 300) * 6.0;
    }

    void display() {
        cout << "\nCustomer ID: " << customerID;
        cout << "\nName: " << name;
        cout << "\nUnits Consumed: " << units;
        cout << "\nTotal Bill: ₹" << totalBill;
        cout << "\n-----------------------------";
    }
};

void generateBill() {
    ElectricityBill e;
    ofstream file("bills.txt", ios::app);

    e.input();

    file << e.customerID << "," << e.name << ","
         << e.units << "," << e.totalBill << endl;

    file.close();

    cout << "\nBill Generated Successfully!\n";
    e.display();
}

void viewBills() {
    ifstream file("bills.txt");
    string line;

    cout << "\n===== All Bills =====\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n====== Electricity Bill Generator ======\n";
        cout << "1. Generate Bill\n";
        cout << "2. View All Bills\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            generateBill();
            break;
        case 2:
            viewBills();
            break;
        case 3:
            cout << "Exiting Program...\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
