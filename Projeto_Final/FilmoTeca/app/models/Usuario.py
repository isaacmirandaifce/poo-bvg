from pydantic import BaseModel, Field, validator
from typing import List, Optional
from app.models.Filme import Filme

class Usuario(BaseModel):
    id: Optional[int] = Field(default=None)
    nome: str
    email: str
    senha: str
    favoritos: Optional[List[Filme]] = []
