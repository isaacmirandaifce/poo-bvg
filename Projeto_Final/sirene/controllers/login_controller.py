from flask import Blueprint, request, redirect, url_for, flash, render_template, session
from werkzeug.security import generate_password_hash, check_password_hash
import sqlite3
from functools import wraps

auth_bp = Blueprint('auth', __name__)

# Decorator para rotas que requerem login
def login_required(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if 'user_id' not in session:
            flash('Por favor faça login para acessar esta página', 'danger')
            return redirect(url_for('auth.login'))
        return f(*args, **kwargs)
    return decorated_function

@auth_bp.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']
        email = request.form.get('email', '')

        # Validações básicas
        if not username or not password:
            flash('Username e senha são obrigatórios', 'danger')
            return redirect(url_for('auth.register'))

        hashed_password = generate_password_hash(
            password,
            method='pbkdf2:sha256',
            salt_length=16
        )

        try:
            conn = sqlite3.connect('sirene.db')
            cursor = conn.cursor()
            
            cursor.execute(
                "INSERT INTO users (username, password, email) VALUES (?, ?, ?)",
                (username, hashed_password, email)
            )
            
            conn.commit()
            flash('Cadastro realizado com sucesso! Faça login.', 'success')
            return redirect(url_for('auth.login'))
            
        except sqlite3.IntegrityError as e:
            flash('Usuário ou email já cadastrado', 'danger')
            return redirect(url_for('auth.register'))
            
        finally:
            conn.close()

    return render_template('auth/register.html')

@auth_bp.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        conn = sqlite3.connect('sirene.db')
        cursor = conn.cursor()
        
        try:
            cursor.execute(
                "SELECT id, username, password FROM users WHERE username = ?",
                (username,)
            )
            user = cursor.fetchone()

            if user and check_password_hash(user[2], password):
                session['user_id'] = user[0]
                session['username'] = user[1]
                
                flash(f'Bem-vindo, {user[1]}!', 'success')
                return redirect(url_for('inicio'))
            
            flash('Usuário ou senha incorretos', 'danger')
            
        except sqlite3.Error as e:
            flash('Erro ao acessar o banco de dados', 'danger')
            print(f"Database error: {e}")
            
        finally:
            conn.close()
    
    return render_template('auth/login.html')

@auth_bp.route('/logout', methods=['GET'])
@login_required
def logout():
    session.pop('user_id', None)
    session.pop('username', None)
    flash('Você foi desconectado com sucesso', 'info')
    return redirect(url_for('auth.login'))