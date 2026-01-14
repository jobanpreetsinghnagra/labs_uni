// Practical 4: Implementation of Bresenham's Line Drawing Algorithm

#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>

using namespace std;

void bresenhamLine(int x1, int y1, int x2, int y2, int color = WHITE) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    bool isSteep = dy > dx;
    if (isSteep) {
        swap(dx, dy);
    }

    int p = 2 * dy - dx;
    int x = x1;
    int y = y1;

    for (int i = 0; i <= dx; ++i) {
        putpixel(x, y, color);
        if (p >= 0) {
            if (isSteep)
                x += sx;
            else
                y += sy;
            p -= 2 * dx;
        }
        if (isSteep)
            y += sy;
        else
            x += sx;
        p += 2 * dy;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2;
    cout << "Bresenham's Line Drawing Algorithm\n";
    cout << "Enter x1 y1: ";
    cin >> x1 >> y1;
    cout << "Enter x2 y2: ";
    cin >> x2 >> y2;

    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);

    bresenhamLine(x1, y1, x2, y2, WHITE);

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

