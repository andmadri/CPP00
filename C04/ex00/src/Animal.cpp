#include "../incl/Animal.hpp"

Animal::Animal(): type("Animal"){
}

Animal::Animal(const Animal& other){
    *this = other;
}

Animal& Animal::operator=(const Animal& other){
    if (this != &other){
        this->type = other.type;
    }
    return *this;
}

void Animal::makeSound() const{
    std::cout << "[Animal Sound]" << std::endl;
}

std::string Animal::getType() const{
    return type;
}