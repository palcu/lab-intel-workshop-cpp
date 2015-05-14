#include <iostream>

using namespace std;

template <typename T>
class Pair {
private:
    T first;
    T second;
public:
    Pair(const T& theFirst, const T& theSecond)
        :first(theFirst), second(theSecond) {
        
    }
    const T& getFirst() const {
        return first;
    }
    const T& getSecond() const {
        return second;
    }
};

int main(int argc, const char * argv[]) {
    Pair<int> p(5,7);
    
    cout << p.getFirst() << " " << p.getSecond();
    return 0;
}

