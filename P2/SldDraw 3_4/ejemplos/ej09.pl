m(X,[X|_]).
m(X,[Y|Ys]):-
	X\==Y,
	m(X,Ys).