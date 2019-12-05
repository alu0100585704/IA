comb(_,0,[]).
comb([X|Xs],N,[X|Ys]):-
	N>0,
	N1 is N-1,
	comb(Xs,N1,Ys).
comb([_|Xs],N,Ys):-
	N>0,
	comb(Xs,N,Ys).

partes([],[]).
partes([X|Xs],[X|Ys]):-
	partes(Xs,Ys).
partes([_|Xs],Ys):-
	partes(Xs,Ys).

