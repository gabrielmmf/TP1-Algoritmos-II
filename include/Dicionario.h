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

    int EncontraNoDicionario(string chave);
    void InsereNoDicionario(string chave, int index);
  
    Node *raiz; 
};

#endif