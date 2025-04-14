from flask import Blueprint, render_template, request
from controllers.senha_controller import emitir_senha

senha_bp = Blueprint('senha', __name__)

@senha_bp.route('/emitir', methods=['GET', 'POST'])
def emitir():
    if request.method == 'POST':
        nome = request.form['nome']
        cpf = request.form['cpf']
        tipo = request.form['tipo']

        senha = emitir_senha(nome, cpf, tipo)
        mensagem = f"Senha {senha.numero} emitida com sucesso!"
        return render_template('emitir.html', mensagem=mensagem)

    return render_template('emitir.html')
