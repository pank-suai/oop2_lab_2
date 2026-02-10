#pragma once

#include "Component.hpp"
#include <vector>

class ComputerCalculator {
private:
    int basePrice;
    std::vector<Component> components;
    static constexpr double DISCOUNT_RATE = 0.1;

public:
    ComputerCalculator(int basePrice);
    
    void addComponent(const Component& component);
    std::vector<Component>& getComponents();
    
    int getBasePrice() const;
    int getComponentsSum() const;
    bool allComponentsChecked() const;
    int getDiscount() const;
    int getTotalPrice() const;
};
