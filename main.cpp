#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book
{
public:
    int bookID;
    string title;
    string author;
    bool issued;

    void addBook()
    {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;

        ofstream file("library.txt", ios::app);

        file << bookID << endl;
        file << title << endl;
        file << author << endl;
        file << issued << endl;

        file.close();

        cout << "\nBook Added Successfully!\n";
    }
};

void displayBooks()
{
    ifstream file("library.txt");

    int id;
    string title, author;
    bool issued;

    cout << "\n===== BOOK LIST =====\n";

    while (file >> id)
    {
        file.ignore();
        getline(file, title);
        getline(file, author);
        file >> issued;

        cout << "\nBook ID : " << id;
        cout << "\nTitle   : " << title;
        cout << "\nAuthor  : " << author;

        if (issued)
            cout << "\nStatus  : Issued\n";
        else
            cout << "\nStatus  : Available\n";
    }

    file.close();
}

void searchByTitle()
{
    ifstream file("library.txt");

    int id;
    string title, author, searchTitle;
    bool issued;
    bool found = false;

    cin.ignore();

    cout << "Enter Title to Search: ";
    getline(cin, searchTitle);

    while (file >> id)
    {
        file.ignore();
        getline(file, title);
        getline(file, author);
        file >> issued;

        if (title == searchTitle)
        {
            cout << "\nBook Found!\n";
            cout << "Book ID : " << id << endl;
            cout << "Author  : " << author << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nBook Not Found!\n";
    }

    file.close();
}

void searchByAuthor()
{
    ifstream file("library.txt");

    int id;
    string title, author, searchAuthor;
    bool issued;
    bool found = false;

    cin.ignore();

    cout << "Enter Author Name to Search: ";
    getline(cin, searchAuthor);

    while (file >> id)
    {
        file.ignore();
        getline(file, title);
        getline(file, author);
        file >> issued;

        if (author == searchAuthor)
        {
            cout << "\nBook Found!\n";
            cout << "Book ID : " << id << endl;
            cout << "Title   : " << title << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nAuthor Not Found!\n";
    }

    file.close();
}

void issueBook()
{
    cout << "\nBook Issued Successfully!\n";
    cout << "(Demo Version)\n";
}

void returnBook()
{
    cout << "\nBook Returned Successfully!\n";
    cout << "(Demo Version)\n";
}

int main()
{
    Book b;
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";

        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search By Title\n";
        cout << "4. Search By Author\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchByTitle();
            break;

        case 4:
            searchByAuthor();
            break;

        case 5:
            issueBook();
            break;

        case 6:
            returnBook();
            break;

        case 7:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}
