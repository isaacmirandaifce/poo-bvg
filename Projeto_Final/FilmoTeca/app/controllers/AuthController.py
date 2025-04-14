from fastapi import APIRouter, HTTPException, status
from app.services.UsuarioService import UsuarioService

router = APIRouter()

@router.post("/api/login")
def login(email: str, senha: str):
    try:
        usuario = UsuarioService.login(email, senha)
        return {
            "message": "Login bem-sucedido",
            "usuario_id": usuario.id,
            "nome": usuario.nome
        }
    except ValueError as e:
        raise HTTPException(
            status_code=status.HTTP_401_UNAUTHORIZED,
            detail=str(e)
        )