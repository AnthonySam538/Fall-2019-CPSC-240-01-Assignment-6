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
		fld negativeOne;
		fld b;
		fmul;
		fld b;
		fld b;
		fmul;
		fld four;
		fld a;
		fld c;
		fmul;
		fmul;
		fsub;
		fsqrt;
		fadd;
		fld two;
		fld a;
		fmul;
		fdiv;
		fstp x1;

		//Find x2 = -1b*bb*4ac**-sqrt-2a*/
		fld negativeOne;
		fld b;
		fmul;
		fld b;
		fld b;
		fmul;
		fld four;
		fld a;
		fld c;
		fmul;
		fmul;
		fsub;
		fsqrt;
		fsub;
		fld two;
		fld a;
		fmul;
		fdiv;
		fstp x2;
	}

	//display results
	cout << "\tX = " << x1 << ", " << x2;

	return 0;
}