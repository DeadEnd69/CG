#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void plot(int xCenter, int yCenter, int x, int y)
{
    putpixel(xCenter + x, yCenter + y, 15);
    putpixel(xCenter - x, yCenter + y, 15);
    putpixel(xCenter + x, yCenter - y, 15);
    putpixel(xCenter - x, yCenter - y, 15);
    putpixel(xCenter + y, yCenter + x, 15);
    putpixel(xCenter + y, yCenter - x, 15);
    putpixel(xCenter - y, yCenter + x, 15);
    putpixel(xCenter - y, yCenter - x, 15);
}

void midPointCirlce(int xCenter, int yCenter, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    plot(xCenter, yCenter, x, y);
    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p += 2 * x + 3;
        }
        else
        {
            y--;
            p += 2 * x - 2 * y + 5;
        }
        plot(xCenter, yCenter, x, y);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    midPointCirlce(100, 100, 500);
    getch();
    closegraph();
    return 0;
}