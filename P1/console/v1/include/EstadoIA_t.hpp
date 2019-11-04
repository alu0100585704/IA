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

    EstadoIA_t&  operator= (const string valor);
    EstadoIA_t& operator= (const int valor);
    EstadoIA_t& operator= (const EstadoIA_t &valor);
    bool operator  == (const EstadoIA_t &valor)const;
    bool operator < (const EstadoIA_t &valor) const;
    void limpiar();

    friend ostream & operator << (ostream & os,EstadoIA_t & valor);

};

