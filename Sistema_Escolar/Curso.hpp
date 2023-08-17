#pragma once
#include<iostream>
#include<string>

class Curso
{
private:
    std::string nome;
    std::string descricao;
    std::string codigo;
public:
    Curso();
    Curso(std::string nome,std::string descricao,std::string codigo);
    ~Curso();
    void cadastrar();
    friend std::ostream& operator<<(std::ostream& os, const Curso& p);
};

