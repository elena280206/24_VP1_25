//Шадчина Елена 24ВП1, курсовая работа, вариант 25
#include <iostream>
#include "FigureList.h"
#include "Triangle.h"
#include "Trapeze.h"
#include "Complex.h"

int main() {

    system("mode con cols=180 lines=60");
    system("color F0");
    SetConsoleTitle(L"Графические фигуры - 24VP2_25");
    setlocale(LC_ALL, "ru");

    try {
        FiguresList collection;

        Triangle* triangle = new Triangle(600, 200, 180, 250, RGB(255, 255, 255), RGB(128, 0, 128));
        Trapeze* trapeze = new Trapeze(600, 100, 180, 250, RGB(128, 0, 128), RGB(255, 0, 0));


        Figure* triPart = new Triangle(500, 400, 200, 200, RGB(0, 255, 255), RGB(0, 128, 128));
        Figure* trapPart = new Trapeze(500, 500, 100, 200, RGB(255, 0, 0), RGB(128, 0, 128));
        Complex* complexFig = new Complex(triPart, trapPart);


        collection.addFigures({ trapeze, triangle });
        collection.displayAll();
        collection.addFigures({ complexFig });

        triangle->draw();
        Sleep(1000);
        triangle->hide();
        Sleep(1000);
        triangle->move(850, 220);
        Sleep(1000);
        triangle->hide();


        trapeze->draw();
        Sleep(1000);
        trapeze->hide();
        Sleep(1000);
        trapeze->move(800, 320);
        Sleep(1000);
        trapeze->hide();


        complexFig->draw();
        Sleep(1500);
        collection.hide();
        Sleep(1000);
        complexFig->move(250, 220);
        collection.clearAll();
    }
    catch (const Figure::BorderException& e) {
        std::cerr << "Ошибка границы: " << e.what() << std::endl;
    }
    catch (const Figure::InvalidParameters& e) {
        std::cerr << "Ошибка параметров: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
