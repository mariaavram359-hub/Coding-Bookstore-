//
// Created by lenovo on 21.05.2026.
//

#include "DeseuPlastic.h"

DeseuPlastic::DeseuPlastic(float cantitate_plastic)
    : Deseu(cantitate_plastic){
}

int DeseuPlastic::timp_descompunere_ani() const {
    return 500;
}

float DeseuPlastic::calculeaza_amprenta_carbon() const {
    return 6.0f * cantitate;
}

std::string DeseuPlastic::get_tip() const {
    return "Plastic";
}
