//
// Created by lenovo on 21.05.2026.
//

#ifndef OOP_DESEUELECTRONIC_H
#define OOP_DESEUELECTRONIC_H

#pragma once
#include "Deseu.h"

class DeseuElectronic : public Deseu {
    public:

    explicit DeseuElectronic(float cantitate_electric);

    [[nodiscard]] int timp_descompunere_ani() const override;
    [[nodiscard]] std::string get_tip() const override;
    [[nodiscard]] float calculeaza_amprenta_carbon() const override;
};
#endif //OOP_DESEUELECTRONIC_H