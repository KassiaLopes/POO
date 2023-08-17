#include"Coordenador.hpp"
std::vector<std::string> perg_aloc_prof;

std::string quoootesql( const std::string& s ) {
    return std::string("'") + s + std::string("'");
}

void Pergt()
{
    perg_aloc_prof.push_back("Ano da Turma ?");
    perg_aloc_prof.push_back("Nome do Professor ?");
}


Coordenador::Coordenador(){}

Coordenador::Coordenador(std::string Login,std::string senha)
{
}

Coordenador::~Coordenador()
{
}

void Coordenador::AlocarProfessor()
{
    sqlite3* DB;
    char* messaggeError;
    
    std::string query = "SELECT * FROM ALOC_PROF;";
    std::string entradas[3];
    Pergt();
    int z=1;
    std::cout<<"BEM-VINDO AO ALOCAMENTO DE PROFESSORES"<<std::endl;
    std::cout<<"         Aperte Enter para Entrar" << std::endl;
    //std::cin.ignore(9999999, '\n');
    for (int i = 0; i <= z; i++)
    {
        int exit = sqlite3_open("Aloc_prof.db", &DB);
        std::cin.ignore(9999999, '\n');
        for (int i = 0; i < 2; i++)
        {
            std::cout<<perg_aloc_prof[i]<<std::endl;
            getline(std::cin,entradas[i]);    
        }


        std::string sql ="INSERT INTO ALOC_PROF (Turma,Professor) VALUES ("
        + quoootesql(entradas[0]) + ","
        + quoootesql(entradas[1]) +");";

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) 
        {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(messaggeError);
        }
        else{std::cout << "Professor(a) Alocado(a) com Sucesso" << std::endl;}

        sqlite3_close(DB);

        std::cout<<"Deseja Alocar um(a) Novo(a) Professor(a) ?"<<std::endl
            <<"Caso queria Aperte s"<<std::endl;
        std::string chave;
        std::cin>>chave;
        if (chave == "S" or chave == "s"){z+=1;std::cout<<std::endl;}
        else{break;std::cout<<std::endl;}
    }    
}
