#pragma once

#include<iostream>
#include<sqlite3.h>
#include<string>
#include<vector>
#include"Secretaria.hpp"
#include"Recursos_Humanos.hpp"
#include"Coordenador.hpp"
using namespace std;
vector<string> Turmas;
string prof;
int z=0;
static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        prof=argv[i];
    }
  
    printf("\n");
    return 0;
}

std::string quoteesql( const std::string& s ) {
    return std::string("'") + s + std::string("'");
}

void Cadastrarcurso()
{
    Secretaria a;
    a.Cadastrarcursos();
}
void VisualizarCursos()
{
    sqlite3* DB;
    int exit = sqlite3_open("Cursos.db", &DB);
    string query = "SELECT * FROM CURSOS;";
    cout << "TABELA DE CURSOS CADASTRADOS" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    sqlite3_close(DB);
    
}

void CadastrarDisciplinas()
{
    Secretaria a;
    a.CadastrarDisciplinas();
   
}

void VisualizarDisciplinas()
{
    sqlite3* DB;
    int exit = sqlite3_open("Disciplinas.db", &DB);
    string query = "SELECT * FROM DISCIPLINAS;";
    cout << "TABELA DE DISCIPLINAS CADASTRADAS" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    sqlite3_close(DB);
}
void CadastrarAlunos()
{
    Secretaria a;
    a.CadastrarAlunos();
}
void VisualizarAlunos()
{
    sqlite3* DB;
    int exit = sqlite3_open("Alunos.db", &DB);
    string query = "SELECT * FROM ALUNOS;";
    cout << "TABELA DE ALUNO(A)S CADASTRADO(A)S" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void CadastrarProfessores()
{
    Recursos_Humanos a;
    a.CadastrarProfessor();
}

void VisualizarProfessor()
{
    sqlite3* DB;
    int exit = sqlite3_open("Professor.db", &DB);
    string query = "SELECT * FROM PROFESSOR;";
    cout << "TABELA DE PROFESSOR(A)S CADASTRADO(A)S" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void CadastrarTurmas()
{
    Secretaria a;
    a.CadastrarTurmas();
}

void VisualizarTurmas()
{
    sqlite3* DB;
    int exit = sqlite3_open("Turmas.db", &DB);
    string query = "SELECT * FROM TURMAS;";
    cout << "TABELA DE TURMAS CADASTRADAS" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}
/// MODELO DE ALOCAGEM///
void AlocarProfessor()
{
    std::string valor ="-1";
    sqlite3* DBB;
    int exitt = sqlite3_open("Turmas.db", &DBB);
    string queryy = "SELECT Ano FROM TURMAS WHERE Ano > "+ quoteesql(valor) +"";
    std::cout << "TABELA DE TURMAS CADASTRADAS" << std::endl;
    sqlite3_exec(DBB, queryy.c_str(), callback, NULL, NULL); 
    sqlite3_close(DBB);


    sqlite3* DB;
    int exit = sqlite3_open("Professor.db", &DB);
    string query = "SELECT Nome FROM PROFESSOR ";
    cout << "TABELA DE PROFESSOR(A)S CADASTRADO(A)S" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);

    Coordenador a;
    a.AlocarProfessor();


}

static int PegaTurma(void* data, int argc, char** argv, char** azColName)
{
    int i;
 
    for (i = 0; i < argc; i++) {
        ("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        Turmas.push_back(argv[i]);
        z++;
    }
    
   
    return 0;
}

void vetor()
{
    string vet[99];
    for (int i = 0; i < z; i++)
    {
        vet[i]=Turmas[i];
    }
    for (int i = 0; i < z; i++)
    {
        Turmas.pop_back();
    }
    
    
    for (int i = 0; i < (z-1); i++)
    {
        for (int y = 1; y < z; y++)
        {
            if(vet[i]==vet[y])
            {
                
                vet[y]="0";
            }
        }
        
    }

    for (int i = 0; i < z; i++)
    {
        if (vet[i]!="0")
        {
            Turmas.push_back(vet[i]);
            cout<<"Turma ----->"<<Turmas[i]<<endl;
            sqlite3* D;
            int exitt = sqlite3_open("Aloc_prof.db", &D);
            string queryy = "SELECT Professor FROM ALOC_PROF WHERE Turma = "+ quoteesql(Turmas[i]) +";";
            //cout << "TABELA DE PROFESSORES ALOCADOS" << endl;
            sqlite3_exec(D, queryy.c_str(), callback, NULL, NULL); 
            sqlite3_close(D);
        }
        
    }
    //cout<<"PASSOU POR AQUI"<<endl;
    z=0;
    
    
}


void vetor2()
{
    string vet[99];
    for (int i = 0; i < z; i++)
    {
        vet[i]=Turmas[i];
    }
    for (int i = 0; i < z; i++)
    {
        Turmas.pop_back();
    }
    
    
    for (int i = 0; i < (z-1); i++)
    {
        for (int y = 1; y < z; y++)
        {
            if(vet[i]==vet[y])
            {
                
                vet[y]="0";
            }
        }
        
    }

    for (int i = 0; i < z; i++)
    {
        if (vet[i]!="0")
        {
            Turmas.push_back(vet[i]);
            cout<<"Turma ----->"<<Turmas[i]<<endl;
            sqlite3* D;
            int exitt = sqlite3_open("Aloc_aluno.db", &D);
            string queryy = "SELECT Aluno FROM ALOC_ALUNO WHERE Turma = "+ quoteesql(Turmas[i]) +";";
            //cout << "TABELA DE PROFESSORES ALOCADOS" << endl;
            sqlite3_exec(D, queryy.c_str(), callback, NULL, NULL); 
            sqlite3_close(D);
        }
        
    }
    //cout<<"PASSOU POR AQUI"<<endl;
    z=0;
    
    
}


void VisualizarAlocProfs()
{

    
    sqlite3* DB;
    int exit = sqlite3_open("Aloc_prof.db", &DB);
    string query = "SELECT Turma FROM ALOC_PROF;";
    cout << "TABELA DE PROFESSORES ALOCADOS" << endl;
    sqlite3_exec(DB, query.c_str(), PegaTurma, NULL, NULL); 
    sqlite3_close(DB);
    vetor();
    
    

}


void AlocarAluno()
{
    std::string valor ="-1";
    sqlite3* DBB;
    int exitt = sqlite3_open("Turmas.db", &DBB);
    string queryy = "SELECT Ano FROM TURMAS WHERE Ano > "+ quoteesql(valor) +"";
    std::cout << "TABELA DE TURMAS CADASTRADAS" << std::endl;
    sqlite3_exec(DBB, queryy.c_str(), callback, NULL, NULL); 
    sqlite3_close(DBB);


    sqlite3* DB;
    int exit = sqlite3_open("Alunos.db", &DB);
    string query = "SELECT Nome FROM ALUNOS ";
    cout << "TABELA DE ALUNO(A)S CADASTRADO(A)S" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);

    Secretaria a;
    a.AlocarAlunos();


}

void VisualizarAlunosAlocs()
{
    sqlite3* DB;
    int exit = sqlite3_open("Aloc_aluno.db", &DB);
    string query = "SELECT Turma FROM ALOC_ALUNO;";
    cout << "TABELA DE ALUNO(A)S ALOCADOS" << endl;
    sqlite3_exec(DB, query.c_str(), PegaTurma, NULL, NULL); 
    sqlite3_close(DB);
    vetor2();
}

void CadastrarNotas()
{
    std::cin.ignore(9999999, '\n');
   // VisualizarAlocProfs();
    sqlite3* DB;
    string valor;
    cout<<"Digite Seu Nome Professor"<<endl;
    getline(cin, valor);
    int exit = sqlite3_open("Aloc_prof.db", &DB);
    string query = "SELECT Turma FROM ALOC_PROF WHERE Professor = "+ quoteesql(valor) +";";
    cout << "SUA TURMA ALOCADA" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
    
    sqlite3* D;
    int exitt = sqlite3_open("Aloc_aluno.db", &D);
    string queryy = "SELECT Aluno FROM ALOC_ALUNO WHERE Turma = "+ quoteesql(prof) +";";
    cout << "Alunos Da Sua Turma" << endl;
    sqlite3_exec(D, queryy.c_str(), callback, NULL, NULL); 
    sqlite3_close(D);

    Secretaria a;
    a.CadastrarNotas();
    
}

void Vernotas()
{
    sqlite3* DB;
    int exit = sqlite3_open("Notas_alunos.db", &DB);
    string query = "SELECT * FROM NOTAS_ALUNOS;";
    cout << "TABELA DE TURMAS CADASTRADAS" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void ConsultarNotas()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;
    std::string nome;
    std::cout<<"Digite Seu Nome Aluno"<<std::endl;
    getline(std::cin,nome);
    int exit = sqlite3_open("Notas_alunos.db", &DB);
    string query = "SELECT * FROM NOTAS_ALUNOS WHERE Aluno = "+ quoteesql(nome) +";";
    //cout << "TABELA DE TURMAS CADASTRADAS" << endl;
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}


void atNotas()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite a Disciplina que Deseja Alterar !"<<std::endl;
    getline(std::cin,chave);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite a Coluna que Deseja Alterar !"<<std::endl;
    getline(std::cin,coluna);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite o Novo Valor !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Notas_alunos.db", &DB);
    string query = "UPDATE NOTAS_ALUNOS SET "+ coluna +" = "+ quoteesql(valor) +" WHERE Disciplina = "+ quoteesql(chave) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}
