#include <iostream>
using namespace std;

class Livros{

    public:


    string nome;
    int dt_lan;
    string editora;


};

class Clientes{

    public:

    string nome;
    string cpf;
    string dt_nasc;
    string endereco;

};

void print (Livros livro){

    cout <<"\nNome:" << livro.nome;
    cout <<"\nEditora: "<<livro.editora<<"\n";
    cout <<"Data de Lançamento: " << livro.dt_lan << "\n\n";

}

void print (Clientes cliente){

    cout << "\nNome: " << cliente.nome;
    cout << "\nData de Nascimento: "<< cliente.dt_nasc;
    cout << "\nCPF: " << cliente.cpf;
    cout << "\nEndereço: " << cliente.endereco <<"\n\n";

}

int main() {




    Livros livro1;
    Clientes cliente1;
    int pegar;
    bool pego = false;
    int devolver;

    while(true){

        cout<<"\n\n----------------------------\nEscolha:\n\n1)Cadastrar Livro\n2)Cadastrar Cliente\n3)Fazer Empréstimo\n4)Devolução\n5)Listar\n6)Parar\n\n";


        int esc;
        cin >> esc;

        if(esc == 1){


       

        cin.ignore();
        cout << "Me fala o nome do livro \n";
        getline(cin, livro1.nome );
   

        cout << "\nAgora me fala a editora que publicou ele\n";
        getline(cin, livro1.editora );

        cout << "\nAgora me informe o ano de lançamento desse livro\n";
        cin >> livro1.dt_lan;



        print(livro1);
        }
        else if(esc == 2){

            

            cin.ignore();
            cout << "\nMe fala o nome do cliente\n";
            getline(cin, cliente1.nome );

            cout << "\nMe fala a data de nascimento do cliente\n";
            getline(cin, cliente1.dt_nasc );

            cout << "\nMe fala o CPF do cliente\n";
            getline(cin, cliente1.cpf );

            cout << "\nMe fala o endereço do cliente\n";
            getline(cin, cliente1.endereco );


            
            print(cliente1);

        }
        else if(esc == 3){

         

            cout << "\nOs Livros\n";
            print(livro1);

            cout << "Pegar Livro?\n1)Sim\n2)Não\n";

            cin >> pegar;

            if(pegar == 1 && pego == false){

                cout << "Você pegou o " << livro1.nome << ".\n";

                pego = true;

            }

            else if (pego == true){
            cout << "Esse livro já foi pego.";
            }





            


            

        }
        else if(esc == 4){

            cout << "Você deseja devolver o " << livro1.nome <<"?\n1)Sim\n2)Não\n\n";
            cin >> devolver;

            if(devolver == 1){

                cout << "\n\nCerto, você devolveu o Livro\n\n";
                pego = false;

            }



        }
        else if(esc == 5){

            

            cout << "\n\nOs Clientes\n";
            print(cliente1);

            cout << "\nOs Livros\n";
            print(livro1);


        }
        else if(esc == 6){

            break;
        }
    }


    return 0;

}
