import sqlite3

def create_users_table():
    # Conecta ao banco existente
    conn = sqlite3.connect('sirene.db')
    cursor = conn.cursor()
    
    try:
        # Cria a tabela 'users' se não existir
        cursor.execute('''
            CREATE TABLE IF NOT EXISTS users (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                username TEXT UNIQUE NOT NULL,
                password TEXT NOT NULL,
                email TEXT UNIQUE,
                is_admin BOOLEAN DEFAULT 0,
                created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
            )
        ''')
        
        conn.commit()
        print("✅ Tabela 'users' criada com sucesso!")
        
    except sqlite3.Error as e:
        print(f"❌ Erro ao criar tabela: {e}")
        
    finally:
        conn.close()

if __name__ == '__main__':
    create_users_table()