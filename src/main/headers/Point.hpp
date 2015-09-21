/*
 * Point.hpp
 *
 *  Created on: Sep 20, 2015
 *      Author: jpollak
 */


#ifndef SRC_MAIN_HEADERS_POINT_HPP_
#define SRC_MAIN_HEADERS_POINT_HPP_

class Point {
public:

	Point(unsigned short x, unsigned short y) {
		_x = x;
		_y = y;
	}

	unsigned short x() {
		return _x;
	}

	unsigned short y() {
		return _y;
	}

private:
	unsigned short _x;
	unsigned short _y;

};

#endif /* SRC_MAIN_HEADERS_POINT_HPP_ */
