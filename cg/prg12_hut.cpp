// Practical 12: Program to draw a Hut (geometrical figure)

#include <graphics.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    cleardevice();
    setbkcolor(BLACK);

    // Base of hut (rectangle)
    setcolor(WHITE);
    int left = 150, top = 200, right = 350, bottom = 350;
    rectangle(left, top, right, bottom);

    // Door
    int dleft = 220, dtop = 260, dright = 280, dbottom = bottom;
    rectangle(dleft, dtop, dright, dbottom);

    // Window
    int wleft = 170, wtop = 230, wright = 210, wbottom = 270;
    rectangle(wleft, wtop, wright, wbottom);
    line(wleft, (wtop + wbottom) / 2, wright, (wtop + wbottom) / 2);
    line((wleft + wright) / 2, wtop, (wleft + wright) / 2, wbottom);

    // Roof (triangle)
    line(left, top, (left + right) / 2, 120);
    line((left + right) / 2, 120, right, top);

    // Side extension (small room)
    int sleft = right, stop = 230, sright = right + 120, sbottom = bottom;
    rectangle(sleft, stop, sright, sbottom);
    // Roof of side room
    line(right, stop, (right + sright) / 2, 150);
    line((right + sright) / 2, 150, sright, stop);

    outtextxy(10, 10, (char*)"Simple Hut Drawing");

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

