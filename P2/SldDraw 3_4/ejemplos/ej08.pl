p([],[]).
p([X|Xs],[Y|Ys]) :- q(X,Y), p(Xs,Ys).
q(a,b).
q(a,Y) :- s(X), s(Y).
q(a,c).
q(b,b).
s(a).
s(b).