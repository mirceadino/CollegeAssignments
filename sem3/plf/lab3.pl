% max(A: int, B: int, R: int): R is the maximum between A and B.
% max(i, i, o).
max(A, B, R) :-
  R is ((A + B + abs(A - B)) / 2).

% maxel(L: list, R: int): R is the maximum element in the list L.
% maxel(i, o).
maxel([], -1).
maxel([H|T], R) :-
  maxel(T, RT),
  max(RT, H, R).

% findpos(L: list, I: int, E: int, R: list): R is a list containing the
% I-indexed positions from the list L where the element E occurs.
% findpos(i, i, i, o).
findpos([], _, _, []).
findpos([H|T], I, E, [I|RT]) :-
  H = E,
  IR is I + 1,
  findpos(T, IR, E, RT).
findpos([H|T], I, E, R) :- 
  H \= E,
  IR is I + 1,
  findpos(T, IR, E, R).

% maxpos(L: list, R: list): R is a list containing the 1-indexed positions
% where the maximum in L occurs.
% maxpos(i, o).
maxpos(L, R) :- 
  maxel(L, M),
  findpos(L, 1, M, R).

% transform(L: list, R: list): R is a list in which the sublists from L are
% replaced with maxpos(sublist).
% transform(i, o).
transform([], []).
transform([H|T], [HR|R]) :-
  is_list(H),
  maxpos(H, HR),
  transform(T, R).
transform([H|T], [H|R]) :-
  number(H),
  transform(T, R).
