#!/usr/bin/env python3
"""
UI тест для проверки Qt приложения калькулятора
Использует визуальную верификацию через скриншоты
"""

import subprocess
import time
import os
import sys

def run_command(cmd):
    """Выполнение команды shell"""
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    return result.stdout.strip()

def take_screenshot(name):
    """Создание скриншота окна"""
    filename = f"images/test_{name}.png"
    cmd = f"screencapture -x {filename}"
    run_command(cmd)
    print(f"  ✓ Скриншот сохранен: {filename}")
    time.sleep(0.5)

def verify_window_title():
    """Проверка заголовка окна"""
    print("\n[Тест] Проверка заголовка окна...")
    # Получаем заголовок активного окна
    cmd = """osascript -e 'tell application "System Events" to get name of first window of (first process whose frontmost is true)'"""
    title = run_command(cmd)
    
    if "Панков Вячеслав Дмитриевич" in title and "М412" in title:
        print(f"  ✓ Заголовок корректен: {title}")
        return True
    else:
        print(f"  ✗ ОШИБКА: Заголовок не содержит ФИО и группу: {title}")
        return False

def manual_test_instructions():
    """Инструкции для ручного тестирования"""
    print("\n" + "="*60)
    print("ИНСТРУКЦИИ ДЛЯ РУЧНОГО ТЕСТИРОВАНИЯ")
    print("="*60)
    
    scenarios = [
        ("Начальное состояние", "Все чекбоксы выключены", "50000 руб"),
        ("Монитор включен", "Только Монитор отмечен", "65000 руб"),
        ("Монитор + Клавиатура", "Монитор и Клавиатура отмечены", "68000 руб"),
        ("3 из 4", "Монитор + Клавиатура + Мышь", "70000 руб (БЕЗ скидки)"),
        ("ВСЕ 4 комплектующих", "Все 4 чекбокса отмечены", "72500 руб (СО скидкой 2500)"),
    ]
    
    for i, (scenario, action, expected) in enumerate(scenarios, 1):
        print(f"\n{i}. {scenario}")
        print(f"   Действие: {action}")
        print(f"   Ожидаемый результат: {expected}")
    
    print("\n" + "="*60)
    print("КРИТЕРИИ ПРОВЕРКИ:")
    print("="*60)
    print("✓ Заголовок окна содержит ФИО и группу")
    print("✓ 4 чекбокса для комплектующих (Монитор, Клавиатура, Мышь, Колонки)")
    print("✓ Label с развернутым выводом расчета")
    print("✓ Автоматический пересчет БЕЗ кнопки")
    print("✓ Скидка 10% применяется ТОЛЬКО при выборе ВСЕХ 4 комплектующих")
    print("="*60 + "\n")

def main():
    print("="*60)
    print("АВТОМАТИЗИРОВАННОЕ ТЕСТИРОВАНИЕ Qt КАЛЬКУЛЯТОРА")
    print("="*60)
    
    # Проверка что приложение запущено
    result = run_command("pgrep -x computer_calculator")
    if not result:
        print("\n✗ ОШИБКА: Приложение не запущено!")
        print("  Запустите: ./build_qt/computer_calculator.app/Contents/MacOS/computer_calculator")
        sys.exit(1)
    
    print(f"✓ Приложение запущено (PID: {result})")
    
    # Даем время на загрузку
    time.sleep(2)
    
    # Тест заголовка окна
    verify_window_title()
    
    # Создаем скриншот начального состояния
    print("\n[Тест] Скриншот начального состояния...")
    take_screenshot("02_initial_verified")
    
    # Вывод инструкций для ручного тестирования
    manual_test_instructions()
    
    print("✓ Автоматизированная часть завершена")
    print("  Продолжите ручное тестирование согласно инструкциям выше\n")

if __name__ == "__main__":
    main()
