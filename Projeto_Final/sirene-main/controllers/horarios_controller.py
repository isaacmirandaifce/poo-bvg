from flask import Blueprint, request, jsonify, session, redirect, url_for, flash
import sqlite3

import unicodedata

def normalizar_dia(dia):
    return ''.join(c for c in unicodedata.normalize('NFD', dia)
                   if unicodedata.category(c) != 'Mn').lower()

horarios_bp = Blueprint("horarios", __name__)

@horarios_bp.route("/", methods=["GET"])
def listar_horarios():
    conn = sqlite3.connect("sirene.db")
    cursor = conn.cursor()
    cursor.execute("SELECT * FROM horarios")
    horarios = cursor.fetchall()
    conn.close()
    return jsonify(horarios)

@horarios_bp.route("/", methods=["POST"])
def adicionar_horario():
    data = request.get_json()
    horario = data.get("horario")
    dia = data.get("dia")

    if not horario or not dia:
        return jsonify({"error": "Horário ou dia inválido"}), 400

    dia_normalizado = normalizar_dia(dia)

    conn = sqlite3.connect("sirene.db")
    cursor = conn.cursor()
    cursor.execute("INSERT INTO horarios (dia, horario) VALUES (?, ?)", (dia_normalizado, horario))
    conn.commit()
    conn.close()
    return jsonify({"message": "Horário adicionado com sucesso!"})

@horarios_bp.route("/editar", methods=["POST"])
def editar_horario():
    data = request.form
    horario_antigo = data.get("horario_antigo")
    novo_horario = data.get("novo_horario")
    dias = request.form.getlist("dias")

    if not horario_antigo or not novo_horario or not dias:
        return jsonify({"error": "Dados incompletos"}), 400

    dias_normalizados = [normalizar_dia(dia) for dia in dias]

    conn = sqlite3.connect("sirene.db")
    cursor = conn.cursor()

    # 1. Apaga os registros antigos com o horário antigo
    cursor.execute("DELETE FROM horarios WHERE horario = ?", (horario_antigo,))

    # 2. Insere os novos registros com o novo horário
    for dia in dias_normalizados:
        cursor.execute("INSERT INTO horarios (dia, horario) VALUES (?, ?)", (dia, novo_horario))

    conn.commit()
    conn.close()

    flash("Horário atualizado com sucesso!", "success")
    return redirect("/inicio")


@horarios_bp.route("/excluir", methods=["POST"])
def excluir_horario():
    horario = request.form.get("horario")
    conn = sqlite3.connect("sirene.db")
    cursor = conn.cursor()
    cursor.execute("DELETE FROM horarios WHERE horario = ?", (horario,))
    conn.commit()
    conn.close()
    return redirect("/inicio")
