from flask import Blueprint, render_template, redirect, url_for, flash
from datetime import datetime
from services.senha_service import SenhaService
from services.guiche_service import GuicheService
from dados.guiches_data import guiches
from dados.fila_data import  senhas_aguardando 

guiche_bp = Blueprint('guiche', __name__)
senha_service = SenhaService()

def obter_guiche(numero):
    return guiches[numero - 1]

@guiche_bp.route('/guiche/<int:numero>')
def tela_guiche(numero):
    guiche = obter_guiche(numero)  
    return render_template('guiche.html', 
                         guiche=guiche,
                         senhas=senhas_aguardando,
                         senha_atual=guiche.cliente_atual)

@guiche_bp.route('/guiche/<int:numero>/chamar')
def chamar_proxima(numero):
    try:
        guiche = obter_guiche(numero)
        guiche_service = GuicheService(senha_service)

        guiche_service.chamar_proxima_senha(guiche)
        senha = guiche.cliente_atual
        if senha:
            flash(f'Senha {senha.numero} chamada!', 'success')

        else:
            flash('Não há senhas na fila!', 'info')
            
    except Exception as e:
        flash(f'Erro: {str(e)}', 'danger')
        
    return redirect(url_for('guiche.tela_guiche', numero=numero))

@guiche_bp.route('/guiche/<int:numero>/liberar')
def liberar(numero):
    try:
        guiche = obter_guiche(numero)
        guiche_service = GuicheService(senha_service)

        guiche_service.finalizar_atendimento(guiche)
        flash('Atendimento finalizado com sucesso!', 'success')

    except Exception as e:
        flash(f'Erro: {str(e)}', 'danger')

    return redirect(url_for('guiche.tela_guiche', numero=numero))