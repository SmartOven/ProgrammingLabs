#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "lab_4.h"
using std::cout;
using std::cin;

int menu() {
    std::cout << "/----------SELECT_ACTION----------/\n\n";
    std::cout << "1 - Add figure\n";
    std::cout << "2 - Show all figures\n";
    std::cout << "3 - Sum all figure's squares\n";
    std::cout << "4 - Sum all figure's perimeters\n";
    std::cout << "5 - Show figure's mass' center\n";
    std::cout << "6 - Show count of memory from all classes\n";
    std::cout << "7 - Sort all figures by mass\n";
    std::cout << "8 - Exit from program\n";
    int action;
    std::cin >> action;
    action = static_cast<int>(action);
    while (action < 1 || action > 8) {
        std::cout << "Error, no such command in list!!! Try again!\n";
        std::cin >> action;
    }
    return action;
};
int FigureSELECT() {
    while (true) {
        std::cout << "/-----Select_type_of_figure-----/\n";
        std::cout << "1 - Hexagon\n";
        std::cout << "2 - Ellipse\n";
        int select;
        std::cin >> select;
        if (select < 1 || select > 2) {
            std::cout << "Error, no such command in list!!! Try again!\n";
            continue;
        }
        return select;
    }
}
int main() {
    std::vector <Figure*> figures;
    size_t count = 0;
    while (true) {
        const int command = menu();
        switch (command) {
        case 1: {
            const int select = FigureSELECT();
            if (select == 1) {
                figures.push_back(new Hexagon);
                figures[count]->initFromDialog();
                count++;
            }
            else {
                figures.push_back(new Ellipse);
                figures[count]->initFromDialog();
                count++;
            }
            break;
        }
        case 2: {
            for (auto& figure : figures) {
                std::cout << figure->classname() << "\n";
            }
            break;
        }

        case 3: {
            double sum = 0;
            for (auto& figure : figures) {
                sum += figure->square();
            }
            std::cout << "Sum of all figure's squares is - " << sum << '\n';
            break;
        }

        case 4: {
            double sum = 0;
            for (auto& figure : figures) {
                sum += figure->perimeter();
            }
            std::cout << "Sum of all figure's perimeters is - " << sum << '\n';
            break;
        }
        case 5: {
            Vector2D mass_center;
            double mass = 0;
            for (auto& figure : figures) {
                Vector2D buffer = figure->position() * figure->mass();
                mass_center += buffer;
                mass += figure->mass();
            }
            std::cout << "Center is ";
            mass_center /= mass;
            mass_center.print();
            break;
        }
        case 6: {
            unsigned int countMemory = 0;
            for (auto& figure : figures) {
                countMemory += figure->size();
            }
            std::cout << "Count of memory for this system is - " << countMemory << '\n';
            break;
        }
        case 7: {
            std::sort(figures.begin(), figures.end(),
                [](Figure* a, Figure* b)
                {
                    return (a->mass() < b->mass());
                });
            std::cout << "All figures was successfully sorted\n";
            break;
        }
        default:
            std::cout << "Done!\n";
            return 0;
        }
    }
}