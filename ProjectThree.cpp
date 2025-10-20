#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include "Product.h"
using namespace std;

// Prototypes
void searchProduct(const map<string, Product>& t_list);
void printList(const map<string, Product>& t_list);
void printChart(const map<string, Product>& t_list);
void displayMenu();


int main()
{
    map<string, Product> productList; // map = { {name, Product(name)}, ...} as in {"Apples" , {"Apples", 1}} on the first read of Apples
    string productName;

    fstream inFile("CS210_Project_Three_Input_File.txt");
    ofstream outFile("frequency.dat");

    if (!inFile.is_open()) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    if (!outFile.is_open()) {
        cout << "Error creating or to writing the output file." << endl;
        return 1;
    }

    // Reads the input file and determines frequency
    while (getline(inFile, productName)) {
        if (productList.find(productName) != productList.end()) {
            // If an existing product name is read, add 1 to the quantity of that product
            productList[productName].increaseQuantity();
        }
        else {
            // Add the new product to the map
            productList[productName] = Product(productName);
        }
    }
    inFile.close();

    // Creates a backup of the frequency data
    for (auto const& pair : productList) {
        outFile << pair.first << " " << pair.second.getProductQuantity() << endl;
    }
    outFile.close();


    // Menu loop
    bool exitProgram = false;
    while (!exitProgram) {
        displayMenu();

        int menuOption;
        while (!(cin >> menuOption)) {
            cout << "Invalid input. Enter a number 1-4." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            displayMenu();
        }

        switch (menuOption) {
            case 1:
                searchProduct(productList);
                break;
            case 2:
                printList(productList);
                break;
            case 3:
                printChart(productList);
                break;
            case 4:
                cout << "Closing program . . ." << endl;
                exitProgram = true;
                break;
            default:
                cout << menuOption << " is not a valid option. Enter 1-4" << endl;
                break;
        }
    }

 return 0;
}


// Functions


void displayMenu() {
    cout << "\tEnter your choice (1-4)\t" << endl;
    cout << "1. Item Quantity Search" << endl;
    cout << "2. List of Items and Quantity" << endl;
    cout << "3. Chart of Items and Quantity" << endl;
    cout << "4. Quit the Program" << endl;
}

// Uses the user's name input as a key and searches the map to print the matching name and frequency
void searchProduct(const map<string, Product>& t_list) {
    string inputName;
    cout << "Enter the item name: " << endl;
    cin >> inputName;

    if (cin.fail() || inputName.empty()) {
        cout << "Invalid search." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        return;
    }

    // Searches the map for an element that has a key equal to inputName. The iterator points to the element if a match is found, otherwise 
    auto iterator = t_list.find(inputName);

    if (iterator != t_list.end()) { // Match found
        cout << iterator->first << " " << iterator->second.getProductQuantity() << endl;
    }
    else { // No match found
        cout << inputName << " was not found." << endl;
    }

    cout << endl;
}

// Prints a list of each product name and frequency (numerical) in the map
void printList(const map<string, Product>& t_list) {
    cout << "------ List of Products and Frequency ------" << endl;

    // Iterates through each element pair in the Product map
    for (auto const& pair : t_list) {
        cout << pair.first << " " << pair.second.getProductQuantity() << endl;
    }
    cout << endl;
}

// Prints a histogram of each product name and frequency (represented with *) in the map
void printChart(const map<string, Product>& t_list) {
    cout << "------ Histogram of Products and Frequency ------" << endl;

    // Iterates through each element pair in the Product map
    for (auto const& pair : t_list) {
        cout << left << setfill(' ') << setw(13) << pair.first << " | " << right << setfill('*') << setw(pair.second.getProductQuantity()) << "" << endl;
    }
    cout << endl;
}
