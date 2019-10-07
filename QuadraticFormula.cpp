#include <iostream>

using namespace std;

float a, b, c, x1, x2, two = 2, four = 4, negativeOne = -1;

int main()
{
	//get data
	cout << "To see the two real roots of aX^2+ bX + c = 0, enter the a, b, and c values: ";
	cin >> a >> b >> c;

	//perform calculations in assembly
	_asm
	{
		//Find x1 = -1b*bb*4ac**-sqrt+2a*/
		fld negativeOne; // -1
		fld b;           // -1, b
		fmul;            // -1*b
		fld b;           // -1*b, b
		fld b;           // -1*b, b, b
		fmul;            // -1*b, b*b
		fld four;        // -1*b, b*b, 4
		fld a;           // -1*b, b*b, 4, a
		fld c;           // -1*b, b*b, 4, a, c
		fmul;            // -1*b, b*b, 4, a*c
		fmul;            // -1*b, b*b, 4*a*c
		fsub;            // -1*b, b*b-4*a*c
		fsqrt;           // -1*b, (b*b-4*a*c)^(1/2)
		fadd;            // -1*b+(b*b-4*a*c)^(1/2)
		fld two;         // -1*b+(b*b-4*a*c)^(1/2), 2
		fld a;           // -1*b+(b*b-4*a*c)^(1/2), 2, a
		fmul;            // -1*b+(b*b-4*a*c)^(1/2), 2*a
		fdiv;            // (-1*b+(b*b-4*a*c)^(1/2))/(2*a)
		fstp x1;

		//Find x2 = -1b*bb*4ac**-sqrt-2a*/
		fld negativeOne; // -1
		fld b;           // -1, b
		fmul;            // -1*b
		fld b;           // -1*b, b
		fld b;           // -1*b, b, b
		fmul;            // -1*b, b*b
		fld four;        // -1*b, b*b, 4
		fld a;           // -1*b, b*b, 4, a
		fld c;           // -1*b, b*b, 4, a, c
		fmul;            // -1*b, b*b, 4, a*c
		fmul;            // -1*b, b*b, 4*a*c
		fsub;            // -1*b, b*b-4*a*c
		fsqrt;           // -1*b, (b*b-4*a*c)^(1/2)
		fsub;            // -1*b-(b*b-4*a*c)^(1/2)
		fld two;         // -1*b-(b*b-4*a*c)^(1/2), 2
		fld a;           // -1*b-(b*b-4*a*c)^(1/2), 2, a
		fmul;            // -1*b-(b*b-4*a*c)^(1/2), 2*a
		fdiv;            // (-1*b-(b*b-4*a*c)^(1/2))/(2*a)
		fstp x2;
	}

	//display results
	cout << "\tX = " << x1 << ", " << x2;

	return 0;
}
