#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

class Professor {
public:
    int id;
    std::string nome;

    Professor(int id = 0, const std::string& nome = "");
    std::string to_csv() const;
    static Professor from_csv(const std::string& csv_line);
};

#endif // PROFESSOR_H