//Enter required header files
#include <stdio.h>
#include <math.h>


/**
 * @brief Returns 1 if the triangle is right-angled triangle else 0. 
 * 
 * Example:
 * right_angled(3.00, 4.00, 5.00) returns 1
 * right_angled(5.00, 13.00, 12.00) returns 1
 * right_angled(8.00, 4.00, 7.00) returns 1
*/
int right_angled(int a, int b, int c)
{
    if (a + b == c || a + c == b || b + c == a)
        return 1;
    
    return 0;
}


/**
 * @brief Returns the distance between the given two 2D points using the distance formula d((x1,y1), (x2,y2)) = sqrt((x1-x2)^2 + (y1-y2)^2).
 *
 * Example:
 * calcLen(1, -1, 1, 9) returns 10.00
 * calcLen(1, -1, 4, -1) returns 3.00
 * calcLen(1, 9, 4, -1) returns 10.44
 */
//Have the required parameters
double calcLen(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int calc_len(int x1, int y1, int x2, int y2)
{
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}


/**
 * @brief Returns 1 if the triangle can be constructed given the 3 sides as parameters using the Triangle Inequality Theorem. 
 * If the triangle cannot be constructed, it returns 0.
 * 
 * The triangle inequality states that for any triangle, the sum of the lengths of any two sides must be greater than the length of the remaining side.
 * Note: It should be true for all three combinations of added side lengths, only then you will have a triangle.
 * 
 * Example:
 * validTriangle(3.00, 10.00, 10.44) returns 1
 * validTriangle(7.00, 10.00, 5.00) returns 1
 * validTriangle(5.00, 8.00, 3.00) returns 0
 */
//Have the required parameters
int validTriangle(double s1, double s2, double s3)
{
    if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1)
        return 0;
    
    return 1;
}


/**
 * @brief Takes the coordinates as parameters.
 * Returns 1 if the triangle is equilateral (all sides are equal)
 * Returns 2 if the triangle is isosceles right angled (2 sides are equal and the sides follow the pythagoras theorem)
 * Returns 3 if the triangle is isosceles (2 sides are equal and the sides do not follow the pythagoras theorem) 
 * Returns 4 if the triangle is right angled but not isosceles(The sides follow the pythagoras theorem)
 * Returns 5 if the triangle is scalene (All sides are different) 
 *  
 * Example:
 * triangleType(1, 0, 5, 0, 1, 4) returns 2
 * triangleType(-4, 0, 4, 0, 0, 3) returns 3
 * triangleType(1, -1, 4, -1, 1, 9) returns 4
 * triangleType(-4, 0, 3, 0, 0, 4) returns 5
 */
//Have the required parameters
int triangleType(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int side3 = calc_len(x2, y2, x3, y3);
    int side1 = calc_len(x1, y1, x2, y2);
    int side2 = calc_len(x1, y1, x3, y3);

    if (side1 == side2 || side2 == side3 || side1 == side3)
    {
        if (side1 == side2 && side2 == side3)
            return 1;
        
        if (right_angled(side1 ,side2, side3) == 1)
            return 2;

        return 3;
    }

    if (right_angled(side1 ,side2, side3) == 1)
        return 4;
    
    return 5;
}

int main()
{
    //*******DO NOT CHANGE main()********
    
    int x1, y1;
    int x2, y2;
    int x3, y3;

    printf("Enter 3 coordinates for 3 points:\n");
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    double side1 = calcLen(x1, y1, x2, y2);
    double side2 = calcLen(x1, y1, x3, y3);
    double side3 = calcLen(x2, y2, x3, y3);

    int valid = validTriangle(side1, side2, side3);

    if (valid == 0)
        printf("Triangle cannot be constructed.\n");

    else
    {
        printf("Triangle can be constructed.\n");
        int type = triangleType(x1, y1, x2, y2, x3, y3);
        if(type == 1)
            printf("This is an equilateral triangle.\n");
        else if(type == 2)
            printf("This is an isosceles right triangle.\n");
        else if(type == 3)
            printf("This is an isosceles triangle.\n");
        else if (type == 4)
            printf("This is a right angled triangle.\n");
        else if (type == 5)
            printf("This is a scalene triangle.\n");
    }
    return 0;
}