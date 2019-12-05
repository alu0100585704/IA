pdc(p,gripe).
pdc(j,hepa).
pdc(c,intox).
pdc(p,hepa).
pdc(m,hepa).

stm(fieb,gripe).
stm(diar,intox).
stm(can,hepa).
stm(can,gripe).

spm(asp,fieb).
spm(loc,diar).
spm(for,can).

% Un fármaco alivia una enfermedad si la enfermedad tiene un síntoma que sea suprimido por el fármaco. 

alv(F_A,E):-
	stm(_S,E),
	spm(F_A,_S).

% Una persona debería tomar un fármaco si padece una enfermedad que sea aliviada por el fármaco.
tm(P,F):-
	pdc(P,E),
	alv(F,E).





