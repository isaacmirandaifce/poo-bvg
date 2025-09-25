

from django.contrib import admin
from django.contrib.auth.models import Group 
from .models import Mesa, Reserva

# --- PERSONALIZAÇÃO DA TELA DE MESAS ---
class MesaAdmin(admin.ModelAdmin):
    list_display = ('numero', 'capacidade') # Campos que aparecerão na lista de mesas
    search_fields = ('numero',) # Adiciona uma barra de busca por número da mesa

# --- PERSONALIZAÇÃO DA TELA DE RESERVAS ---
class ReservaAdmin(admin.ModelAdmin):
    list_display = ('nome_cliente', 'cpf_cliente','mesa', 'data', 'hora', 'quantidade_pessoas') # Campos da lista
    list_filter = ('data', 'mesa') # Adiciona um filtro rápido por data e por mesa
    search_fields = ('nome_cliente', 'telefone_cliente') # Adiciona busca por nome ou telefone


admin.site.register(Mesa, MesaAdmin)
admin.site.register(Reserva, ReservaAdmin)

# Remove o modelo "Grupo" do painel de administração
admin.site.unregister(Group)