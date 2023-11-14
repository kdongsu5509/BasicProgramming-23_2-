#include <stdio.h>

typedef struct _complex complex_t;

struct _complex
{
    double real;
    double imag;
};

void cmult(complex_t x, complex_t y, complex_t *z);
void cdiv(complex_t *a, complex_t *b, complex_t *c);

int main()
{
    complex_t a, b, c, d, e;
    scanf("%lf %lf", &a.real, &a.imag);
    scanf("%lf %lf", &b.real, &b.imag);

    // 입력은 a,b에 되어있음.
    cmult(a, b, &c);  // 분자 * 분모 -> 유리화 과정 // 저장은 c에
    cmult(b, b, &d);  // 분모 유리화 // 저장은 d에
    cdiv(&c, &d, &e); // e로 저장 // d는 정수임.
    printf("%.2f + %.2fi", e.real, e.imag);
}

void cmult(complex_t x, complex_t y, complex_t *z)
{
    double R = (x.real * y.real) - (x.imag * -(y.imag));
    double I = (x.real * -(y.imag)) + (x.imag * y.real); // 0이 됨.
    z->real = R;
    z->imag = I;
}
void cdiv(complex_t *a, complex_t *b, complex_t *c)
{
    double R = a->real / b->real;
    double I = a->imag / b->real;
    c->real = R;
    c->imag = I;
}
