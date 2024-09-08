#include <iostream>
#include <cmath>
#include "tgaimage.h"
using namespace std;
struct Point;
bool special_case(Point& A, Point &B);
const TGAColor white = TGAColor(255, 255, 255, 255);
TGAImage image(100, 100, TGAImage::RGB);

/*
	CREDITS
*/

/*
PERSPECTIVE PROJECTION

	- Simulate the appearence of depth, making objects appear smaller as they get further from the view

	BASIC	
		- Consider a 3d point P(x, y, z) in a scene
		- Consider a camera positioned at the origin C(0, 0, 0) looking down the negative z-axis
		- The distance from the camera to the projection plane is z = -d

	PROJECTION IN 2D

		- In perspective projection the coordinates P(x,y,z) in 3D space are projected onto the 2D projection plane, resulting in a 2D point P'(x',y').
		
		- Using similar triangles, the ratio of the distance along the x and y-axis are:
		- X-axis Projection: U = x/z
		- Y-axis Projection: V = y/z

         ---    _______
          |    |       |
       V  |    |       |
          |    |       |
         ---   |_______| 
			    
               |-------|
                   U
*/

// ============================================================================================================================================================



/*
RASTERIZATION
	
	- Process of converting a continuous object to a discrete representation on a raster grid (pixel grid)

	- Diamond Rule ( Used by modern GPUs )

	
	+--------+
	|   /\   |
	|  /  \  |
	| /    \ |
	| \    / |
	|  \  /  |
	|   \/   |
	+--------+ (Diamond Rule. Image this is a pixel unit.)


	- Check every single pixel in the image to see if it meets the condition... if true, draw the pixel.

	
	Below, in main function, has a implementation of incremental line rasterization. (not how lines are drawn in modern software/hardware)

	Algorithm explanation

	- Let's say a line is reprented with integer endpoints (U1, V1)..(U2, V2)
	- Slope of line: S = (V2 - V1) / (U2 - U1)
	- Consider an easy special case:
			- U1 < U2  &  V1 < V2 (line points toward upper-right)

*/

struct Point 
{
	int U;
	int V;
	Point(int u, int v) :U{u}, V{v} {}
};

int main()
{
	
	// INPUT ENDPOINTS | USE NUMBERS 0..100
	Point A (0,0);
	Point B (24, 14);

	// VERIFY SPECIAL CASE
	if(!special_case(A,B))
	{
		cerr << "[ERROR]   U1 > U2 OR V1 > V2!  Finishing program!" << '\n';
		return 0;
	}



	// INCREMENTAL LINE ALGORITHM

	int s = (A.U - B.U) / (A.V - B.V);

	int v = A.V;
	for(int u = A.U; u < B.U; u++)
	{
		v += s;
		image.set(u, round(v), white);
	}

	// INCREMENTAL LINE ALGORITHM END
	// IF YOU WANT TO SEE THE LINE YOU CREATED AN PNG FILE WAS CREATED IN BUILD FOLDER

	image.flip_vertically();
	image.write_tga_file("output.png");

	return 0;
}




bool special_case(Point& A, Point &B)
{
	if(A.U < B.U && A.V < B.V)
	{
		return true; // ok
	}
	return false; // error
}