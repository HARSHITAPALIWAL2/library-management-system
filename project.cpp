#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Book {
    int book_no;
    string book_name;
    string author;
    string publisher;
    double cost_per_book;
    int available_stock;
    int qty_purchased;
};

vector<Book> stock; 

void addStock();
void viewStock();
void updateStock();
void sellBook();
void viewSales();

int main() {
    int choice;

    cout << "Welcome to Library Management System!\n";

    while (true) {
        cout << "\n1. Add Stock\n";
        cout << "2. View Stock\n";
        cout << "3. Update Stock\n";
        cout << "4. Sell Book\n";
        cout << "5. View Sales\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                viewStock();
                break;
            case 3:
                updateStock();
                break;
            case 4:
                sellBook();
                break;
            case 5:
                viewSales();
                break;
            case 6:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void addStock() {
    int book_no;
    string book_name, author, publisher;
    double cost_per_book;
    int available_stock;

    cout << "Enter book number: ";
    cin >> book_no;
    cin.ignore();
    cout << "Enter book name: ";
    getline(cin, book_name);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter publisher: ";
    getline(cin, publisher);
    cout << "Enter cost per book: ";
    cin >> cost_per_book;
    cout << "Enter available stock: ";
    cin >> available_stock;

    stock.push_back({book_no, book_name, author, publisher, cost_per_book, available_stock, 0});
    cout << "Book added successfully!\n";
}

void viewStock() {
    cout << left << setw(10) << "Book No"
         << setw(20) << "Book Name"
         << setw(20) << "Author"
         << setw(20) << "Publisher"
         << setw(10) << "Cost"
         << setw(10) << "Stock" << endl;
    for (auto& book : stock) {
        cout << left << setw(10) << book.book_no
             << setw(20) << book.book_name
             << setw(20) << book.author
             << setw(20) << book.publisher
             << setw(10) << book.cost_per_book
             << setw(10) << book.available_stock << endl;
    }
}

void updateStock() {
    int book_no, new_stock;
    cout << "Enter book number to update: ";
    cin >> book_no;
    cout << "Enter new stock quantity: ";
    cin >> new_stock;

    bool found = false;
    for (auto& book : stock) {
        if (book.book_no == book_no) {
            book.available_stock += new_stock;
            cout << "Stock updated successfully!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found.\n";
    }
}

void sellBook() {
    int book_no;
    cout << "Enter book number to sell: ";
    cin >> book_no;

    bool found = false;
    for (auto& book : stock) {
        if (book.book_no == book_no && book.available_stock > 0) {
            book.available_stock--;
            book.qty_purchased++;
            cout << "Book sold successfully!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Stock unavailable.\n";
    }
}

void viewSales() {
    cout << left << setw(10) << "Book No"
         << setw(20) << "Book Name"
         << setw(10) << "Sold Qty" << endl;
    for (auto& book : stock) {
        if (book.qty_purchased > 0) {
            cout << left << setw(10) << book.book_no
                 << setw(20) << book.book_name
                 << setw(10) << book.qty_purchased << endl;
        }
    }
}