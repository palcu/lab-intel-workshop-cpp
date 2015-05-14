#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


typedef vector<int> Container;

template <typename T>
void incrementAll(T& c) {
    for(typename T::iterator it = c.begin(); it!=c.end(); it++) {
        (*it)++;
    }
}

void printAll(const Container& c) {
    for(Container::const_iterator it = c.begin(); it!=c.end(); it++) {
        cout << *it << endl;
    }
}

int main() {
    Container c;
    c.push_back(3);
    c.push_back(6);
    c.push_back(10);
    
    incrementAll(c);
    printAll(c);
    
    return 0;
}

