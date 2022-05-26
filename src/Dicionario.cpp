#include "Dicionario.h"

using namespace std;

Dicionario::Dicionario()
{
    raiz = new Node(0);
}

Dicionario::~Dicionario()
{
}

void Dicionario::Limpa()
{
}

int Dicionario::EncontraNoDicionario(string chave)
{
    return raiz->PesquisaRecursivo(chave);
}

void Dicionario::InsereNoDicionario(string chave, int index)
{
    raiz->InsereRecursivo(chave, index);
}

void Dicionario::Remove(string chave)
{
}