#include <iostream>
#include <EstadoIA_t.hpp>
#include <string>
using namespace std;
EstadoIA_t::EstadoIA_t():
    valor_(""),
    id_(-1)
{

}

EstadoIA_t::EstadoIA_t(string valor, int id):
    valor_(valor),
    id_(id)
{

}

EstadoIA_t::~EstadoIA_t()
{

}

void EstadoIA_t::operator=(string valor)
{
    valor_=valor;

}

void EstadoIA_t::operator=(int valor)
{
    id_=valor;
}

void EstadoIA_t::operator=(EstadoIA_t valor)
{
    valor_=valor.valor_;
    id_=valor.id_;
}

void EstadoIA_t::limpiar()
{
    valor_="";
    id_=-1;
}

ostream & operator << (ostream & os, EstadoIA_t &valor)
{
    os <<  valor.id_;
return os;

}
