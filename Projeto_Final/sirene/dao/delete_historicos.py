import sqlite3

conn = sqlite3.connect("sirene.db")
cursor = conn.cursor()

# Atualiza todos os registros da tabela historico para status PENDENTE
cursor.execute("""
    UPDATE historico
    SET status = 'PENDENTE'
""")

conn.commit()
conn.close()

print("🔄 Todos os registros da tabela 'historico' foram atualizados para status PENDENTE.")
