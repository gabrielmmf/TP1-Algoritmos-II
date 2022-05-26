#include "Dicionario.h"

using namespace std;

Dicionario::Dicionario()
{
    raiz = new Node(-1);
}

Dicionario::~Dicionario()
{
    delete raiz;
}

int Dicionario::EncontraNoDicionario(string chave)
{
    return raiz->PesquisaRecursivo(chave);
}

void Dicionario::InsereNoDicionario(string chave, int index)
{
    raiz->InsereRecursivo(chave, index);
}
