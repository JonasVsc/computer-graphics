#include<iostream>
using namespace std;


// 2-dimensional vector
struct vector 
{
	float x;
	float y;

	vector() : x{0}, y{0} {};
	vector(float x, float y) : x{x}, y{y} {};
	friend ostream& operator<<(ostream& buf, const vector &v) { buf << '(' << v.x << ',' << v.y << ')'; return buf; }

	// VECTOR ADDITION/SUBTRACTION
	friend vector operator+(const vector& v, const vector& w) { return vector(v.x + w.x, v.y + w.y); }
	friend vector operator-(const vector& v, const vector& w) { return vector(v.x - w.x, v.y - w.y); }

	// SCALAR MULTIPLICATION
	friend vector operator*(const vector& v, float c) { return vector(c * v.x, c * v.y); }
	friend vector operator*(float c, const vector& v) { return vector(c * v.x, c * v.y); } // same as above
};


int main()
{
	vector v(1,2);
	vector w(3,4);

	cout << "v = " << v << '\n';
	cout << "w = " << w << '\n';

	cout << "Sum of:           v + w          = " << v + w << '\n';
	cout << "Expression of:    2(v + w)       = " << 2*(v + w) << '\n';
	cout << "Expression of:    2v + (3v - w)  = " << 2*v + (3*v - w) << '\n';


	return 0;
}