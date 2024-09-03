#include <iostream>

class Cat {
public:
    Cat(int age) : itsAge(age) { numOfCats++; }
    virtual ~Cat() { numOfCats--; }
    virtual int GetAge() { return itsAge; }
    virtual void SetAge(int age) { itsAge = age; }
    static int GetnumOfCats() { return numOfCats; }
    static void TelepathicFunction() {
        std::cout << "There are " << numOfCats << " cats alive!\n";
    }

private:
    int itsAge;
    static int numOfCats;
};

int Cat::numOfCats = 0;

void TelepathicFunction();

int main() {
    const int MaxCats = 5;
    Cat *CatHouse[MaxCats];
    int i;
    for (i = 0; i < MaxCats; i++) {
        CatHouse[i] = new Cat(i);
        TelepathicFunction();
    }

    for (i = 0; i < MaxCats; i++) {
        delete CatHouse[i];
        TelepathicFunction();
    }

    return 0;
}

