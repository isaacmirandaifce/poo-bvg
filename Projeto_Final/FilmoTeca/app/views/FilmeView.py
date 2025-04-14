from fastapi import APIRouter, Request
from fastapi.responses import HTMLResponse, RedirectResponse
from fastapi.templating import Jinja2Templates
from app.services.FilmeService import FilmeService

# Criar o router para views
router = APIRouter()

templates = Jinja2Templates(directory="app/templates/")


@router.get("/home", response_class=HTMLResponse)
async def tela_home(request: Request):
    usuario_id = request.cookies.get("usuario_id")
    
    if not usuario_id:
        return RedirectResponse(url="/login?error=Usuário+não+logado", status_code=303)
    
    try:
        usuario_id_int = int(usuario_id)
        filmes = FilmeService.get_all_filmes()
        filmes_favoritos = FilmeService.get_filmes_favoritos(usuario_id_int)
        
        return templates.TemplateResponse("index.html", {
            "request": request,
            "filmes": filmes,
            "filmes_favoritos": filmes_favoritos,
            "usuario_id": usuario_id_int
        })
        
    except Exception as e:
        print(f"Erro ao carregar home: {str(e)}")
        # Redireciona para a rota de login que já existe
        return RedirectResponse(url="/login?error=Erro+ao+carregar+página", status_code=303)

@router.get("/tela_listar_filmes", response_class=HTMLResponse)
def listar_filmes(request: Request):
    """Exibe a lista de todos os filmes"""
    filmes = FilmeService.get_all_filmes() 
    return templates.TemplateResponse("filmes/listar_filmes.html", {"request": request, "filmes": filmes})

@router.get("/tela_form", response_class=HTMLResponse)
def tela_form(request: Request):
    """
    Exibe a página com o formulário para adicionar um novo filme.
    """
    return templates.TemplateResponse("filmes/add_filme.html", {"request": request})

@router.get("/tela_editar/{filme_id}", response_class=HTMLResponse)
def tela_editar(request: Request, filme_id: int):
    filme = FilmeService.find_filme_by_id(filme_id)
    return templates.TemplateResponse("filmes/editar_filme.html",{"request":request, "filme":filme})

