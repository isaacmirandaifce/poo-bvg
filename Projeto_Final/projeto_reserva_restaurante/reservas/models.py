from django.db import models

class Mesa(models.Model):
    numero = models.IntegerField(unique=True)
    capacidade = models.IntegerField()

    def __str__(self):
        return f"Mesa {self.numero} (Capacidade: {self.capacidade})"

class Reserva(models.Model):
    nome_cliente = models.CharField(max_length=100)
    cpf_cliente = models.CharField(max_length=14)
    telefone_cliente = models.CharField(max_length=15)
    mesa = models.ForeignKey(Mesa, on_delete=models.CASCADE)
    data = models.DateField()
    hora = models.TimeField()
    quantidade_pessoas = models.IntegerField()
    data_criacao = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f"Reserva de {self.nome_cliente} para {self.data}"

    def save(self, *args, **kwargs):
        if self.quantidade_pessoas > self.mesa.capacidade:
            raise ValueError("A quantidade de pessoas excede a capacidade da mesa.")
        super().save(*args, **kwargs)