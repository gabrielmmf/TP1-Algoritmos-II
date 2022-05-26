#include "Node.h"

using namespace std;

Node::Node(int index_)
{
    this->index = index_;
    for (int i = 0; i < TAMANHO_ALFABETO; i++)
    {
        Filhos[i] = nullptr;
    }
}

Node::~Node()
{
    for (int i = 0; i < TAMANHO_ALFABETO; i++)
    {
        delete Filhos[i];
    }
}

void Node::InsereRecursivo(string chave, int index)
{
    int valor = int(chave[0]);
    if (Filhos[valor] == nullptr)
        Filhos[valor] = new Node(-1);
    if (chave.size() > 1)
    {
        chave.erase(0, 1);
        Filhos[valor]->InsereRecursivo(chave, index);
    }
    else
    {
        this->Filhos[valor]->index = index;
    }
    return;
}

int Node::PesquisaRecursivo(string chave)
{
    int valor = int(chave[0]);
    if (Filhos[valor] == nullptr)
        return -1;
    if (chave.size() > 1)
    {
        chave.erase(0, 1);
        return (Filhos[valor]->PesquisaRecursivo(chave));
    }
    else if (Filhos[valor]->index != -1)
        return Filhos[valor]->index;
    else return -1;
}