void atAloc_Aluno()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite a Turma que Deseja Alterar !"<<std::endl;
    getline(std::cin,chave);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite a Coluna que Deseja Alterar !"<<std::endl;
    getline(std::cin,coluna);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite o Novo Valor !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Aloc_aluno.db", &DB);
    string query = "UPDATE ALOC_ALUNO SET "+ coluna +" = "+ quoteesql(valor) +" WHERE Disciplina = "+ quoteesql(chave) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}


void atAlocProfs()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite a Turma que Deseja Alterar !"<<std::endl;
    getline(std::cin,chave);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite a Coluna que Deseja Alterar !"<<std::endl;
    getline(std::cin,coluna);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite o Novo Valor !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Aloc_prof.db", &DB);
    string query = "UPDATE ALOC_PROF SET "+ coluna +" = "+ quoteesql(valor) +" WHERE Disciplina = "+ quoteesql(chave) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void atAlunos()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite a Matricula que Deseja Alterar !"<<std::endl;
    getline(std::cin,chave);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite a Coluna que Deseja Alterar !"<<std::endl;
    getline(std::cin,coluna);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite o Novo Valor !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Alunos.db", &DB);
    string query = "UPDATE ALUNOS SET "+ coluna +" = "+ quoteesql(valor) +" WHERE Disciplina = "+ quoteesql(chave) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void atCursos()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite o Codigo do Curso que Deseja Alterar !"<<std::endl;
    getline(std::cin,chave);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite a Coluna que Deseja Alterar !"<<std::endl;
    getline(std::cin,coluna);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite o Novo Valor !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Cursos.db", &DB);
    string query = "UPDATE CURSOS SET "+ coluna +" = "+ quoteesql(valor) +" WHERE Disciplina = "+ quoteesql(chave) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void atDisciplina()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite o Codigo da Disciplina que Deseja Alterar !"<<std::endl;
    getline(std::cin,chave);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite a Coluna que Deseja Alterar !"<<std::endl;
    getline(std::cin,coluna);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite o Novo Valor !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Disciplinas.db", &DB);
    string query = "UPDATE DISCIPLINAS SET "+ coluna +" = "+ quoteesql(valor) +" WHERE Disciplina = "+ quoteesql(chave) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void atProfessores()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite o Siape que Deseja Alterar !"<<std::endl;
    getline(std::cin,chave);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite a Coluna que Deseja Alterar !"<<std::endl;
    getline(std::cin,coluna);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite o Novo Valor !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Professor.db", &DB);
    string query = "UPDATE PROFESSOR SET "+ coluna +" = "+ quoteesql(valor) +" WHERE Disciplina = "+ quoteesql(chave) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void atTurmas()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite o Ano da Turma que Deseja Alterar !"<<std::endl;
    getline(std::cin,chave);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite a Coluna que Deseja Alterar !"<<std::endl;
    getline(std::cin,coluna);
    //std::cin.ignore(9999999, '\n');
    std::cout<<"Digite o Novo Valor !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Turmas.db", &DB);
    string query = "UPDATE TURMAS SET "+ coluna +" = "+ quoteesql(valor) +" WHERE Disciplina = "+ quoteesql(chave) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}
