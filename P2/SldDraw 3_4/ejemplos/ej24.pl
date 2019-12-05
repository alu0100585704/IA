p(X,Y) :- q(X,Y),r(X).
p(X,Y):-q(X,Y),r(Y).
q(X,Y):-t(X),t(Y).
t(X):-r(X),r(Y).
t(X).
r(a).
r(b).
