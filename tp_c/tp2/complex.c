#include <stdio.h>
#include <math.h>
#include "complex.h"

Complex new_complex(float real, float imaginary){
	Complex c;
	c.real = real;
	c.imaginary = imaginary;
	
	return c;
}

void print_complex(Complex* c){
	printf("nb complexe : %f + i%f\n", c->real, c->imaginary);
	/*printf("%f %f", (*c).real, (*c).imaginary);*/
}

Complex sum(Complex* c1, Complex* c2){
	Complex c;
	c.real = c1->real + c2->real;
	c.imaginary = c1->imaginary + c2->imaginary;
	
	return c;
}

Complex conjugate(Complex* c){
	Complex conjugue;
	conjugue.real = c->real;
	conjugue.imaginary = -(c->imaginary);
		
	return conjugue;
}

float norm(Complex* c){
	float norme_complex;
	norme_complex = sqrt(c->real * c->real + c->imaginary *c->imaginary);
	
	return norme_complex;
}
