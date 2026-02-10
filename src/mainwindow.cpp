#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Подключаем сигналы от чекбоксов к слоту пересчета
    connect(ui->monitorCheckBox, &QCheckBox::checkStateChanged, this, &MainWindow::calculateTotal);
    connect(ui->keyboardCheckBox, &QCheckBox::checkStateChanged, this, &MainWindow::calculateTotal);
    connect(ui->mouseCheckBox, &QCheckBox::checkStateChanged, this, &MainWindow::calculateTotal);
    connect(ui->speakersCheckBox, &QCheckBox::checkStateChanged, this, &MainWindow::calculateTotal);
    
    // Выполняем первоначальный расчет
    calculateTotal();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateTotal()
{
    int componentsSum = 0;
    
    // Суммируем стоимость выбранных комплектующих
    if (ui->monitorCheckBox->isChecked()) {
        componentsSum += MONITOR_PRICE;
    }
    if (ui->keyboardCheckBox->isChecked()) {
        componentsSum += KEYBOARD_PRICE;
    }
    if (ui->mouseCheckBox->isChecked()) {
        componentsSum += MOUSE_PRICE;
    }
    if (ui->speakersCheckBox->isChecked()) {
        componentsSum += SPEAKERS_PRICE;
    }
    
    // Проверяем, выбраны ли все комплектующие для применения скидки
    bool allSelected = ui->monitorCheckBox->isChecked() && 
                       ui->keyboardCheckBox->isChecked() && 
                       ui->mouseCheckBox->isChecked() && 
                       ui->speakersCheckBox->isChecked();
    
    // Рассчитываем скидку (10% на комплектующие, если выбраны все)
    int discount = 0;
    if (allSelected) {
        discount = static_cast<int>(componentsSum * DISCOUNT_RATE);
    }
    
    // Рассчитываем итоговую сумму
    int total = BASE_PRICE + componentsSum - discount;
    
    // Формируем текст результата
    QString resultText;
    resultText += QString("Сумма основного изделия: %1 руб\n").arg(BASE_PRICE);
    resultText += QString("Сумма комплектующих: %1 руб\n").arg(componentsSum);
    resultText += QString("Скидка: %1 руб").arg(discount);
    
    if (allSelected && discount > 0) {
        resultText += " (применена скидка 10% на комплектующие)\n";
    } else {
        resultText += "\n";
    }
    
    resultText += QString("\nИтого: %1 руб").arg(total);
    
    // Отображаем результат
    ui->resultLabel->setText(resultText);
}
