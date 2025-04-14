from flask import Blueprint, render_template, jsonify
from controllers.painel_controller import listar_ultimas_chamadas
from dados.guiches_data import guiches

painel_bp = Blueprint("painel", __name__)

@painel_bp.route("/painel")
def painel():
    ultimas = listar_ultimas_chamadas()
    senha_atual = ultimas[0] if ultimas else None
    return render_template("painel.html", senha=senha_atual, historico=ultimas)

@painel_bp.route("/api/senha_atual")
def senha_json():
    ultimas = listar_ultimas_chamadas()
    if ultimas:
        return jsonify(ultimas[0])
    return jsonify({})


@painel_bp.route("/api/historico")
def historico_json():
    return jsonify(listar_ultimas_chamadas())
