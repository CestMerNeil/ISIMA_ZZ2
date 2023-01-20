#include <iostream>
#include <string>

int main(int argc, char ** argv)
{

    //
    // g++ -Wall -Wextra -g name.cpp -o name
    // ./name
    //
    // Compiler
    // Main.cpp -> Main.o -> a.out 
    // edition des liens
    // g++ -> jusquu'à compilation
    // ldd -> pour linker les fichers .o
    // 
    /*
    //using myMap = std::map<std::string, std::tuple<int, int>>;
    using str = std::string;
    str a;
    using namespace std;
    using namespace std::chrono;

    std::string a; // This is the best way to write!!!!!
    */
    
    
    // For the "Hello World!"
    int i;
    for(i=0; i<120; ++i)
    {
        //std::cout << "Bonjour les ZZ" << 2 << std::endl;
    }

    // For the input
    /*
    std::string prenom;
    int age;
    std::cout << "Quel est votre prénom?" << std::endl;
    std::cin >> prenom;
    std::cout << "Quel est votre age?" << std::endl;
    std::cin >> age;
    std::cout << "Bonjour " << prenom << std::endl;
    */

    
    // For string
    std::string firstString;
    std::string secondString;
    std::cout << "Please input the first string:" << std::endl;
    std::cin >> firstString;
    std::cout << "Please input the second string:" << std::endl;
    std::cin >> secondString;

    int lengthFirstString = firstString.size();
    int lengthSecondString = secondString.size();

    if(lengthFirstString == lengthSecondString)
    {
        std::cout << "Come on, you've entered two strings of same sizes!" << std::endl;
    }
    #ifdef 
    #elif
    #endif
    else if(lengthFirstString > lengthSecondString)
    {
        std::cout << "It's the second one who is more short! The length is " << 
        lengthSecondString << ". And the string is" << secondString << std::endl;
    }
    else{
        std::cout << "It's the first one who is more short! The length is " << 
        lengthFirstString << ". And the string is" << firstString << std::endl;
    }


    return 0;
}