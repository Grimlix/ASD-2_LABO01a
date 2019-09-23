#include "GraphFromImage.h"

GraphFromImage::GraphFromImage(const bitmap_image& i) : image(i) {}

// throws std::out_of_range
GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {
   Iterable listAdj;

   //adj up
   int nouvelAdj = v - image.width();
   if(!(nouvelAdj < 0) and memeCouleur(v, nouvelAdj)){
      listAdj.push_back(nouvelAdj);
   }
   //adj left
   nouvelAdj = v - 1;
   if(!(v % image.width() == 0) and memeCouleur(v, nouvelAdj)){
      listAdj.push_back(nouvelAdj);
   }
   //adj right
   nouvelAdj = v + 1;
   if(!(nouvelAdj % image.width() == 0) and memeCouleur(v, nouvelAdj)){
      listAdj.push_back(nouvelAdj);
   }
   //adj down
   nouvelAdj = v + image.width();
   if(!(nouvelAdj > (image.width() * image.height())) and memeCouleur(v, nouvelAdj)){
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
   return idx / (int)image.width();
}

int GraphFromImage::V() const {
   return image.height() * image.width();
}

bool GraphFromImage::memeCouleur(int s1, int s2) const{
   
   unsigned char r1, g1, b1, r2, g2, b2;
   
   image.get_pixel(x(s1), y(s1), r1, g1, b1);
   image.get_pixel(x(s2), y(s2), r2, g2, b2);
   
   return (r1 == r2 and g1 == g2 and b1 == b2);
   
}
