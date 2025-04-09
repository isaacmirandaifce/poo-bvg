from flask import Blueprint, render_template, redirect, url_for, flash
from models.historico import HistoricoSirene  # Importe a classe aqui
import sqlite3

# Criação da instância do sistema de sirenes
historico_sirene = HistoricoSirene()

historico_bp = Blueprint("historico", __name__)

@historico_bp.route("/ativar")
def ativar_sistema():
    print("Ativando sistema de sirenes...")
    historico_sirene.ativar()
    flash("Sistema de sirenes ativado!", "success")
    return redirect(url_for("historico.exibir_historico"))


def buscar_historico():
    conn = sqlite3.connect("sirene.db")
    cursor = conn.cursor()
    cursor.execute("""
        SELECT h.id, h.horario, h.status, h.registrado_em, ho.dia
        FROM historico h
        LEFT JOIN horarios ho ON h.horario_id = ho.id
        ORDER BY h.registrado_em DESC
    """)
    registros = cursor.fetchall()
    conn.close()

    # Converte os registros em dicionários
    return [
        {
            "id": r[0],
            "horario": r[1],
            "status": r[2],
            "registrado_em": r[3],
            "dia": r[4]
        } for r in registros
    ]

@historico_bp.route("/historico")
def exibir_historico():
    historico = buscar_historico()
    return render_template("historico.html", historico=historico, ativo=historico_sirene.ativo)

