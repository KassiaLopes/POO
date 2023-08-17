#include"Pessoa.hpp"

Pessoa::Pessoa(){}

Pessoa::Pessoa(std::string nome,std::string endereco,std::string telefone)
:nome(nome),
endereco(endereco),
telefone(telefone)
{
    std::cout<<"Metodo Construtor de Pessoa"<<std::endl;
}

Pessoa::~Pessoa()
{
    std::cout<<"Metodo Destrutor de Pessoa"<<std::endl;
}

