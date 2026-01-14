// Practical 11: Polygon Clipping using Sutherland-Hodgman Algorithm

#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <vector>

using namespace std;

struct Point2D {
    float x, y;
};

enum Edge { LEFT_EDGE, RIGHT_EDGE, BOTTOM_EDGE, TOP_EDGE };

int xminSH, yminSH, xmaxSH, ymaxSH;

bool inside(const Point2D &p, Edge edge) {
    switch (edge) {
        case LEFT_EDGE:   return p.x >= xminSH;
        case RIGHT_EDGE:  return p.x <= xmaxSH;
        case BOTTOM_EDGE: return p.y >= yminSH;
        case TOP_EDGE:    return p.y <= ymaxSH;
    }
    return false;
}

Point2D intersect(const Point2D &p1, const Point2D &p2, Edge edge) {
    Point2D i;
    float m = (p2.x - p1.x) / (p2.y - p1.y + 0.00001f);

    switch (edge) {
        case LEFT_EDGE:
            i.x = xminSH;
            i.y = p1.y + (xminSH - p1.x) / ( (p2.x - p1.x) / (p2.y - p1.y + 0.00001f) );
            break;
        case RIGHT_EDGE:
            i.x = xmaxSH;
            i.y = p1.y + (xmaxSH - p1.x) / ( (p2.x - p1.x) / (p2.y - p1.y + 0.00001f) );
            break;
        case BOTTOM_EDGE:
            i.y = yminSH;
            i.x = p1.x + (p2.x - p1.x) * (yminSH - p1.y) / (p2.y - p1.y + 0.00001f);
            break;
        case TOP_EDGE:
            i.y = ymaxSH;
            i.x = p1.x + (p2.x - p1.x) * (ymaxSH - p1.y) / (p2.y - p1.y + 0.00001f);
            break;
    }
    return i;
}

vector<Point2D> clipWithEdge(const vector<Point2D> &poly, Edge edge) {
    vector<Point2D> output;
    if (poly.empty()) return output;

    Point2D S = poly.back();
    for (const auto &E : poly) {
        if (inside(E, edge)) {
            if (inside(S, edge)) {
                output.push_back(E);
            } else {
                Point2D i = intersect(S, E, edge);
                output.push_back(i);
                output.push_back(E);
            }
        } else if (inside(S, edge)) {
            Point2D i = intersect(S, E, edge);
            output.push_back(i);
        }
        S = E;
    }
    return output;
}

void drawPolygon(const vector<Point2D> &poly, int color) {
    setcolor(color);
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        int x1 = static_cast<int>(poly[i].x);
        int y1 = static_cast<int>(poly[i].y);
        int x2 = static_cast<int>(poly[(i + 1) % n].x);
        int y2 = static_cast<int>(poly[(i + 1) % n].y);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int n;
    cout << "Sutherland-Hodgman Polygon Clipping\n";
    cout << "Enter clipping window (xmin ymin xmax ymax): ";
    cin >> xminSH >> yminSH >> xmaxSH >> ymaxSH;

    cout << "Enter number of vertices of polygon: ";
    cin >> n;
    vector<Point2D> poly(n);
    cout << "Enter vertices (x y) in order:\n";
    for (int i = 0; i < n; ++i) {
        cin >> poly[i].x >> poly[i].y;
    }

    cleardevice();
    setbkcolor(BLACK);

    // Draw clipping window
    setcolor(WHITE);
    rectangle(xminSH, yminSH, xmaxSH, ymaxSH);

    // Draw original polygon in RED
    drawPolygon(poly, RED);

    // Perform clipping
    vector<Point2D> clipped = clipWithEdge(poly, LEFT_EDGE);
    clipped = clipWithEdge(clipped, RIGHT_EDGE);
    clipped = clipWithEdge(clipped, BOTTOM_EDGE);
    clipped = clipWithEdge(clipped, TOP_EDGE);

    // Draw clipped polygon in GREEN
    drawPolygon(clipped, GREEN);

    outtextxy(10, 10, (char*)"Red: Original polygon, Green: Clipped polygon");

    cout << "Press any key to exit...";
    getch();
    closegraph();
    return 0;
}

