#include "listacandidatos.h"
#include "nocandidato.h"

ListaCandidatos::ListaCandidatos()
{
    head = NULL;
}

void ListaCandidatos::adicioneComoHead(Candidato *_c)
{
    NoCandidato *noc = new NoCandidato(_c, head);
    head = noc;
}

bool ListaCandidatos::estaVazia()
{
    if(head ==  NULL){
        return true;
    }else{
        return false;
    }
}

int ListaCandidatos::tamanho()
{
    NoCandidato *no;
    no = head;
    int tam = 0;
    while(no != NULL){
        tam ++;
        no = no->next;
    }
    return tam;
}
