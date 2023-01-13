#include <iostream>
using namespace std;

int main(int, char**) {
   int * p = new int;

   *p = 3;
   cout << *p << endl;

   // delete p;

   return 0;
}