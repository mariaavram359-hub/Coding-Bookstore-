// #inlcude <iostream>
#include "ContainerElectronice.h"
#include "ContainerBiodegradabile.h"
#include "ContainerPlastic.h"

int main() {
    std::cout << "--- Initializare Sistem Smart de Gestionare a Deseurilor ---\n";

    const ContainerPlastic container1(1, "Piata Unirii", 150.0f, 85.5f);

    const ContainerBiodegradabile container2(2, "Parcul Central", 100.0f, 22.5f, true);

    const ContainerElectronice container3(3, "Supermarket", 50.0f, true);

    container1.afiseaza();
    container2.afiseaza();
    container3.afiseaza();

    std::cout << "Sistem oprit cu succes.\n";
    return 0;
}