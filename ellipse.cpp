#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void setPixel(int, int, int, int);
void directEllipse(int, int, int, int);
void trigonometicEllipse(int, int, int, int);
void midPointEllipse(int, int, int, int);

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    outtextxy(50, 100, "With direct ellipse algorithms");
    trigonometicEllipse(300, 300, 50, 75);
    outtextxy(350, 300, "With trignometric ellipse algorithms");
    midPointEllipse(500, 100, 50, 75);
    outtextxy(400, 100, "With mid point ellipse algorithms");
    getch();
    return 0;
    // Program by Animesh Acharya BSC. CSIT
}

void midPointEllipse(int xc, int yc, int a, int b)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = b;
    // Initial decision parameter of region 1
    d1 = (b * b) - (a * a * b) + (0.25 * a * a);
    dx = 2 * b * b * x;
    dy = 2 * a * a * y;
    // For region 1
    while (dx < dy)
    {
        setPixel(x, y, xc, yc);
        // Checking and updating value of decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = (2 * b * b) * x;
            d1 = d1 + dx + (b * b);
        }
        else
        {
            y--;
            x++;
            dx = (2 * b * b) * x;
            dy = (2 * a * a) * y;
            d1 = d1 + dx - dy + (b * b);
        }
    }

    // Decision parameter of region 2
    d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) + ((a * a) * ((y - 1) * (y - 1))) - (a * a * b * b);
    // Plotting points of region 2
    while (y >= 0)
    {
        setPixel(x, y, xc, yc);
        // Checking and updating parameter value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = (2 * a * a) * y;
            d2 = d2 + (b * b) - dy;
        }
        else
        {
            x++;
            y--;
            dx = (2 * b * b) * x;
            dy = (2 * a * a) * y;
            d2 = d2 + dx - dy + (a * a);
        }
    }
}

void trigonometicEllipse(int h, int k, int a, int b)
{
    double x, y, ang = 0;
    x = 0, y = b;

    while (ang <= 45)
    {
        setPixel(floor(x), floor(y), h, k);

        x = a * cos(ang);
        y = b * sin(ang);

        ang = ang + 0.01;
    }
}
void directEllipse(int h, int k, int a, int b)
{
    float x = 0, y = b;
    float x1 = 1 - ((x * x) / (a * a));
    float y1 = b * sqrt(x1);

    while (y >= 0)
    {
        setPixel(x, y, h, k);

        x += 0.5;
        x1 = 1 - ((x * x) / (a * a));
        y = b * sqrt(x1);
    }
}

void setPixel(int x, int y, int h, int k)
{
    putpixel(x + h, y + k, 15);
    putpixel(x + h, -y + k, 15);
    putpixel(-x + h, y + k, 15);
    putpixel(-x + h, -y + k, 15);
}