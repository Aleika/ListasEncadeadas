#include "nocandidato.h"

NoCandidato::NoCandidato(Candidato *_c, NoCandidato *_next)
{
    conteudo = _c;
    next = _next;
}

string NoCandidato::toString(){

    NoCandidato *aux = this;
    stringstream stream;

    while(aux != NULL){
        stream << aux->conteudo->sobrenome << " " << aux->conteudo->nome << " " << aux->conteudo->nota << " -> ";
        aux = aux->next;
    }
    stream << "0";
    return stream.str();
}
