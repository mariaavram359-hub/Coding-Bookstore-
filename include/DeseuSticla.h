#ifndef OOP_DESEUSTICLA_H
#define OOP_DESEUSTICLA_H

#pragma once
#include "Deseu.h"
#include <string>

class DeseuSticla : public Deseu {
public:
    explicit DeseuSticla(float cantitate_sticla);

    [[nodiscard]] int timp_descompunere_ani() const override;
    [[nodiscard]] std::string get_tip() const override;
    [[nodiscard]] float calculeaza_amprenta_carbon() const override;

    [[nodiscard]] std::string genereaza_raport_ecologic() const override;
    void afiseaza_impl(std::ostream &os) const override;
};

#endif //OOP_DESEUSTICLA_H