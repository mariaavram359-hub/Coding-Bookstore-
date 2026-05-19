#include "ContainerBiodegradabile.h"

ContainerBiodegradabile::ContainerBiodegradabile(int id_bio, const std::string &locatie_bio, float capacitate_bio,
    float temperatura_bio, bool anti_miros) : ContainerDeseuri(id_bio, locatie_bio, capacitate_bio),
    temperatura(temperatura_bio), sistem_anti_miros(anti_miros){
}

ContainerDeseuri * ContainerBiodegradabile::clone() const {
    return new ContainerBiodegradabile(*this);
}

void ContainerBiodegradabile::afiseaza_impl() const {
    std::cout << "[Specific Biologic] Temperatura interna: " << temperatura << " grade Celsius\n";
    std::cout << "[Specific Biologic] Sistem anti-miros: "
              << (sistem_anti_miros ? "ACTIV" : "INACTIV") << "\n";
}
