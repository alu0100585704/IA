#pragma once
#include <string>
#include <iostream>
using namespace std;

class EstadoIA_t {

private:
public:
    string valor_;
    int id_;

    EstadoIA_t();
    EstadoIA_t(string valor,int id);
    ~EstadoIA_t();

    void operator= (string valor);
    void operator=(int valor);
    void operator= (EstadoIA_t valor);

    void limpiar();

    friend ostream & operator << (ostream & os,EstadoIA_t & valor);

};

