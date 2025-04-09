from django.db import models
from django.contrib.auth.models import User

#Classe definição de um novo tipo de objeto (Review), herdando de models.Model (Herança)
class Review(models.Model):
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    game_id = models.IntegerField()  # ID do jogo no IGDB
    texto = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)

    def __str__(self):
        return f'Review de {self.user.username} - Jogo {self.game_id}'
