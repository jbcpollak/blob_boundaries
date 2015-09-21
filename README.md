Blob Analysis Example
==

Finds the boundaries of any blob in a 10x10 grid.

This code uses a Flood-Fill algorithm, as defined here:

	Flood-fill (node, target-color, replacement-color):
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
		 
	(Source: https://en.wikipedia.org/wiki/Flood_fill)

Notes
==

*  I considered writing the code in Java but decided to use the opportunity as a C++ refresher
*  This is the first C++ code I've written in 10 years, re-learned quite a bit
*  The project uses features introduced in the recent C++11 standard

Limitations
== 

*  Code assumes only one blob in the image
*  This version is destructive to the source image. Variations can be done by either using a set to tracking the visited pixels, or by duplicating the source image for modification.
*  I could not figure out a variation of the algorithm to examine only 44 cells for the sample blob

Compiling
==

The project uses the Gradle build system. Run the following to compile:

    ./gradlew debugMainExecutable
    
Once compiled, run the following to run the code:

    ./build/binaries/mainExecutable/debug/main

Other Sample Code
==

Here are links to other sample code that might be relevant

*   [React-based JavaScript app](https://github.com/jbcpollak/react-depression-screener)

    This project demonstrates good professional coding practices, such as unit tests and continuous integration.  

*   [A-Star in Clojure](https://github.com/jbcpollak/AStar-Clojure)

    An implementation of A-Star search in Clojure, written a few years ago to demonstrate knowledge of functional programming.