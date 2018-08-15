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
    NoCandidato *aux;
    no = head;

    if(this->estaVazia()){
        return false;
    }

    if(head->conteudo->nome == nome && head->conteudo->sobrenome == sobrenome){
        head = no->next;
        delete no;
        return true;
    }

    while(no->next != NULL){
        if(no->next->conteudo->nome == nome && no->next->conteudo->sobrenome == sobrenome){
            if(no->next->next == NULL){
                cout << "-------------------------------oi--------------------------------";
                delete no->next;
                no->next = NULL;
                return true;
            }else{
                aux = no->next->next;
                delete no->next;
                no->next = aux;
                return true;
            }
        }else{
            no = no->next;
        }

    }

    return false;

}

void ListaCandidatos::filtrarCandidatos(int nota){
    NoCandidato *aux;
    aux = head;

    while(aux->next != NULL){
        if(aux->conteudo->nota < nota){
            this->remove(aux->conteudo->nome, aux->conteudo->sobrenome);
        }
        aux = aux->next;
    }
}

void ListaCandidatos::concatena(ListaCandidatos *l){
    NoCandidato *no;
    no = head;

    while(no->next != NULL){

        no = no->next;
    }

    no->next = l->head;
}
