#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <time.h>
#include <math.h>
#include <cstring>
#include <string.h>
#include <matricula_t.hpp>
#include <cstdlib>
using namespace std;


//constructor por defecto genera una matricula aleatoria

matricula_t::matricula_t(void) : 
valor_(0),
estado_(1)
{
    
    set_aleatorio();
    
}
//construcotr con parametro true, genera matricula aleatoria , false genera matriculas como si se hubieran borrado.
matricula_t::matricula_t(bool activa)
{
    if (activa) set_aleatorio();
    else borrar();
    
    estado_=1; //indico que esta ocupada y no borrada, puesto que fue en contructor.
        
}

matricula_t::~matricula_t(void)
{
    
}


void matricula_t::calcular_valor(void)
{
    int valor_numeros=0;
    int valor_letras=0;
    
    //pondero cada posicion numerica en base 10.
for (int i=0; i<=3;i++) 
        valor_numeros= valor_numeros + matricula_[i]* pow(10,3-i);
    
        //pondero cada posicion de letra  en base 26.

for (int i=4; i<=6;i++) 
        valor_letras= valor_letras + matricula_[i]* pow(26,6-i);
    
    valor_=valor_numeros * valor_letras; //valor numerico final de la matricula
    
}

ostream & matricula_t::write(ostream & os)
{
    os << matricula_<< "(" << valor_ << ")";
    return os;
}
ostream & matricula_t::write_valor(ostream & os)
{
    os << "(" << valor_ << ")";
    return os;
}

string & matricula_t::get_set(void)
{
 return matricula_;   
}

unsigned long matricula_t::get_valor(void)
{
    return valor_;
}
matricula_t matricula_t::operator = (string  matricula)
{
    matricula_=matricula;        
    calcular_valor();
}

bool matricula_t::operator ==(matricula_t  matricula)
{
    //matricula_t::n_comparacion_++;
    if (valor_==matricula.get_valor()) return true;
    else return false;
}
bool matricula_t::operator ==(string matricula)
{
    //matricula_t::n_comparacion_++;
    //invierto la respuesta,puesto que la comparacion devulve 0 si son iguales, y para interpretarlo como valores boleanos el true es igual a 1.
    if (matricula_ == matricula) 
        return true;
    else return false;
    
 
}
bool matricula_t::operator > (matricula_t  matricula)
{
    //matricula_t::n_comparacion_++;
    if (valor_>matricula.get_valor()) return true;
    else return false;
}
bool matricula_t::operator < (matricula_t  matricula)
{
   // matricula_t::n_comparacion_++;
    if (valor_<matricula.get_valor()) return true;
    else return false;
}
void matricula_t::set_aleatorio(void)
{
    matricula_="       ";
    // relleno la parte izquierda de la matrícula, cuatro numeros.
for (int i=0;i < 4;i++)
    matricula_[i]=48 + rand() % 10;
// relleno las ultimas tres posiciones de la matricula, las letras, en base 26    
for (int i=4;i < 7;i++)
    matricula_[i]=65 + rand() % 26;

calcular_valor();
}
void matricula_t::set(string  matricula)
{
    matricula_=matricula;
        
    calcular_valor();

}
void matricula_t::borrar(void)
{
        valor_=0;
        estado_=2;
        matricula_=="XXXXXXX";        

}

ostream & operator << (ostream & os, matricula_t & valor)
{
    os << valor.matricula_;
    return os;
}
istream & operator >> (istream & is,matricula_t &valor)
{
    is >> valor.matricula_;
    valor.calcular_valor();
    return is;
}
