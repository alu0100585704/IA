#pragma once

#include <iostream>
using namespace std;

#include <sll_node_t.hpp>

namespace RMLIB {

   	template <class T>
	class sll_t {
	private:
		sll_node_t<T>* head_;

	public:
		sll_t(void);
		virtual ~sll_t(void);

		void insert_head(sll_node_t<T>* n);
		sll_node_t<T>* extract_head(void);

		void insert_after(sll_node_t<T>* pred, sll_node_t<T>* n);
		sll_node_t<T>* extract_after(sll_node_t<T>* pred);

		sll_node_t<T>* head(void);

		bool empty(void) const;	
		ostream&  write(ostream& os) const;
	};
    
}
