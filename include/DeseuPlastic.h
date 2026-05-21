//
// Created by lenovo on 21.05.2026.
//

#ifndef OOP_DESEUPLASTIC_H
#define OOP_DESEUPLASTIC_H

#include "Deseu.h"

class DeseuPlastic : public Deseu {
public:
    explicit DeseuPlastic(float cantitate_plastic);

    [[nodiscard]] int timp_descompunere_ani() const override;
    [[nodiscard]] float calculeaza_amprenta_carbon() const override;

    [[nodiscard]] std::string get_tip() const override;

};
#endif //OOP_DESEUPLASTIC_H