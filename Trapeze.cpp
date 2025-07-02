#include "Trapeze.h"

Trapeze::Trapeze(int x, int y, int a, int b, COLORREF bg, COLORREF border)
    : Figure(x, y, a, b, bg, border) {
    if (a <= 0 || b <= 0) {
        throw InvalidParameters("Параметры трапеции должны быть положительными");
    }
}

void Trapeze::draw() {
    points[0] = { position.x, position.y };
    points[1] = { position.x, position.y + height };
    points[2] = { position.x + widthL, position.y + height };
    points[3] = { position.x + widthT, position.y };

    if (points[0].x < windowRect.left || points[1].y > windowRect.bottom ||
        points[2].x > windowRect.right || points[3].y < windowRect.top) {
        throw BorderException("Трапеция достигла границ окна");
    }

    HPEN pen = CreatePen(PS_SOLID, 3, borderColor);
    HBRUSH brush = CreateSolidBrush(bgColor);
    SelectObject(hDC, pen);
    SelectObject(hDC, brush);

    POINT winPoints[4] = { {points[0].x, points[0].y},
                         {points[1].x, points[1].y},
                         {points[2].x, points[2].y},
                         {points[3].x, points[3].y} };
    Polygon(hDC, winPoints, 4);

    DeleteObject(pen);
    DeleteObject(brush);
}

void Trapeze::hide() {
    HPEN pen = CreatePen(PS_SOLID, 3, RGB(240, 240, 240));
    HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
    SelectObject(hDC, pen);
    SelectObject(hDC, brush);

    POINT winPoints[4] = { {points[0].x, points[0].y},
                         {points[1].x, points[1].y},
                         {points[2].x, points[2].y},
                         {points[3].x, points[3].y} };
    Polygon(hDC, winPoints, 4);

    DeleteObject(pen);
    DeleteObject(brush);
}