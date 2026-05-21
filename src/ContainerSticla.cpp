#include "../include/ContainerSticla.h"

ContainerSticla::ContainerSticla(int id_container, const std::string& locatie_container, float capacitate_maxima_container, bool manipulare_atenta)
    : ContainerDeseuri(id_container, locatie_container, capacitate_maxima_container), necesita_manipulare_atenta(manipulare_atenta) {
    tip_acceptat = "Sticla";
}

ContainerSticla* ContainerSticla::clone() const {
    return new ContainerSticla(*this);
}

void ContainerSticla::afiseaza_impl() const {
    std::cout << " -> Tip: STICLA | Manipulare atenta: " << (necesita_manipulare_atenta ? "DA (Pericol Cioburi)" : "NU") << "\n";
}