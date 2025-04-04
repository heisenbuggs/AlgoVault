struct Point {
    int x;
    int y;
};

// Finds squared euclidean distance between two points
int dist(Point &a, Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// Checks if angle ABC is a right angle
int isOrthogonal(Point &a, Point &b, Point &c) {
    return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
}

// Checks if ABCD form a rectangle (in that order)
int isRectangle(Point &a, Point &b, Point &c, Point &d) {
    return isOrthogonal(a, b, c) && isOrthogonal(b, c, d) && isOrthogonal(c, d, a);
}

// Checks if ABCD form a rectangle, in any orientation
int isRectangleAnyOrder(Point &a, Point &b, Point &c, Point &d) {
    return isRectangle(a, b, c, d) || isRectangle(b, c, a, d) | isRectangle(c, a, b, d);
}

// Checks if ABCD form a square (in that order)
int isSquare(Point &a, Point &b, Point &c, Point &d) {
    return isRectangle(a, b, c, d) && dist(a, b) == dist(b, c);
}

// Checks if ABCD form a square, in any orientation
int isSquareAnyOrder(Point &a, Point &b, Point &c, Point &d) {
    return isSquare(a, b, c, d) || isSquare(b, c, a, d) | isSquare(c, a, b, d);
}
