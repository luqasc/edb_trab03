#include <iostream>
#include <string>

#ifndef HEADER_H
#define HEADER_H

using namespace std;

//Classe para cada elemento da pilha.
//"x" é o caractere, e "prox" é o ponteiro para o próximo caractere.
class Elemento
{
    public:
        char x;
        Elemento *prox;
        //Construtor padrão
        Elemento()
        {
            x = '\0';
            prox = nullptr;
        }
        //Construtor parametrizado
        Elemento(char a)
        {
            x = a;
            prox = nullptr;
        }
        //Destrutor
        ~Elemento()
        {
        }
};

//Classe para a pilha inteira;
//É guardado o objeto "Elemento" do topo da pilha, e o número de elementos "n".
class Pilha
{
    public:
        Elemento *top;
        int n = 0;

        //Construtor
        Pilha()
        {
            top = nullptr;
        }
        //Destrutor
        ~Pilha()
        {
            //Laço para exclusão de cada objeto "Elemento" alocado dinamicamente
            Elemento *atual = top;
            while (atual != nullptr)
            {
                Elemento *temp = atual->prox;
                delete atual;
                atual = temp;
            }
        }
        //Tamanho da pilha
        int size()
        {
            return n;
        }
        //Adição de elemento ao topo da pilha
        void push(char i_)
        {         
            Elemento *novo = new Elemento(i_);

            //Caso 1: Pilha vazia
            if (top == nullptr)
            {
                top = novo;
                n++;
            }
            //Caso 2: Pilha já tem elemento(s)
            else
            {
                novo->prox = top;
                top = novo;
                n++;
            }
        }
        //Remoção de elemento do topo
        void pop()
        {
            //Iterador
            Elemento *out = top;

            //Topo é redirecionado ao próximo elemento
            if (top != nullptr)
            {
                top = top->prox;
                //Topo original é deletado
                delete out;
                n--;
            }
        }
        //Exibição dos elementos da pilha
        void show()
        {
            //Caso 1: Pilha vazia
            if (top == nullptr)
            {
                cout << "Pilha vazia.\n";
            }
            //Caso 2: Pilha não-vazia
            else
            {
                //Variável auxiliar para impressão dos elementos
                Elemento *aux = top;
                while (aux != nullptr)
                {
                    cout << aux->x << "\n";
                    aux = aux->prox;
                }
            }
        }

        //Retorna se a pilha está vazia (true) ou não (false)
        bool empty()
        {
            if (top == nullptr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

#endif