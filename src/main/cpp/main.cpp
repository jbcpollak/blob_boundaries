#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <memory>
#include <exception>

#include "Image.hpp"

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
