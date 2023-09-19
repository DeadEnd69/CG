#include <stdio.h>
#include <graphics.h>
#include <math.h>

void lineDDA(int x1, int y1, int x2, int y2)
{
    float dx, dy, steps, x = x1, y = y1, inx, iny;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = (abs(dy) > abs(dx)) ? abs(dy) : abs(dx);
    inx = dx / steps;
    iny = dy / steps;
    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), 15);

        printf("%f %f\n", round(x), round(y));
        x += inx;
        y += iny;
    }
}
void BSA(int x1, int y1, int x2, int y2)
{
    int dx, dy;
    float p, x, y, xEnd, slope;
    /*
        dx = x2 - x1;
        dy = y1 - y2;
        if (dy < 0)
        {
            dy = -y2 - (-y1);
        }
        if (dx < 0)
        {
            dx = -x2 - (-x1);
        }
    */

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (x1 > x2)
    {
        x1 = -x1;
        x2 = -x2;
    }
    if (y1 > y2)
    {
        y1 = -y1;
        y2 = -y2;
    }

    // slope = dy / dx;
    if (dx >= dy)
    {

        p = 2 * dy - dx;
    }
    else
    {
        p = 2 * dx - dy;
    }
    if ((x1) < (x2))
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
    while (x <= xEnd)
    {
        putpixel(abs(round(x)), abs(round(y)), 15);
        printf("The value of p is %f\n", p);
        printf("%f %f\n", abs(x), abs(y));
        x += 1;
        if (p < 0)
        {
            p += 2 * dy;
        }
        else
        {
            y++;
            p += 2 * dy - 2 * dx;
        }
        // putpixel(round(x), round(y), 15);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    BSA(10, 50, 300, 300);
    outtextxy(300, 300, "BSA Algorithm");
    lineDDA(100, 00, 100, 400);
    outtextxy(100, 400, "DDA Algorithm");
    getch();
    closegraph();

    return 0;
}