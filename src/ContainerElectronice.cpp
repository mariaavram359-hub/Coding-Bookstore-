#include <ContainerElectronice.h>

ContainerElectronice::ContainerElectronice(int id_container, std::string locatie_container,
float capacitate_electronice, bool senzor_scurgeri_electronice)
: ContainerDeseuri(id_container, std::move(locatie_container), capacitate_electronice),
  senzor_scurgeri_activ(senzor_scurgeri_electronice) {
}

ContainerDeseuri * ContainerElectronice::clone() const {
    return new ContainerElectronice(*this);
}

void ContainerElectronice::afiseaza_impl() const {
    std::cout << "[Specific Baterii/Electronice] Senzor scurgeri toxice: "
              << (senzor_scurgeri_activ ? "ACTIV SI FUNCTIONAL" : "ALERTA - INACTIV") << "\n";
}
