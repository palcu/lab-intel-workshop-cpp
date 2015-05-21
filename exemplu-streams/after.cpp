#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>

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

class Equal {
private:
    string s1;
public:
    Equal(string s2) : s1(s2){}
    bool operator() (FullName fullname) {
        return s1 == fullname.surname;
    }
};

void printNamesForsurname(const string& searchedSurname,
                          const list<FullName>& names) {
    list<FullName>::const_iterator it = find_if(names.begin(),
                                                names.end(),
                                                Equal(searchedSurname));
    
    if (it == names.end()) {
        cout << "No first name found for surname " << searchedSurname << endl;
    } else {
        cout << *it;
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
