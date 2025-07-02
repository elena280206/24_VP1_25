#include "FigureList.h"

void FiguresList::addFigures(std::initializer_list<Figure*> figs) {
    for (auto fig : figs) {
        figures.push_back(fig);
    }
}

void FiguresList::displayAll() const {
    system("cls");
    for (auto fig : figures) {
        fig->draw();
        Sleep(1000);
    }
}

void FiguresList::hide() {
    for (auto figure : figures) {
        figure->hide();
        Sleep(600);
    }
}

void FiguresList::clearAll() {
    figures.clear();
}