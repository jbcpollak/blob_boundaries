#include <iostream>
#include <vector>

int main(int argc, char ** argv)
{
	/*
	 * Image Definition
	 */
	std::vector<unsigned short> image {
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

	const unsigned short width = 10;
	const unsigned short height = 10;

	unsigned short cell_reads = 0;

	unsigned short top = 10;
	unsigned short left = 10;
	unsigned short bottom = 0;
	unsigned short right = 0;

	// Iterate over image height
	for (unsigned short j = 0; j < height; j++) {
		// Iterate over image width
		for (unsigned short i = 0; i < width; i++) {
			cell_reads++;

			if (image[j*height+i] == 0) {
				continue;
			}

			top = (top < j) ? top : j;
			left = (left < i) ? left : i;
			bottom = (bottom > j) ? bottom : j;
			right = (right > i) ? right : i;



		}
	}

	std::cout << "Cell Reads: " << cell_reads << "\n";
	std::cout << "Top: " << top << "\n";
	std::cout << "Left: " << left << "\n";
	std::cout << "Bottom: " << bottom << "\n";
	std::cout << "Right: " << right << "\n";

	return 0;
}
