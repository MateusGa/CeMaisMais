#include <iostream>
#include <list>
#include <cstdlib>

class Livro
{

public:
    std::string nome;
    int dt_lan;
    std::string editora;
};

class Cliente
{

public:
    std::string nome;
    std::string cpf;
    std::string dt_nasc;
    std::string endereco;
};
class Emprestimo
{

public:
    std::string nomeCli;
    std::string nomeLi;
};

void print(Livro &livro)
{

    std::cout << "\nNome:" << livro.nome;
    std::cout << "\nEditora: " << livro.editora << "\n";
    std::cout << "Data de Lançamento: " << livro.dt_lan << "\n\n";
}

void print(Cliente &cliente)
{

    std::cout << "\nNome: " << cliente.nome;
    std::cout << "\nData de Nascimento: " << cliente.dt_nasc;
    std::cout << "\nCPF: " << cliente.cpf;
    std::cout << "\nEndereço: " << cliente.endereco << "\n\n";
}
void print(Emprestimo &emprestimo)
{

    std::cout << "\nCliente: " << emprestimo.nomeCli;
    std::cout << "\nLivro: " << emprestimo.nomeLi << "\n\n";
}
Livro cadastraLivro(Livro &livro1)
{

    std::cin.ignore();
    std::cout << "Me fala o nome do livro \n";
    getline(std::cin, livro1.nome);

    std::cout << "\nAgora me fala a editora que publicou ele\n";
    getline(std::cin, livro1.editora);

    std::cout << "\nAgora me informe o ano de lançamento desse livro\n";
    std::cin >> livro1.dt_lan;

    return livro1;

    print(livro1);
}
Cliente cadastraCliente(Cliente &cliente1)
{

    std::cin.ignore();
    std::cout << "\nMe fala o nome do cliente\n";
    getline(std::cin, cliente1.nome);

    std::cout << "\nMe fala a data de nascimento do cliente\n";
    getline(std::cin, cliente1.dt_nasc);

    std::cout << "\nMe fala o CPF do cliente\n";
    getline(std::cin, cliente1.cpf);

    std::cout << "\nMe fala o endereço do cliente\n";
    getline(std::cin, cliente1.endereco);

    return cliente1;

    print(cliente1);
}
Emprestimo fazerEmprestimo(std::list<Livro> &lisLivro, std::list<Cliente> &lisCli, Emprestimo &emprestimo1)
{

    std::list<Livro>::iterator itL = lisLivro.begin();
    std::list<Cliente>::iterator itC = lisCli.begin();
    int escC;
    int escL;
    int conC = 1;
    int conL = 1;

    std::cout << "\nMe fale qual Cliente está fazendo o empréstimo:\n";
    for (Cliente cli : lisCli)
    {
        std::cout << "----------------------------------------\n";
        std::cout << conC << ")";
        print(cli);
        conC += 1;
    }
    std::cout << "----------------------------------------\n";

    std::cin >> escC;

    advance(itC, escC - 1);

    std::cout << "\nMe fale qual Livro está sendo pego:\n";
    for (Livro li : lisLivro)
    {
        std::cout << "----------------------------------------\n";
        std::cout << conL << ")";
        print(li);
        conL += 1;
    }
    std::cout << "----------------------------------------\n";
    std::cin >> escL;

    advance(itL, escL - 1);

    emprestimo1.nomeCli = itC->nome;
    emprestimo1.nomeLi = itL->nome;

    return emprestimo1;
}
void devolverLivro(std::list<Emprestimo> &lisEmpr)
{

    std::list<Emprestimo>::iterator itE = lisEmpr.begin();
    int escEmp;
    int conEmp = 1;

    std::cout << "\nMe fale qual empréstimo será devolvido\n\n";
    for (Emprestimo emp : lisEmpr)
    {
        std ::cout << conEmp << ")\n";
        std::cout << "----------------------------------------";
        print(emp);
        conEmp += 1;
    }
    std::cout << "----------------------------------------\n";

    std ::cin >> escEmp;

    advance(itE, escEmp - 1);

    lisEmpr.erase(itE);
}
void listarTudo(std::list<Livro> &lisLivro, std::list<Cliente> &lisCli, std::list<Emprestimo> &lisEmpre)
{

    std::cout << "Os livros\n\n";
    for (Livro li : lisLivro)
    {
        std::cout << "----------------------------------------";
        print(li);
    }
    std::cout << "----------------------------------------";

    std::cout << "\nOs clientes\n\n";
    for (Cliente cli : lisCli)
    {
        std::cout << "----------------------------------------";
        print(cli);
    }
    std::cout << "----------------------------------------";

    std::cout << "\nOs Emprestimos\n\n";
    for (Emprestimo emp : lisEmpre)
    {
        std::cout << "----------------------------------------";
        print(emp);
    }
    std::cout << "----------------------------------------";
}

int main()
{

    Livro livro1;
    Cliente cliente1;
    Emprestimo emprestimo1;

    std::list<Livro> lisLivro;
    std::list<Cliente> lisCli;
    std::list<Emprestimo> lisEmpr;

    while (true)
    {

        std::cout << "\n\n----------------------------\nEscolha:\n\n1)Cadastrar Livro\n2)Cadastrar Cliente\n3)Fazer Empréstimo \n4)Devolução (Ainda não finalizado)\n5)Listar\n6)Parar\n\n";

        int esc;
        std::cin >> esc;
        std::cout << "----------------------------------------\n";

        if (esc == 1)
        {

            lisLivro.push_back(cadastraLivro(livro1));
        }

        else if (esc == 2)
        {

            lisCli.push_back(cadastraCliente(cliente1));
        }
        else if (esc == 3)
        {

            lisEmpr.push_back(fazerEmprestimo(lisLivro, lisCli, emprestimo1));
        }
        else if (esc == 4)
        {

            devolverLivro(lisEmpr);
        }
        else if (esc == 5)
        {

            listarTudo(lisLivro, lisCli, lisEmpr);
        }
        else if (esc == 6)
        {
            system("cls");
            break;
        }
        else
        {

            std::cout << "Por favor, escolha uma opção válida";
        }
    }

    return 0;
}
