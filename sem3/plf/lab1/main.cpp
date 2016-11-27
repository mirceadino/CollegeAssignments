#include "lista.h"
#include <iostream>

using std::cout;
using std::cin;

bool inclusionE(TElem e, Lista l) {
  if (e_vida(l)) {
    return false;
  }
  if (primul(l) == e) {
    return true;
  }
  return inclusionE(e, restul_fara_primul(l));
}

bool inclusionL(Lista l, Lista r) {
  if (e_vida(l)) {
    return true;
  }
  if (!inclusionE(primul(l), r)) {
    return false;
  }
  return inclusionL(restul_fara_primul(l), r);
}

Lista insert(Lista l, TElem e, TElem e1) {
  if (e_vida(l)) {
    return creare_vida();
  }
  if (primul(l) == e) {
    Lista r = restul_fara_primul(l);
    r = adauga_primul(r, e1);
    return adauga_primul(r, primul(l));
  }
  Lista r = restul_fara_primul(l);
  return adauga_primul(insert(r, e, e1), primul(l));
}

int main(int argc, char** argv) {
  if (argc <= 1) {
    cout << "Read the first list: \n";
    Lista l = creare();
    tipar(l);

    cout << "Read the second list: \n";
    Lista r = creare();
    tipar(r);

    cout << "Is the first list included in the second list?\n";
    cout << (inclusionL(l, r) ? "true" : "false") << "\n";
  } else {
    cout << "Read the list: \n";
    Lista l = creare();
    tipar(l);

    cout << "Read e: ";
    TElem e;
    cin >> e;

    cout << "Read the new element: ";
    TElem e1;
    cin >> e1;

    Lista r = insert(l, e, e1);
    tipar(r);
  }

  return 0;
}
