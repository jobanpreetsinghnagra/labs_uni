// Practical 10: Line Clipping using Cohen-Sutherland Algorithm

#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

// Region codes
const int INSIDE = 0; // 0000
const int LEFT   = 1; // 0001
const int RIGHT  = 2; // 0010
const int BOTTOM = 4; // 0100
const int TOP    = 8; // 1000

int xmin, ymin, xmax, ymax;

int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;
    return code;
}

void cohenSutherlandLineClipAndDraw(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int codeOut;
            int x, y;

            if (code1 != 0)
                codeOut = code1;
            else
                codeOut = code2;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            } else {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(GREEN);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2;
    cout << "Cohen-Sutherland Line Clipping\n";
    cout << "Enter clipping window (xmin ymin xmax ymax): ";
    cin >> xmin >> ymin >> xmax >> ymax;
    cout << "Enter line endpoints (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    cleardevice();
    setbkcolor(BLACK);

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line in RED
    setcolor(RED);
    line(x1, y1, x2, y2);

    // Clip and draw in GREEN
    cohenSutherlandLineClipAndDraw(x1, y1, x2, y2);

    outtextxy(10, 10, (char*)"Red: Original line, Green: Clipped line");

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