void AtualizarListas()
{
    int valor;
    cout<<"Escolha uma Opção:"<<endl;
    cout<<"1--->Atualizar Notas"<<endl;
    cout<<"2--->Atualizar Alocação de Alunos"<<endl;
    cout<<"3--->Atualizar Alocação de professores"<<endl;
    cout<<"4--->Atualizar Alunos"<<endl;
    cout<<"5--->Atualizar Cursos"<<endl;
    cout<<"6--->Atualizar Disciplinas"<<endl;
    cout<<"7--->Atualizar Professores"<<endl;
    cout<<"8--->Atualizar Turmas"<<endl;
    cin>>valor;
    if (valor == 1)
    {
        //cout<<"Entrou no 1"<<endl;
        atNotas();
    }
    else if (valor == 2)
    {
        //cout<<"Entrou no 2"<<endl;
        atAloc_Aluno();
    }
    else if (valor == 3)
    {
        atAlocProfs();
    }
    else if (valor == 4)
    {
        atAlunos();
    }
    else if (valor == 5)
    {
        atCursos();   
    }
    else if (valor == 6)
    {
        atDisciplina();
    }
    else if (valor == 7)
    {
        atProfessores();
    }
    else if (valor == 8)
    {
        atTurmas();
    }
     
    
    
       
}

