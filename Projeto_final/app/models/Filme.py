from pydantic import BaseModel, Field, validator
from typing import Optional, List
from enum import Enum

class GeneroFilme(str, Enum):
    ACAO = "Ação"
    COMEDIA = "Comédia"
    DRAMA = "Drama"
    FICCAO = "Ficção Científica"
    TERROR = "Terror"
    ROMANCE = "Romance"
    ANIMACAO = "Animação"
    OUTRO = "Outro"  # Adicionando uma categoria para valores desconhecidos

    @classmethod
    def _missing_(cls, value):
        """Método especial para lidar com valores não encontrados no enum"""
        # Tenta fazer match case-insensitive
        value_lower = str(value).lower().strip()
        for member in cls:
            if member.value.lower() == value_lower:
                return member
        return cls.OUTRO  # Retorna 'Outro' para valores desconhecidos

class Filme(BaseModel):
    id: Optional[int] = Field(default=None, gt=0)
    titulo: str = Field(..., min_length=1, max_length=100)
    genero: GeneroFilme = Field(default=GeneroFilme.OUTRO)
    descricao: str = Field(default="Descrição não disponível", min_length=10, max_length=500)
    ano: int = Field(..., gt=1888, le=2025)
    avaliacao: float = Field(default=0.0, ge=0, le=10)
    
    class Config:
        use_enum_values = True
        json_encoders = {
            GeneroFilme: lambda v: v.value
        }
    
    @validator('genero', pre=True)
    def validar_genero(cls, v):
        if v is None:
            return GeneroFilme.OUTRO
        return GeneroFilme(v)  # Isso agora usará o _missing_ para valores desconhecidos
    
    @validator('descricao', pre=True)
    def validar_descricao(cls, v):
        if v is None or len(str(v).strip()) < 10:
            return "Descrição não disponível"
        return v
# from pydantic import BaseModel, Field
# from typing import Optional

# class Filme(BaseModel):
#     id: Optional[int] = Field(default=None)
#     titulo: str
#     genero: str
#     descricao: str
#     ano: int
#     avaliacao: float

