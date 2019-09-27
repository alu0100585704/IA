#include <iostream>
#include <sll_node_t.hpp>
using namespace std;

namespace RMLIB {


	template <class T>
	sll_node_t<T>::sll_node_t():
	data_(),
	next_(NULL)
	{}

	template <class T>
	sll_node_t<T>::sll_node_t(T data) :
	data_(data),
	next_(NULL)
	{}

	template <class T>
	sll_node_t<T>::~sll_node_t(void) 
	{
		next_ = NULL;
	}

	template <class T>
	void sll_node_t<T>::set_next(sll_node_t<T>* next)
	{
		next_ = next;
	}

	template <class T>
	sll_node_t<T>* sll_node_t<T>::get_next(void) const
	{
		return next_;
	}

	template <class T>
	void sll_node_t<T>::set_data(const T& data)
	{
		data_ = data;
	}

	template <class T>
	T sll_node_t<T>::get_data(void) const
	{
		return data_;
	}

	template <class T>
	ostream& sll_node_t<T>::write(ostream& os) const
	{
		os << data_;
		return os;
	}
}
