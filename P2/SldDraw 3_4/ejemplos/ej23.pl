std(juan).
std(pedro).

csd(juan).

not(X):-call(X),!,fail.
not(X).

es1(X):-not(csd(X)),std(X).

%es2(X):-std(X),not(csd(X)).
