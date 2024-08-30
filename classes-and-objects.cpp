#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Declaration of Widths
const int WIDTH1 = 20;
const int WIDTH2 = 25;
const int WIDTH3 = 10;

struct entry {
    string title;
    string author;
    int year;
};

// Function to do case insensitive string comparison
bool strCompare (string& str1, string& str2)
{
    if (str1.length() != str2.length())
        return false;

    for (int i = 0; str1[i] != '\0'; ++i) {
        if (toupper(str1[i]) != toupper(str2[i]))
            return false;
    }

    return true;
}

class Library {
    private:
        vector<entry> libEntries;
        entry entryHelper;

    public:
        void addEntry() {
            cin.ignore();
            cout << "\nEnter title: ";
            getline(cin, entryHelper.title);

            cout << "\nEnter author: ";
            getline(cin, entryHelper.author);

            cout << "\nEnter year: ";
            cin >> entryHelper.year;

            libEntries.push_back(entryHelper);

            cout << "\n\nBook added successfully!" << endl;
        }

        void displayEntry() {
            if (libEntries.size() == 0)
            {
                cout << "\nThere are no entries in the library yet!" << endl;
                return;
            }

            cout << "\nBook List:" << endl;
            cout << left << setw(WIDTH1) << "\nTitle" 
            << setw(WIDTH2) << "Author" 
            << setw(WIDTH3) << "Year" << endl;

            for (int i = 0; i < libEntries.size(); i++)
            {
                cout << left << setw(WIDTH1) << libEntries[i].title 
                << setw(WIDTH2) << libEntries[i].author 
                << setw(WIDTH3) << libEntries[i].year << endl;
            }
        }

        void searchEntry() {
            if (libEntries.size() == 0)
            {
                cout << "\nThere are no entries in the library yet!" << endl;
                return;
            }

            cout << "\nEnter a book title to search: ";
            cin.ignore();
            getline(cin, entryHelper.title);

            for (int i = 0; i < libEntries.size(); i++) {
                if (strCompare(libEntries[i].title,entryHelper.title)) //(libEntries[i].title == entryHelper.title)
                {
                    cout << "\nBook found!" << endl;
                    cout << "Title: " << libEntries[i].title << endl;
                    cout << "Author: " << libEntries[i].author << endl;
                    cout << "Year: " << libEntries[i].year << endl;
                    return;
                }
            }

            cout << "\nBook not found!" << endl;
        }
};

int menu()
{
    int choice;

    cout << "<==================>";
    cout << "\nMenu" << endl;
    cout << "\n1 — Add Book";
    cout << "\n2 - Display Books";
    cout << "\n3 - Search Books";
    cout << "\n4 - Exit" << endl;
        
    cout << "\nType the number to where you want to go: ";
    cin >> choice;
    cout << "<==================>" << endl;

    return choice;
}

int main(void)
{
    Library newLib;

    char choice;
    bool continueProg = true;

    while (continueProg)
    {
        cout << endl;
        switch(menu())
        {
            case 1:
                newLib.addEntry();
                break;

            case 2:
                newLib.displayEntry();
                break;

            case 3:
                newLib.searchEntry();
                break;

            case 4:
                do {
                cout << "\nAre you sure you want to exit? [Y/N]: ";
                cin >> choice;

                if (toupper(choice) == 'Y'){
                    continueProg = false;
                }
                } while (toupper(choice) != 'Y' && toupper(choice) != 'N');
                
                break;
            
            default:
                cout << "\nInvalid Input! Please try again!" << endl;
        }
    }

    return 0;
}