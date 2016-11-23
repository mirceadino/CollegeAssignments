% merge(L, R, S) - merges two sorted lists without keeping the duplicates
% merge(i, i, o)
% L - int list
% R - int list
% S - int list
merge([], [], []).
merge(L, [], L) :-
  L\=[].
merge([], R, R) :-
  R\=[].
merge([A|L], [B|R], [A|T]) :-
  A=B,
  merge(L, R, T).
merge([A|L], [B|R], [A|T]) :-
  A<B,
  merge(L, [B|R], T).
merge([A|L], [B|R], [B|T]) :-
  A>B,
  merge([A|L], R, T).
