from django.urls import path
from . import views
from django.contrib.auth.views import LoginView

urlpatterns = [
    path('', views.igdb_teste, name='igdb_teste'),
    path('detalhes/<int:game_id>/', views.igdb_detalhes, name='igdb_detalhes'),    
]
