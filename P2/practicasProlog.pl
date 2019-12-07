%condicion de final de exito
orillas([],_).

%%Situaciones posibles

orillas(X,Y):-permutacion(X,[lobo]) , permutacion(Y,[pastor,oveja,col]).
orillas(X,Y):-permutacion(X,[oveja]) , permutacion(Y,[pastor,lobo,col]).
orillas(X,Y):-permutacion(X,[col]) , permutacion(Y,[pastor,lobo,oveja]).
orillas(X,Y):-permutacion(X,[pastor,oveja]) , permutacion(Y,[lobo,col]).
orillas(X,Y):-permutacion(X,[lobo,col]) , permutacion(Y,[pastor,oveja]).
orillas(X,Y):-permutacion(X,[pastor,lobo,oveja]) , permutacion(Y,[col]).
orillas(X,Y):-permutacion(X,[oveja,col,pastor]) , permutacion(Y,[lobo]).
orillas(X,Y):-permutacion(X,[col,pastor,lobo]) , permutacion(Y,[oveja]).


%las situaciones que no se pueden dar
%orillas([pastor],[lobo,oveja,col]).
%orillas([pastor,lobo],[oveja,col]).
%orillas([pastor,col],[lobo,oveja]).
%orillas([lobo,oveja],[pastor,col]).
%orillas([oveja,col],[pastor,lobo]).
%orillas([lobo,oveja,col],[pastor]).

buscar(Valor,[Valor | _]).
buscar(Valor,[_|Cola]):- buscar(Valor,Cola).

agregar([], L, L).
agregar([H|L1], L2, [H|L3]):- agregar(L1, L2, L3).

% extraer(X,L,R) - Unifica si la lista R equivale
% a la lista L, extrayendo de ella el elemento X.
% Ej: extraer(c,[a,b,c,d,e],[a,b,d,e]).
extraer(X,[X|T],T).
extraer(X,[A|T],[A|R]):-extraer(X,T,R).

% permutacion(X,Y) - Unifica si la lista X es una
% permutacion de la lista Y. El segundo argumento
% siempre debe estar completamente definido.
% Ej: permutacion([a,b,c],[b,a,c]).
permutacion([],[]).
permutacion([X|T],Y):-extraer(X,Y,Z),permutacion(T,Z).


mover(pastor,Origen,Destino,NuevoOrigen,NuevoDestino):-extraer(pastor,Origen,NuevoOrigen),
    												   agregar([pastor],Destino,NuevoDestino).

mover(oveja,Origen,Destino,NuevoOrigen,NuevoDestino):- buscar(oveja,Origen),
    												   mover(pastor,Origen,Destino,OrigenTemp,DestinoTemp),    													
    												   extraer(oveja,OrigenTemp,NuevoOrigen),
    												   agregar([oveja],DestinoTemp,NuevoDestino).
mover(lobo,Origen,Destino,NuevoOrigen,NuevoDestino):- buscar(lobo,Origen),
    												   mover(pastor,Origen,Destino,OrigenTemp,DestinoTemp),    													
    												   extraer(lobo,OrigenTemp,NuevoOrigen),
    												   agregar([lobo],DestinoTemp,NuevoDestino).
mover(col,Origen,Destino,NuevoOrigen,NuevoDestino):- buscar(col,Origen),
    												   mover(pastor,Origen,Destino,OrigenTemp,DestinoTemp),    													
    												   extraer(col,OrigenTemp,NuevoOrigen),
    												   agregar([col],DestinoTemp,NuevoDestino).
%Unifica si el ultimo movimiento es igual al actual
ultimoMovimiento(UltimoOrigen,UltimoDestino,OrigenActual,DestinoActual):-permutacion(UltimoOrigen,OrigenActual),permutacion(UltimoDestino,DestinoActual).
%Wraper
solucion(ListaInicial,DestinoInicial,Camino):-solucionR(ListaInicial,DestinoInicial,[],Camino,[],[]).
%Caso Base, solucion encontrada.
%solucionR(X,OrillaDestino,PasoAPaso,PasoAPaso,_,_):-permutacion(X,[col]), permutacion(OrillaDestino,[pastor,lobo,oveja]).
solucionR([],_,PasoAPaso,PasoAPaso,_,_).

solucionR(Origen,Destino,PasoAPaso,Camino,UltimoOrigen,UltimoDestino):-buscar(pastor,Origen),
    										mover(_,Origen,Destino,NuevoOrigen,NuevoDestino), 
    										not(ultimoMovimiento(UltimoOrigen,UltimoDestino,NuevoOrigen,NuevoDestino)),
    										orillas(NuevoOrigen,NuevoDestino),    										
    										agregar(PasoAPaso,[[NuevoOrigen,NuevoDestino]],PasoAPaso2),     										
    										solucionR(NuevoOrigen,NuevoDestino,PasoAPaso2,Camino,Origen,Destino).

solucionR(Origen,Destino,PasoAPaso,Camino,UltimoOrigen,UltimoDestino):-buscar(pastor,Destino),
    										mover(_,Destino,Origen,NuevoDestino,NuevoOrigen), 
    										not(ultimoMovimiento(UltimoOrigen,UltimoDestino,NuevoOrigen,NuevoDestino)),
    										orillas(NuevoOrigen,NuevoDestino),
    										agregar(PasoAPaso,[[NuevoOrigen,NuevoDestino]],PasoAPaso2),     										
    										solucionR(NuevoOrigen,NuevoDestino,PasoAPaso2,Camino,Origen,Destino).



