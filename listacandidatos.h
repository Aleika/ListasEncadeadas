#ifndef LISTACANDIDATOS_H
#define LISTACANDIDATOS_H
#include "nocandidato.h"
#include "candidato.h"

class ListaCandidatos
{
public:
    NoCandidato* head;
    ListaCandidatos();
    void adicioneComoHead(Candidato* c);
    ListaCandidatos(string nomeDoArquivo);
    string toString();
    bool estaVazia();
    int tamanho();
};

#endif // LISTACANDIDATOS_H
