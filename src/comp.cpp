#include "comp.hpp"

bool are_equal(sf::Vector2u size, sf::Image& im1, sf::Image& im2, sf::Vector2u& err){
  int x = size.x, y = size.y;
  int *d1 = (int*)im1.getPixelsPtr(), *d2 = (int*)im2.getPixelsPtr();
  for(int i=0; i < x; i++)
    for(int j=0; j < y; j++)
      if(d1[j+i*x]!=d2[j+i*x]){
        err = sf::Vector2u(i, j);
        return false;
      }
  return true;
}
