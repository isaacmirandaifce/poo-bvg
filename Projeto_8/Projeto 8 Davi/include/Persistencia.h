#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <string>
#include <vector>

class SistemaAcademico;

class Persistencia {
    std::string baseDir;
    std::string alunosPath;
    std::string professoresPath;
    std::string disciplinasPath;

    void ensureDirExists() const;
    static void atomicWrite(const std::string& path, const std::string& content);
    static std::vector<std::string> readLines(const std::string& path);
    static std::string joinLines(const std::vector<std::string>& v);
public:
    explicit Persistencia(const std::string& dir = "data");

    void loadAll(SistemaAcademico& sistema);
    void saveAll(const SistemaAcademico& sistema) const;

    const std::string& getBaseDir() const { return baseDir; }
};

#endif // PERSISTENCIA_H
