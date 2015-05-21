#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <utility>

using namespace std;


istream& operator >> (istream& is, pair<string, string>& fullname) {
    is >> fullname.first >> fullname.second;
    return is;
}

ostream& operator << (ostream& os, pair<string, string>& fullname) {
    os << fullname.first;
    return os;
}


map<string, string> readNamesFromFile(const string& fileName) {
    ifstream fin(fileName);
    
    map<string, string> names;
    pair<string, string> name;
    
    while ( fin >> name ) {
        names.insert(name);
    }
    
    return names;
}


void printNamesForsurname(const string& searchedSurname,
                          const map<string, string>& names) {
    map<string, string>::const_iterator foundSurname = names.find(searchedSurname);
    if (foundSurname != names.end()) {
        cout << foundSurname->second;
    } else {
        cout << "No first name found for surname " << searchedSurname << endl;
    }
}

int main() {
    map<string, string> names = readNamesFromFile("/Users/alex/input.txt");
    
    cout << "Enter surname: ";
    string searchedSurname;
    cin >> searchedSurname;
    printNamesForsurname(searchedSurname, names);
    return 0;
}
