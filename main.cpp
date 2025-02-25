#include <iostream>
#include "Box.h"

using namespace std;

int main(void) {
   // Print total number of objects before creating object.
   cout << "Initial Stage Count: " << Box::getCount() << endl;

   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   // Print total number of objects after creating object.
   cout << "Final Stage Count: " << Box::getCount() << endl;

   return 0;
}
