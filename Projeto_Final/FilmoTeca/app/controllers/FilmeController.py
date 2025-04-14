from fastapi import APIRouter, HTTPException
from app.models.Filme import Filme
from app.services.FilmeService import FilmeService

router = APIRouter()

@router.post('/filmes',status_code=201)
def add_filme(filme: Filme):
    try:
        FilmeService.add_filme(filme)
        return {"message":"Filme adicionado com sucesso."}
    except ValueError as e:
        raise HTTPException(status_code=400,detail=str(e))
    
@router.get('/filmes')
def get_all_filmes():
    return FilmeService.get_all_filmes()

@router.get("/filmes/{filme_id}")
def find_filme_by_id(filme_id: int):
    try:
        filme = FilmeService.find_filme_by_id(filme_id)  
        return filme
    except ValueError:
        raise HTTPException(status_code=404, detail="Filme não encontrado")  

@router.delete('/filmes/{filme_id}')
def delete_filme(filme_id: int):
    try:
        FilmeService.delete_filme(filme_id)
        return {"message":"Filme deletado com sucesso."}
    except ValueError as e:
        raise HTTPException(status_code=404,detail=str(e))
    
@router.put('/filmes/{filme_id}')
def update_filme(filme_id: int, filme_atualizado: Filme):
    try:
        FilmeService.update_filme(filme_id,filme_atualizado)
        return {'message':'Filme atualizado com sucesso.'}
    except ValueError as e:
        raise HTTPException(status_code=404,detail=str(e))