#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;
namespace RMLIB {

	template <class T>
	class vector_t{
	private:
		T*      v_;
		int     sz_;

	public:
            vector_t(void);
            vector_t(int sz);
            vector_t(vector_t<T> & vector_a_copiar);
            ~vector_t(void);
            void resize(int sz);
            int get_sz(void) const;
            virtual T get_v(int pos) const;
            virtual T& get_set_v(int pos);            
            istream& read(istream& is);
            ostream& write(ostream& os) const;
            T & operator[](int pos);
            vector_t<T> & operator=(vector_t<T> & vector_a_copiar);            
            template <class U>
            friend ostream & operator << (ostream & os, vector_t<U> & valor);
            template <class U>
            friend istream & operator >> (istream & is,vector_t<U> &valor);

            private:

            void crea_vector(void);
            void destruye_vector(void);
            

	};

  
}

