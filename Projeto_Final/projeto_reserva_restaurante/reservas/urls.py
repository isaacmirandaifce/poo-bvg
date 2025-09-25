# reservas/urls.py

from django.urls import path
from . import views

urlpatterns = [
    path('', views.criar_reserva, name='criar_reserva'),
    path('sucesso/', views.sucesso_reserva, name='sucesso_reserva'),
 
]