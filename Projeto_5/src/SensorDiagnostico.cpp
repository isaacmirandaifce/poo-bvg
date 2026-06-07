void SensorDiagnostico::processarDados() {

    std::cout << "\n=== DIAGNOSTICO ===" << std::endl;
    std::cout << "ID: " << idDispositivo << std::endl;
    std::cout << "RPM: " << rpmMotor << std::endl;
    std::cout << "Temperatura: "
              << temperaturaFluido << " C" << std::endl;

    // Verifica se a temperatura está acima do limite
    if (temperaturaFluido > 100) {
        std::cout << "ALERTA: Motor superaquecido!"
                  << std::endl;
    } else {
        std::cout << "Motor funcionando normalmente."
                  << std::endl;
    }
}