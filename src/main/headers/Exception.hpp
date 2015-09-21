/*
 * Exception.hpp
 *
 *  Created on: Sep 20, 2015
 *      Author: jpollak
 */

#ifndef SRC_MAIN_HEADERS_EXCEPTION_HPP_
#define SRC_MAIN_HEADERS_EXCEPTION_HPP_

class SeedNotFoundException : public std::exception
{
  virtual const char* what() const throw()
  {
    return "No cell found!";
  }
};




#endif /* SRC_MAIN_HEADERS_EXCEPTION_HPP_ */
