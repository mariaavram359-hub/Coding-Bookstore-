//
// Created by lenovo on 21.05.2026.
//
#include "../include/DeseuBiologic.h"

DeseuBiologic::DeseuBiologic(float cantitate_bio)
    : Deseu(cantitate_bio){
}

int DeseuBiologic::timp_descompunere_ani() const {
    return 1;
}

float DeseuBiologic::calculeaza_amprenta_carbon() const {
    return cantitate * 0.5f;
}

std::string DeseuBiologic::get_tip() const {
    return "Biologic";
}

