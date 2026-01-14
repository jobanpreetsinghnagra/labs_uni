// Practical 3: Implementation of DDA Line Drawing Algorithm
// Note: This example uses classic BGI-style graphics (graphics.h).
// Make sure you have a compatible graphics library (e.g., WinBGIm) set up in your environment.

#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>

using namespace std;

void ddaLine(int x1, int y1, int x2, int y2, int color = WHITE) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / static_cast<float>(steps);
    float yInc = dy / static_cast<float>(steps);

    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);

    putpixel(static_cast<int>(round(x)), static_cast<int>(round(y)), color);

    for (int i = 0; i < steps; ++i) {
        x += xInc;
        y += yInc;
        putpixel(static_cast<int>(round(x)), static_cast<int>(round(y)), color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2;
    cout << "DDA Line Drawing Algorithm\n";
    cout << "Enter x1 y1: ";
    cin >> x1 >> y1;
    cout << "Enter x2 y2: ";
    cin >> x2 >> y2;

    setbkcolor(BLACK);
    cleardevice();
    setcolor(WHITE);

    ddaLine(x1, y1, x2, y2, WHITE);

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

