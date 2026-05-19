//
// Created by lenovo on 20.05.2026.
//

#ifndef OOP_STATIESORTARE_H
#define OOP_STATIESORTARE_H

#pragma once
#include <vector>
#include "ContainerDeseuri.h"

class StatieSortare {
private:
    std::vector<ContainerDeseuri*> flota_containere;
    static float total_reciclat;

public:
    StatieSortare() = default;
    ~StatieSortare();

    void adaugaContainer(ContainerDeseuri* container);
    void mentenanta_rutina() const;

    void colecteaza_tot_gunoiul() const;
    static void afiseaza_statistici();
};


#endif //OOP_STATIESORTARE_H
