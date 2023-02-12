#include <iostream>

class A;
class M;
class F;

class A {
    public:
    int num;
    M * classM;

    A() {
        std::cout << "A::A()" << std::endl;
    }

    ~A() {
        std::cout << "A::~A()" << std::endl;
    }

    A(const A&) {
        std::cout << "A::A(const A&)" << std::endl;
    }

    A(int num) {
        this->num = num;
        std::cout << "Opération d'affectation" << std::endl;
    }
};

class M {
    public:
    int num;

    M() {
        std::cout << "M::M()" << std::endl;
    }

    ~M() {
        std::cout << "M::~M()" << std::endl;
    }

    M(const M&) {
        std::cout << "M::M(const M&)" << std::endl;
    }

    M(int num) {
        this->num = num;
        std::cout << "Opération d'affectation" << std::endl;
    }
};

class F : public M {
    public:
    F() {
        std::cout << "F::F()" << std::endl;
    }
    ~F() {
        std::cout << "F::~F()" << std::endl;
    }
    
    F(const F& f) {
        std::cout << "F::F(const F&)" << std::endl; 
    }

    F(int num) {
        M::num = num;
    }
    
};

int main(int, char**) {
    F f1;
    F f2 = f1;
    F *f3 = new F(3);
    f1 = f2;

    A a1;
    A a2 = a1;

    return 0;
}