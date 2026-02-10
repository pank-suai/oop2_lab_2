#pragma once

#include <string>

class Component {
private:
    std::string name;
    int price;
    bool checked;

public:
    Component(std::string name, int price, bool checked = false);
    
    std::string getName() const;
    int getPrice() const;
    bool isChecked() const;
    void setChecked(bool value);
    void toggle();
};
