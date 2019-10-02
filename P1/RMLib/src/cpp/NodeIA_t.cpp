#include <nodeIA_t.hpp>
template<class T>
NodeIA_t<T>::NodeIA_t():
    estado_(NULL),
    profundidad_(0),
    costo_(0),
    accion_(""),
    LS_(NULL),
    padre_(NULL),
    estudiado_(false)
{
inicializar();

}

template<class T>
NodeIA_t<T>::~NodeIA_t()
{
    if (estado_!=NULL)
       delete estado_;

    if (LS_ != NULL)
        delete LS_;

    if (padre_!=NULL)
        delete padre_;

}

template<class T>
void NodeIA_t<T>::inicializar()
{
  if (estado_!=NULL)
     delete estado_;

  if (LS_ != NULL)
      delete LS_;

  if (padre_!=NULL)
      delete padre_;

    estado_=new EstadoIA_t;
    LS_= new RMLIB::dll_t<NodeIA_t>;
    padre_= new NodeIA_t;
}
