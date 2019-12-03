%  Prácticas de Prolog - Inteligencia Artificial
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

% no_vecinos(A,B) - Unifica si A y B son números
% no consecutivos.
no_vecinos(A,B):- A=\=B+1, A=\=B-1.

% solucion(A,[B,C,D],[E,F,G],H) - Unifica si, para
% la cuadrícula mostrada, las variables
% A a H son números de 1 a 8, tales que       A
% no existen números consecutivos en        B C D
% casillas vecinas horizontal, vertical     E F G
% ni diagonalmente.                           H
% Ej: solucion(2,[5,8,6],[3,1,4],7).
solucion(A,[B,C,D],[E,F,G],H):-
    permutacion([A,B,C,D,E,F,G,H],[1,2,3,4,5,6,7,8]),
    no_vecinos(A,B),no_vecinos(A,C),no_vecinos(A,D),
    no_vecinos(B,C),no_vecinos(B,E),no_vecinos(B,F),
    no_vecinos(C,D),no_vecinos(C,E),no_vecinos(C,F),
    no_vecinos(C,G),no_vecinos(D,F),no_vecinos(D,G),
    no_vecinos(E,F),no_vecinos(E,H),no_vecinos(F,G),
    no_vecinos(F,H),no_vecinos(G,H).

% ================================================

% Definición mediante hechos de un grafo.
arista(1,2).    %    ,->-( 2 )->-.
arista(1,3).    %   /      |      \
arista(2,4).    % ( 1 )    ^    ( 4 ) 
arista(3,2).    %   \      |      /
arista(3,4).    %    `->-( 3 )->-´

% camino(X,Y,L) - Unifica si L es una lista de nodos
% que represente un camino válido en el grafo descrito
% desde el nodo X hasta el nodo Y.
% Ej: camino(1,4,[1,3,2,4]).
camino(X,X,Acc,R):-reverse(Acc,R).
camino(X,Y,Acc,R):-arista(X,Z),camino(Z,Y,[Z|Acc],R).
camino(X,Y,R):-camino(X,Y,[X],R). % wrapper
