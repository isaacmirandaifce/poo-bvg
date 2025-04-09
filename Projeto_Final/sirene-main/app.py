from flask import Flask, render_template, session, redirect, url_for, request, flash
from controllers.horarios_controller import horarios_bp
from controllers.sirene_controller import sirene_bp
from controllers.login_controller import auth_bp
from services.schedule_service import iniciar_verificacao_horarios
import sqlite3

app = Flask(__name__, template_folder="templates", static_folder="static")
app.secret_key = 'sua_chave_secreta_muito_segura'  # Adicione esta linha

# Registra todos os Blueprints
app.register_blueprint(horarios_bp, url_prefix="/horarios")
app.register_blueprint(sirene_bp, url_prefix="/sirene")
app.register_blueprint(auth_bp, url_prefix="/auth")

# Rota principal redireciona para login
@app.route("/")
def home():
    if 'user_id' not in session:
        return redirect(url_for('auth.login'))
    
    return render_template('index.html', username=session.get('username'))

@app.route("/inicio", methods=["GET"])
def inicio():
    if 'user_id' not in session:
        return redirect(url_for('auth.login'))
    
    conn = sqlite3.connect("sirene.db")
    cursor = conn.cursor()
    
    cursor.execute("SELECT dia, horario FROM horarios ORDER BY horario ASC")
    resultados = cursor.fetchall()
    conn.close()

    # Organiza dados como {horario: {dia: True/False}}
    dias_semana = ['segunda', 'terca', 'quarta', 'quinta', 'sexta']
    agenda = {}

    for dia, horario in resultados:
        if horario not in agenda:
            agenda[horario] = {d: False for d in dias_semana}
        agenda[horario][dia.lower()] = True

    return render_template("index.html", agenda=agenda, dias_semana=dias_semana, username=session.get('username'))


@app.route("/inicio", methods=["POST"])
def agendar():
    horario = request.form.get("horario")
    dias = request.form.getlist("dias")  # <- lista de dias marcados

    if not horario or not dias:
        flash("Preencha todos os campos!", "danger")
        return redirect(url_for("inicio"))

    conn = sqlite3.connect("sirene.db")
    cursor = conn.cursor()
    for dia in dias:
        cursor.execute("INSERT INTO horarios (dia, horario) VALUES (?, ?)", (dia, horario))
    conn.commit()
    conn.close()

    flash("Horário(s) agendado(s) com sucesso!", "success")
    return redirect(url_for("inicio"))


if __name__ == "__main__":
    iniciar_verificacao_horarios()
    app.run(debug=True)