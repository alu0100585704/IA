#pragma once
#include <string>
#include <iostream>
using namespace std;

class EstadoIA_t {

private:
public:
    std::string valor_;
    int id_;

    EstadoIA_t();
    EstadoIA_t(std::string valor,int id);
    ~EstadoIA_t();

    operator = (std::string valor);
    operator =(int valor);
    operator = (EstadoIA_t valor);

    void limpiar();

    friend ostream & operator << (ostream & os,EstadoIA_t & valor);

};

