#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
void lineBSA(int x1, int y1, int x2, int y2)
{
    float x, y, xEnd, p, dx, dy;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 > x1)
    {
        x = x1;
        y = y1;
        xEnd = x2;
    }
    else
    {
        x = x2;
        y = y2;
        xEnd = x1;
    }
    p = 2 * dy - dx;
    putpixel(round(x), round(y), 15);
    while (x <= xEnd)
    {
        x++;
        if (p < 0)
        {
            p += 2 * dy;
        }
        else
        {
            y++;
            p += 2 * dy - 2 * dx;
        }
        printf("%f %f\n", round(x), round(y));
        putpixel(round(x), round(y), 15);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    lineBSA(100, 100, 10, 50);
    getch();
    closegraph();
    return 0;
}