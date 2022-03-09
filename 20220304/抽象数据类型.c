#include <stdio.h>
#include <math.h>

//抽象类型
typedef struct
{
    float realpart;
    float imagpart;
} Complex;

void assign(Complex *A, float real, float imag)
{
    A->realpart = real;
    A->imagpart = imag;
    //printf("%f %f\n", A->realpart, A->imagpart);
}

void add(Complex *c, Complex *a, Complex *b)
{
    c->realpart = a->realpart + b->realpart;
    c->imagpart = a->imagpart + b->imagpart;
    //printf("%f %f\n", c->realpart, c->imagpart);
}

void multiply(Complex *c, Complex a, Complex b)
{
    c->realpart = (a.realpart) * (b.realpart) - (a.imagpart) * (b.imagpart);
    c->imagpart = (a.imagpart) * (b.realpart) + (a.realpart) * (b.imagpart);
}

void divide(Complex *dc, Complex da, Complex db)
{
    dc->realpart = ((da.realpart) * (db.realpart) + (da.imagpart) * (db.imagpart)) / (pow(db.realpart, 2) + pow(db.imagpart, 2));
    dc->imagpart = ((da.imagpart) * (db.realpart) - (da.realpart) * (db.imagpart)) / (pow(db.realpart, 2) + pow(db.imagpart, 2));
}

void getreal(Complex *dz)
{
    printf("%f\n", dz->realpart);
}

void getimag(Complex *dz)
{
    printf("%f\n", dz->imagpart);
}

int main()
{
    // float realdata = 2.0;
    // float imagdata = 1.0;
    Complex z1, z2, z3, z4, z;
    float realpart, imagpart;
    //Complex B;
    //Complex C;
    assign(&z1, 8.0, 6.0);
    assign(&z2, 4.0, 3.0);
    add(&z3, &z1, &z2);
    multiply(&z4, z1, z2);
    divide(&z, z4, z3);
    if (z.realpart)
    {
        getreal(&z);
        getimag(&z);
    }
}
