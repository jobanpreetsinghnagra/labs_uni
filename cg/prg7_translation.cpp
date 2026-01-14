// Practical 7: 2D Transformation - Translation
// Demonstrates translation of a triangle.

#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

void drawTriangle(const Point &p1, const Point &p2, const Point &p3, int color) {
    setcolor(color);
    line(p1.x, p1.y, p2.x, p2.y);
    line(p2.x, p2.y, p3.x, p3.y);
    line(p3.x, p3.y, p1.x, p1.y);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    Point p1, p2, p3;
    int tx, ty;

    cout << "2D Translation of Triangle\n";
    cout << "Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << "Enter translation factors tx ty: ";
    cin >> tx >> ty;

    cleardevice();
    setbkcolor(BLACK);

    // Original triangle in WHITE
    drawTriangle(p1, p2, p3, WHITE);

    // Translated triangle in YELLOW
    Point p1t = {p1.x + tx, p1.y + ty};
    Point p2t = {p2.x + tx, p2.y + ty};
    Point p3t = {p3.x + tx, p3.y + ty};
    drawTriangle(p1t, p2t, p3t, YELLOW);

    outtextxy(10, 10, (char*)"White: Original, Yellow: Translated");

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

