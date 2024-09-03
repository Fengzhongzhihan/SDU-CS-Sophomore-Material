#include <iostream>
using namespace std;

class SimpleCircle {
public:
    // Constructors
    SimpleCircle();
    SimpleCircle(int);
    SimpleCircle(const SimpleCircle&);
    // Destructor
    ~SimpleCircle();
    
    // Member functions
    void setRadius(int);
    int getRadius() const;
private:
    int *itsRadius;
};

// Constructor definitions
SimpleCircle::SimpleCircle() {
    itsRadius = new int(5);
}

SimpleCircle::SimpleCircle(int radius) {
    itsRadius = new int(radius);
}

SimpleCircle::SimpleCircle(const SimpleCircle& rhs) {
    int val = *rhs.itsRadius;
    itsRadius = new int(val);
}

// Destructor definition
SimpleCircle::~SimpleCircle() {
    delete itsRadius;
}

// Member function definitions
void SimpleCircle::setRadius(int radius) {
    *itsRadius = radius;
}

int SimpleCircle::getRadius() const {
    return *itsRadius;
}

int main() {
    SimpleCircle circleOne, circleTwo(9);
    
    cout << "CircleOne: " << circleOne.getRadius() << endl;
    cout << "CircleTwo: " << circleTwo.getRadius() << endl;
    
    return 0;
}
