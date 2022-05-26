#ifndef NODE_H
#define NODE_H
#define TAMANHO_ALFABETO 128

#include <iostream>

using namespace std;

class Node
{
public:
    Node(int index_);
    ~Node();

    void InsereRecursivo(string chave, int index);
    int PesquisaRecursivo(string chave);

private:
    int index;
    char chave;
    Node *Filhos[TAMANHO_ALFABETO];
    friend class Dicionario;
};

#endif