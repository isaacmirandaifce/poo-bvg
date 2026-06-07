void RastreadorAvancado::processarDados() {

    // Combina informações do GPS e do diagnóstico
    std::cout << "\n=== RASTREADOR AVANCADO ==="
              << std::endl;

    std::cout << "ID: "
              << idDispositivo << std::endl;

    std::cout << "Latitude: "
              << getLatitude() << std::endl;

    std::cout << "Longitude: "
              << getLongitude() << std::endl;

    std::cout << "RPM: "
              << getRpmMotor() << std::endl;

    std::cout << "Temperatura: "
              << getTemperatura()
              << " C" << std::endl;
}