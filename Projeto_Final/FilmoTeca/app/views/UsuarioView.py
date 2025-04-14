from fastapi import APIRouter, Request
from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates
from app.services.UsuarioService import UsuarioService
from app.services.FilmeService import FilmeService

# Criar o router para views
router = APIRouter()


templates = Jinja2Templates(directory="app/templates/")


@router.get("/tela_listar_usuarios", response_class=HTMLResponse)
def listar_usuarios(request: Request):
    """Exibe a lista de todos os usuários"""
    usuarios = UsuarioService.get_all_usuarios()  # Busca os usuarios no serviço
    return templates.TemplateResponse("usuarios/listar_usuarios.html", {"request": request, "usuarios": usuarios})

@router.get("/tela_form_usuario", response_class=HTMLResponse)
def tela_form_usuario(request: Request):
    """
    Exibe a página com o formulário para adicionar um novo filme.
    """
    return templates.TemplateResponse("usuarios/add_usuario.html", {"request": request})

@router.get("/tela_editar_usuario/{usuario_id}", response_class=HTMLResponse)
def tela_editar(request: Request, usuario_id: int):
    usuario = UsuarioService.find_usuario_by_id(usuario_id)
    filmes = FilmeService.get_all_filmes()
    return templates.TemplateResponse("usuarios/editar_usuario.html",{"request":request, "usuario":usuario,"filmes":filmes})