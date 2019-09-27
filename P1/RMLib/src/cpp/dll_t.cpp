#include <cassert>
#include <iostream>
#include <cstdio>

#include <dll_node_t.hpp>
#include <dll_t.hpp>

using namespace std;

namespace RMLIB {


    template <class T>
    dll_t<T>::dll_t(void) :
    head_(NULL),
    tail_(NULL),
    sz_(0) {
    }

    template <class T>
    dll_t<T>::~dll_t(void) {

        dll_node_t<T>* aux = NULL;

        while (head_ != NULL) {
            aux = head_;
            head_ = head_->get_next();
            delete aux;
            aux = NULL;
        }
        sz_ = 0;
        head_ = NULL;
        tail_ = NULL;
    }

    template <class T>
    bool dll_t<T>::empty(void) {

	if (head_ == NULL){

	   assert(tail_ == NULL);
	   assert(sz_ == 0);

	   return true;
	} else 
	   return false;
    }

    template <class T>
    void dll_t<T>::insert_head_nodo(dll_node_t<T>* nodo) {

        assert(nodo != NULL);

        if (empty()) {
            head_ = nodo;
            tail_ = head_;
        } else {
            head_->set_prev(nodo);
            nodo->set_next(head_);
            head_ = nodo;
        }

        sz_++;
    }

    template <class T>
    void dll_t<T>::insert_head_valor(T  valor)
    {
     dll_node_t<T> * aux;
     aux=NULL;
     aux=new dll_node_t<T>(valor);
     insert_head_nodo(aux)             ;
    }
      template <class T>
    void dll_t<T>::insert_head_valor(T  valor, int valor1)
    {
     dll_node_t<T> * aux;
     aux=NULL;
     aux=new dll_node_t<T>(valor);
     aux->get_set_valor1()=valor1;
     insert_head_nodo(aux)             ;
    }

            template <class T>
    void dll_t<T>::insert_head_valor(T  valor, double valor2)
    {
     dll_node_t<T> * aux;
     aux=NULL;
     aux=new dll_node_t<T>(valor);
     aux->get_set_valor2()=valor2;
     insert_head_nodo(aux)             ;
    }
  
                  template <class T>
    void dll_t<T>::insert_head_valor(T  valor, char valor3)
    {
     dll_node_t<T> * aux;
     aux=NULL;
     aux=new dll_node_t<T>(valor);
     aux->get_set_valor3()=valor3;
     insert_head_nodo(aux)             ;
    }
  
    template <class T>
    void dll_t<T>::insert_tail_valor(T  valor)
    {
     dll_node_t<T> * aux;
     aux=NULL;
     aux=new dll_node_t<T>(valor);
     insert_tail_nodo(aux)             ;        
    }
    
    template <class T>
    void dll_t<T>::insert_tail_valor(T  valor, int valor1)
    {
     dll_node_t<T> * aux;
     aux=NULL;
     aux=new dll_node_t<T>(valor);
     aux->get_set_valor1()=valor1;
     insert_tail_nodo(aux)             ;        
    }
    
    
    template <class T>
    void dll_t<T>::insert_tail_valor(T  valor, double valor2)
    {
     dll_node_t<T> * aux;
     aux=NULL;
     aux=new dll_node_t<T>(valor);
     aux->get_set_valor1()=valor2;
     insert_tail_nodo(aux)             ;        
    }
    
    
    template <class T>
    void dll_t<T>::insert_tail_valor(T  valor, char valor3)
    {
     dll_node_t<T> * aux;
     aux=NULL;
     aux=new dll_node_t<T>(valor);
     aux->get_set_valor1()=valor3;
     insert_tail_nodo(aux)             ;        
    }
    

