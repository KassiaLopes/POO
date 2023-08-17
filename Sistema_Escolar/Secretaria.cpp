#include"Secretaria.hpp"
void perguntas_Dis();
std::vector<std::string> perg_Curso;
std::vector<std::string> perguntas;
std::vector<std::string> perg_aluno;
std::vector<std::string> perg_turma;
std::vector<std::string> perg_Aloc_Alunos;
std::vector<std::string> perg_Notas_Alunos;

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}

std::string quotesql( const std::string& s ) {
    return std::string("'") + s + std::string("'");
}

/////CONSTRUTORES E DESTRUTORES///////
Secretaria::Secretaria(){}

Secretaria::Secretaria(std::string login, std::string senha)
:login(login),senha(senha)
{
}

Secretaria::~Secretaria()
{
}

////////////FIM CONSTRUTORES E DESTRUTORES///////////////

void Secretaria::Cadastrarcursos()
{
    sqlite3* DB;
    char* messaggeError;
    
    std::string query = "SELECT * FROM CURSOS;";
    std::string entradas[4];
    perguntas_Dis();
    int z=1;
    std::cout<<"BEM-VINDO AO CADASTRAMENTO DE CURSOS"<<std::endl;
    std::cout<<"         Aperte Enter para Entrar" << std::endl;
    //std::cin.ignore(9999999, '\n');
    for (int i = 0; i <= z; i++)
    {
        int exit = sqlite3_open("Cursos.db", &DB);
        std::cin.ignore(9999999, '\n');
        for (int i = 0; i < 4; i++)
        {
            std::cout<<perg_Curso[i]<<std::endl;
            getline(std::cin,entradas[i]);    
        }


        std::string sql ="INSERT INTO CURSOS (Codigo,Curso,Descricao,Coordenador) VALUES ("
        + quotesql(entradas[0]) + ","
        + quotesql(entradas[1]) + ","
        + quotesql(entradas[2]) + ","
        + quotesql(entradas[3]) + ");";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) 
        {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(messaggeError);
        }
        else{std::cout << "Curso Cadastrado com Sucesso" << std::endl;}

        sqlite3_close(DB);

        std::cout<<"Deseja Cadastrar um Novo Curso ?"<<std::endl
            <<"Caso queria Aperte s"<<std::endl;
        std::string chave;
        std::cin>>chave;
        if (chave == "S" or chave == "s"){z+=1;std::cout<<std::endl;}
        else{break;std::cout<<std::endl;}
    } 
}


void Secretaria::CadastrarDisciplinas()
{
    sqlite3* DB;
    char* messaggeError;
    
    std::string query = "SELECT * FROM DISCIPLINAS;";
    std::string entradas[6];
    perguntas_Dis();
    int z=1;
    std::cout<<"BEM-VINDO AO CADASTRAMENTO DE DISCIPLINAS"<<std::endl;
    std::cout<<"         Aperte Enter para Entrar" << std::endl;
    //std::cin.ignore(9999999, '\n');
    for (int i = 0; i <= z; i++)
    {
        int exit = sqlite3_open("Disciplinas.db", &DB);
        std::cin.ignore(9999999, '\n');
        for (int i = 0; i < 6; i++)
        {
            std::cout<<perguntas[i]<<std::endl;
            getline(std::cin,entradas[i]);    
        }


        std::string sql ="INSERT INTO DISCIPLINAS (Codigo,Descricao,Carga_Horaria,Ementa,Bibliografia,Pre_Requisitos) VALUES ("
        + quotesql(entradas[0]) + ","
        + quotesql(entradas[1]) + ","
        + quotesql(entradas[2]) + ","
        + quotesql(entradas[3]) + ","
        + quotesql(entradas[4]) + ","
        + quotesql(entradas[5]) +");";

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) 
        {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(messaggeError);
        }
        else{std::cout << "Disciplina Cadastrada com Sucesso" << std::endl;}

        sqlite3_close(DB);

        std::cout<<"Deseja Cadastrar uma Nova Disciplina ?"<<std::endl
            <<"Caso queria Aperte s"<<std::endl;
        std::string chave;
        std::cin>>chave;
        if (chave == "S" or chave == "s"){z+=1;std::cout<<std::endl;}
        else{break;std::cout<<std::endl;}
    }    
}


