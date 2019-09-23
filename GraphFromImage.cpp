#include "GraphFromImage.h"

GraphFromImage::GraphFromImage(const bitmap_image& i) : image(i) {
    /* A IMPLEMENTER */
}

// throws std::out_of_range
GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {
   Iterable listAdj;
   
   
   // verifier si pixel et noir sinon on laisse tomber
   
   //adj up
   int nouvelAdj = v - image.width();
   if(!(nouvelAdj  < 0)){
      listAdj.push_back(nouvelAdj);
   }
   //adj left
   if(!(v % image.width() == 0)){
      nouvelAdj = v - 1;
      listAdj.push_back(nouvelAdj);
   }
   //adj right
   nouvelAdj = v + 1;
   if(!(nouvelAdj % image.width() == 0)){
      listAdj.push_back(nouvelAdj);
   }
   //adj down
   nouvelAdj = v + image.width();
   if(!(nouvelAdj > (image.width() * image.height()))){
      listAdj.push_back(nouvelAdj);
   }
   return listAdj;
}

// throws std::out_of_range
int GraphFromImage::idx(int x, int y) const {
   return y * image.width() + x; 
}

// throws std::out_of_range
int GraphFromImage::x(int idx) const {
   return idx % image.width();
}

// throws std::out_of_range
int GraphFromImage::y(int idx) const {
   return floor(idx / (int)image.width());
}

int GraphFromImage::V() const {
   return image.height() * image.width();
}
