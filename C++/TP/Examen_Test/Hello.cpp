#include <iostream>

// using namespace std;
// using std::cout;

class direBonjour
{
    private:
    int numb;

    public:
    std::string name;
};

int main(int argc, char ** argv)
{
    direBonjour test;
    test.name = "hola";

    std::cout << test.name << 2;
    std::cout << std::endl;

    return 0;
}