#include "listacandidatos.h"
#include "nocandidato.h"
#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

ListaCandidatos::ListaCandidatos()
{
    head = NULL;
}

ListaCandidatos::ListaCandidatos(string nomeDoArquivo)
{
    head = NULL;
    ifstream fcin(nomeDoArquivo);

    string dados;
    getline(fcin,dados);
    cout << "Nome da regiao: " << dados << endl;

    while(getline(fcin,dados)){
        Candidato *c1 = new Candidato(dados);
        this->adicioneComoHead(c1);
    }
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

string ListaCandidatos::toString(){

    NoCandidato *aux = head;
    stringstream stream;

    if(head != NULL){
        while(aux != NULL){
            stream << aux->conteudo->sobrenome << " " << aux->conteudo->nome << " " << aux->conteudo->nota << " -> ";
            aux = aux->next;
        }
    }
    stream << "0";
    return stream.str();
}

bool ListaCandidatos::remove(string nome, string sobrenome){
    NoCandidato *no;
    no = head;
    NoCandidato *aux;

    if(this->estaVazia()){
        return false;
    }
    if(this->tamanho()==1){
        if(head->conteudo->nome == nome && head->conteudo->sobrenome == sobrenome){
            head = no->next;
            delete no;
            return true;
        }else{
            return false;
        }
    }

    while(no->next != NULL){
        if(no->next->conteudo->nome == nome && no->next->conteudo->sobrenome == sobrenome){
           aux = no->next->next;
           delete no->next;
           no->next = aux;
           return true;
        }else{
            no = no->next;
        }

    }
    if(no->next == NULL && no->conteudo->nome == nome && no->conteudo->sobrenome == sobrenome){
        delete no;
        return true;
    }else{
        return false;
    }

}
