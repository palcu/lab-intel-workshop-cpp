#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


const unsigned MAX_NAME_LENGTH = 30;


struct FullName {
    char surname[MAX_NAME_LENGTH];
    char firstName[MAX_NAME_LENGTH];
};

istream& operator >> (istream& is, FullName& fullname) {
    is >> fullname.surname >> fullname.firstName;
    return is;
}

ostream& operator << (ostream& os, const FullName& fullname) {
    os << fullname.firstName;
    return os;
}


int readNamesFromFile(const char* fileName, FullName*& names) {
    ifstream fin(fileName);
    int nameCount=0;
    FullName name;
    while ( fin >> name ) {
        nameCount++;
        names = (FullName*)realloc(names, nameCount*sizeof(FullName));
        names[nameCount - 1] = name;
    }
    return nameCount;
}


void printNamesForsurname(int nameCount, char searchedSurname[], FullName* names) {
    unsigned foundNamesCount = 0;
    for (unsigned int i = 0; i < nameCount; i++) {
        if (strcmp(names[i].surname, searchedSurname) == 0) {
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
    char searchedSurname[MAX_NAME_LENGTH];
    cin >> searchedSurname;
    printNamesForsurname(nameCount, searchedSurname, names);
    
    free(names);
    return 0;
}


