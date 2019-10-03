#include <iostream>

using namespace std;

float a, b, c, h, l, w, triangleArea, trianglePerimeter, rectangleArea, rectanglePerimeter, two = 2;

int main()
{
	//get data
    cout << "Enter the values of a, b, c, and h for the triangle: (c is the base of the triangle) ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: ";
	cin >> l >> w;

	//perform calculations in assembly
	_asm
	{
		//Calculate triangleArea = ch/2 = ch*2/
		fld c;   // c
		fld h;   // c, h
		fmul;    // c*h
		fld two; // c*h, 2
		fdiv;    // c*h/2
		fstp triangleArea; // triangleArea = c*h/2

		//Calculate trianglePerimeter = a+b+c = abc++
		fld a; // a
		fld b; // a, b
		fld c; // a, b, c
		fadd;  // a, b+c
		fadd;  // a+b+c
		fstp trianglePerimeter; // trianglePerimeter = a+b+c

		//Calculate rectangleArea = l*w = lw*
		fld l; // l
		fld w; // l, w
		fmul;  // l*w
		fstp rectangleArea; // rectangleArea = l*w

		//Calculate rectanglePerimeter = 2*(l+w) = 2lw+*
		fld two; // 2
		fld l;   // 2, l
		fld w;   // 2, l, w
		fadd;    // 2, l+w
		fmul;    // 2*(l+w)
		fstp rectanglePerimeter; // rectanglePerimeter = 2*(l+w)
	}

	//display results
	cout << "\nTriangle\n\tArea............" << triangleArea << "\n\tPerimeter......." << trianglePerimeter
		 << "\nRectangle\n\tArea............" << rectangleArea << "\n\tPerimeter......." << rectanglePerimeter;
}