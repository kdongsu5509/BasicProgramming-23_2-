#include <stdio.h>
#include <stdlib.h>

typedef struct _complex complex_t;
typedef struct _complex *complex_ptr;

struct _complex
{
    float real;
    float imag;
};

complex_ptr cmult(complex_t a, complex_t b);
complex_ptr cdiv(complex_ptr a, complex_ptr b);

int main()
{
    complex_t a, b;
    complex_ptr c;

    printf("Enter the real and imaginary parts of the first complex number: ");
    scanf("%f %f", &a.real, &a.imag);

    printf("Enter the real and imaginary parts of the second complex number: ");
    scanf("%f %f", &b.real, &b.imag);

    c = cmult(a, b);
    printf("Multiplication Result: (%.3f) + (%.3f)i\n", c->real, c->imag);
    free(c);

    c = cdiv(&a, &b);
    printf("Division Result: (%.3f) + (%.3f)i\n", c->real, c->imag);
    free(c);

    return 0;
}

complex_ptr cmult(complex_t a, complex_t b)
{
    complex_ptr temp = (complex_ptr)malloc(sizeof(struct _complex));

    double R = (a.real * b.real) - (a.imag * b.imag);
    double I = (a.real * b.imag) + (a.imag * b.real);
    temp->real = R;
    temp->imag = I;

    return temp;
}

complex_ptr cdiv(complex_ptr a, complex_ptr b)
{
    complex_ptr temp = (complex_ptr)malloc(sizeof(struct _complex));

    if (b->real == 0.0 && b->imag == 0.0)
    {
        fprintf(stderr, "Error: Division by zero is undefined.\n");
        exit(1);
    }

    double divisor = b->real * b->real + b->imag * b->imag;

    temp->real = (a->real * b->real + a->imag * b->imag) / divisor;
    temp->imag = (a->imag * b->real - a->real * b->imag) / divisor;

    return temp;
}
