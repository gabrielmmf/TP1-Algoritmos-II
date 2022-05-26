#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <string>
#include "Node.h"

using namespace std;

class Dicionario
{
public:
    Dicionario();
    ~Dicionario();
    void Limpa();

    int EncontraNoDicionario(string chave);
    void InsereNoDicionario(string chave, int index);
    void Remove(string chave);
    

    Node *raiz; 

};

#endif