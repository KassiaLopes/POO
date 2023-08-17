#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sqlite3.h>

class Coordenador
{
private:
    std::string Login;
    std::string senha;
public:
    Coordenador();
    Coordenador(std::string Login,std::string senha);
    ~Coordenador();
    void AlocarProfessor();
};

