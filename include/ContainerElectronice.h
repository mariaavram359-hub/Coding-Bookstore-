//
// Created by lenovo on 19.05.2026.
//

#ifndef OOP_CONTAINERELECTRONICE_H
#define OOP_CONTAINERELECTRONICE_H

#pragma once
#include "ContainerDeseuri.h"

class ContainerElectronice : public ContainerDeseuri {
private:
    bool senzor_scurgeri_activ;

public:
    ContainerElectronice(int id_container, std::string locatie_container, float capacitate_electronice,
        bool senzor_scurgeri_electronice);

    [[nodiscard]] ContainerDeseuri* clone() const override;

protected:

    void afiseaza_impl() const override;
};

#endif //OOP_CONTAINERELECTRONICE_H