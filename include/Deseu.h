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
    virtual void afiseaza_impl(std::ostream& os) const = 0;


public:
    explicit Deseu(float cantitate);
    virtual ~Deseu();

    void afiseaza(std::ostream& os) const;

    [[nodiscard]] virtual int timp_descompunere_ani() const = 0;
    [[nodiscard]] virtual float calculeaza_amprenta_carbon() const = 0;

    [[nodiscard]] virtual std::string get_tip() const = 0;
    [[nodiscard]] virtual std::string genereaza_raport_ecologic() const = 0;
    [[nodiscard]] float get_cantitate() const;
    friend std::ostream& operator<<(std::ostream& os, const Deseu& deseu);
};
#endif //OOP_DESEU_H