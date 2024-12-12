#include "io.hpp"

std::string string_of(sf::Vector2u v2u){
  char pair[211];
  sprintf(
    pair,
    "(%d,%d)",
    v2u.x, v2u.y
  );
  return std::string(pair);
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

