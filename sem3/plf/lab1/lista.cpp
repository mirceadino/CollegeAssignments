#include "lista.h"
#include <iostream>

using namespace std;


PNod creare_rec() {
  TElem x;
  cout << "x=";
  cin >> x;
  if (x == 0) {
    return NULL;
  } else {
    PNod p = new Nod();
    p->e = x;
    p->urm = creare_rec();
    return p;
  }
}

Lista creare() {
  Lista l;
  l._prim = creare_rec();
  return l;
}

void tipar_rec(PNod p) {
  if (p != NULL) {
    cout << p->e << " ";
    tipar_rec(p->urm);
  } else {
    cout << "\n";
  }
}

void tipar(Lista l) {
  tipar_rec(l._prim);
}

void distrug_rec(PNod p) {
  if (p != NULL) {
    distrug_rec(p->urm);
    delete p;
  }
}

void distruge(Lista l) {
  //se elibereaza memoria alocata nodurilor listei
  distrug_rec(l._prim);
}


PNod copie_rec(PNod r) {
  if (r == nullptr) {
    return nullptr;
  }

  PNod p = new Nod();
  p->e = r->e;
  p->urm = copie_rec(r->urm);
  return p;
}

Lista copie(Lista l) {
  Lista r;
  r._prim = copie_rec(l._prim);
  return r;
}

bool e_vida(Lista l) {
  return l._prim == nullptr;
}

Lista creare_vida() {
  Lista l;
  l._prim = nullptr;
  return l;
}

TElem primul(Lista l) {
  if (!e_vida(l)) {
    return l._prim->e;
  }
  return -1;
}

Lista restul_fara_primul(Lista l) {
  if (!e_vida(l)) {
    Lista r;
    r._prim = l._prim->urm;
    return r;
  }
  return creare_vida();
}

Lista adauga_primul(Lista l, TElem e) {
  PNod p = new Nod();
  Lista r = copie(l);
  p->e = e;
  p->urm = r._prim;
  r._prim = p;
  return r;
}