void DNotas()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite a Disciplina que Deseja Deletar !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Notas_alunos.db", &DB);
    string query = "DELETE FROM NOTAS_ALUNOS WHERE Disciplina = "+ quoteesql(valor) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}
void DAloc_Aluno()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite o Nome do Aluno Para Ser Retirado da Turma !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Aloc_aluno.db", &DB);
    string query = "DELETE FROM ALOC_ALUNO WHERE Aluno = "+ quoteesql(valor) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}


void DAlocProfs()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite o Professor que Deseja Deletar da Turma !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Aloc_prof.db", &DB);
    string query = "DELETE FROM ALOC_PROF WHERE Professor = "+ quoteesql(valor) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void DAlunos()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite a Matricula para ser Deletada !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Alunos.db", &DB);
    string query = "DELETE FROM ALUNOS WHERE Matricula = "+ quoteesql(valor) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void DCursos()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;

    std::cout<<"Digite o Codigo do Curso para ser Deletado !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Cursos.db", &DB);
    string query = "DELETE FROM CURSOS WHERE Codigo = "+ quoteesql(valor) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void DDisciplina()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite o Codigo da Disciplina para ser Deletada !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Disciplinas.db", &DB);
    string query = "DELETE FROM DISCIPLINAS WHERE Codigo = "+ quoteesql(valor) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void DProfessores()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;

    std::string coluna,valor,chave;
    std::cout<<"Digite o Siape que Deseja Deletar !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Professor.db", &DB);
    string query = "DELETE FROM PROFESSOR WHERE Siape = "+ quoteesql(valor) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}


void DTurmas()
{
    std::cin.ignore(9999999, '\n');
    sqlite3* DB;
    std::string valor;
    std::cout<<"Digite o Ano que Deseja Deletar !"<<std::endl;
    getline(std::cin,valor);
    //std::cin.ignore(9999999, '\n');
    int exit = sqlite3_open("Turmas.db", &DB);
    string query = "DELETE FROM TURMAS WHERE Ano = "+ quoteesql(valor) +";";
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
    sqlite3_close(DB);
}

void DeletarListas()
{
    int valor;
    cout<<"Escolha uma Opção:"<<endl;
    cout<<"1--->Deletar Notas"<<endl;
    cout<<"2--->Deletar Alocação de Alunos"<<endl;
    cout<<"3--->Deletar Alocação de professores"<<endl;
    cout<<"4--->Deletar Alunos"<<endl;
    cout<<"5--->Deletar Cursos"<<endl;
    cout<<"6--->Deletar Disciplinas"<<endl;
    cout<<"7--->Deletar Professores"<<endl;
    cout<<"8--->Deletar Turmas"<<endl;
    cin>>valor;
    if (valor == 1)
    {
        //cout<<"Entrou no 1"<<endl;
        DNotas();
    }
    else if (valor == 2)
    {
        //cout<<"Entrou no 2"<<endl;
        DAloc_Aluno();
    }
    else if (valor == 3)
    {
        DAlocProfs();
    }
    else if (valor == 4)
    {
        DAlunos();
    }
    else if (valor == 5)
    {
        DCursos();   
    }
    else if (valor == 6)
    {
        DDisciplina();
    }
    else if (valor == 7)
    {
        DProfessores();
    }
    else if (valor == 8)
    {
        DTurmas();
    }
}

//chave="Eletronica";
//valor="95.0";
//coluna="Frequencia";