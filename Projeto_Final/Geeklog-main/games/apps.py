from django.apps import AppConfig

#classe que herda de AppConfig - exemplo de herança
class GamesConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'games'