void Secretaria::CadastrarAlunos()
{
    sqlite3* DB;
    char* messaggeError;
    
    std::string query = "SELECT * FROM ALUNOS;";
    std::string entradas[5];
    perguntas_Dis();
    int z=1;
    std::cout<<"BEM-VINDO AO CADASTRAMENTO DE ALUNOS"<<std::endl;
    std::cout<<"         Aperte Enter para Entrar" << std::endl;
    //std::cin.ignore(9999999, '\n');
    for (int i = 0; i <= z; i++)
    {
        int exit = sqlite3_open("Alunos.db", &DB);
        std::cin.ignore(9999999, '\n');
        for (int i = 0; i < 5; i++)
        {
            std::cout<<perg_aluno[i]<<std::endl;
            getline(std::cin,entradas[i]);    
        }


        std::string sql ="INSERT INTO ALUNOS (Matricula,Nome,Endereco,Telefone,Curso_Aprovado) VALUES ("
        + quotesql(entradas[0]) + ","
        + quotesql(entradas[1]) + ","
        + quotesql(entradas[2]) + ","
        + quotesql(entradas[3]) + ","
        + quotesql(entradas[4]) +");";

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) 
        {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(messaggeError);
        }
        else{std::cout << "Aluno(a) Cadastrado(a) com Sucesso" << std::endl;}

        sqlite3_close(DB);

        std::cout<<"Deseja Cadastrar um(a) Novo(a) Aluno(a) ?"<<std::endl
            <<"Caso queria Aperte s"<<std::endl;
        std::string chave;
        std::cin>>chave;
        if (chave == "S" or chave == "s"){z+=1;std::cout<<std::endl;}
        else{break;std::cout<<std::endl;}
    }    
}

void Secretaria::CadastrarTurmas()
{
    sqlite3* DB;
    char* messaggeError;
    
    std::string query = "SELECT * FROM TURMAS;";
    std::string entradas[5];
    perguntas_Dis();
    int z=1;
    std::cout<<"BEM-VINDO AO CADASTRAMENTO DE TURMAS"<<std::endl;
    std::cout<<"         Aperte Enter para Entrar" << std::endl;
    //std::cin.ignore(9999999, '\n');
    for (int i = 0; i <= z; i++)
    {
        int exit = sqlite3_open("Turmas.db", &DB);
        std::cin.ignore(9999999, '\n');
        for (int i = 0; i < 4; i++)
        {
            std::cout<<perg_turma[i]<<std::endl;
            getline(std::cin,entradas[i]);    
        }


        std::string sql ="INSERT INTO TURMAS (Ano,Semestre,Horarios,Dias_da_Semana) VALUES ("
        + quotesql(entradas[0]) + ","
        + quotesql(entradas[1]) + ","
        + quotesql(entradas[2]) + ","
        + quotesql(entradas[3]) +");";

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) 
        {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(messaggeError);
        }
        else{std::cout << "Turma Cadastrada com Sucesso" << std::endl;}

        sqlite3_close(DB);

        std::cout<<"Deseja Cadastrar uma Nova Turma ?"<<std::endl
            <<"Caso queria Aperte s"<<std::endl;
        std::string chave;
        std::cin>>chave;
        if (chave == "S" or chave == "s"){z+=1;std::cout<<std::endl;}
        else{break;std::cout<<std::endl;}
    }    
}





void Secretaria::AlocarAlunos()
{
    sqlite3* DB;
    char* messaggeError;
    
    std::string query = "SELECT * FROM ALOC_ALUNO;";
    std::string entradas[3];
    perguntas_Dis();
    int z=1;
    std::cout<<"BEM-VINDO AO ALOCAMENTO DE ALUNOS"<<std::endl;
    std::cout<<"         Aperte Enter para Entrar" << std::endl;
    //std::cin.ignore(9999999, '\n');
    for (int i = 0; i <= z; i++)
    {
        int exit = sqlite3_open("Aloc_aluno.db", &DB);
        std::cin.ignore(9999999, '\n');
        for (int i = 0; i < 2; i++)
        {
            std::cout<<perg_Aloc_Alunos[i]<<std::endl;
            getline(std::cin,entradas[i]);    
        }


        std::string sql ="INSERT INTO ALOC_ALUNO (Turma,Aluno) VALUES ("
        + quotesql(entradas[0]) + ","
        + quotesql(entradas[1]) +");";

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) 
        {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(messaggeError);
        }
        else{std::cout << "Aluno(a) Alocado(a) com Sucesso" << std::endl;}

        sqlite3_close(DB);

        std::cout<<"Deseja Alocar um(a) Novo(a) Aluno(a) ?"<<std::endl
            <<"Caso queria Aperte s"<<std::endl;
        std::string chave;
        std::cin>>chave;
        if (chave == "S" or chave == "s"){z+=1;std::cout<<std::endl;}
        else{break;std::cout<<std::endl;}
    }    
}

