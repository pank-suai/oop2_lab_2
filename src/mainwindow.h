#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculateTotal();

private:
    Ui::MainWindow *ui;
    
    const int BASE_PRICE = 50000;
    const int MONITOR_PRICE = 15000;
    const int KEYBOARD_PRICE = 3000;
    const int MOUSE_PRICE = 2000;
    const int SPEAKERS_PRICE = 5000;
    const double DISCOUNT_RATE = 0.10;
};
