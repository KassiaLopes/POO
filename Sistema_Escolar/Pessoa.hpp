#pragma once
#include<iostream>
#include<string>

class Pessoa
{
protected:
    std::string nome;
    std::string endereco;
    std::string telefone;
public:
    Pessoa();
    Pessoa(std::string nome,std::string endereco,std::string telefone);
    virtual ~Pessoa();
    virtual void cadastrar() = 0;
};
