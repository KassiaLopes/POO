#pragma once
//#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> perg_Curso;
std::vector<std::string> perguntas;
std::vector<std::string> perg_aluno;
std::vector<std::string> perg_prof;
std::vector<std::string> perg_turma;

void perguntas_Dis()
{
    // PERGUNTAS PARA O CURSO
    perg_Curso.push_back("Digite o Codigo do Curso ");
    perg_Curso.push_back("Digite o Nome do Curso");
    perg_Curso.push_back("Digite a Descrição do Curso");
    perg_Curso.push_back("Digite o Nome do Coordenador");
    // PERGUNTAS PARA DISCIPLINA
    perguntas.push_back("Digite o nome da Materia");
    perguntas.push_back("Digite a Ementa da Materia");
    perguntas.push_back("Digite a Bibliografia da Materia");
    perguntas.push_back("Digite os Pre-Requisitos da Materia");
    perguntas.push_back("Digite o Codigo da Materia");
    perguntas.push_back("Digite a Carga Horaria da Materia");

    // PERGUNTAS PARA ALUNO
    perg_aluno.push_back("Digite o Nome do Aluno(a)");
    perg_aluno.push_back("Digite o Endereço do Aluno(a)");
    perg_aluno.push_back("Digite o Telefone Do ALuno(a)");
    perg_aluno.push_back("Digite a Matricula do Aluno(a)");
    perg_aluno.push_back("Digite o Curso Do Aluno(a)");


    // PERGUNTAS PARA PROFESSOR
    perg_prof.push_back("Digite o Nome do Professor(a)");
    perg_prof.push_back("Digite o Endereço do Professor(a)");
    perg_prof.push_back("Digite o Telefone Do Professor(a)");
    perg_prof.push_back("Digite o Titulo do Professor(a)");
    perg_prof.push_back("Digite a Função do Professor(a)");
    perg_prof.push_back("Digite o Siape do Professor(a)");

    //PERGUNTAS PARA TURMA
    perg_turma.push_back("Digite o Ano da Turma ");
    perg_turma.push_back("Digite o Semestre da Turma");
    perg_turma.push_back("Digite os Horarios");
    perg_turma.push_back("Digite o Dia da Semana da Turma");
    

}