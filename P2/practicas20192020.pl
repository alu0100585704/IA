%Condición de exito
orillas([lobo,oveja,col],[pastor]).
%
%Situaciones posibles
%
orillas([pastor,lobo,oveja,col],[]).
orillas([lobo],[pastor,oveja,col]).
orillas([oveja],[pastor,lobo,col]).
orillas([col],[pastor,lobo,oveja]).
orillas([pastor,oveja],[lobo,col]).
orillas([lobo,col],[pastor,oveja]).
orillas([pastor,lobo,oveja],[col]).
orillas([oveja,col,pastor],[lobo]).
orillas([col,pastor,lobo],[oveja]).
%
%las situaciones que no se pueden dar
%
%orillas([pastor],[lobo,oveja,col]).
%orillas([pastor,lobo],[oveja,col]).
%orillas([pastor,col],[lobo,oveja]).
%orillas([lobo,oveja],[pastor,col]).
%orillas([oveja,col],[pastor,lobo]).
%orillas([lobo,oveja,col],[pastor]).

%X=[[[],[]]]


%solucion([],[pastor,oveja,col,lobo]).
solucion(Lista,X):-solucionR(Lista,[],X).
%solucionR([oveja,col,lobo],[pastor],[pastor]).
%solucionR(OrillaOrigen,OrillaDestino,X):- member(pastor,OrillaOrigen), pastorEnOrigen(OrillaOrigen,OrillaDestino),solucion(OrillaOrigen,OrillaDestino).
solucionR(OrillaOrigen,OrillaDestino,X):- buscar(pastor,OrillaOrigen),pastorEnOrigen(OrillaOrigen,OrillaDestino),solucion(OrillaOrigen,OrillaDestino).
%solucion(OrillaOrigen,OrillaDestino):- member(pastor,OrigllaDestino), pastorEnDestino(OrillaOrigen,OrillaDestino),solucion(OrillaOrigen,OrillaDestino).

pastorEnOrigen(OrillaOrigen,OrillaDestino):- extraer(pastor,OrillaOrigen,OrillaSinPastor), OrillaOrigen = OrillaSinPastor.
%pastorEnOrigen(OrillaOrigen,OrillaDestino):- extraer(pastor,OrillaOrigen,OrillaSinPastor),OrillaOrigen = OrillaSinPastor, agregar([pastor],OrillaDestino,NuevaOrillaDestino),OrillaDestino=NuevaOrillaDestino,orillas(OrillaOrigen,OrillaDestino).
%pastorEnOrigen(OrillaOrigen,OrillaDestino):- extraer(pastor,OrillaOrigen,OrillaDestino),extraer(oveja,OrillaOrigen,OrillaDestino),orillas(OrillaOrigen,OrillaDestino).
%pastorEnOrigen(OrillaOrigen,OrillaDestino):- extraer(pastor,OrillaOrigen,OrillaDestino),extraer(lobo,OrillaOrigen,OrillaDestino),orillas(OrillaOrigen,OrillaDestino).
%pastorEnOrigen(OrillaOrigen,OrillaDestino):- extraer(pastor,OrillaOrigen,OrillaDestino),extraer(col,OrillaOrigen,OrillaDestino),orillas(OrillaOrigen,OrillaDestino).

%pastorEnDestino(OrillaOrigen,OrillaDestino):- extraer(pastor,OrillaDestino,OrillaOrigen),orillas(OrillaOrigen,OrillaDestino).
%pastorEnDestino(OrillaOrigen,OrillaDestino):- extraer(pastor,OrillaDestino,OrillaOrigen),extraer(oveja,OrillaDestino,OrillaOrigen),orillas(OrillaOrigen,OrillaDestino).
%pastorEnDestino(OrillaOrigen,OrillaDestino):- extraer(pastor,OrillaDestino,OrillaOrigen),extraer(col,OrillaDestino,OrillaOrigen),orillas(OrillaOrigen,OrillaDestino).
%pastorEnDestino(OrillaOrigen,OrillaDestino):- extraer(pastor,OrillaDestino,OrillaOrigen),extraer(lobo,OrillaDestino,OrillaOrigen),orillas(OrillaOrigen,OrillaDestino).

%append([[[a,b] | [[b,c]]]],[[[f,c] | [[x,y]]]],Y).
%append([[[a,b] | [[b,c]]]],[[[a,b],[c,d]]],Y).

%buscar(Valor,[]).
buscar(Valor,[Valor | Cola]).
buscar(Valor,[Otro | Cola]):- buscar(Valor,Cola).

agregar([], L, L).
agregar([H|L1], L2, [H|L3]):- agregar(L1, L2, L3).

%  %  Prácticas de Prolog - Inteligencia Artificial
% Grado en Ingeniería Informática, curso 2019/2020
% ----------- Universidad de La Laguna -----------
%   Javier Hernández Aceituno (jhernaac@ull.es)
% ================================================

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
