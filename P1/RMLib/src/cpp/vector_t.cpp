#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector_t.hpp>
using namespace std;
namespace RMLIB {


// Implementaci�n m�todos p�blicos
        
                template <class T>
		vector_t<T>::vector_t(void):
			v_(NULL),
			sz_(0) {}
                template <class T>
		vector_t<T>::vector_t(int sz):
			v_(NULL),
			sz_(sz) {

			crea_vector();
		}
                template <class T> //construcotr copia
                vector_t<T>::vector_t(vector_t<T> & vector_a_copiar) :
                v_(NULL)                                      
                {
                    sz_=vector_a_copiar.get_sz();
                    crea_vector();
                    for (int i=0; i< sz_;i++)                    
                        v_[i]=vector_a_copiar[i];
                    
                }
                template <class T>
		vector_t<T>::~vector_t(void){

			destruye_vector();
		}
                template <class T>
		void vector_t<T>::resize(int sz)
		{
			destruye_vector();
			sz_ = sz;
			crea_vector();
		}
                template <class T>
		int vector_t<T>::get_sz(void) const
		{
			return sz_;
		}
                template <class T>
		 T vector_t<T>::get_v(int pos) const{
		
			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}
                template <class T>
		T& vector_t<T>::get_set_v(int pos){

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

                template <class T>
                T & vector_t<T>::operator[](int pos)
                {
                    return v_[pos];
                }
                           

         template <class T>
        vector_t<T> & vector_t<T>::operator=(vector_t<T> & vector_a_copiar)
         {
             
             sz_=vector_a_copiar.get_sz();   
             resize(sz_);
             for (int i=0; i < sz_;i++)
                 v_[i]=vector_a_copiar[i];
                 
         }
// Implementaci�n m�todos privados        
        
	template <class T>
        void vector_t<T>::crea_vector(void){
			v_ = new T[sz_];
		}

        template <class T>                  
        void vector_t<T>::destruye_vector(void)
		{
			if (v_ != NULL){
				delete [] v_;
				v_ = NULL;
			}
		}


template <class U>
ostream & operator << (ostream & os, vector_t<U> & valor)
{
        
    for(int i = 0; i < valor.sz_; i ++)
		 	os << endl << i << " : " << setw(8)  << valor.v_[i] << endl;
    
    return os;
}
template <class U>        
istream & operator >> (istream & is,vector_t<U> &valor)
{
    			is >> valor.sz_;

			valor.resize(valor.sz_);

			for(int i = 0; i < valor.sz_; i ++)
			 	is >> valor.v_[i];
    
    return is;
}
  
}

