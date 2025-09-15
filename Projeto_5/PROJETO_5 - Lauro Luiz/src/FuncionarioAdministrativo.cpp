#include "FuncionarioAdministrativo.h"

// Construtor padrão
FuncionarioAdministrativo::FuncionarioAdministrativo()
    : Usuario("", "", "Funcionário Administrativo"), departamento(""), cargo("") {}

// Construtor parametrizado
FuncionarioAdministrativo::FuncionarioAdministrativo(const std::string& nome, const std::string& email,
                                                     const std::string& departamento, const std::string& cargo)
    : Usuario(nome, email, "Funcionário Administrativo"), departamento(departamento), cargo(cargo) {}

// Destrutor virtual
FuncionarioAdministrativo::~FuncionarioAdministrativo() {}

// Métodos getters
std::string FuncionarioAdministrativo::getDepartamento() const {
    return departamento;
}

std::string FuncionarioAdministrativo::getCargo() const {
    return cargo;
}

// Métodos setters
void FuncionarioAdministrativo::setDepartamento(const std::string& departamento) {
    this->departamento = departamento;
}

void FuncionarioAdministrativo::setCargo(const std::string& cargo) {
    this->cargo = cargo;
}

// Sobrescrita do método virtual puro da classe base
void FuncionarioAdministrativo::gerarRelatorio() const {
    std::cout << "\n========== RELATÓRIO DO FUNCIONÁRIO ADMINISTRATIVO ==========\n";
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Departamento: " << departamento << std::endl;
    std::cout << "Cargo: " << cargo << std::endl;

    // Informações adicionais baseadas no cargo
    std::cout << "\nResponsabilidades do cargo:" << std::endl;
    if (cargo == "Coordenador" || cargo == "Diretor") {
        std::cout << "- Supervisão de equipes" << std::endl;
        std::cout << "- Tomada de decisões estratégicas" << std::endl;
        std::cout << "- Planejamento departamental" << std::endl;
    } else if (cargo == "Secretário" || cargo == "Assistente") {
        std::cout << "- Atendimento ao público" << std::endl;
        std::cout << "- Suporte administrativo" << std::endl;
        std::cout << "- Organização de documentos" << std::endl;
    } else {
        std::cout << "- Atividades gerais do departamento" << std::endl;
    }

    std::cout << "============================================================\n" << std::endl;
}

// Sobrescrita do método exibirInformacoes
void FuncionarioAdministrativo::exibirInformacoes() const {
    std::cout << "\n--- Informações do Funcionário ---" << std::endl;
    Usuario::exibirInformacoes();
    std::cout << "Departamento: " << departamento << std::endl;
    std::cout << "Cargo: " << cargo << std::endl;
}

// Método específico para exibir hierarquia organizacional
void FuncionarioAdministrativo::exibirHierarquia() const {
    std::cout << "\n--- Hierarquia Organizacional ---" << std::endl;
    std::cout << "Funcionário: " << nome << std::endl;
    std::cout << "Posição: " << cargo << " - " << departamento << std::endl;

    // Simula uma hierarquia simples
    if (cargo == "Diretor") {
        std::cout << "Nível: Alto (Nível 1)" << std::endl;
    } else if (cargo == "Coordenador") {
        std::cout << "Nível: Médio (Nível 2)" << std::endl;
        std::cout << "Reporta para: Diretor" << std::endl;
    } else {
        std::cout << "Nível: Operacional (Nível 3)" << std::endl;
        std::cout << "Reporta para: Coordenador" << std::endl;
    }
}

// Método para verificar se pode acessar determinado sistema
bool FuncionarioAdministrativo::podeAcessarSistema(const std::string& sistema) const {
    // Lógica simples de permissões baseada no cargo
    if (cargo == "Diretor") {
        return true; // Diretor tem acesso a tudo
    } else if (cargo == "Coordenador") {
        return (sistema == "Acadêmico" || sistema == "Relatórios" || sistema == "Recursos Humanos");
    } else if (cargo == "Secretário" || cargo == "Assistente") {
        return (sistema == "Acadêmico" || sistema == "Atendimento");
    }

    return false; // Outros cargos têm acesso limitado
}
