%
%Este programa permite resolver y devolver la traza seguida para el acertijo del pastor la oveja, lobo y col.
%Está realizado con hechos y acumuladores.
%Permite la permutación de las listas y además he incorporado un parámetro para resolver incluso sin tener porque partir de la posición inicial.
%Se agrega un wraper para no tener que especificar todos los parámetros.
%
%Sintaxis:
%:-solucion(A,B,X). Donde A=lista orilla 1, B=lista orilla 2, X = contendrá resultado de la traza y solución
%Ejemplo
%:-solucion([pastor,lobo,oveja,col],[],X). Devolverá la traza desde la posición todos en la orilla 1.
%:-solucion([lobo,col],[pastor,oveja],X). Devolverá la traza desde la posición en la que lobo y col  están en la orilla 1 y pastor y oveja están en la orilla 2.
%:-solucion([lobo,oveja,col],[pastor],X). Devolverá falso, puesto que esta posición inicial no se puede dar, ya que el lobo se comería a la oveja o la oveja a la col.


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

%
% Creo mi propio buscar porque el predicad "member" no me funciona con el SLDDRAW 3.4, programa que he usado para realizar trazas del programa
% a través de árboles. 
%

buscar(Valor,[Valor | _]).
buscar(Valor,[_|Cola]):- buscar(Valor,Cola).
%
% Creo mi propio agregar porque el predicad "append" no me funciona con el SLDDRAW 3.4, programa que he usado para realizar trazas del programa
% a través de árboles. 
%

agregar([], L, L).
agregar([H|L1], L2, [H|L3]):- agregar(L1, L2, L3).

%
%Extraer y permutacion han sido dados por el profesor
%
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

%
% Mover quita de la lista Origen el objeto (pastor, oveja, lobo o col) especificado y lo inserta en la lista destino-
% las nuevas listas son NuevoOrigen y NuevoDestino
%

%
% Mover el pastor es el único que no comprueba si está en la lista antes de moverlo, puesto que se llega habiendo hecha ya esa comprobación en el predicado solución.
% Además, mover el pastor es el único movimiento que se podría realizar solo, los otros tres, siempre mueven primero al pastor y después el objeto seleccionado por backtraking
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

%
%Unifica si el ultimo movimiento realizado es igual al actual, o sea, al que acabo de realizar. De esta forma, como lo niego en la regla, solo acepta el movimiento si realmente
%no unificó, o sea, no fue igual al anterior, así evitó bucles. 
%
ultimoMovimiento(UltimoOrigen,UltimoDestino,OrigenActual,DestinoActual):-permutacion(UltimoOrigen,OrigenActual),permutacion(UltimoDestino,DestinoActual).
%Wraper
solucion(ListaInicial,DestinoInicial,Camino):-solucionR(ListaInicial,DestinoInicial,[],Camino,[],[]).



%Caso Base, solucion encontrada. orilla uno vacía, la orilla 2 me da igual porque esta claro que estaría llena.
solucionR([],_,PasoAPaso,PasoAPaso,_,_).

%
%Con la línea de abajo podría modificar mi condición de parada, y que la solución final sea la que yo quiera. Es para pruebas
%solucionR(X,OrillaDestino,PasoAPaso,PasoAPaso,_,_):-permutacion(X,[col]), permutacion(OrillaDestino,[pastor,lobo,oveja]).
%


%
% Básicamente lo que diferencia  cada predicado solucionR, es si el pastor está en la orilla1  o en la orilla 2.
% En base a eso,el pastor siempre lo muevo, comprueba que ese movimiento  no lleva a una situación idéntica al paso anterior.
% Si el movimiento ya se había realizado en el paso anterior, se busca por backtraking otro movimiento diferente.
% Si el movimiento no se había realizado, comprueba que se haya llegado a una posición legal,  comprobando con los hechos.
% Si es posición legal, agrego a la traza el nuevo estado y vuelvo a seguir buscando soluciones o comprobar si ya es la solución final.
% En caso que la posición no sea legal, por backtraking, hago otro movimiento y continuo.
%
%
%Si el pastor está en la orilla origen 
%
solucionR(Origen,Destino,PasoAPaso,Camino,UltimoOrigen,UltimoDestino):-buscar(pastor,Origen),
    										mover(_,Origen,Destino,NuevoOrigen,NuevoDestino), 
    										not(ultimoMovimiento(UltimoOrigen,UltimoDestino,NuevoOrigen,NuevoDestino)),
    										orillas(NuevoOrigen,NuevoDestino),    										
    										agregar(PasoAPaso,[[NuevoOrigen,NuevoDestino]],PasoAPaso2),     										
    										solucionR(NuevoOrigen,NuevoDestino,PasoAPaso2,Camino,Origen,Destino).

%
%Si el pastor está en la orilla destino 
%
solucionR(Origen,Destino,PasoAPaso,Camino,UltimoOrigen,UltimoDestino):-buscar(pastor,Destino),
    										mover(_,Destino,Origen,NuevoDestino,NuevoOrigen), 
    										not(ultimoMovimiento(UltimoOrigen,UltimoDestino,NuevoOrigen,NuevoDestino)),
    										orillas(NuevoOrigen,NuevoDestino),
    										agregar(PasoAPaso,[[NuevoOrigen,NuevoDestino]],PasoAPaso2),     										
    										solucionR(NuevoOrigen,NuevoDestino,PasoAPaso2,Camino,Origen,Destino).



