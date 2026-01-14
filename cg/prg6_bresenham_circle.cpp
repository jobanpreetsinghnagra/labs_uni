// Practical 6: Implementation of Bresenham's Circle Generation Algorithm

#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

void drawCirclePoints(int xc, int yc, int x, int y, int color = WHITE) {
    putpixel(xc + x, yc + y, color);
    putpixel(xc - x, yc + y, color);
    putpixel(xc + x, yc - y, color);
    putpixel(xc - x, yc - y, color);
    putpixel(xc + y, yc + x, color);
    putpixel(xc - y, yc + x, color);
    putpixel(xc + y, yc - x, color);
    putpixel(xc - y, yc - x, color);
}

void bresenhamCircle(int xc, int yc, int r, int color = WHITE) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    drawCirclePoints(xc, yc, x, y, color);

    while (x <= y) {
        x++;
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        drawCirclePoints(xc, yc, x, y, color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc, yc, r;
    cout << "Bresenham's Circle Generation Algorithm\n";
    cout << "Enter center (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius r: ";
    cin >> r;

    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);

    bresenhamCircle(xc, yc, r, WHITE);

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

