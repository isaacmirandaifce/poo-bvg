class SeguroVeiculo {
public:
virtual double calcularValor(double base, double taxa) const {
return base * (1 + taxa);
}
virtual ~SeguroVeiculo() {}
};

class SeguroCarro : public SeguroVeiculo {
public:
double calcularValor(double base, double taxa) const override {
return base * (1 + taxa + 0.02); // acréscimo para carro
}
};

class SeguroMoto : public SeguroVeiculo {
public:
double calcularValor(double base, double taxa) const override {
return base * (1 + taxa + 0.05); // acréscimo para moto
}
};