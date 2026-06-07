int main() {

    // Vetor que armazenará diferentes tipos de dispositivos
    std::vector<Dispositivo*> dispositivos;

    // Criando objetos dinamicamente
    dispositivos.push_back(
        new SensorGPS(
            "GPS001",
            100,
            -3.7319,
            -38.5267));

    dispositivos.push_back(
        new SensorDiagnostico(
            "OBD001",
            200,
            3200,
            95));

    dispositivos.push_back(
        new RastreadorAvancado(
            "ADV001",
            300,
            -3.7319,
            -38.5267,
            3500,
            105));

    // Polimorfismo: chama processarDados()
    // de acordo com o tipo real do objeto
    for (Dispositivo* dispositivo : dispositivos) {
        dispositivo->processarDados();
    }

    // Testando a sobrecarga de métodos
    SensorGPS gps(
        "GPS999",
        500,
        -3.7,
        -38.5);

    gps.transmitirPayload();
    gps.transmitirPayload("CHAVE123");

    // Liberando memória alocada com new
    for (Dispositivo* dispositivo : dispositivos) {
        delete dispositivo;
    }

    return 0;
}