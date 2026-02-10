#include "Component.hpp"

Component::Component(std::string name, int price, bool checked)
    : name(name), price(price), checked(checked) {}

std::string Component::getName() const {
    return name;
}

int Component::getPrice() const {
    return price;
}

bool Component::isChecked() const {
    return checked;
}

void Component::setChecked(bool value) {
    checked = value;
}

void Component::toggle() {
    checked = !checked;
}
