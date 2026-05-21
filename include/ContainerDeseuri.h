
#ifndef OOP_CONTAINERDESEURI_H
#define OOP_CONTAINERDESEURI_H

#pragma once
#include <iostream>
#include "Deseu.h"

class ContainerDeseuri {
protected:
    int id{};
    std::string locatie;
    float capacitate_maxima{};
    int grad_umplere{};

public:
    ContainerDeseuri(int id_container, std::string locatie_container, float capacitate_maxima_container);

    virtual ~ContainerDeseuri() = default;
    [[nodiscard]] virtual ContainerDeseuri* clone() const = 0;
    void afiseaza() const;

    void adauga_deseuri(const Deseu& deseu_aruncat);
    ContainerDeseuri& operator+=(const Deseu& deseu_aruncat);

    friend std::ostream& operator<<(std::ostream& os, const ContainerDeseuri& container);

    float goleste();

    [[nodiscard]] float get_grad_umplere() const;

protected:
    std::string tip_acceptat;
    virtual void afiseaza_impl() const = 0;
};

#endif //OOP_CONTAINERDESEURI_H