    template <class T>
    void dll_t<T>::insert_tail_nodo(dll_node_t<T>* nodo) {

        assert(nodo != NULL);

        if (empty()) {
            head_ = nodo;
            tail_ = head_;
        } else {
            tail_->set_next(nodo);
            nodo->set_prev(tail_);
            tail_ = nodo;
        }

        sz_++;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::extract_tail_nodo(void) {

        assert(!empty());

        dll_node_t<T>* aux = tail_;

        tail_ = tail_->get_prev();

        if (tail_ != NULL)
            tail_->set_next(NULL);
        else
            head_ = NULL;

        sz_--;

	aux->set_next(NULL);
	aux->set_prev(NULL);

        return aux;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::extract_head_nodo(void) {

        assert(!empty());

        dll_node_t<T>* aux = head_;

        head_ = head_->get_next();

        if (head_)
            head_->set_prev(NULL);
        else
            tail_ = NULL;

        sz_--;

	aux->set_next(NULL);
	aux->set_prev(NULL);

        return aux;
    }

    template <class T>
    T  dll_t<T>::extract_head_valor(void)
    {
        dll_node_t<T> * aux;
        T valor;
        
        aux=extract_head_nodo();
        valor=aux->get_set_data();
        delete aux;
        return valor;
        
    }
    
        template <class T>
    T  dll_t<T>::extract_head_valor(int & valor1)
    {
        dll_node_t<T> * aux;
        T valor;
        
        aux=extract_head_nodo();
        valor=aux->get_set_data();
        valor1=aux->get_set_valor1();
        delete aux;
        return valor;
        
    }
            template <class T>
    T  dll_t<T>::extract_head_valor(double & valor2)
    {
        dll_node_t<T> * aux;
        T valor;
        
        aux=extract_head_nodo();
        valor=aux->get_set_data();
        valor2=aux->get_set_valor2();
        delete aux;
        return valor;
        
    }
                        template <class T>
    T  dll_t<T>::extract_head_valor(char & valor3)
    {
        dll_node_t<T> * aux;
        T valor;
        
        aux=extract_head_nodo();
        valor=aux->get_set_data();
        valor3=aux->get_set_valor3();
        delete aux;
        return valor;
        
    }
            
    template <class T>
    T  dll_t<T>::extract_tail_valor(void)
    {
        dll_node_t<T> * aux;
        T valor;
        
        aux=extract_tail_nodo();
        valor=aux->get_set_data();
        delete aux;
        return valor;
        
    }
                
    template <class T>
    T  dll_t<T>::extract_tail_valor(int & valor1)
    {
        dll_node_t<T> * aux;
        T valor;
        
        aux=extract_tail_nodo();
        valor=aux->get_set_data();
        valor1=aux->get_set_valor1();
        delete aux;
        return valor;
        
    }
    template <class T>
    T  dll_t<T>::extract_tail_valor(double & valor2)
    {
        dll_node_t<T> * aux;
        T valor;
        
        aux=extract_tail_nodo();
        valor=aux->get_set_data();
        valor2=aux->get_set_valor2();
        delete aux;
        return valor;
        
    }template <class T>
    T  dll_t<T>::extract_tail_valor(char & valor3)
    {
        dll_node_t<T> * aux;
        T valor;
        
        aux=extract_tail_nodo();
        valor=aux->get_set_data();
        valor3=aux->get_set_valor3();
        delete aux;
        return valor;        
    }
    

    template <class T>
    dll_node_t<T>* dll_t<T>::get_head_nodo(void) {
	return head_;
    }

    template <class T>
    dll_node_t<T>* dll_t<T>::get_tail_nodo(void) {
	return tail_;
    }
    template <class T>
    T &  dll_t<T>::get_set_head_valor(void)
    {                                
        return head_->get_set_data();
        
    }
    template <class T>
    T &  dll_t<T>::get_set_tail_valor(void)
    {                                
        return tail_->get_set_data();
        
    }
    template <class T>
    ostream& dll_t<T>::write(ostream& os) {
		
        dll_node_t<T>* aux = head_;

        while (aux != NULL) {
            aux->write(os);
            aux = aux->get_next();
        }

	return os;
    }

    template <class T>
    void dll_t<T>::remove_nodo(dll_node_t<T>* nodo) {
			
        assert(nodo != NULL);

        if (nodo->get_prev() != NULL)
            nodo->get_prev()->set_next(nodo->get_next());
        else
            head_ = nodo->get_next();

        if (nodo->get_next() != NULL)
            nodo->get_next()->set_prev(nodo->get_prev());
        else
            tail_ = nodo->get_prev();

	delete nodo;

        sz_--;

    }

    template <class T>
    int dll_t<T>::get_size(void) {
        return sz_;
    }	
    
           
template <class U>
ostream & operator << (ostream & os, dll_t<U> & valor)
{
dll_node_t<U>* aux = valor.head_;

        while (aux != NULL) {
            os << aux;
            aux = aux->get_next();
        }

	return os;
}

  
}
