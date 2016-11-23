#ifndef LISTA_H
#define LISTA_H


//tip de data generic (pentru moment este intreg)
typedef int TElem;

//referire a structurii Nod;
struct Nod;

//se defineste tipul PNod ca fiind adresa unui Nod
typedef Nod* PNod;

typedef struct Nod {
  TElem e;
  PNod urm;
} Nod;

typedef struct {
//prim este adresa primului Nod din lista
  PNod _prim;
} Lista;

//operatii pe lista - INTERFATA

//crearea unei liste din valori citite pana la 0
Lista creare();
//tiparirea elementelor unei liste
void tipar(Lista l);
// destructorul listei
void distruge(Lista l);



Lista copie(Lista l);
bool e_vida(Lista l);
Lista creare_vida();
TElem primul(Lista l);
Lista restul_fara_primul(Lista l);
Lista adauga_primul(Lista l, TElem e);

#endif
