#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sqlite3.h>
class Recursos_Humanos
{
private:
    std::string Login;
    std::string senha;
public:
    Recursos_Humanos();
    Recursos_Humanos(std::string Login,std::string senha);
    
    ~Recursos_Humanos();
    void CadastrarProfessor();
};

