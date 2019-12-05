p(X,Y):-q(X,Y),r(Y).
p(X,Y) :- q(X,Y),r(X).
q(X,Y):-t(X),t(Y).
t(X).
t(X):-r(X),q(c,X).
r(a).
r(b).
