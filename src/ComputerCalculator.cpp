#include "ComputerCalculator.hpp"

ComputerCalculator::ComputerCalculator(int basePrice) : basePrice(basePrice) {}

void ComputerCalculator::addComponent(const Component& component) {
    components.push_back(component);
}

std::vector<Component>& ComputerCalculator::getComponents() {
    return components;
}

int ComputerCalculator::getBasePrice() const {
    return basePrice;
}

int ComputerCalculator::getComponentsSum() const {
    int sum = 0;
    for (const auto& comp : components) {
        if (comp.isChecked()) {
            sum += comp.getPrice();
        }
    }
    return sum;
}

bool ComputerCalculator::allComponentsChecked() const {
    for (const auto& comp : components) {
        if (!comp.isChecked()) {
            return false;
        }
    }
    return true;
}

int ComputerCalculator::getDiscount() const {
    if (allComponentsChecked()) {
        return static_cast<int>(getComponentsSum() * DISCOUNT_RATE);
    }
    return 0;
}

int ComputerCalculator::getTotalPrice() const {
    return basePrice + getComponentsSum() - getDiscount();
}
