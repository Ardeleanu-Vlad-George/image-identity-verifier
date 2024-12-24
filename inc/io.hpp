#ifndef _IO_HPP_
#define _IO_HPP_

#include <string>
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

std::ostream& log_help(std::ostream&);

std::ostream& log_cla_err(std::ostream&, int, int);

std::ostream& log_size_err(std::ostream&, char*, sf::Vector2u, char*, sf::Vector2u);

std::ostream& log_pixel_err(std::ostream&, sf::Vector2u, char*, sf::Image&, char*, sf::Image&);

std::ostream& log_succes(std::ostream&);

std::string string_of(sf::Vector2u v2u);

std::string string_of(sf::Color clr);

#endif//_IO_HPP_
