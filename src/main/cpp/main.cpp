#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <exception>

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

class SeedNotFoundException : public std::exception
{
  virtual const char* what() const throw()
  {
    return "No cell found!";
  }
};

class Image {
public:
	Image(std::vector<unsigned short>& img,
			const unsigned short width,
			const unsigned short height) :
				_img(img), _width(width), _height(height) {

		_top = height;
		_left = width;
	}

	/*
	 * Source: https://en.wikipedia.org/wiki/Flood_fill
	 * Flood-fill (node, target-color, replacement-color):
		 1. If target-color is equal to replacement-color, return.
		 2. Set Q to the empty queue.
		 3. Add node to the end of Q.
		 4. While Q is not empty:
		 5.     Set n equal to the first element of Q.
		 6.     Remove first element from Q.
		 7.     If the color of n is equal to target-color:
		 8.         Set the color of n to replacement-color and mark "n" as processed.
		 9.         Add west node to end of Q if west has not been processed yet.
		 10.        Add east node to end of Q if east has not been processed yet.
		 11.        Add north node to end of Q if north has not been processed yet.
		 12.        Add south node to end of Q if south has not been processed yet.
		 13. Return.
	 */
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

	void checkNeighbor(int x, int y) {
		if (y < _height && y > 0 && x < _width && x > 0 && _img[y*_height+x] == 1) {
			_cell_reads++;
			_queue.push_back(std::unique_ptr<Point>(new Point(x, y)));
		}
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

				if (_img[j*_height+i] > 0) {
					return std::unique_ptr<Point>(new Point(i, j));
				}
			}
		}

		throw new SeedNotFoundException();
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

int main(int argc, char ** argv)
{
	/*
	 * Image Definition
	 */
	std::vector<unsigned short> data {
			0,0,0,0,0,0,0,0,0,0,
			0,0,1,1,1,0,0,0,0,0,
			0,0,1,1,1,1,1,0,0,0,
			0,0,1,0,0,0,1,0,0,0,
			0,0,1,1,1,1,1,0,0,0,
			0,0,0,0,1,0,1,0,0,0,
			0,0,0,0,1,0,1,0,0,0,
			0,0,0,0,1,1,1,0,0,0,
			0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0
	};

	Image image = Image(data, 10, 10);

	image.floodFill();

	// Success
	return 0;
}
