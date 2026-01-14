// Practical 8: 2D Transformations - Scaling, Rotation, Mirror Reflection, Shearing
// Demonstrates various transformations on a triangle.

#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    float x, y;
};

void drawTriangle(const Point &p1, const Point &p2, const Point &p3, int color) {
    setcolor(color);
    line(static_cast<int>(p1.x), static_cast<int>(p1.y),
         static_cast<int>(p2.x), static_cast<int>(p2.y));
    line(static_cast<int>(p2.x), static_cast<int>(p2.y),
         static_cast<int>(p3.x), static_cast<int>(p3.y));
    line(static_cast<int>(p3.x), static_cast<int>(p3.y),
         static_cast<int>(p1.x), static_cast<int>(p1.y));
}

Point scale(const Point &p, float sx, float sy) {
    Point r;
    r.x = p.x * sx;
    r.y = p.y * sy;
    return r;
}

Point rotate(const Point &p, float angleDeg) {
    float rad = angleDeg * 3.14159f / 180.0f;
    Point r;
    r.x = p.x * cos(rad) - p.y * sin(rad);
    r.y = p.x * sin(rad) + p.y * cos(rad);
    return r;
}

Point reflectX(const Point &p) {
    Point r = p;
    r.y = -r.y;
    return r;
}

Point reflectY(const Point &p) {
    Point r = p;
    r.x = -r.x;
    return r;
}

Point shearX(const Point &p, float shx) {
    Point r;
    r.x = p.x + shx * p.y;
    r.y = p.y;
    return r;
}

Point shearY(const Point &p, float shy) {
    Point r;
    r.x = p.x;
    r.y = p.y + shy * p.x;
    return r;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    Point p1, p2, p3;
    cout << "2D Transformations of Triangle\n";
    cout << "Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ";
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    cleardevice();
    setbkcolor(BLACK);

    // Draw original triangle in WHITE
    drawTriangle(p1, p2, p3, WHITE);

    // Scaling
    float sx, sy;
    cout << "Enter scaling factors sx sy: ";
    cin >> sx >> sy;
    Point ps1 = scale(p1, sx, sy);
    Point ps2 = scale(p2, sx, sy);
    Point ps3 = scale(p3, sx, sy);
    drawTriangle(ps1, ps2, ps3, YELLOW);

    // Rotation
    float angle;
    cout << "Enter rotation angle in degrees: ";
    cin >> angle;
    Point pr1 = rotate(p1, angle);
    Point pr2 = rotate(p2, angle);
    Point pr3 = rotate(p3, angle);
    drawTriangle(pr1, pr2, pr3, GREEN);

    // Reflection about X-axis
    Point rx1 = reflectX(p1);
    Point rx2 = reflectX(p2);
    Point rx3 = reflectX(p3);
    drawTriangle(rx1, rx2, rx3, CYAN);

    // Shearing in X-direction
    float shx;
    cout << "Enter shearing factor shx (X-direction): ";
    cin >> shx;
    Point sh1 = shearX(p1, shx);
    Point sh2 = shearX(p2, shx);
    Point sh3 = shearX(p3, shx);
    drawTriangle(sh1, sh2, sh3, MAGENTA);

    outtextxy(10, 10, (char*)"White: Original, Yellow: Scaled, Green: Rotated");
    outtextxy(10, 25, (char*)"Cyan: Reflected (X-axis), Magenta: Sheared (X)");

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

