//
// Created by lenovo on 21.05.2026.
//
#include "Deseu.h"

Deseu::Deseu(float cantitate_deseu)
    :cantitate(cantitate_deseu){
}

Deseu::~Deseu() = default;

float Deseu::get_cantitate() const {
    return cantitate;
}

