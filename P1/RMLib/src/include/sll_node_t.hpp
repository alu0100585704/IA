#pragma once

#include <iostream>
using namespace std;

namespace RMLIB {

	template <class T>
	class sll_node_t {
	private:
		sll_node_t<T>* next_;
		T              data_;

	public:
		sll_node_t(void);
		sll_node_t(T data);
		~sll_node_t(void);

		void set_next(sll_node_t<T>* next);
		sll_node_t<T>* get_next(void) const;

		void set_data(const T& data);
		T get_data(void) const;

		ostream& write(ostream& os) const;
	};


}
