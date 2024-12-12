#include <iostream>
#include <string>
#include <cstdio>
#include <SFML/Graphics.hpp>

std::string string_of(int x, int y){
  return "("+std::to_string(x)+","+std::to_string(y)+")";
}

std::string string_of(sf::Vector2u v2u){
  return string_of(v2u.x, v2u.y);
}

std::string string_of(sf::Color clr){
  char hex_rgb[211];
  sprintf(
    hex_rgb, 
    "[#%02x%02x%02x at opac:%05.2lf%%]",
    clr.r, clr.g, clr.b, 
    100.*clr.a/255.
  );
  return std::string(hex_rgb);
}

int main(int argc, char *argv[]){
  if(3 != argc){
    std::cout<<"Invalid number of arguments.\n";
    std::cout<<"Two are needed.\n";
    std::cout<<"\tFirst image that is compared.\n";
    std::cout<<"\tSecond image that is compared.\n";
    return -1;
  }
  sf::Image i1, i2;
  i1.loadFromFile(argv[1]);
  i2.loadFromFile(argv[2]);
  sf::Vector2u s1=i1.getSize(), s2=i2.getSize(); 

  if(s1 != s2){
    std::cout<<"Images are not equal. Sizes differ.\n";
    std::cout<<string_of(s1)<<" for "<<argv[1]<<'\n';
    std::cout<<string_of(s2)<<" for "<<argv[2]<<'\n';
    return -2;
  }

  int *d1 = (int*) i1.getPixelsPtr(), *d2 = (int*) i2.getPixelsPtr();
  int x = s1.x, y = s2.y;
  for(int i=0; i < x; i++)
    for(int j=0; j < y; j++)
      if(d1[i*x+j]!=d2[i*x+j]){
        std::cout<<"Found difference at:"<<string_of(i,j)<<"\n";
        std::cout<<string_of(i1.getPixel(i, j))<<" for "<<argv[1]<<'\n';
        std::cout<<string_of(i2.getPixel(i, j))<<" for "<<argv[2]<<'\n';
        return -3;
      }
  std::cout<<"All checks passed. Images are equal.\n";
  return 0;
}
