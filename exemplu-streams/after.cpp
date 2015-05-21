#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

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


list<FullName> readNamesFromFile(const string& fileName) {
    ifstream fin(fileName);
    
    list<FullName> names;
    FullName name;
    
    while ( fin >> name ) {
        names.push_back(name);
    }
    
    return names;
}


void printNamesForsurname(const string& searchedSurname,
                          const list<FullName>& names) {
    unsigned foundNamesCount = 0;
    list<FullName>::const_iterator it;
    for (it = names.begin(); it != names.end(); it++) {
        if ((*it).surname == searchedSurname) {
            foundNamesCount++;
            cout << *it;
        }
    }
    if (foundNamesCount == 0) {
        cout << "No first name found for surname " << searchedSurname << endl;
    }
}

int main() {
    list<FullName> names = readNamesFromFile("/Users/alex/input.txt");
    
    cout << "Enter surname: ";
    string searchedSurname;
    cin >> searchedSurname;
    printNamesForsurname(searchedSurname, names);
    return 0;
}
