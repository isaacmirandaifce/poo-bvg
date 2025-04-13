from app.controllers.FilmeController import router as filme_router
from app.controllers.UsuarioController import router as usuario_router
from app.controllers.AuthController import router as auth_router
from app.views.FilmeView import router as filme_view_router
from app.views.UsuarioView import router as usuario_view_router
from app.views.AuthView import router as auth_view_router
from fastapi.staticfiles import StaticFiles

from fastapi import FastAPI
from fastapi.templating import Jinja2Templates
from pathlib import Path

# Criação da instância do FastAPI
app = FastAPI()

# Configurar o diretório de templates
BASE_PATH = Path(__file__).resolve().parent
TEMPLATES = Jinja2Templates(directory=str(BASE_PATH / "templates"))
STATIC_DIR = BASE_PATH / "static"
app.mount("/static", StaticFiles(directory=STATIC_DIR), name="static")

# Incluindo os controladores (routers)
app.include_router(filme_router, tags=["API - Filmes"])
app.include_router(usuario_router, tags=["API - Usuários"])
app.include_router(auth_router, tags=["API - Auth"])

# Incluindo as views
app.include_router(filme_view_router, tags=["Views - Filmes"])
app.include_router(usuario_view_router, tags=["Views - Usuários"])
app.include_router(auth_view_router, tags=["Views - Auth"])
