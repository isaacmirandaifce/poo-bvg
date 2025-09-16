#include "Persistencia.h"
#include "SistemaAcademico.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <sys/stat.h>
#include <cctype>

#ifdef _WIN32
#include <direct.h>
#define MKDIR(dir) _mkdir(dir)
#else
#include <unistd.h>
#define MKDIR(dir) mkdir(dir, 0755)
#endif

Persistencia::Persistencia(const std::string& dir)
    : baseDir(dir),
      alunosPath(dir + std::string("/alunos.csv")),
      professoresPath(dir + std::string("/professores.csv")),
      disciplinasPath(dir + std::string("/disciplinas.csv")) {}

void Persistencia::ensureDirExists() const {
    struct stat st{};
    if (stat(baseDir.c_str(), &st) != 0) {
        MKDIR(baseDir.c_str());
    }
}

static bool is_header_line(const std::string& line){
    if(line.empty()) return false;
    return !std::isdigit(static_cast<unsigned char>(line[0]));
}

std::vector<std::string> Persistencia::readLines(const std::string& path){
    std::ifstream in(path);
    std::vector<std::string> lines;
    if(!in.good()) return lines;
    std::string line;
    bool header_skipped = false;
    while(std::getline(in, line)){
        if(!header_skipped && is_header_line(line)){
            header_skipped = true;
            continue;
        }
        if(line.empty()) continue;
        lines.push_back(line);
    }
    return lines;
}

std::string Persistencia::joinLines(const std::vector<std::string>& v){
    std::ostringstream oss;
    for(size_t i=0;i<v.size();++i){
        oss << v[i];
        if(i+1<v.size()) oss << "\n";
    }
    return oss.str();
}

void Persistencia::atomicWrite(const std::string& path, const std::string& content){
    std::string tmp = path + ".tmp";
    {
        std::ofstream out(tmp, std::ios::trunc);
        out << content;
    }
    std::remove(path.c_str());
    std::rename(tmp.c_str(), path.c_str());
}

void Persistencia::loadAll(SistemaAcademico& sistema){
    ensureDirExists();
    auto aLines = readLines(alunosPath);
    auto pLines = readLines(professoresPath);
    auto dLines = readLines(disciplinasPath);

    for(const auto& l : aLines){
        try { sistema.getAlunosMut().push_back(Aluno::fromCSV(l)); }
        catch(const std::exception& e){ std::cerr << "[WARN aluno] " << e.what() << "\n"; }
    }
    for(const auto& l : pLines){
        try { sistema.getProfessoresMut().push_back(Professor::fromCSV(l)); }
        catch(const std::exception& e){ std::cerr << "[WARN prof] " << e.what() << "\n"; }
    }
    for(const auto& l : dLines){
        try { sistema.getDisciplinasMut().push_back(Disciplina::fromCSV(l)); }
        catch(const std::exception& e){ std::cerr << "[WARN disc] " << e.what() << "\n"; }
    }
}

void Persistencia::saveAll(const SistemaAcademico& sistema) const{
    ensureDirExists();
    std::vector<std::string> alunosLines = {"id;nome;curso"};
    for(const auto& a : sistema.getAlunos()) alunosLines.push_back(a.toCSV());

    std::vector<std::string> professoresLines = {"id;nome;area"};
    for(const auto& p : sistema.getProfessores()) professoresLines.push_back(p.toCSV());

    std::vector<std::string> disciplinasLines = {"codigo;nome;cargaHoraria"};
    for(const auto& d : sistema.getDisciplinas()) disciplinasLines.push_back(d.toCSV());

    atomicWrite(alunosPath, joinLines(alunosLines));
    atomicWrite(professoresPath, joinLines(professoresLines));
    atomicWrite(disciplinasPath, joinLines(disciplinasLines));
}
