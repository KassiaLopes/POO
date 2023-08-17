#include"Recursos_Humanos.hpp"
std::vector<std::string> perg_prof;


std::string quootesql( const std::string& s ) {
    return std::string("'") + s + std::string("'");
}


void perguntaas_Dis()
{
    // PERGUNTAS PARA PROFESSOR
    perg_prof.push_back("Digite o Siape do Professor(a)");
    perg_prof.push_back("Digite o Nome do Professor(a)");
    perg_prof.push_back("Digite o Endereço do Professor(a)");
    perg_prof.push_back("Digite o Telefone Do Professor(a)");
    perg_prof.push_back("Digite o Titulo do Professor(a)");
    perg_prof.push_back("Digite a Função do Professor(a)");
    
}

Recursos_Humanos::Recursos_Humanos(){}

Recursos_Humanos::Recursos_Humanos(std::string Login,std::string senha)
{
}

Recursos_Humanos::~Recursos_Humanos()
{
}

void Recursos_Humanos::CadastrarProfessor()
{
    sqlite3* DB;
    char* messaggeError;
    
    std::string query = "SELECT * FROM PROFESSOR;";
    std::string entradas[7];
    perguntaas_Dis();
    int z=1;
    std::cout<<"BEM-VINDO AO CADASTRAMENTO DE PROFESSORES"<<std::endl;
    std::cout<<"         Aperte Enter para Entrar" << std::endl;
    //std::cin.ignore(9999999, '\n');
    for (int i = 0; i <= z; i++)
    {
        int exit = sqlite3_open("Professor.db", &DB);
        std::cin.ignore(9999999, '\n');
        for (int i = 0; i < 6; i++)
        {
            std::cout<<perg_prof[i]<<std::endl;
            getline(std::cin,entradas[i]);    
        }


        std::string sql ="INSERT INTO PROFESSOR (Siape,Nome,Endereco,Telefone,Titulo,Funcao) VALUES ("
        + quootesql(entradas[0]) + ","
        + quootesql(entradas[1]) + ","
        + quootesql(entradas[2]) + ","
        + quootesql(entradas[3]) + ","
        + quootesql(entradas[4]) + ","
        + quootesql(entradas[5]) +");";

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
        if (exit != SQLITE_OK) 
        {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(messaggeError);
        }
        else{std::cout << "Professor(a) Cadastrado(a) com Sucesso" << std::endl;}

        sqlite3_close(DB);

        std::cout<<"Deseja Cadastrar um(a) Novo(a) Professor(a) ?"<<std::endl
            <<"Caso queria Aperte s"<<std::endl;
        std::string chave;
        std::cin>>chave;
        if (chave == "S" or chave == "s"){z+=1;std::cout<<std::endl;}
        else{break;std::cout<<std::endl;}
    }    
}
