#include"Functions.hpp"



int main ()
{
   /*sqlite3* DB;
    std::string sql = "CREATE TABLE PROFESSOR("
                      "Siape           TEXT    NOT NULL, "
                      "Nome           TEXT    NOT NULL, "
                      "Endereco           TEXT    NOT NULL, "
                      "Telefone           TEXT    NOT NULL, "
                      "Titulo           TEXT    NOT NULL, "
                      "Funcao       TEXT    NOT NULL );";
    int exit = 0;
    exit = sqlite3_open("Professor.db", &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
  
    if (exit != SQLITE_OK) {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    sqlite3_close(DB);
    return (0);*/

   while (true)
   {
         char escolha;
         cout<<"ESCOLHA O TIPO DE CADASTRAMENTO"<<endl;
         cout<<"1 ----> Cadastramento de Cursos."<<endl
               <<"2 ----> Cadastramento de Disciplinas."<<endl
               <<"3 ----> Cadastramento de Alunos."<<endl
               <<"4 ----> Cadastramento de Professores."<<endl
               <<"5 ----> Cadastramento de Turmas."<<endl
               <<"6 ----> Alocar Professores em Turmas."<<endl
               <<"7 ----> Alocar Alunos em Turmas."<<endl
               <<"8 ----> Alocar Notas nos Alunos."<<endl
               <<"9 ----> Visualizar Cursos Cadastrados. "<<endl
               <<"A ----> Visualizar Disciplinas Cadastradas."<<endl
               <<"B ----> Visualizar Alunos Cadastrados."<<endl
               <<"C ----> Visualizar Professores Cadastrados."<<endl
               <<"D ----> Visualizar Turmas Cadastradas."<<endl
               <<"I ----> Visualizar Professores Alocados."<<endl
               <<"F ----> Visualizar Alunos Alocados."<<endl
               <<"G ----> Visualizar as Notas de Todos os Alunos."<<endl
               <<"H ----> Aluno Visualizar suas Notas."<<endl
               <<"J ----> Atualizar Listas."<<endl
               <<"K ----> Deletar Listas."<<endl
               <<"X ----> UNKNOWN."<<endl
               <<"E ----> Para Fechar o Sistema"<<endl;
         cout<<"Seleção : ";
         cin>>escolha;
         
         if (escolha == '1')
         {
               Cadastrarcurso();
         }
         else if (escolha == '2')
         {
               CadastrarDisciplinas();
         }
         else if (escolha == '3')
         {
               CadastrarAlunos();
         }
         else if (escolha == '4')
         {
               CadastrarProfessores();
         }
         else if (escolha == '5')
         {
               CadastrarTurmas();
         }
         else if (escolha == '6')
         {
               AlocarProfessor();
         }
         else if (escolha == '7')
         {
               AlocarAluno();
         }
         else if (escolha == '8')
         {
            CadastrarNotas();
            
         }
         else if (escolha == '9')
         {
            VisualizarCursos();
            std::cin.ignore(9999999, '\n');
            cout<<"Pressione Enter Para Sair"<<endl;
            std::cin.ignore(9999999, '\n');
         }
         else if (escolha == 'A')
         {
            VisualizarDisciplinas();
            std::cin.ignore(9999999, '\n');
            cout<<"Pressione Enter Para Sair"<<endl;
            std::cin.ignore(9999999, '\n');
         }
         else if (escolha == 'B')
         {
            VisualizarAlunos();
            std::cin.ignore(9999999, '\n');
            cout<<"Pressione Enter Para Sair"<<endl;
            std::cin.ignore(9999999, '\n');
         }
         else if (escolha == 'C')
         {
            VisualizarProfessor();
            std::cin.ignore(9999999, '\n');
            cout<<"Pressione Enter Para Sair"<<endl;
            std::cin.ignore(9999999, '\n');
         }
         else if (escolha == 'D')
         {
            VisualizarTurmas();
            std::cin.ignore(9999999, '\n');
            cout<<"Pressione Enter Para Sair"<<endl;
            std::cin.ignore(9999999, '\n');
         }
         else if (escolha == 'I')
         {
            VisualizarAlocProfs();
            std::cin.ignore(9999999, '\n');
            cout<<"Pressione Enter Para Sair"<<endl;
            std::cin.ignore(9999999, '\n');
         }
         else if (escolha == 'F')
         {
            VisualizarAlunosAlocs();
            std::cin.ignore(9999999, '\n');
            cout<<"Pressione Enter Para Sair"<<endl;
            std::cin.ignore(9999999, '\n');
         }
         else if (escolha == 'G')
         {
            Vernotas();
            std::cin.ignore(9999999, '\n');
            cout<<"Pressione Enter Para Sair"<<endl;
            std::cin.ignore(9999999, '\n');
         }
         else if (escolha == 'H')
         {
            ConsultarNotas();
            std::cin.ignore(9999999, '\n');
            cout<<"Pressione Enter Para Sair"<<endl;
            std::cin.ignore(9999999, '\n');
         }
         else if (escolha == 'J')
         {
           AtualizarListas();
         }
         else if (escolha == 'K')
         {
           DeletarListas();
         }
         else if (escolha == 'X')
         {
           
         }     
         else if (escolha == 'E' )
         {
               cout<<"PROGRAMA ENCERRADO"<<endl;
               break;
         }
         
         else if (escolha >= 'a' && escolha <='z')
                                 //or 
                  //escolha >= 'A' && escolha <='Z')
         {
               cout<<"OPÇÂO NÃO IDENTIFICADA FECHAMENTO INVESPERADO"<<endl;
               break;
         }
         
    } 
  

  //string query = "UPDATE NOTAS_ALUNOS SET Frequencia = 95.0 WHERE "+ teste +" = "+ quoteesql(nome) +";";
   


   
}


/*

std::cin.ignore(9999999, '\n');
sqlite3* DB;

std::string coluna,valor,chave;
std::cout<<"Digite a Disciplina que Deseja Alterar !"<<std::endl;
coluna="Eletronica";
valor="100.0";
chave="Frequencia";
//getline(std::cin,coluna);
//std::cin.ignore(9999999, '\n');
std::cout<<"Digite a Coluna que Deseja Alterar !"<<std::endl;
//getline(std::cin,coluna);
//std::cin.ignore(9999999, '\n');
std::cout<<"Digite o Novo Valor !"<<std::endl;
//getline(std::cin,valor);
//std::cin.ignore(9999999, '\n');
//cout<<quoteesql("XX");
int exit = sqlite3_open("Notas_alunos.db", &DB);
string query = "UPDATE NOTAS_ALUNOS SET Frequencia = 80.0 WHERE Disciplina = Eletronica";
//string query = "UPDATE NOTAS_ALUNOS SET Frequencia = "+ quoteesql(valor) +"; WHERE Disciplina = "+ quoteesql(chave) +";";
sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
sqlite3_close(DB);
*/