#include "ComputerCalculator.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printHeader() {
    std::cout << "========================================" << std::endl;
    std::cout << "  Расчет стоимости компьютера" << std::endl;
    std::cout << "  Панков Вячеслав Дмитриевич, группа М412" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;
}

void printComponents(ComputerCalculator& calculator) {
    std::cout << "Основное изделие:" << std::endl;
    std::cout << "  [X] Компьютер - " << calculator.getBasePrice() << " руб" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Комплектующие:" << std::endl;
    auto& components = calculator.getComponents();
    for (size_t i = 0; i < components.size(); ++i) {
        std::cout << "  " << (i + 1) << ". ";
        std::cout << "[" << (components[i].isChecked() ? "X" : " ") << "] ";
        std::cout << components[i].getName() << " - ";
        std::cout << components[i].getPrice() << " руб" << std::endl;
    }
    std::cout << std::endl;
}

void printCalculation(ComputerCalculator& calculator) {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Расчет:" << std::endl;
    std::cout << "  Основное изделие: " << calculator.getBasePrice() << " руб" << std::endl;
    std::cout << "  Сумма комплектующих: " << calculator.getComponentsSum() << " руб" << std::endl;
    
    int discount = calculator.getDiscount();
    if (discount > 0) {
        std::cout << "  Скидка (10%): -" << discount << " руб" << std::endl;
    } else {
        std::cout << "  Скидка: 0 руб" << std::endl;
    }
    
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "  ИТОГО: " << calculator.getTotalPrice() << " руб" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
    
    if (calculator.allComponentsChecked()) {
        std::cout << "* Применена скидка 10% на все комплектующие!" << std::endl;
        std::cout << std::endl;
    }
}

void printMenu() {
    std::cout << "Выберите действие:" << std::endl;
    std::cout << "  1-4: Переключить комплектующее" << std::endl;
    std::cout << "  0: Выход" << std::endl;
    std::cout << "Ваш выбор: ";
}

int main() {
    ComputerCalculator calculator(50000);
    
    calculator.addComponent(Component("Монитор", 15000));
    calculator.addComponent(Component("Клавиатура", 3000));
    calculator.addComponent(Component("Мышь", 2000));
    calculator.addComponent(Component("Колонки", 5000));
    
    while (true) {
        clearScreen();
        printHeader();
        printComponents(calculator);
        printCalculation(calculator);
        printMenu();
        
        int choice;
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        if (choice == 0) {
            std::cout << std::endl << "Программа завершена." << std::endl;
            break;
        }
        
        if (choice >= 1 && choice <= 4) {
            calculator.getComponents()[choice - 1].toggle();
        }
    }
    
    return 0;
}
