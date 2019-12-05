p(X,v,v).
p(X,f(X,Y),Z):-p(X,Y,Z).
p(X,f(Y,Z),f(X,T)):-p(X,Z,T).
