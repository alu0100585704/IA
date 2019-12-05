% ¿Podemos conocer qué dolencia tiene Pedro?  
%:-pdc(p,X).
 

% ¿Quién padece gripe?
%:-pdc(X,gripe).

% ¿Qué síntomas tiene Pedro? 
%:-pdc(_,_e),stm(S,_e).

% ¿Quién padece diarrea? 
%:-pdc(X,_A),stm(diar,_A).

%¿Y quién está cansado?
%:-pdc(P,_E),stm(can,_E).

% ¿Hay algún fármaco que debe tomar Pedro? 
%:-tm(_,F).

% ¿Hay algún síntoma que compartan Juan y María?
%:-pdc(p,_E1),pdc(m,_E2),stm(S,_E1),stm(S,_E2).

% Que farmacos debo comprar para todos
:-pdc(p,_E),alv(F,_E).









