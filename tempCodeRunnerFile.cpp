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