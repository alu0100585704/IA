cn([],Ys,Ys).
cn([X|Xs],Ys,[X|Zs]):-
	cn(Xs,Ys,Zs).

aa([],[],vacio).
aa([X|Xs],Ys,nodo(I,X,D)):-
	cn(As,Bs,Xs),
	cn(Cs,[X|Ds],Ys),
	aa(As,Cs,I),
	aa(Bs,Ds,D).