#ifndef COMPLEX_H
#define COMPLEX_H


/**
 * z = a +ib
 */
typedef struct complex{
	float real;
	float imaginary;
} Complex;

Complex new_complex(float real, float imaginary);

void print_complex(Complex* c);

/**
 * z1+z2 = (a+ib)+(c+id) = (a+c)+i(b+d)
 */
Complex sum(Complex* c1, Complex* c2);

/**
 * conjugue (a+ib) = a-ib = a+i(-b)
 */
Complex conjugate(Complex* c);

/**
 * norme (a+ib) = racine_carre(a²+b²)
 */
float norm(Complex* c);

#endif
