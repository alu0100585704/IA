fa1(0,1).
fa1(N,F):- N>0,NN is N-1,fa1(NN,FF),F is N *FF.

fa2(N,P):-fa2p(N,1,P).
fa2p(0,P,P).
fa2p(N,A,P):-N>0,
	AA is A*N,
	NN is N-1,
	fa2p(NN,AA,P).