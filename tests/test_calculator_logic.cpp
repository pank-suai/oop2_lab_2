// Тест логики расчета стоимости компьютера
// Проверяет все критические сценарии без UI

#include <iostream>
#include <cassert>
#include <cmath>

// Константы из MainWindow
const int BASE_PRICE = 50000;
const int MONITOR_PRICE = 15000;
const int KEYBOARD_PRICE = 3000;
const int MOUSE_PRICE = 2000;
const int SPEAKERS_PRICE = 5000;
const double DISCOUNT_RATE = 0.10;

// Функция расчета (дублирует логику из mainwindow.cpp)
int calculatePrice(bool monitor, bool keyboard, bool mouse, bool speakers) {
    int componentsSum = 0;
    
    if (monitor) componentsSum += MONITOR_PRICE;
    if (keyboard) componentsSum += KEYBOARD_PRICE;
    if (mouse) componentsSum += MOUSE_PRICE;
    if (speakers) componentsSum += SPEAKERS_PRICE;
    
    bool allSelected = monitor && keyboard && mouse && speakers;
    
    int discount = 0;
    if (allSelected) {
        discount = static_cast<int>(componentsSum * DISCOUNT_RATE);
    }
    
    return BASE_PRICE + componentsSum - discount;
}

void test_scenario(const char* name, bool m, bool k, bool ms, bool s, int expected) {
    int result = calculatePrice(m, k, ms, s);
    std::cout << "Тест: " << name << " ... ";
    if (result == expected) {
        std::cout << "OK (" << result << " руб)\n";
    } else {
        std::cout << "ОШИБКА! Ожидалось: " << expected << ", получено: " << result << "\n";
        exit(1);
    }
}

int main() {
    std::cout << "=== Тестирование логики калькулятора ===\n\n";
    
    // Критические сценарии
    test_scenario("Только компьютер", false, false, false, false, 50000);
    test_scenario("Компьютер + Монитор", true, false, false, false, 65000);
    test_scenario("Компьютер + Монитор + Клавиатура", true, true, false, false, 68000);
    test_scenario("Компьютер + Монитор + Клавиатура + Мышь", true, true, true, false, 70000);
    test_scenario("ВСЕ (со скидкой 10%)", true, true, true, true, 72500);
    
    // Проверка что скидка НЕ применяется при неполном наборе
    test_scenario("3 из 4 (без скидки)", true, true, true, false, 70000);
    test_scenario("2 из 4 (без скидки)", true, true, false, false, 68000);
    
    std::cout << "\n✓ Все тесты пройдены успешно!\n";
    return 0;
}
