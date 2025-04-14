from services.senha_service import SenhaService
from services.guiche_service import GuicheService
from dados.guiches_data import guiches

senha_service = SenhaService()
guiche_service = GuicheService(senha_service)

def obter_guiche(numero):
    return guiches[numero - 1]

def chamar_proxima_senha(numero_guiche):
    guiche = obter_guiche(numero_guiche)
    guiche_service.chamar_proxima_senha(guiche)
    return guiche

def finalizar_atendimento(numero_guiche):
    guiche = obter_guiche(numero_guiche)
    guiche_service.finalizar_atendimento(guiche)
    return guiche

def liberar_guiche(numero_guiche):
    guiche = obter_guiche(numero_guiche)
    guiche.liberar()
    return guiche
