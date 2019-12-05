casado(juan,maria).
casado(pedro,luisa).
casado(andres,ana).

%casado(X,Y):-casado(Y,X).

casados(X,Y):-casado(X,Y).
casados(X,Y):-casado(Y,X).
