#include <stdio.h>
#include <graphics.h>
#include <conio.h>
void circlePlotPoints(int xCenter, int yCenter, int x, int y)
{
    putpixel(xCenter + x, yCenter + y, 15);
    putpixel(xCenter - x, yCenter + y, 15);
    putpixel(xCenter + x, yCenter - y, 15);
    putpixel(xCenter - x, yCenter - y, 15);
    putpixel(xCenter - y, yCenter - x, 15);
    putpixel(xCenter + y, yCenter - x, 15);
    putpixel(xCenter - y, yCenter + x, 15);
    putpixel(xCenter + y, yCenter + x, 15);
}

void midPointCircle(int x, int y, int radius)
{
    int x1 = 0;
    int y1 = radius;
    int p = 1 - radius;
    circlePlotPoints(x, y, x1, y1);
    while (x1 < y1)
    {
        x1++;
        if (p < 0)
        {
            p += 2 * x1 + 3;
        }
        else
        {
            y1--;
            p += 2 * x1 + 5 - 2 * y1;
        }
        circlePlotPoints(x, y, x1, y1);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    midPointCircle(100, 100, 100);
    getch();
    closegraph();
    return 0;
}