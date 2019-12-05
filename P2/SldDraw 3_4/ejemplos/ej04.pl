p([X,Xs]):-q(X,Xs).
p(X):-r(Y).

%Utilizar una de las dos siguientes
%q(X,Y):-s(X),!,t(Y).
q(X,Y):-s(X),t(Y).

q(a).
q(X,Y):-q([],X).

s(W):-q(W).
s(V).

t([X|Xs]):-s(Xs).
t([X|Xs]):-r(Xs).
t([X|Xs]):-q(X).

r([]).
r([X|Xs]):-s(X),r(Xs).



