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
    bool estaVazia();
    int tamanho();
};

#endif // LISTACANDIDATOS_H
