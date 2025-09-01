#include <iostream>
using namespace std;

class Book {
    int Id;
    bool available;

public:
    Book() {
        Id = 0;
        available = false;
    }

    void setId(int id) {
        this->Id = id;
        available = true; 
    }

    int getId() {
        return Id;
    }

    void setAvailable(bool avail) {
        available = avail;
    }

    bool getAvailable() {
        return available;
    }
};

int main() {
    int noCategories;
    int* noBooks;
    string* CategoryNames;

    cout << "Enter the no of categories: ";
    cin >> noCategories;

    noBooks = new int[noCategories];
    CategoryNames = new string[noCategories];

    for (int i = 0; i < noCategories; i++) {
        cout << "Enter Category Name for Category " << i + 1 << ": ";
        cin >> CategoryNames[i];

        cout << "Enter number of books for this category: ";
        cin >> noBooks[i];
    }

    Book** B = new Book*[noCategories];

    for (int i = 0; i < noCategories; i++) {
        B[i] = new Book[noBooks[i]];
        for (int j = 0; j < noBooks[i]; j++) {
            int id;
            cout << "Enter Book ID for category " << CategoryNames[i] << ", Book " << j + 1 << ": ";
            cin >> id;
            B[i][j].setId(id);
        }
    }

    int searchId;
    cout << "Enter Book ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < noCategories; i++) {
        for (int j = 0; j < noBooks[i]; j++) {
            if (B[i][j].getId() == searchId) {
                found = true;
                cout << "Book found in category: " << CategoryNames[i] << endl;
                cout << "Availability: " << (B[i][j].getAvailable() ? "Yes" : "No") << endl;
                break; 
            }
        }
    }

    if (!found) {
        cout << "Book not found." << endl;
    }

    
    for (int i = 0; i < noCategories; i++) {
        delete[] B[i];
    }
    delete[] B;
    delete[] noBooks;
    delete[] CategoryNames;

    return 0;
}
