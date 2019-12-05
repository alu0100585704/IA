p(X):-X is 3+2.

not(X):- call(X),
	!,
	fail.
not(_). 

