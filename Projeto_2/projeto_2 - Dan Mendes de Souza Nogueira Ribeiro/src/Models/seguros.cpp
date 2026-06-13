#include <iostream>
#include <string>
#include "seguros.h"


//metodos da classe seguro
double seguro::getBase() { return base < 0 ? -1 : base; };

void seguro::setBase(double baseAdicionar) { base = baseAdicionar; };

void seguro::refatorarBase(double valor) { base *= valor; };

bool seguro::testarBaseValida() { return base >= 0; };

// metodos da classe do seguro do automovel.
void seguroAuto::calcular_premio() { ano < 2010 ? refatorarBase(1.2) : refatorarBase(1.5); };

int seguroAuto::getAno() { return ano < 0 ? -1 : ano; }

std::string seguroAuto::getPlacaCarro() { return placaCarro; }

void seguroAuto::setAno(int anoAdicionar) { ano = anoAdicionar; };

void seguroAuto::setPlacaCarro(std::string placaAdicionar) { placaCarro = placaAdicionar; };

// metodos da classe do seguro de vida
void seguroVida::calcular_premio() { idade > 60 ? refatorarBase(2.0) : refatorarBase(1.1); }

int seguroVida::getIdade() { return idade < 0 ? -1 : idade; }

std::string seguroVida::getCausa() { return causa; }

void seguroVida::setIdade(int idadeAdicionar) { idade = idadeAdicionar; };

void seguroVida::setCausa(std::string causaAdicionar) { causa = causaAdicionar; };

// metodos da classe do seguro do Residencial
void seguroResidencial::calcular_premio() { tipoImovel == "CASA" ? refatorarBase(1.15) : refatorarBase(1.05); };

std::string seguroResidencial::getTipoImovel() { return tipoImovel; }

std::string seguroResidencial::getEndereco() { return endereco; }

void seguroResidencial::setTipoImovel(std::string tipoImovelAdicionar) { tipoImovel = tipoImovelAdicionar; };

void seguroResidencial::setEndereco(std::string enderecoAdicionar) { endereco = enderecoAdicionar; };
