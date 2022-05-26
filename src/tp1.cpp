#include <iostream>
#include <string.h>
#include <fstream>
#include <streambuf>
#include <Dicionario.h>

using namespace std;

void Compressao(string entrada, string saida)
{
    Dicionario dicionario;
    string texto = "";
    char aux;
    string string_atual = "";
    ifstream file(entrada);
    if (file.is_open())
    {
        while (file)
        {
            aux = file.get();
            texto += aux;
        }
    }

    for (int i = 0; i < int(texto.size()) - 1; i++)
    {
        string_atual += texto[i];
        // if(dicionario.EstaNoDicionario(string_atual))
        cout << texto[i];
    }
    string pesquisa;
    cout << "Inserindo abobora no dicionario: " << endl;
    dicionario.InsereNoDicionario("abobora", 1);
    cout << "Inserindo macaco no dicionario: " << endl;
    dicionario.InsereNoDicionario("macaco", 2);
    cout << "Inserindo forte no dicionario: " << endl;
    dicionario.InsereNoDicionario("forte", 3);
    cout << "Inserindo fraco no dicionario: " << endl;
    dicionario.InsereNoDicionario("fraco", 4);
    cout << "Inserindo marcos no dicionario: " << endl;
    dicionario.InsereNoDicionario("marcos", 5);
    cout << "Inserindo menta no dicionario: " << endl;
    dicionario.InsereNoDicionario("menta", 6);
    cout << "Inserindo feio no dicionario: " << endl;
    dicionario.InsereNoDicionario("feio", 7);
    cout << "Inserindo bonito no dicionario: " << endl;
    dicionario.InsereNoDicionario("bonito", 8);

    while (true)
    {
        cout << "Digite a pesquisa no dicionario: " << endl;
        cin >> pesquisa;

        if (dicionario.EncontraNoDicionario(pesquisa) != -1)
        {
            cout << "A palavra " << pesquisa << " esta no dicionario no indice " << dicionario.EncontraNoDicionario(pesquisa) << endl;
        }
        else
        {
            cout << "A palavra " << pesquisa << " nao esta no dicionario" << endl;
        }
    }
}

void Descompressao(string entrada, string saida)
{
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
