#pragma once

#include <dll_t.hpp>
#include <NodeIA_t.hpp>

template <class T>
class GrafoIA_t {

private:

 RMLIB::dll_t<NodeIA_t> *grafo_;
 int numeroNodos_;

public:



    GrafoIA_t();
    GrafoIA_t(char nombrefichero[], int &errorapertura);

    ~GrafoIA_t();

    int actualizar(char nombrefichero[], int &errorapertura);
    void liberarMemoria();

};



