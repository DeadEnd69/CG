#include <graphics.h>
#include <conio.h>
#include <math.h>
void setPixels(int x, int y, int xCenter, int yCenter)
{
	putpixel(xCenter + x, yCenter + y, 15);
	putpixel(xCenter - x, yCenter + y, 15);
	putpixel(xCenter + x, yCenter - y, 15);
	putpixel(xCenter - x, yCenter - y, 15);
	putpixel(xCenter + y, yCenter + x, 15);
	putpixel(xCenter - y, yCenter + x, 15);
	putpixel(xCenter + y, yCenter - x, 15);
	putpixel(xCenter - y, yCenter - x, 15);
}
void midPointCircle(int xc, int yc, int radius)
{
	float p, x = 0, y = radius;
	p = 1 - radius;

	while (x < y)
	{
		printf("(%f, %f)\n", x, y);
		printf("p= %f", p);
		printf("\n\n------------------------------------------\n\n");

		setPixels(x, y, xc, yc);
		x++;
		if (p < 0)
		{
			p += 2 * x + 3;
		}
		else
		{
			y--;
			p += 2 * x + 5 - 2 * y;
		}
	}
}

void directCircle(int xCenter, int yCenter, int radius)
{
	double x = 0, y = radius;

	while (pow(x, 2) < pow(radius, 2))
	{
		setPixels(floor(x), floor(y), xCenter, yCenter);
		x++;
		y = pow(pow(radius, 2) - pow(x, 2), 0.5);
		printf("%f %f %d\n", x, y, radius);
	}
}

void trigonoCircle(int xCenter, int yCenter, int radius)
{
	float x = 0, y = radius;
	float deg;
	while (deg <= 45)
	{
		setPixels(x, y, xCenter, yCenter);
		deg += 0.009;
		x = radius * cos(deg);
		y = radius * sin(deg);
	}
}
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, (char *)"");
	midPointCircle(0, 0, 10);
	outtextxy(50, 050, "With Mid-point circle algorithm");
	directCircle(100, 300, 50);
	outtextxy(50, 350, "With direct circle algorithm");
	trigonoCircle(400, 100, 50);
	outtextxy(350, 150, "With trignometric circle algorthm");
	getch();
	closegraph();
	return 0;
}
