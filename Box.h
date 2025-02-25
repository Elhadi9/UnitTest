#ifndef BOX_H
#define BOX_H

class Box {
   public:
      static int objectCount;
      
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0);
      double Volume() const;
      static int getCount();
      
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

#endif // BOX_H
