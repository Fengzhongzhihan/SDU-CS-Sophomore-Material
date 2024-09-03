#include <iostream>

class fuel; // 提前声明类 fuel

class engine {
    friend class fuel; // 将 fuel 类声明为 engine 类的友元
private:
    int powerLevel;
public:
    engine() {
        powerLevel = 0;
    }
    void engine_fn(fuel &f); // 声明一个函数，该函数接受 fuel 类的引用作为参数
};

class fuel {
    friend class engine; // 将 engine 类声明为 fuel 类的友元
private:
    int fuelLevel;
public:
    fuel() {
        fuelLevel = 0;
    }
    void fuel_fn(engine &e); // 声明一个函数，该函数接受 engine 类的引用作为参数
};

// 在 engine 类中定义 engine_fn 函数
void engine::engine_fn(fuel &f) {
    std::cout << "Engine function called with fuel level: " << f.fuelLevel << std::endl;
}

// 在 fuel 类中定义 fuel_fn 函数
void fuel::fuel_fn(engine &e) {
    std::cout << "Fuel function called with power level: " << e.powerLevel << std::endl;
}

int main() {
    engine e;
    fuel f;
    
    e.engine_fn(f); // 调用 engine_fn 函数，传入 fuel 对象 f
    f.fuel_fn(e);   // 调用 fuel_fn 函数，传入 engine 对象 e
    
    return 0;
}
