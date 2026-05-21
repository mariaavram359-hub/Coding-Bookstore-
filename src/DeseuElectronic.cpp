//
// Created by lenovo on 21.05.2026.
//
#include "DeseuElectronic.h"

DeseuElectronic::DeseuElectronic(float cantitate_electric)
    :Deseu(cantitate_electric){
}

int DeseuElectronic::timp_descompunere_ani() const {
    return 1000;
}

std::string DeseuElectronic::get_tip() const {
    return "Electronice";
}


float DeseuElectronic::calculeaza_amprenta_carbon() const {
    return cantitate * 25.0f;
}