void Secretaria::CadastrarNotas()
{
    sqlite3* DB;
    char* messaggeError;
    
    std::string query = "SELECT * FROM NOTAS_ALUNOS;";
    std::string entradas[8];
    float notas[8];
    //float valor=0;
    perguntas_Dis();
    int z=1;
    std::cout<<"BEM-VINDO AO CADASTRAMENTO DE NOTAS"<<std::endl;
    std::cout<<"         Aperte Enter para Entrar" << std::endl;
    //std::cin.ignore(9999999, '\n');
    for (int i = 0; i <= z; i++)
    {
        int exit = sqlite3_open("Notas_alunos.db", &DB);
        std::cin.ignore(9999999, '\n');
        std::cout<<perg_Notas_Alunos[0]<<std::endl;
        getline(std::cin,entradas[0]);
        std::cout<<perg_Notas_Alunos[1]<<std::endl;
        getline(std::cin,entradas[1]);
        std::cout<<perg_Notas_Alunos[2]<<std::endl;
        std::cin>>notas[2];
        entradas[2] = std::to_string(notas[2]); // Converter de float para string
        std::cout<<perg_Notas_Alunos[3]<<std::endl;
        std::cin>>notas[3];
        entradas[3] = std::to_string(notas[3]); // Converter de float para string
        float x=((notas[2]+notas[3])/2);
        if ( x < 7)
        {
           
            std::cout<<perg_Notas_Alunos[4]<<std::endl;
            std::cin>>notas[4];
            entradas[4] = std::to_string(notas[4]);
            if (((notas[4]+x)/2) >= 5)
            {
                
                entradas[5] = "Aprovado_por_Nota";
                //std::cout<<"Entrada 5"<<entradas[5]<<std::endl;
            }
            else
            {
                entradas[5] = "Reprovado_por_Nota";
                //std::cout<<"Entrada 5 else"<<entradas[5]<<std::endl;
            }

 
            //getline(std::cin,entradas[i]);    
          
        }
        else
        {
            entradas[4]="NULO";
            entradas[5] = "Aprovado_por_Nota";

        }
        std::cin.ignore(9999999, '\n');
        std::cout<<perg_Notas_Alunos[6]<<std::endl;
        std::cin>>notas[4];
        if (notas[4]<75)
        {
            entradas[5] = "Reprovado_por_Falta";
        }
        entradas[6] = std::to_string(notas[4]); // Converter de float para string
        
        //getline(std::cin,entradas[6]);
       /* for (int i = 0; i < 2; i++)
        {
            std::cout<<perg_Notas_Alunos[i]<<std::endl;
            getline(std::cin,entradas[i]);    
        }
        for (int i = 2; i < 4; i++)
        {
            std::cout<<perg_Notas_Alunos[i]<<std::endl;
            std::cin>>notas[i];
            entradas[i] = notas[i];
            //getline(std::cin,entradas[i]);    
        }
        
        if (((notas[2]+notas[3])/2) < 7)
        {
            for (int i = 4; i < 5; i++)
            {
                std::cout<<perg_Notas_Alunos[i]<<std::endl;
                std::cin>>notas[i];
                entradas[i] = notas[i];
                //getline(std::cin,entradas[i]);    
            }
        }
        else
        {
            entradas[4]="NULO";
        }
        std::cout<<perg_Notas_Alunos[5]<<std::endl;
        getline(std::cin,entradas[5]); */
    

        std::string sql ="INSERT INTO NOTAS_ALUNOS (Disciplina,Aluno,AP_1,AP_2,AF,Situacao,Frequencia) VALUES ("
        + quotesql(entradas[0]) + ","
        + quotesql(entradas[1]) + ","
        + quotesql(entradas[2]) + ","
        + quotesql(entradas[3]) + ","
        + quotesql(entradas[4]) + ","
        + quotesql(entradas[5]) + ","
        + quotesql(entradas[6]) +");";

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) 
        {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(messaggeError);
        }
        else{std::cout << "Notas Cadastradas com Sucesso" << std::endl;}

        sqlite3_close(DB);
        
        std::cout<<"Deseja Cadastrar um Novo(a) Aluno(a) ?"<<std::endl
            <<"Caso queria Aperte s"<<std::endl;
        std::string chave;
        std::cin>>chave;
        if (chave == "S" or chave == "s"){z+=1;std::cout<<std::endl;}
        else
        {
            break;
            std::cout<<std::endl;
        }
    }    
}






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
    perg_aluno.push_back("Digite a Matricula do Aluno(a)");
    perg_aluno.push_back("Digite o Nome do Aluno(a)");
    perg_aluno.push_back("Digite o Endereço do Aluno(a)");    
    perg_aluno.push_back("Digite o Telefone Do ALuno(a)");
    perg_aluno.push_back("Digite o Curso Do Aluno(a)");

    //PERGUNTAS PARA TURMA
    perg_turma.push_back("Digite o Ano da Turma ");
    perg_turma.push_back("Digite o Semestre da Turma");
    perg_turma.push_back("Digite os Horarios");
    perg_turma.push_back("Digite o Dia da Semana da Turma");
    
    //PERGUNTAS PARA ALOC ALUNOS
    
    perg_Aloc_Alunos.push_back("Ano da Turma ?");
    perg_Aloc_Alunos.push_back("Nome do Aluno(a) ?");

    //PERGUNTAS DE NOTAS
    perg_Notas_Alunos.push_back("Digite o nome da Disciplina");
    perg_Notas_Alunos.push_back("Digite o Nome do Aluno(a)");
    perg_Notas_Alunos.push_back("Digite a Nota da AP_1");
    perg_Notas_Alunos.push_back("Digite a Nota da AP_2");
    perg_Notas_Alunos.push_back("Digite a Nota da AF");
    perg_Notas_Alunos.push_back("Digite a Situação do Aluno(a)");
    perg_Notas_Alunos.push_back("Digite a Frequência");


}