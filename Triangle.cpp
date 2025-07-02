#include "Triangle.h"

Triangle::Triangle(int x, int y, int a, int b, COLORREF bg, COLORREF border)
    : Figure(x, y, a, b, bg, border) {
    if (a <= 0 || b <= 0) {
        throw InvalidParameters("Параметры треугольника должны быть положительными");
    }

}

void Triangle::draw() {
    points[0] = { position.x, position.y };
    points[1] = { position.x, position.y + height };
    points[2] = { position.x + widthL, position.y + height };

    if (points[0].x < windowRect.left || points[0].y < windowRect.top || points[1].y > windowRect.bottom ||
        points[2].x > windowRect.right) {
        throw BorderException("Треугольник достиг границ окна");
    }

    HPEN pen = CreatePen(PS_SOLID, 3, borderColor);
    HBRUSH brush = CreateSolidBrush(bgColor);
    SelectObject(hDC, pen);
    SelectObject(hDC, brush);

    POINT winPoints[3] = { {points[0].x, points[0].y},
                          {points[1].x, points[1].y},
                          {points[2].x, points[2].y} };
    Polygon(hDC, winPoints, 3);

    DeleteObject(pen);
    DeleteObject(brush);
}

void Triangle::hide() {
    HPEN pen = CreatePen(PS_SOLID, 3, RGB(240, 240, 240));
    HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
    SelectObject(hDC, pen);
    SelectObject(hDC, brush);

    POINT winPoints[3] = { {points[0].x, points[0].y},
                         {points[1].x, points[1].y},
                         {points[2].x, points[2].y} };
    Polygon(hDC, winPoints, 3);

    DeleteObject(pen);
    DeleteObject(brush);
}