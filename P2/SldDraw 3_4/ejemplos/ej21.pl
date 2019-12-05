arco(a,b).
arco(a,c).
arco(b,c).
arco(c,d).
arco(d,e).
arco(e,f).

con1(X,Y):-arco(X,Y).
con1(X,Z):-arco(X,Y),
	con1(Y,Z).

con2(X,Y):-arco(X,Y).
con2(X,Z):- con2(X,Y),
	con2(Y,Z).


