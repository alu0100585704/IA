%% Selecciona
sel(X,[X|Xs],Xs).
sel(X,[Y|Xs],[Y|Ys]):-
	sel(X,Xs,Ys).
