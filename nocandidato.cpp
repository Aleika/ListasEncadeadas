#include "nocandidato.h"

NoCandidato::NoCandidato(Candidato *_c, NoCandidato *_next)
{
    conteudo = _c;
    next = _next;
}
