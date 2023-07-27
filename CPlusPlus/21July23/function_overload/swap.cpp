#include <iostream>

// function overloading

void swap(int& a, int& b) //integer and call by ref
{
    int t;
    t = a;
    a = b;
    b = t;
}

void swap(float *a, float *b) //float
{
    float t;
    t = *a;
    *a = *b;
    *b = t;
}
void swap(double *a, double *b) //double
{
    double t;
    t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int *ap, *bp;
    int a = 2, b = 3;
    ap = &a;
    bp = &b;
    swap(a, b); //direct pass variables
    std::cout << "int ::      a = " << *ap << "\tb= " << *bp << "\n";

    float *afp, *bfp;
    float af = 2.2f, bf = 3.3f;
    afp = &af;
    bfp = &bf;
    swap(afp, bfp);
    std::cout << "float ::    a = " << *afp << "\tb= " << *bfp << "\n";

    float *adp, *bdp;
    float ad = 6.4, bd = 4.9;
    adp = &ad;
    bdp = &bd;
    swap(adp, bdp);
    std::cout << "Double ::   a = " << *adp << "\tb= " << *bdp << "\n";

    return 0;
}