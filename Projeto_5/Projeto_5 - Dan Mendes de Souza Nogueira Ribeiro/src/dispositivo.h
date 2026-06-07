#ifndef dispositivo
#define dispositivo
#include <iostream>
#include <string>

/**
 * @brief Classe base abstrata que representa um dispositivo genérico.
 */
class Dispositivo{

    protected:
        /** @brief Identificador único do dispositivo no sistema. */
        std::string idDispositivo;
        /** @brief Marca de tempo associada ao processamento do dispositivo. */
        int timestamp;

    public:
        /**
         * @brief Construtor padrão da classe Dispositivo.
         */
        Dispositivo();

        /**
         * @brief Destrutor virtual para garantir a limpeza adequada de classes derivadas.
         */
        virtual ~Dispositivo();

        /**
         * @brief Método virtual puro para processar os dados.
         * faz com que as classes filhas implementem a sua própria lógica.
         */
        virtual void processarDados() = 0;
};

#endif