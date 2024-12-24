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

std::ostream& log_succes(std::ostream& os){
  return os<<"All checks are passed, the images are equal\n";
}

std::ostream& log_help(std::ostream& os){
  os<<"Give the following args:\n";
  os<<"\t1. first  image of the comparison\n";
  os<<"\t2. second image of the comparison\n";
  return os;
}

std::ostream& log_cla_err(std::ostream& os, int err_count, int cla_count){
  os<<err_count<<" args were given\n";
  os<<cla_count<<" args are needed\n";
  log_help(os);
  return os;
}

std::ostream& log_size_err(std::ostream& os, char *i1, sf::Vector2u s1, char *i2, sf::Vector2u s2){
  os<<"Images are not equal. Sizes differ.\n";
  os<<string_of(s1)<<" for "<<i1<<'\n';
  os<<string_of(s2)<<" for "<<i2<<'\n';
  return os;
}

std::ostream& log_pixel_err(std::ostream& os, sf::Vector2u pos, char *i1, sf::Image& d1, char *i2, sf::Image& d2){
  os<<"Found difference at:"<<string_of(pos)<<"\n";
  os<<string_of(d1.getPixel(pos.x, pos.y))<<" for "<<i1<<'\n';
  os<<string_of(d2.getPixel(pos.x, pos.y))<<" for "<<i2<<'\n';
  return os;
}
