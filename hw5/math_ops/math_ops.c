
#include <stdio.h>

char c1=5, c2=6, c3;
int i1=5, i2=6, i3;
long long int j2=5, j3=6, j4;
float f1=1.01, f2=2.02, f3;
long double d1=1.01, d2=2.02, d3;

int main(void) {
	
	//int math: char type

	c3 = c1 + c2;
	c3 = c1 - c2;
	c3 = c1 * c2;
	c3 = c1 / c2;
	
	//int math: int type
	
	i3 = i1 + i2;
	i3 = i1 - i2;
	i3 = i1 * i2;
	i3 = i1 / i2;
	
	//int math: long type
	
	j4 = j2 + j3;
	j4 = j2 - j3;
	j4 = j2 * j3;
	j4 = j2 / j3;
	
	//float math: single precision float
	
	f3 = f1 + f2;
	f3 = f1 - f2;
	f3 = f1 * f2;
	f3 = f1 / f2;
	
	//float math: long double-precision float

	d3 = d1 + d2;
	d3 = d1 - d2;
	d3 = d1 * d2;
	d3 = d1 / d2;
	
}