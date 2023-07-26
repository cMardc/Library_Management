
// * Staring Of "book.h" Header File

#pragma once

//Libraries Needed : 
#include <string>

//Standard Namespace 
using std::string, std::to_string;




//Make First Letter Uppercase, Others Lowercase, (Include That Every Character After Spaces Also Would Be Uppercase)
string capitalize(string input) {
    string output = "";
    if(input.empty()) {
        return "";
    }
    output += toupper(input[0]);
    for(size_t i = 1; i < input.size(); i++) {
        if(input[i - 1] == ' ') {
            output += toupper(input[i]);
        }
        else {
            output += tolower(input[i]);
        }
    }
    return output;
}



class book
{

private:

    // * All Data About Book
    string title = "Unknown", author = "Unknown", genre = "Unknown", ISBN = "Unknown", releaseDate = "Unknown", publisher = "UNKNOWN";
    bool available = NULL;
    int numberOfPages = 0, bookID = -1, countOfRatings = 0;
    float rating = 0;
    float allRatings = 0;

public:



    // * INIT Function For Book Class
    book(string titleINP, string authorINP, string genreINP, string ISBNinp, string releaseDateINP, string publisherINP, bool availableINP, int numOfPages, int id) {
        //Make All Strings Formatted In Correct Way
        titleINP    = capitalize(titleINP);
        authorINP   = capitalize(authorINP);
        genreINP    = capitalize(genreINP);
        ISBNinp     = capitalize(ISBNinp);
        releaseDate = capitalize(releaseDateINP);
        publisher   = capitalize(publisher);

        //Attach Inputs To Object's Private Data
        this->title = titleINP;
        this->author = authorINP;
        this->genre = genreINP;
        this->ISBN = ISBNinp;
        this->releaseDate = releaseDateINP;
        this->publisher = publisherINP;
        this->available = availableINP;
        this->numberOfPages = numOfPages;
        this->bookID = id;
    }

    

    // * Get Functions For Private Data : 

    bool isAvailable() {
        return available;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    string getGenre() {
        return genre;
    }

    string getISBN() {
        return ISBN;
    }

    string getReleaseDate() {
        return releaseDate;
    }

    string getPublisher() {
        return publisher;
    }

    int getNumberOfPages() {
        return numberOfPages;
    }

    float getRatingValue() {
        return rating;
    }

    int getID() {
        return this->bookID;
    }

    // * Function To Rate A Book
    void rate(float ratingINP) {
        allRatings += ratingINP;
        countOfRatings += 1;
        rating = allRatings / countOfRatings;
    }

    // * Setting Availability For Book
    bool setAvailability(bool availability) {
        this->available = availability;
        return this->available;
    }

    // * Get Info 
    string info() {

        /*
        FORMAT : 
            ========================================
            Title: $(title)
            Author: $(author)
            Genre: $(genre)
            ========================================
            Publisher: $(publisher)
            ISBN: $(isbn)
            Available: $(available)
            ID: $(id)
            Pages: $(numberOfPages)
            ========================================
            Rating: $(rating)
            Total Rating Count: $(Count Of Rating)
            ========================================
        */


        string infoStr = "========================================\nTitle: " + this->title + "\nAuthor: " + this->author + "\nGenre: " + genre;
        infoStr += "\n========================================\nPublisher: " + this->publisher + "\nISBN: " + this->ISBN + "\nAvailable: ";
        this->available ? infoStr += "True\n" : infoStr += "False\n";
        infoStr += "ID: " + to_string(this->bookID) + "\nPages: " + to_string(this->numberOfPages);
        infoStr += "\n========================================\nRating: " + to_string(this->rating) + "\nTotal Rating Count: " + to_string(this->countOfRatings);
        infoStr += "\n========================================\n";

        return infoStr;
    }

    // * Check If User Can Borrow The Book Or Not
    bool borrowFN() {
        if(this->available) {
            this->available = false;
            return true;
        }
        return false;
    }

    // * Check If User Must Return The Book Or Not
    bool returnFN() {
        if(!this->available) {
            this->available = true;
            return true;
        }
        return false;
    }


};


