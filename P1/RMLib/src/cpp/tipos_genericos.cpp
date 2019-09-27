#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;
namespace RMLIB {

class int_t{
public:
    int valor_;    

int & get_set(void)
{
    return valor_;
}
void set(int valor)
{
    valor_=valor;
}

ostream & write (ostream & os)
{
      os << valor_;
}

int_t & operator = (int valor)
{
    valor_=valor;
}

bool  operator < (int valor)
{
    if (valor_<valor) return true;
    else return false;
    
}

bool  operator > (int valor)
{
        if (valor_>valor) return true;
    else return false;
    
    
}
bool  operator == (int valor)
{
        if (valor_==valor) return true;
    else return false;
}

bool  operator < (int_t valor)
{
    if (valor_< valor.get_set()) return true;
    else return false;
    
}

bool  operator > (int_t valor)
{
    if (valor_>valor.get_set()) return true;
    else return false;
        
}
bool  operator == (int_t valor)
{
    if (valor_==valor.get_set()) return true;
    else return false;    
    
}
};

class double_t {
public:
    double valor_;    
double  & get_set(void)
{
    return valor_;
}
void set(double valor)
{
    valor_=valor;
}

ostream & write (ostream & os)
{
      os << valor_;
}

};

class char_t {
public:
    char valor_;
char & get_set(void)
{
    return valor_;
}
void set(char valor)
{
    valor_=valor;
}

ostream & write (ostream & os)
{
      os << valor_;
}
};

}