//
// Created by lenovo on 21.05.2026.
//
#include "Deseu.h"
#include <iostream>

Deseu::Deseu(float cantitate_deseu)
    :cantitate(cantitate_deseu){
}

Deseu::~Deseu() = default;

float Deseu::get_cantitate() const {
    return cantitate;
}

void Deseu::afiseaza(std::ostream& os) const {
    afiseaza_impl(os);
}

std::ostream& operator<<(std::ostream& os, const Deseu& deseu) {
    deseu.afiseaza(os);
    return os;
}