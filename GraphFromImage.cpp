#include "GraphFromImage.h"

GraphFromImage::GraphFromImage(const bitmap_image& i) : image(i) {
    /* A IMPLEMENTER */
}

// throws std::out_of_range
GraphFromImage::Iterable GraphFromImage::adjacent(int v) const {
   
}

// throws std::out_of_range
int GraphFromImage::idx(int x, int y) const {
   return y * 10 + x; 
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
