
//Starting Of "main.cpp" : 

//Libraries And Headers Needed
#include <iostream>
#include <vector>
#include <iomanip>
#include "book.h"

//Using Standard Namespace
using namespace std;




//Remove All Spaces From String And Make It Lowercase
string lowercaseNoSpace(string input) {
    string output = "";
    for(size_t i = 0; i < input.size(); i++) {
        if(input[i] != ' ') {
            output += tolower(input[i]);
        }
    }
    return output;
}



// * Main Function To Run On Starting
int main(int argc, char** argv) {


    // * Create Vector (Dynamic Array) Of Books
    vector<book> books;

    //Help String
    string help = "Commands : add, delete, view, show, borrow, return, exit, help\n";


    cout << "Type \"help\" To Get Help\n";

    // * Main Loop Here
    while(true) {
        string command;
        cout << "$>";
        getline(cin, command);
        command = lowercaseNoSpace(command);
        // * Gives Help About Commands
        if(command == "help") {
            cout << help;
        }
        //* Adds Books
        else if(command == "add") {
            //Get All Atributes As Input
            string title, author, genre, publisher, isbn, releaseDate;
            int pages, id;
            cout << "Title: ";
            getline(cin, title);
            cout << "Author: ";
            getline(cin, author);
            cout << "Genre : ";
            getline(cin, genre);
            cout << "Publisher: ";
            getline(cin, publisher);
            cout << "ID: ";
            cin >> id;
            cout << "ISBN : ";
            cin >> isbn;
            cout << "Release Date: ";
            cin >> releaseDate;
            cout << "Page Count: ";
            cin >> pages;
            book newBook(title, author, genre, isbn, releaseDate, publisher, true, pages, id);
            books.push_back(newBook);
        }
        // * Deletes Books
        else if(command == "delete") {
            int id;
            cout << "ID: ";
            cin >> id;
            for(size_t i = 0; i < books.size(); i++) {
                if(id == books[i].getID()) {
                    books.erase(books.begin() + i);
                }
            }
        }
        // * Views Books With A Keyword (Search Filter)
        else if (command == "view") {
            // ? Format : 
            // * TITLE | GENRE | AUTHOR | ID | Publisher | AVAILABLE | ISBN
            string keyWord;
            cout << "KeyWord : ";
            cin >> keyWord;
            cout << "==========================================================\n";
            cout << setw(30) << left << "TITLE" << " | ";
            cout << setw(15) << left << "GENRE" << " | ";
            cout << setw(25) << left << "AUTHOR" << " | ";
            cout << setw(5) << left << "ID" << " | ";
            cout << setw(15) << left << "PUBLISHER" << " | ";
            cout << setw(10) << left << "AVAILABLE" << " | ";
            cout << "ISBN\n";
            for (size_t i = 0; i < books.size(); i++) {
                if (lowercaseNoSpace(books[i].getTitle()).find(lowercaseNoSpace(keyWord)) != std::string::npos) {
                    cout << setw(30) << left << books[i].getTitle() << " | ";
                    cout << setw(15) << left << books[i].getGenre() << " | ";
                    cout << setw(25) << left << books[i].getAuthor() << " | ";
                    cout << setw(5) << left << books[i].getID() << " | ";
                    cout << setw(15) << left << books[i].getPublisher() << " | ";
                    cout << setw(10) << left << (books[i].isAvailable() ? "True" : "False") << " | ";
                    cout << books[i].getISBN() << "\n";
                }
            }
        }
        // Shows All Books
        else if (command == "show") {
            // ? Format : 
            // * TITLE | GENRE | AUTHOR | ID | Publisher | AVAILABLE | ISBN
            cout << "==========================================================\n";
            cout << setw(30) << left << "TITLE" << " | ";
            cout << setw(15) << left << "GENRE" << " | ";
            cout << setw(25) << left << "AUTHOR" << " | ";
            cout << setw(5) << left << "ID" << " | ";
            cout << setw(15) << left << "PUBLISHER" << " | ";
            cout << setw(10) << left << "AVAILABLE" << " | ";
            cout << "ISBN\n";
            for (size_t i = 0; i < books.size(); i++) {
                cout << setw(30) << left << books[i].getTitle() << " | ";
                cout << setw(15) << left << books[i].getGenre() << " | ";
                cout << setw(25) << left << books[i].getAuthor() << " | ";
                cout << setw(5) << left << books[i].getID() << " | ";
                cout << setw(15) << left << books[i].getPublisher() << " | ";
                cout << setw(10) << left << (books[i].isAvailable() ? "True" : "False") << " | ";
                cout << books[i].getISBN() << "\n";
            }
        }
        else if(command == "borrow") {
            int id;
            cout << "ID: ";
            cin >> id;
            for(size_t i = 0; i < books.size(); i++) {
                if(books[i].getID() == id) {
                    if(books[i].borrowFN()) {
                        cout << "Succesfuly Borrowed Book: " + books[i].getTitle() + "\n";
                    }
                    else {
                        cout << "Failed To Borrow Book: " + books[i].getTitle() + "\n";
                    }
                }
            }
        }
        else if(command == "return") {
            int id;
            cout << "ID: ";
            cin >> id;
            for(size_t i = 0; i < books.size(); i++) {
                if(books[i].getID() == id) {
                    if(books[i].returnFN()) {
                        cout << "Succesfuly Returned Book: " + books[i].getTitle() + "\n";
                    }
                    else {
                        cout << "Failed To Return Book: " + books[i].getTitle() + "\n";
                    }
                }
            }
        }
        // * Exits The App
        else if(command == "exit") {
            break;
        }
            // * If Command Is Wrong
        else if(!command.empty()) {
            cout << "\aUnknown Command : " << command << '\n';
        }
    }


    return 0;
}


/*
 ? RESULTS : 



    * 1. (+) Book Class: Create a class to represent a book with attributes like title, author, genre, ISBN, availability status, etc.

    * 2. (+) Book Database: Implement a data structure (e.g., array, vector, or linked list) to store the collection of books in the library.

    * 3. (+) Add and Update Books: Provide functionality for librarians to add new books to the library and update the information of existing books.

    * 4. (+) Search Books: Allow users to search for books by title, author, or genre. Display the search results showing available books and their details.

    * 5. (+) Borrowing and Returning Books: Enable library members to borrow books and return them. Keep track of the borrowed books and their due dates.

    ! 6. (|-| Need A Database / Isn't Important In Offline) Membership Management: Implement a system to manage library members, including their information (e.g., name, contact details, member ID).



*/
