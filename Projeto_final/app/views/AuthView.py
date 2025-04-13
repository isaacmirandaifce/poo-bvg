from fastapi import APIRouter, Request, Form
from fastapi.responses import HTMLResponse, RedirectResponse
from fastapi.templating import Jinja2Templates
from app.services.UsuarioService import UsuarioService

router = APIRouter()
templates = Jinja2Templates(directory="app/templates")

@router.get("/", response_class=HTMLResponse)
async def show_login(request: Request):
    return templates.TemplateResponse("auth/login.html", {
        "request": request,
        "error": None  # Inicializa sem erros
    })

@router.post("/", response_class=HTMLResponse)
async def process_login(
    request: Request,
    email: str = Form(...),
    senha: str = Form(...)
):
    try:
        usuario = UsuarioService.login(email, senha)
        response = RedirectResponse(url="/home", status_code=303)
        response.set_cookie(key="usuario_id", value=str(usuario.id))
        return response
    except ValueError as e:
        # Retorna a mesma página com mensagem de erro
        return templates.TemplateResponse("auth/login.html", {
            "request": request,
            "error": str(e),
            "email": email  # Mantém o email digitado
        })