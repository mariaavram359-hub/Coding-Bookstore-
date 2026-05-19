#include "ContainerPlastic.h"

#include <utility>

ContainerPlastic::ContainerPlastic(int id_plastic, std::string locatie_plastic, float capacitate_plastic,
    float eficienta_plastic) : ContainerDeseuri(id_plastic, std::move(locatie_plastic), capacitate_plastic),
    eficienta_compactor(eficienta_plastic) {
}

ContainerDeseuri * ContainerPlastic::clone() const {
    return new ContainerPlastic(*this);
}

void ContainerPlastic::afiseaza_impl() const {
    std::cout << "[Specific Plastic] Eficienta compactor: " << eficienta_compactor << "%\n";
}
