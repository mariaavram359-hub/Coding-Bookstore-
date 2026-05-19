//
// Created by lenovo on 19.05.2026.
//

#ifndef OOP_CONTAINERBIODEGRADABILE_H
#define OOP_CONTAINERBIODEGRADABILE_H

#pragma once
#include "ContainerDeseuri.h"

class ContainerBiodegradabile : public ContainerDeseuri {
private:
    float temperatura;
    bool sistem_anti_miros;

public:
    ContainerBiodegradabile(int id_bio, const std::string &locatie_bio, float capacitate_bio,
        float temperatura_bio, bool anti_miros);

    [[nodiscard]] ContainerDeseuri* clone() const override;

protected:

    void afiseaza_impl() const override;
};
#endif //OOP_CONTAINERBIODEGRADABILE_H