class Professor : public UsuarioAutenticavel, public Relatorio {
public:
    Professor(const std::string& nome,
    const std::string& email,
    const std::string& senha);

    bool autenticar(const std::string& senhaInformada) const override;
    void gerarRelatorio() const override;
};