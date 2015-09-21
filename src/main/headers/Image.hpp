/*
 * Image.hpp
 *
 *  Created on: Sep 20, 2015
 *      Author: jpollak
 */

#ifndef SRC_MAIN_HEADERS_IMAGE_HPP_
#define SRC_MAIN_HEADERS_IMAGE_HPP_

#include "Point.hpp"
#include "Exception.hpp"

class Image {
public:
	Image(std::vector<unsigned short>& img,
			const unsigned short width,
			const unsigned short height) :
				_img(img), _width(width), _height(height) {

		_top = height;
		_left = width;
	}

	void floodFill() {

		try {
			_queue.push_back(getSeed());
		} catch(std::exception& e) {
			std::cout << e.what() << '\n';
			return;
		}

		while(!_queue.empty()) {
			std::unique_ptr<Point>& front = _queue.front();

			int x = front->x();
			int y = front->y();

			_queue.pop_front();

			// clear the cell so we don't iterate backwards over the blob
			_img[y*_height+x] = 0;

			_left = (_left < x) ? _left : x;
			_right = (_right > x) ? _right : x;

			_top = (_top < y) ? _top : y;
			_bottom = (_bottom > y) ? _bottom : y;

			checkNeighbor(x-1, y);
			checkNeighbor(x+1, y);
			checkNeighbor(x, y-1);
			checkNeighbor(x, y+1);
		}

		printReport();
	}

	void printReport() {

		std::cout << "Cell Reads: " << _cell_reads << "\n";
		std::cout << "Top: " << _top << "\n";
		std::cout << "Left: " << _left << "\n";
		std::cout << "Bottom: " << _bottom << "\n";
		std::cout << "Right: " << _right << "\n";
	}

private:
	std::unique_ptr<Point> getSeed() {
		// Iterate over image height
		for (unsigned short j = 0; j < _height; j++) {
			// Iterate over image width
			for (unsigned short i = 0; i < _width; i++) {
				_cell_reads++;

				if (_img[j*_height+i] == 1) {
					return std::unique_ptr<Point>(new Point(i, j));
				}
			}
		}

		throw new SeedNotFoundException();
	}

	void checkNeighbor(int x, int y) {
		if (y < _height && y > 0 && x < _width && x > 0 && _img[y*_height+x] == 1) {

			_queue.push_back(std::unique_ptr<Point>(new Point(x, y)));
			_cell_reads++;
		}
	}

	std::vector<unsigned short>& _img;
	const unsigned short _width;
	const unsigned short _height;

	std::list<std::unique_ptr<Point>> _queue;

	unsigned short _cell_reads = 0;

	unsigned short _top = 10;
	unsigned short _left = 10;
	unsigned short _bottom = 0;
	unsigned short _right = 0;
};

#endif /* SRC_MAIN_HEADERS_IMAGE_HPP_ */
