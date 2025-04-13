from fastapi import APIRouter, HTTPException
from app.models.Filme import Filme
from app.services.FilmeService import FilmeService
from app.models.Usuario import Usuario
from app.services.UsuarioService import UsuarioService

router = APIRouter()

@router.post('/usuarios',status_code=201)
def add_filme(usuario: Usuario):
    try:
        UsuarioService.add_usuario(usuario)
        return {"message":"Usuário adicionado com sucesso."}
    except ValueError as e:
        raise HTTPException(status_code=400,detail=str(e))
    
@router.get('/usuarios')
def get_all_usuarios():
    return UsuarioService.get_all_usuarios()

@router.get('/usuarios/{usuario_id}')
def find_usuario_by_id(usuario_id: int):
    try:
        usuario = UsuarioService.find_usuario_by_id(usuario_id)  
        return usuario
    except ValueError:
        raise HTTPException(status_code=404, detail="Usuário não encontrado")  

@router.delete('/usuarios/{usuario_id}')
def delete_usuario(usuario_id: int):
    try:
        UsuarioService.delete_usuario(usuario_id)
        return {"message":"Usuário deletado com sucesso."}
    except ValueError as e:
        raise HTTPException(status_code=404,detail=str(e))
    
@router.put('/usuarios/{usuario_id}')
def update_usuario(usuario_id: int, usuario_atualizado: Usuario):
    try:
        UsuarioService.update_usuario(usuario_id,usuario_atualizado)
        return {'message':'Usuário atualizado com sucesso.'}
    except ValueError as e:
        raise HTTPException(status_code=404,detail=str(e))

@router.post('/usuarios/{usuario_id}/favoritos/{filme_id}')
def add_filme_a_usuario(usuario_id: int, filme_id: int):
    try:
        UsuarioService.add_filme_a_usuario(usuario_id, filme_id)
        return {'message': 'Filme adicionado aos favoritos com sucesso.'}
    except ValueError as e:
        raise HTTPException(status_code=404, detail=str(e))

@router.delete('/usuarios/{usuario_id}/favoritos/{filme_id}')
def remove_filme_de_usuario(usuario_id: int, filme_id: int):
    try:
        UsuarioService.remove_filme_de_usuario(usuario_id, filme_id)
        return {'message': 'Filme removido dos favoritos com sucesso.'}
    except ValueError as e:
        raise HTTPException(status_code=404, detail=str(e))


