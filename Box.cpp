#include "Box.h"
#include <iostream>

using namespace std;

// Initialize static member of class Box
int Box::objectCount = 0;

// Constructor definition
Box::Box(double l, double b, double h) {
   cout <<"Constructor called." << endl;
   length = l;
   breadth = b;
   height = h;

   // Increase every time object is created
   objectCount++;
}

double Box::Volume() const {
   return length * breadth * height;
}

int Box::getCount() {
   return objectCount;
}
