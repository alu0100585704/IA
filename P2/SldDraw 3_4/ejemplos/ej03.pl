for(I,J,I):-
	I =< J.
for(I,J,K):-
	I<J,
	NI is I+1,
	for(NI,J,K).
