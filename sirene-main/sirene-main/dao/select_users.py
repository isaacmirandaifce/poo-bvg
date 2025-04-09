import sqlite3
import unicodedata
from datetime import datetime

def normalizar_dia(dia_str):
    return ''.join(
        c for c in unicodedata.normalize('NFD', dia_str.lower())
        if unicodedata.category(c) != 'Mn'
    )

conn = sqlite3.connect("sirene.db")
cursor = conn.cursor()

# Criação da tabela 'historico' se não existir
cursor.execute("""
CREATE TABLE IF NOT EXISTS historico (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    horario_id INTEGER,
    horario TEXT,
    status TEXT,
    registrado_em TEXT,
    FOREIGN KEY (horario_id) REFERENCES horarios(id)
)
""")
print("✅ Tabela 'historico' verificada/criada.")

# Verifica se existe a coluna "horario" na tabela 'horarios'
try:
    cursor.execute("SELECT id, horario, dia FROM horarios")
except sqlite3.OperationalError:
    print("❌ A tabela 'horarios' não contém as colunas necessárias.")
    conn.close()
    exit()

registros = cursor.fetchall()

print("📋 Horários cadastrados:\n")

for id_, horario, dia in registros:
    dia_normalizado = normalizar_dia(dia)
    cursor.execute("UPDATE horarios SET dia = ? WHERE id = ?", (dia_normalizado, id_))
    print(f"🕒 ID: {id_} | Horário: {horario} | Dia (normalizado): {dia_normalizado}")

    # Verifica se já existe histórico para esse horário
    cursor.execute("SELECT COUNT(*) FROM historico WHERE horario_id = ?", (id_,))
    existe = cursor.fetchone()[0]

    if not existe:
        # Insere no histórico com status inicial 'NAO_OCORREU'
        cursor.execute("""
            INSERT INTO historico (horario_id, horario, status, registrado_em)
            VALUES (?, ?, ?, ?)
        """, (id_, horario, 'NAO_OCORREU', datetime.now().strftime("%Y-%m-%d %H:%M:%S")))

conn.commit()
conn.close()
print("\n✅ Tabela 'historico' preenchida com sucesso!")
