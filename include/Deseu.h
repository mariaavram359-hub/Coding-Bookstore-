//
// Created by lenovo on 21.05.2026.
//

#ifndef OOP_DESEU_H
#define OOP_DESEU_H

#pragma once
#include <string>

class Deseu {
protected:
    float cantitate;

public:
    explicit Deseu(float cantitate);
    virtual ~Deseu();

    [[nodiscard]] virtual int timp_descompunere_ani() const = 0;
    [[nodiscard]] virtual float calculeaza_amprenta_carbon() const = 0;

    [[nodiscard]] virtual std::string get_tip() const = 0;
    [[nodiscard]] float get_cantitate() const;
};
#endif //OOP_DESEU_H