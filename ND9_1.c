#include <stdio.h>
#include <math.h>


typedef struct// a
{
    float x;
    float y;
}Point;

void printPoint(Point p);
Point createPoint(double x, double y);
double getDistance(Point a, Point b);


int main()
{
    Point p1, p2;
    p1.x = 2.0, p1.y = -3.0;
    p2.x = -4.0, p2.y = 5.0;

    double distance = getDistance(createPoint(p1.x, p1.y), createPoint(p2.x, p2.y)); 
    return 0;
}

double getDistance(Point a, Point b)
{
    double distance = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    return distance;
}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;
    printPoint(p);
}

void printPoint(Point p)
{
    printf("( %.1f ; %.1f )\n", p.x, p.y);
}
