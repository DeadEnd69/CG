#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void plot(float x, float y, float xCenter, float yCenter)
{
    putpixel(round(xCenter + x), round(yCenter + y), 15);
    putpixel(round(xCenter - x), round(yCenter + y), 15);
    putpixel(round(xCenter + x), round(yCenter - y), 15);
    putpixel(round(xCenter - x), round(yCenter - y), 15);
    // printf("(%f, %f)\n", xCenter + x, yCenter + y);
    // printf("(%f, %f)\n", xCenter - x, yCenter + y);
    // printf("(%f, %f)\n", xCenter + x, yCenter - y);
    // printf("(%f, %f)\n", xCenter - x, yCenter - y);

    // printf("\n\n");
}

void midPointEllipse(float a, float b, float xCenter, float yCenter)
{
    float x = 0, y = b, p1, p2, dx, dy;
    dx = 2 * pow(b, 2) * x;
    dy = 2 * pow(a, 2) * y;
    p1 = pow(b, 2) - pow(a, 2) * b + 1 / 4 * pow(a, 2);
    // p1 = pow(b, 2)*(x+1/2) - pow(a, 2)  * b + 1 / 4 * pow(a, 2);
    plot(x, y, xCenter, yCenter);
    printf("The value of dx and dy are %f and %f, pow: %f", dx, dy, p1);
    do
    {
        x++;
        if (p1 < 0)
        {
            dx = 2 * (pow(b, 2)) * x + 2 * pow(b, 2);
            p1 = 2 * dx + pow(b, 2);
        }
        else
        {
            y--;
            dx = 2 * (pow(b, 2)) * x + 2 * pow(b, 2);
            dy = 2 * (pow(a, 2)) * y + 2 * pow(a, 2);
            p1 += dx - dy + pow(b, 2);
            printf("Enter the first loop\n");
        }

        plot(xCenter, yCenter, x, y);
    } while (dx < dy);
    p2 = pow(b, 2) * pow((1 / 2), 2) + pow(b, 2) * pow((b - 1), 2) - pow(a, 2) * pow(b, 2);
    while (y >= 0)
    {
        printf("Enter the second loop\n");
        y--;
        if (p2 > 0)
        {
            dx = 2 * (pow(a, 2) * x) + 2 * pow(a, 2);
            p2 += -2 * pow(a, 2) * (y) + pow(a, 2);
        }
        else
        {
            dx = 2 * (pow(a, 2)) * x + 2 * pow(a, 2);
            dy = 2 * (pow(b, 2)) * y + 2 * pow(b, 2);
            p2 += dx - dy + pow(a, 2);
        }
        plot(x, y, xCenter, yCenter);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    midPointEllipse(100, 200, 200, 200);
    // plot(10, 10, 50, 50);
    getch();
    closegraph();
    return 0;
}