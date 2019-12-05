padre(juan,luis).
padre(juan,maria).
padre(juan,carmen).
padre(pedro,antonio).
padre(pedro,ana).
padre(luis,andres).
padre(luis,sergio).
padre(antonio,gabriel).
madre(maria, jose).

persona(X).						


progenitor(A,D) :- padre(A,D).
progenitor(A,D) :- madre(A,D).

antepasado(A,D) :- progenitor(A,D).
antepasado(A,D) :- progenitor(A,H), 
		   antepasado(H,D). 	


% uso +-
nietos(A,N):-
	padre(A,P),
	padre(P,N).
% uso +-
abuelo(N,A):-
	padre(P,N),
	padre(A,P).




