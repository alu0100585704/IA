pf([],Ys).
pf([X|Xs],[X|Ys]):-pf(Xs,Ys).
