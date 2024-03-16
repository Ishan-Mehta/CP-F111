#include<stdio.h>

int main()
{
    struct person
    {
        char *name;
        char address[100];
        int aadhaar;
    } p2, p4;

    typedef struct
    {
        /* data */
    } batsman_t;
    

    p2.aadhaar = 2342;
    p2.name = "bksjafdb";

    int a[] = {3, 45, 36};
    p4.name = p2.name;


    struct person p3;

    struct person p1 = {"Ishan Mehta", "Nashik Nusta form!", 32432521};

    printf("p1: name: %s, address: %s, aadhaar: %d\n", p1.name, p1.address, p1.aadhaar);
    printf("p1: name: %d, address: %d, aadhaar: %d\n", &p1.name, &p1.address, &p1.aadhaar);
    printf("p1: name: %p, address: %p, aadhaar: %p\n", p1.name, p1.address, p1.aadhaar);
    printf("p1: name: %p, address: %p, aadhaar: %p\n\n", &p1.name, &p1.address, &p1.aadhaar);

    p3 = p1;

    printf("p3: name: %s, address: %s, aadhaar: %d\n", p3.name, p3.address, p3.aadhaar);
    printf("p3: name: %d, address: %d, aadhaar: %d\n", &p3.name, &p3.address, &p3.aadhaar);
    printf("p3: name: %p, address: %p, aadhaar: %p\n", p3.name, p3.address, p3.aadhaar);
    printf("p3: name: %p, address: %p, aadhaar: %p\n\n", &p3.name, &p3.address, &p3.aadhaar);

    printf("p1: name: %s, address: %s, adhaar: %d\n", p1.name, p1.address, p1.aadhaar);
    printf("p1: name: %d, address: %d, adhaar: %d\n", &p1.name, &p1.address, &p1.aadhaar);
    printf("p1: name: %p, address: %p, adhaar: %p\n", p1.name, p1.address, p1.aadhaar);
    printf("p1: name: %p, address: %p, adhaar: %p\n\n", &p1.name, &p1.address, &p1.aadhaar);
    
    
}