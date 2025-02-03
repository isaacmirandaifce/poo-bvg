#include <iostream>
#include <string>

class FuncionarioAdministrativo {
private:
    std::string nome;
    std::string email;
    std::string departamento;
    std::string cargo;

public:
    /* Construtor */
    FuncionarioAdministrativo(const std::string& n, const std::string& e, const std::string& dep, const std::string& c)
        : nome(n), email(e), departamento(dep), cargo(c) {}

    /* Método para autenticar */
    bool autenticar(const std::string& emailParam) {
        return email == emailParam;
    }

    /* Método para exibir as informações do funcionário */
    void exibirInformacoes() const {
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Departamento: " << departamento << std::endl;
        std::cout << "Cargo: " << cargo << std::endl;
    }

    /* Método para gerar um relatório */
    void gerarRelatorio() const {
        std::cout << "Relatório do Funcionario Administrativo:" << std::endl;
        exibirInformacoes();
    }
};

int main() {
    /* Criando um funcionário administrativo */
    FuncionarioAdministrativo funcionario1("Larissa", "larissa@gmail.com", "Recursos Humanos", "Assistente");

    /* Tentando autenticar */
    if (funcionario1.autenticar("larissa@gmail.com")) {
        std::cout << "Autenticação bem-sucedida!" << std::endl;
    } else {
        std::cout << "Falha na autenticação!" << std::endl;
    }

    /* Exibindo informações do funcionário */
    funcionario1.gerarRelatorio();

    return 0;
}
