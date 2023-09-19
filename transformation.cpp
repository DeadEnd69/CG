#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159265358979323846

void translation(int, int, int, int, int, int);
void rotation(int, int, int, int, int);
void rotationArbitrary(int, int, int, int, int, int, int);
void scaling(int, int, int, int, int, int);
void reflection();
void shear_x(int);
void shear_y(int);

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int ch;
    printf("\n\n 1. Translation \n 2. Rotation \n 3. Rotation about arbitrary point \n 4. Scaling \n 5. Reflection \n 6. X-shear \n 7. Y-shear");
    printf("Enter your Choice (1,2,3,4,5,6,7): ");
    scanf("%d", &ch);

    if (ch == 1)

        translation(100, 100, 200, 200, 50, 25);
    else if (ch == 2)
        rotation(10, 100, 10, 200, -45);
    else if (ch == 3)
        rotationArbitrary(50, 50, 50, 200, 10, 20, -45);
    else if (ch == 4)
        scaling(10, 100, 25, 200, 5, 2);
    else if (ch == 5)
        reflection();
    else if (ch == 6)
        shear_x(2);
    else if (ch == 7)
        shear_y(2);
    else
        printf("\n\nInvalid Entry");

    getch();
    closegraph();
    return 0;
}
void shear_x(int shear_f)
{
    int x1 = 100, x2 = 100, x3 = 200;
    int y1 = 100, y2 = 150, y3 = 75;

    setcolor(14);
    outtextxy(x1 - 20, y1 - 20, "Original triangle");
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    setcolor(15);
    x1 = x1 + y1 * shear_f;
    x2 = x2 + y2 * shear_f;
    x3 = x3 + y3 * shear_f;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    outtextxy(x3 + 20, y3 + 20, "After x-shear");
}

void shear_y(int shear_f)
{
    int x1 = 50, x2 = 100, x3 = 200;
    int y1 = 50, y2 = 150, y3 = 75;

    setcolor(14);
    outtextxy(x1 - 20, y1 - 20, "Original triangle");
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    setcolor(15);
    y1 = y1 + x1 * shear_f;
    y2 = y2 + x2 * shear_f;
    y3 = y3 + x3 * shear_f;
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x3 + 20, y2 + 20, "After y-shear");
}

void reflection()
{
    int x1 = 100, x2 = 100, x3 = 200;
    int y1 = 100, y2 = 200, y3 = 100;

    setcolor(WHITE);
    line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);

    setcolor(YELLOW);
    outtextxy(x1 - 20, y1 - 20, "Original triangle");

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);

    // Reflection about origin
    setcolor(WHITE);
    outtextxy(getmaxx() / 2, getmaxy() / 2, "Center ");
    line(getmaxx() / 2 + x1, getmaxy() / 2 + y1, getmaxx() / 2 + x2, getmaxy() / 2 + y2);
    line(getmaxx() / 2 + x2, getmaxy() / 2 + y2, getmaxx() / 2 + x3, getmaxy() / 2 + y3);
    line(getmaxx() / 2 + x3, getmaxy() / 2 + y3, getmaxx() / 2 + x1, getmaxy() / 2 + y1);
    outtextxy(getmaxx() / 2 + x1, getmaxy() / 2 + y1 - 20, "Reflection about origin");

    // Reflection about x-axis
    setcolor(WHITE);
    line(getmaxx() / 2 - x1, getmaxy() / 2 + y1, getmaxx() / 2 - x2, getmaxy() / 2 + y2);
    line(getmaxx() / 2 - x2, getmaxy() / 2 + y2, getmaxx() / 2 - x3, getmaxy() / 2 + y3);
    line(getmaxx() / 2 - x3, getmaxy() / 2 + y3, getmaxx() / 2 - x1, getmaxy() / 2 + y1);
    outtextxy(getmaxx() / 2 - x3, getmaxy() / 2 + y1 - 20, "Reflection about x-axis");

    // Reflection about y-axis
    setcolor(WHITE);
    line(getmaxx() / 2 + x1, getmaxy() / 2 - y1, getmaxx() / 2 + x2, getmaxy() / 2 - y2);
    line(getmaxx() / 2 + x2, getmaxy() / 2 - y2, getmaxx() / 2 + x3, getmaxy() / 2 - y3);
    line(getmaxx() / 2 + x3, getmaxy() / 2 - y3, getmaxx() / 2 + x1, getmaxy() / 2 - y1);
    outtextxy(getmaxx() / 2 + x1, getmaxy() / 2 - y1 + 20, "Reflection about y-axis");
}

void translation(int x1, int y1, int x2, int y2, int tx, int ty)
{
    outtextxy(x1 - 2, y1 - 2, "Original Line");
    line(x1, y1, x2, y2);

    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;

    outtextxy(x2 + 2, y2 + 2, "Translated Line");
    line(x1, y1, x2, y2);
}

void rotation(int x1, int y1, int x2, int y2, int ang)
{
    outtextxy(x1 - 2, y1 - 2, "Original Line");
    line(x1, y1, x2, y2);

    double angle = ang * PI / 180.0;
    int x3 = x1 + (x2 - x1) * cos(angle) - (y2 - y1) * sin(angle);
    int y3 = y1 + (x2 - x1) * sin(angle) + (y2 - y1) * cos(angle);

    outtextxy(x3 + 2, y3 + 2, "Rotated Line");
    line(x1, y1, x3, y3);
}

void rotationArbitrary(int x1, int y1, int x2, int y2, int xr, int yr, int ang)
{
    outtextxy(x1 - 2, y1 - 2, "Original Line");
    line(x1, y1, x2, y2);

    double angle = ang * PI / 180.0;
    int x3 = xr + (x1 - xr) * cos(angle) - (y1 - yr) * sin(angle);
    int y3 = yr + (x1 - xr) * sin(angle) + (y1 - yr) * cos(angle);

    int x4 = xr + (x2 - xr) * cos(angle) - (y2 - yr) * sin(angle);
    int y4 = yr + (x2 - xr) * sin(angle) + (y2 - yr) * cos(angle);

    outtextxy(x4 + 2, y4 + 2, "Rotated Line about arbitrary point");
    line(x3, y3, x4, y4);
}

void scaling(int x1, int y1, int x2, int y2, int sx, int sy)
{
    outtextxy(x1 - 2, y1 - 2, "Original Line");
    line(x1, y1, x2, y2);

    x1 *= sx;
    y1 *= sy;
    x2 *= sx;
    y2 *= sy;

    outtextxy(x2 + 2, y2 + 2, "Scaled Line");
    line(x1, y1, x2, y2);
}