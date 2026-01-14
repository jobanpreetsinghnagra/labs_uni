// Practical 5: Implementation of Mid-Point Circle Generation Algorithm

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

void midpointCircle(int xc, int yc, int r, int color = WHITE) {
    int x = 0;
    int y = r;
    int p = 1 - r;

    drawCirclePoints(xc, yc, x, y, color);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawCirclePoints(xc, yc, x, y, color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int xc, yc, r;
    cout << "Mid-Point Circle Generation Algorithm\n";
    cout << "Enter center (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius r: ";
    cin >> r;

    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);

    midpointCircle(xc, yc, r, WHITE);

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

