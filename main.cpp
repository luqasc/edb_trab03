#include <iostream>
#include <string>
#include "header.h"

using namespace std;

//Função que percorre o texto digitado pelo usuário e checa seu balanceamento.
bool checagem (string txt)
{
    //Pilha para parênteses/colchetes/chaves
    Pilha parenteses;

    //Variável auxiliar para checagem
    int check = 0;
    
    //Laço que percorre o texto
    for (string::size_type i = 0; i < txt.length(); i++)
    {
        //Se o caractere for (, [ ou {, é colocado na pilha
        if (txt[i] == '(' || txt[i] == '[' || txt[i] == '{')
        {
            parenteses.push(txt[i]);
        }
        //Se o caractere for )...
        if (txt[i] == ')')
        {
            //...e a pilha não estiver vazia...
            if (parenteses.empty() == false)
            {
                //...e o elemento do topo for (, ele é eliminado.
                if (parenteses.top->x == '(')
                {
                    parenteses.pop();
                }
                //Se o elemento não é (, o texto não está balanceado, e o laço pode parar.
                else
                {
                    check = 1;
                    break;
                }
            }
            //Se a pilha estiver vazia, o texto não está balanceado, e o laço pode parar.
            else
            {
                check = 1;
                break;
            }
        }
        //Se o caractere for ]...
        if (txt[i] == ']')
        {
            //...e a pilha não estiver vazia...
            if (parenteses.empty() == false)
            {
                //...e o elemento do topo for [, ele é eliminado.
                if (parenteses.top->x == '[')
                {
                    parenteses.pop();
                }
                //Se o elemento não é [, o texto não está balanceado, e o laço pode parar.
                else
                {
                    check = 1;
                    break;
                }
            }
            //Se a pilha estiver vazia, o texto não está balanceado, e o laço pode parar.
            else
            {
                check = 1;
                break;
            }
        }
        //Se o caractere for }...
        if (txt[i] == '}')
        {
            //...e a pilha não estiver vazia...
            if (parenteses.empty() == false)
            {
                //...e o elemento do topo for {, ele é eliminado.
                if (parenteses.top->x == '{')
                {
                    parenteses.pop();
                }
                //Se o elemento não é {, o texto não está balanceado, e o laço pode parar.
                else
                {
                    check = 1;
                    break;
                }
            }
            //Se a pilha estiver vazia, o texto não está balanceado, e o laço pode parar.
            else
            {
                check = 1;
                break;
            }
        }
    }
    //Fim do laço.
    
    //Se a pilha estiver vazia ao final...
    if (parenteses.empty() == true)
    {
        // ...e a variável de checagem for igual a 0 
        // (pois a pilha pode estar vazia, mas o laço pode 
        // ter encontrado um ")", "]" ou "}" e parado)...
        if (check == 0)
        {
            //...retorna-se true.
            return true;
        }
        // Se check = 1, retorna-se false.
        else
        {
            return false;
        }
    }
    //Se ainda houver elementos na pilha...
    else
    {
        //...ela não está balanceada, e retorna-se false.
        return false;
    }
}

//Função principal
int main ()
{
    string texto;
    cout << "Digite a expressão a ser analisada.\n";
    getline(cin, texto);

    if (checagem(texto))
    {
        //Se for retornado "true"
        cout << "A expressão está balanceada.\n";
    }
    else
    {
        //Se for retornado "false"
        cout << "A expressão não está balanceada.\n";
    }
    return 0;
}