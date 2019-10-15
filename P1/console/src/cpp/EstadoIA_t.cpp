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

EstadoIA_t& EstadoIA_t::operator=(const string valor)
{
    this->valor_=valor;

}

EstadoIA_t& EstadoIA_t::operator=(const int valor)
{
    this->id_=valor;
}

EstadoIA_t& EstadoIA_t::operator=(const EstadoIA_t &valor)
{
    this->valor_=valor.valor_;
    this->id_=valor.id_;
}

bool EstadoIA_t::operator ==(const EstadoIA_t &valor) const
{
    if (this->id_==valor.id_)
        return 1;
    else return 0;

}

bool EstadoIA_t::operator <(const EstadoIA_t &valor) const
{
    if (this->id_< valor.id_)
            return 1;
       else
            return 0;

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
