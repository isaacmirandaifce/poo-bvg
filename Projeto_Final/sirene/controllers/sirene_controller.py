from flask import Blueprint, flash, redirect, url_for
from datetime import datetime
import locale

sirene_bp = Blueprint("sirene", __name__)

@sirene_bp.route("/", methods=["POST"])
def ativar_sirene():
    locale.setlocale(locale.LC_TIME, 'pt_BR')

    agora = datetime.now()
    horario = agora.strftime("%H:%M")
    dia_semana = agora.strftime("%A")

    mensagem = f"🔔 Sirene das {horario} de {dia_semana} ativada!"
    flash(mensagem, "success")

    return redirect(url_for("inicio"))

