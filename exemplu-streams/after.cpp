#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct FullName {
    string surname;
    string firstName;
};

istream& operator >> (istream& is, FullName& fullname) {
    is >> fullname.firstName >> fullname.surname;
    return is;
}

ostream& operator << (ostream& os, const FullName& fullname) {
    os << fullname.firstName;
    return os;
}


int readNamesFromFile(const string& fileName, FullName*& names) {
    ifstream fin(fileName);
    unsigned nameCount=0;
    FullName name;
    while ( fin >> name ) {
        nameCount++;
        FullName* newNames = new FullName[nameCount];
        for (int i=0; i<nameCount - 1; i++) {
            newNames[i] = names[i];
        }
        delete []names;
        names = newNames;
        names[nameCount - 1] = name;
    }
    return nameCount;
}


void printNamesForsurname(int nameCount, const string& searchedSurname, FullName* names) {
    unsigned foundNamesCount = 0;
    for (unsigned int i = 0; i < nameCount; i++) {
        if (names[i].surname == searchedSurname) {
            foundNamesCount++;
            cout << names[i];
        }
    }
    if (foundNamesCount == 0) {
        cout << "No first name found for surname " << searchedSurname << endl;
    }
}

int main() {
    FullName* names = NULL;
    int nameCount = readNamesFromFile("/Users/alex/input.txt", names);
    
    cout << "Enter surname: ";
    string searchedSurname;
    cin >> searchedSurname;
    printNamesForsurname(nameCount, searchedSurname, names);
    
    delete []names;
    return 0;
}


