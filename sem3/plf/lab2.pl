% exists(L: list, X: int)
% Checks if X exists in the list L.
exists([H|T], X) :-
  H = X.
exists([H|T], X) :-
  H \= X,
  exists(T, X).

% included(L: list, R: list)
% Checks if the elements of the list L are included in the list R.
included([], _).
included([H|T], R) :-
  exists(R, H),
  included(T, R).

% equals(L: list, R: list)
% Checks if the lists have the same elements (if they represent equal sets).
equals(L, R) :-
  included(L, R),
  included(R, L).

% kth_element(L: list, K: int, R: int)
% R is the Kth element in the list (1-indexed). If K is invalid, R is -1.
kth_element([], _, -1).
kth_element(_, K, -1) :-
  K < 1.
kth_element([H|T], 1, H).
kth_element([H|T], K, R) :-
  K > 1,
  KT is K - 1,
  kth_element(T, KT, R).
