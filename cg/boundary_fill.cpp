#include <stdio.h>
#include <graphics.h>
#include <dos.h>

/*
 * Boundary Fill Algorithm (Recursive, 4-connected)
 * Fills a region bounded by 'boundary_color' with 'fill_color'
 * starting from seed point (x, y)
 */
void boundaryFill4(int x, int y, int fill_color, int boundary_color) {
    int current = getpixel(x, y);

    if (current != boundary_color && current != fill_color) {
        putpixel(x, y, fill_color);
        delay(1); /* Small delay so you can see the fill happen */

        boundaryFill4(x + 1, y,     fill_color, boundary_color);
        boundaryFill4(x - 1, y,     fill_color, boundary_color);
        boundaryFill4(x,     y + 1, fill_color, boundary_color);
        boundaryFill4(x,     y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    /* Draw a closed boundary shape (rectangle) in WHITE */
    setcolor(WHITE);
    rectangle(100, 100, 300, 250);

    /* Draw a circle boundary in WHITE */
    circle(450, 175, 70);

    outtextxy(10, 10, "Boundary Fill Demo");
    outtextxy(10, 20, "Filling rectangle and circle...");

    delay(1000);

    /* Fill the rectangle with RED (boundary = WHITE) */
    boundaryFill4(200, 175, RED, WHITE);

    /* Fill the circle with CYAN (boundary = WHITE) */
    boundaryFill4(450, 175, CYAN, WHITE);

    outtextxy(10, 30, "Done! Press any key.");
    getch();

    closegraph();
    return 0;
}
