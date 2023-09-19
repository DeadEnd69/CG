// DDA line algorithms:

/*
	1) Get the inputs of two end points
	2) Calculate the difference between two end points dx and dy.
	3) Based on calculated difference, if dx> dy, steps=dx and vice versa
	4) Now calculate the incrementing value
	5) Run a loop and increment the value
*/

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
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
		putpixel(round(x), round(y), 1);

		printf("%f %f\n", round(x), round(y));
		x += inx;
		y += iny;
	}
}

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc\\bgi");
	lineDDA(10, 12, 90, 80);

	outtextxy(100, 100, "DDA Algorthms");
	//	closegraph();
	_getch();
	return 0;
}
