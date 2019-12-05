nat(c).
nat(s(X)):-nat(X).

%suma(c,Y,Y):-nat(Y).
%suma(s(X),Y,s(Z)):-suma(X,Y,Z).

menorigual(c,Y):- nat(Y).
menorigual(s(X),s(Y)):- menorigual(X,Y).

menor(c,s(Y)):- nat(Y).
menor(s(X),s(Y)):- menor(X,Y).

%for(I,J,I) :- menorigual(I,J).
%for(I,J,K) :- menor(I,J), for(s(I),J,K).
