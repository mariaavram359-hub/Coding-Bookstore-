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
    StatieSortare(const StatieSortare& alta_statie);
    StatieSortare& operator=(StatieSortare alta_statie);

    void swap(StatieSortare& alta_statie) noexcept;

    ContainerDeseuri* operator[](size_t index) const;

    void adaugaContainer(ContainerDeseuri* container);
    void mentenanta_rutina() const;

    void sorteaza_dupa_umplere();
    void afiseaza_rezumat() const;
    void colecteaza_tot_gunoiul() const;
    static void afiseaza_statistici();
    [[nodiscard]] float calculeaza_scor_sustenabilitate() const;
    void colectare_automata() const;
};


#endif //OOP_STATIESORTARE_H
