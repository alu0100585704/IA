p(X,Y):-q(X,Y).
p(X,Y):-q(a,X).
q(a,a).
q(X,a):- r(Y),s(X,Y).
q(X,Y):-r(X),p(X,Y).
s(b,b).
s(b,X):-r(X).
r(b).
r(a).