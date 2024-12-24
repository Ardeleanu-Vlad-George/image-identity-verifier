#include <iostream>
#include <SFML/Graphics.hpp>
#include "io.hpp"
#include "comp.hpp"
#include "defs.hpp"
#include <cstring>


int main(int argc, char *argv[]){
  if(2 == argc && 0 == strcmp(HELP_STR, argv[1])){
    log_help(std::clog);
    return 1;
  }

  if(CLA_ARG_COUNT != argc-1){
    log_cla_err(std::clog, argc-1, CLA_ARG_COUNT);
    return -1;
  }

  sf::Image i1, i2;
  i1.loadFromFile(argv[1]);
  i2.loadFromFile(argv[2]);
  sf::Vector2u s1=i1.getSize(), s2=i2.getSize(); 

  if(s1 != s2){
    log_size_err(std::clog, argv[1], s1, argv[2], s2);
    return -2;
  }

  sf::Vector2u err;
  if(!are_equal(s1, i1, i2, err)){
    log_pixel_err(std::clog, err, argv[1], i1, argv[2], i2);
    return -3;
  }

  log_succes(std::cout);
  return 0;
}
