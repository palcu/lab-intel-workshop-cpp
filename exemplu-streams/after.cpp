#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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


vector<FullName> readNamesFromFile(const string& fileName) {
    ifstream fin(fileName);

    vector<FullName> names;
    FullName name;
    
    while ( fin >> name ) {
        names.push_back(name);
    }
    
    return names;
}


void printNamesForsurname(const string& searchedSurname, vector<FullName>& names) {
    unsigned foundNamesCount = 0;
    for (unsigned int i = 0; i < names.size(); i++) {
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
    vector<FullName> names = readNamesFromFile("/Users/alex/input.txt");
    
    cout << "Enter surname: ";
    string searchedSurname;
    cin >> searchedSurname;
    printNamesForsurname(searchedSurname, names);
    return 0;
}

