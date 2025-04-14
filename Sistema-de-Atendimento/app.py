from flask import Flask, render_template
from routes.senha_routes import senha_bp
from routes.painel_routes import painel_bp
from routes.guiche_routes import guiche_bp
from models.guiche import Guiche

# Criando os guichês
guiches = [Guiche(1), Guiche(2), Guiche(3)]

app = Flask(__name__)
app.secret_key = 'chave_super_secreta_123'
# Registrando rotas (Blueprints)
app.register_blueprint(guiche_bp)
app.register_blueprint(painel_bp)
app.register_blueprint(senha_bp)

# Rota principal
@app.route('/')
def home():
    return render_template('index.html')

# Rodando o servidor Flask
if __name__ == '__main__':
    app.run(debug=True)
