#pragma once

#include <iostream>
#include <iomanip>
#include <cassert>
#include <time.h>
#include <math.h>
#include <cstring>
#include <string.h>


using namespace std;

class matricula_t {
   
    private:
        string matricula_;
        unsigned long valor_;    
        int estado_; //0 celda vacía, 1 celda ocupada, 2 celda borrada,

        void calcular_valor(void);
            
        public:
        static unsigned long n_comparacion_; //esta variable se incremente cada vez que se realiza una comparacion. == , >,<
    
            matricula_t(void);
            matricula_t(bool activa);
            ~matricula_t(void);
            ostream & write(ostream & os);
            ostream & write_valor(ostream & os);            
            string & get_set(void);
            unsigned long get_valor(void);
            matricula_t operator = (string matricula);
            bool operator ==(matricula_t  matricula);
            bool operator ==(string  matricula);
            bool operator > (matricula_t  matricula);
            bool operator < (matricula_t  matricula);
            void set_aleatorio(void);
            void set(string  matricula);
            void borrar(void);
            friend ostream & operator << (ostream & os, matricula_t & valor);
            friend istream & operator >> (istream & is,matricula_t &valor);
};
