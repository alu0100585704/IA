#pragma once
#include <string>

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


};
