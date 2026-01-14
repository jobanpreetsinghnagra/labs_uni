// Practical 9: Polygon Filling - Flood-fill, Boundary-fill, and Scan-line algorithms

#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <vector>

using namespace std;

// Recursive flood fill (4-connected)
void floodFill(int x, int y, int oldColor, int newColor) {
    int current = getpixel(x, y);
    if (current != oldColor || current == newColor)
        return;

    putpixel(x, y, newColor);
    floodFill(x + 1, y, oldColor, newColor);
    floodFill(x - 1, y, oldColor, newColor);
    floodFill(x, y + 1, oldColor, newColor);
    floodFill(x, y - 1, oldColor, newColor);
}

// Recursive boundary fill (4-connected)
void boundaryFill(int x, int y, int boundaryColor, int fillColor) {
    int current = getpixel(x, y);
    if (current == boundaryColor || current == fillColor)
        return;

    putpixel(x, y, fillColor);
    boundaryFill(x + 1, y, boundaryColor, fillColor);
    boundaryFill(x - 1, y, boundaryColor, fillColor);
    boundaryFill(x, y + 1, boundaryColor, fillColor);
    boundaryFill(x, y - 1, boundaryColor, fillColor);
}

// Simple scan-line fill for convex polygon
void scanlineFill(const vector<int> &x, const vector<int> &y, int n, int fillColor) {
    int ymax = y[0], ymin = y[0];
    for (int i = 1; i < n; ++i) {
        if (y[i] > ymax) ymax = y[i];
        if (y[i] < ymin) ymin = y[i];
    }

    for (int scanY = ymin; scanY <= ymax; ++scanY) {
        vector<int> intersections;
        for (int i = 0; i < n; ++i) {
            int x1 = x[i], y1 = y[i];
            int x2 = x[(i + 1) % n], y2 = y[(i + 1) % n];

            if (y1 == y2) continue;
            if (scanY < min(y1, y2) || scanY > max(y1, y2)) continue;

            float m = (float)(x2 - x1) / (float)(y2 - y1);
            int xi = static_cast<int>(x1 + m * (scanY - y1));
            intersections.push_back(xi);
        }

        sort(intersections.begin(), intersections.end());
        for (size_t k = 0; k + 1 < intersections.size(); k += 2) {
            int xs = intersections[k];
            int xe = intersections[k + 1];
            for (int xval = xs; xval <= xe; ++xval) {
                putpixel(xval, scanY, fillColor);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int n;
    cout << "Polygon Filling Algorithms\n";
    cout << "Enter number of vertices (convex polygon): ";
    cin >> n;

    vector<int> x(n), y(n);
    cout << "Enter vertices (x y) in order:\n";
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);

    // Draw polygon outline
    for (int i = 0; i < n; ++i) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }

    // Demonstrate scan-line fill
    scanlineFill(x, y, n, GREEN);

    // Demonstrate flood-fill at a point inside the polygon (user-specified)
    int seedx, seedy;
    cout << "Enter seed point inside polygon for flood-fill (x y): ";
    cin >> seedx >> seedy;
    int oldColor = getpixel(seedx, seedy);
    floodFill(seedx, seedy, oldColor, BLUE);

    // Demonstrate boundary-fill on same polygon (re-draw boundary)
    cleardevice();
    setcolor(RED);
    for (int i = 0; i < n; ++i) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
    cout << "Enter seed point inside polygon for boundary-fill (x y): ";
    cin >> seedx >> seedy;
    boundaryFill(seedx, seedy, RED, YELLOW);

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

