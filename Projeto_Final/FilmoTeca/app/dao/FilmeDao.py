import json, os
from typing import List, Optional
from app.models.Filme import Filme

FILMES_FILE = os.path.join(os.path.dirname(__file__), '../data/filmes.json')

class FilmeDao:
    @staticmethod
    def _read_filmes() -> List[Filme]:
        """
        Lê o arquivo de filmes e retorna uma lista de objetos Filme.

        Retorna:
            List[Filme]: Lista de objetos Filme carregados do arquivo JSON.
        
        Lança:
            FileNotFoundError: Se o arquivo filmes.json não for encontrado.
        """
        try:
            with open(FILMES_FILE, 'r') as f:
                filmes = json.load(f)
                return [Filme(**filme) for filme in filmes]
        except FileNotFoundError:
            return []

    @staticmethod
    def _write_filmes(filmes: List[Filme]):
        """
        Grava a lista de filmes no arquivo JSON.

        Parâmetros:
            filmes (List[Filme]): Lista de filmes a ser salva no arquivo JSON.
        """
        with open(FILMES_FILE, 'w') as f:
            json.dump([filme.dict() for filme in filmes], f, indent=4)

    @classmethod
    def _get_novo_id(cls) -> int:
        """
        Gera um novo ID para o próximo filme a ser adicionado.

        Retorna:
            int: O novo ID para o filme.
        """
        filmes = cls._read_filmes()
        return max((f.id for f in filmes), default=0) + 1
    
    @classmethod
    def add_filme(cls, filme: Filme):
        """
        Adiciona um novo filme à base de dados.

        Parâmetros:
            filme (Filme): O objeto filme a ser adicionado.
        
        Lança:
            ValueError: Se já existir um filme com o mesmo ID.
        """
        filmes = cls._read_filmes()
        if filme.id is None:
            filme.id = cls._get_novo_id()

        if any(existe_filme.id == filme.id for existe_filme in filmes):
            raise ValueError('Já existe um filme com esse id.')
        filmes.append(filme)
        cls._write_filmes(filmes)

    @classmethod
    def get_all_filmes(cls) -> List[Filme]:
        """
        Retorna todos os filmes registrados.

        Retorna:
            List[Filme]: Lista de filmes.
        """
        return cls._read_filmes()
    
    @classmethod
    def find_filme_by_id(cls, filme_id: int) -> Optional[Filme]:
        """
        Busca um filme pelo ID.

        Parâmetros:
            filme_id (int): O ID do filme a ser buscado.

        Retorna:
            Optional[Filme]: O filme correspondente ao ID, ou None se não encontrado.
        """
        filmes = cls._read_filmes()
        return next((filme for filme in filmes if filme.id == filme_id), None)
    
    @classmethod
    def delete_filme(cls, filme_id: int) -> bool:
        """
        Deleta um filme pelo ID.

        Parâmetros:
            filme_id (int): O ID do filme a ser deletado.

        Retorna:
            bool: True se o filme foi deletado, False caso contrário.
        """
        filmes = cls._read_filmes()
        filme = cls.find_filme_by_id(filme_id)
        if filme:
            filmes.remove(filme)
            cls._write_filmes(filmes)
            return True
        return False

    @classmethod
    def update_filme(cls, filme_id: int, filme_atualizado: Filme) -> bool:
        """
        Atualiza as informações de um filme existente.

        Parâmetros:
            filme_id (int): O ID do filme a ser atualizado.
            filme_atualizado (Filme): O objeto de filme com as novas informações.

        Retorna:
            bool: True se o filme foi atualizado, False caso contrário.
        """
        filmes = cls._read_filmes()
        filme = next((f for f in filmes if f.id == filme_id), None)
        
        if not filme:
            return False
        
        filme.titulo = filme_atualizado.titulo
        filme.genero = filme_atualizado.genero
        filme.descricao = filme_atualizado.descricao
        filme.ano = filme_atualizado.ano
        filme.avaliacao = filme_atualizado.avaliacao
        
        cls._write_filmes(filmes)
        return True
