import json
import os
from typing import List, Optional
from app.models.Usuario import Usuario
from app.dao.FilmeDao import FilmeDao
from app.models.Filme import Filme


USUARIOS_FILE = os.path.join(os.path.dirname(__file__), '../data/usuarios.json')


class UsuarioDao:
    @staticmethod
    def _read_usuarios() -> List[Usuario]:
        """
        Lê o arquivo de usuários e retorna uma lista de objetos Usuario.

        Retorna:
            List[Usuario]: Lista de objetos Usuario carregados do arquivo JSON.
        
        Lança:
            FileNotFoundError: Se o arquivo usuarios.json não for encontrado.
        """
        try:
            with open(USUARIOS_FILE, 'r') as u:

                usuarios = json.load(u)
    
                return [Usuario(**{
                    **usuario,
                    "favoritos": [Filme(**f) for f in usuario.get("favoritos", [])]
                }) for usuario in usuarios]
        except FileNotFoundError:
            return []

    @staticmethod
    def _write_usuarios(usuarios: List[Usuario]):
        """
        Grava a lista de usuários no arquivo JSON.

        Parâmetros:
            usuarios (List[Usuario]): Lista de usuários a ser salva no arquivo JSON.
        """
        with open(USUARIOS_FILE, 'w') as u:
            
            json.dump([usuario.dict() for usuario in usuarios], u, indent=4)

    @classmethod
    def _get_novo_id(cls) -> int:
        """
        Gera um novo ID para o próximo usuário a ser adicionado.

        Retorna:
            int: O novo ID para o usuário.
        """
        usuarios = cls._read_usuarios()
        return max((u.id for u in usuarios), default=0) + 1

    @classmethod
    def add_usuario(cls, usuario: Usuario):
        """
        Adiciona um novo usuário à base de dados.

        Parâmetros:
            usuario (Usuario): O objeto usuário a ser adicionado.
        
        Lança:
            ValueError: Se já existir um usuário com o mesmo ID.
        """
        usuarios = cls._read_usuarios()
        if usuario.id is None:
            usuario.id = cls._get_novo_id()

        if any(existe_usuario.id == usuario.id for existe_usuario in usuarios):
            raise ValueError('Já existe um usuário com esse id.')

        usuarios.append(usuario)
        cls._write_usuarios(usuarios)

    @classmethod
    def get_all_usuarios(cls) -> List[Usuario]:
        """
        Retorna todos os usuários registrados.

        Retorna:
            List[Usuario]: Lista de usuários.
        """
        return cls._read_usuarios()

    @classmethod
    def find_usuario_by_id(cls, usuario_id: int) -> Optional[Usuario]:
        """
        Busca um usuário pelo ID.

        Parâmetros:
            usuario_id (int): O ID do usuário a ser buscado.

        Retorna:
            Optional[Usuario]: O usuário correspondente ao ID, ou None se não encontrado.
        """
        usuarios = cls._read_usuarios()
        return next((usuario for usuario in usuarios if usuario.id == usuario_id), None)

    @classmethod
    def delete_usuario(cls, usuario_id: int) -> bool:
        """
        Deleta um usuário pelo ID.

        Parâmetros:
            usuario_id (int): O ID do usuário a ser deletado.

        Retorna:
            bool: True se o usuário foi deletado, False caso contrário.
        """
        usuarios = cls._read_usuarios()
        usuario = cls.find_usuario_by_id(usuario_id)
        if usuario:
            usuarios = [u for u in usuarios if u.id != usuario_id]
            cls._write_usuarios(usuarios)
            return True
        return False

    @classmethod
    def update_usuario(cls, usuario_id: int, usuario_atualizado: Usuario) -> bool:
        """
        Atualiza as informações de um usuário existente.

        Parâmetros:
            usuario_id (int): O ID do usuário a ser atualizado.
            usuario_atualizado (Usuario): O objeto de usuário com as novas informações.

        Retorna:
            bool: True se o usuário foi atualizado, False caso contrário.
        """
        if usuario_atualizado.id is None:
            usuario_atualizado.id = usuario_id  # Define o id se ele não foi passado

        usuarios = cls._read_usuarios()
        for i, u in enumerate(usuarios):
            if u.id == usuario_id:
                usuarios[i] = usuario_atualizado
                cls._write_usuarios(usuarios)
                return True
        return False

    @classmethod
    def add_filme_a_usuario(cls, usuario_id: int, filme_id: int):
        """
        Adiciona um filme à lista de favoritos de um usuário.

        Parâmetros:
            usuario_id (int): O ID do usuário ao qual o filme será adicionado.
            filme_id (int): O ID do filme a ser adicionado aos favoritos.
        
        Lança:
            ValueError: Se o usuário ou filme não for encontrado, ou se o filme já estiver nos favoritos.
        """
        usuario = cls.find_usuario_by_id(usuario_id)
        if not usuario:
            raise ValueError("Usuário não encontrado.")

        filme = FilmeDao.find_filme_by_id(filme_id)
        if not filme:
            raise ValueError("Filme não encontrado.")

        if any(f.id == filme.id for f in usuario.favoritos):
            raise ValueError("Filme já está na lista de favoritos do usuário.")

        usuario.favoritos.append(filme)
        cls.update_usuario(usuario_id, usuario)

    @classmethod
    def remove_filme_de_usuario(cls, usuario_id: int, filme_id: int) -> bool:
        """
        Remove um filme da lista de favoritos de um usuário.

        Parâmetros:
            usuario_id (int): O ID do usuário ao qual o filme será removido.
            filme_id (int): O ID do filme a ser removido dos favoritos.

        Retorna:
            bool: True se o filme foi removido com sucesso, False caso contrário.
        
        Lança:
            ValueError: Se o usuário ou filme não for encontrado, ou se o filme não estiver nos favoritos.
        """
        usuario = cls.find_usuario_by_id(usuario_id)
        if not usuario:
            raise ValueError("Usuário não encontrado.")

        filme = next((f for f in usuario.favoritos if f.id == filme_id), None)
        if not filme:
            raise ValueError("Filme não encontrado na lista de favoritos.")

        usuario.favoritos.remove(filme)
        cls.update_usuario(usuario_id, usuario)
        return True
    
    @classmethod
    def find_usuario_by_email(cls, email: str) -> Optional[Usuario]:
        """Busca usuário por email (corrigido)"""
        usuarios = cls._read_usuarios()
        usuario = next((u for u in usuarios if u.email == email), None)
        
        if usuario and isinstance(usuario, Usuario):
            return usuario
        return None
    
    @classmethod
    def get_filmes_favoritos(cls, usuario_id: int) -> List[Filme]:
        usuario = cls.find_usuario_by_id(usuario_id)
        if not usuario:
            raise ValueError("Usuário não encontrado.")
        
        return usuario.favoritos