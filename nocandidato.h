#ifndef NOCANDIDATO_H
#define NOCANDIDATO_H
#include "candidato.h"

class NoCandidato
{
public:
    Candidato *conteudo;
    NoCandidato *next;

    string toString();
    NoCandidato(Candidato *_c, NoCandidato *_next);
};

#endif // NOCANDIDATO_H
