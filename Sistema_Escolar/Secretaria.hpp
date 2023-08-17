#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include<fstream>
#include<utility>
#include <sqlite3.h>
//#include"Perguntas.hpp"




class Secretaria
{
private:
    std::string login;
    std::string senha;
public:
    Secretaria();
    Secretaria(std::string login, std::string senha);
    ~Secretaria();
    void Cadastrarcursos();
    void CadastrarDisciplinas();
    void CadastrarAlunos();
    void CadastrarTurmas();
    void AlocarAlunos();
    void CadastrarNotas();
  
    
    
    
};


