#include <iostream>
#include <string.h>
#include <fstream>
#include <streambuf>
#include <Dicionario.h>
#include <vector>

using namespace std;

void Compressao(string entrada, string saida)
{
    Dicionario dicionario;
    string texto = "";
    string string_atual = "";
    dicionario.InsereNoDicionario(string_atual, 0);

    ifstream file(entrada);
    ofstream output(saida);
    if (file.is_open())
    {
        while (file)
        {
            texto += file.get();
        }
    }

    int iterador_indice = 1;
    int indice_atual = 0;

    for (int i = 0; i < int(texto.size() - 1); i++)
    {
        string_atual += texto[i];
        indice_atual = dicionario.EncontraNoDicionario(string_atual);
        if (indice_atual == -1)
        {
            output << "("
                   << dicionario.EncontraNoDicionario(string_atual.substr(0, string_atual.length() - 1)) << "," << string_atual.substr(string_atual.length() - 1, string_atual.length()) << ")";
            dicionario.InsereNoDicionario(string_atual, iterador_indice);

            string_atual = "";
            iterador_indice++;
        }
        else
        {
            if (i == int(texto.size() - 2))
            {
                output << "(" << indice_atual << ","
                       << ""
                       << ")";
            }
        }
    }
}

void Descompressao(string entrada, string saida)
{
    string texto = "";
    string string_atual = "";
    string string_descomprimida = "";
    vector<string> strings;
    strings.push_back(string_atual);

    ifstream file(entrada);
    ofstream output(saida);
    if (file.is_open())
    {
        while (file)
        {
            texto += file.get();
        }
    }

    int aux = 0;
    for (int i = 0; i < int(texto.size() - 1); i++)
    {
        if (texto[i] == '('){
            i++;
            string_atual = "";
            while(texto[i]!= ','){
                string_atual += texto[i];
                i++;
            }

            aux = stoi(string_atual);

            cout << aux << endl;
            string_atual = "";
            i++;
            while(texto[i]!= ')'){
                string_atual += texto[i];
                i++;
            }
            
            
            string_descomprimida += strings[aux]+string_atual;

            strings.push_back(strings[aux]+string_atual);
            
        }
    }
    output << string_descomprimida;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; ++i)
        cout << "Argumanto " << i << ": " << argv[i] << "\n";

    if (strcmp(argv[1], "-c") == 0 or strcmp(argv[1], "-x") == 0)
    {
        string entrada = argv[2];
        string saida = "saida_generica.txt";
        if (argc >= 4)
        {
            if (strcmp(argv[3], "-o") == 0 and argc >= 5)
            {
                saida = argv[4];
            }
        }

        cout << "entrada: " << entrada << endl
             << "saida: " << saida << endl;
        if (strcmp(argv[1], "-c") == 0)
        {
            Compressao(entrada, saida);
        }
        else if (strcmp(argv[1], "-x") == 0)
        {
            Descompressao(entrada, saida);
        }
    }
    return 0;
}
