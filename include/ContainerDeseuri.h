
#ifndef OOP_CONTAINERDESEURI_H
#define OOP_CONTAINERDESEURI_H

#pragma once
#include <iostream>

class ContainerDeseuri {
protected:
    int id{};
    std::string locatie;
    float capacitate_maxima{};
    int grad_umplere{};

public:
    ContainerDeseuri(int id_container, std::string locatie_container, float capacitate_maxima_container);

    virtual ~ContainerDeseuri() = default;
    virtual ContainerDeseuri* clone() const = 0;
    void afiseaza() const;
protected:
    virtual void afiseaza_impl() const = 0;
};

#endif //OOP_CONTAINERDESEURI_H