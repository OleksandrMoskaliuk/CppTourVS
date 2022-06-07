#ifndef TWO_WAY_LIST_H
#define TWO_WAY_LIST_H
#include <iostream>
#include "Node.h"

namespace my_list
{
	template<typename Data>
	class TwoWayList
	{
	private:
		my_Node::TwoWayNode<Data>* head;
		int size_m;
	public:
		TwoWayList(Data data = Data(), my_Node::TwoWayNode<Data>* prev = nullptr, my_Node::TwoWayNode<Data>* next = nullptr) :
			head(nullptr), size_m(0) {};
		~TwoWayList();
	public:
		int get_size();
		void push_front(Data dt);
		void push_back(Data dt);
		void insert(int index, Data dt);
		Data& operator[](int index);
		void pop_front();
		void pop_back();
		void remove(int index);
		void clean();
	};
	
	template <typename Data>
	TwoWayList<Data>::~TwoWayList()
	{
		//clear
	}

	template <typename Data>
	int TwoWayList<Data>::get_size()
	{
		return this->size_m;
	}

	template<typename Data>
	void TwoWayList<Data>::push_front(Data dt)
	{
		if (this->head == nullptr) 
		{
			this->head = new my_Node::TwoWayNode<Data>(dt);
			size_m++;
			return;
		}
		my_Node::TwoWayNode<Data>* next = this->head;
		this->head = new my_Node::TwoWayNode<Data>(dt,nullptr,next);
		size_m++;

	}

	template<typename Data>
	Data& TwoWayList<Data>::operator[](int index) 
	{
		if (size_m == 0) 
		{
			Data except = Data();
			return except;
		}
		if (index > size_m) index = size_m;
		if (index < 0) index = 0;
		my_Node::TwoWayNode<Data>* current = this->head;
		for(size_t i = 0; i<index; i++)
		{
			current = current->p_next;
		}
		return current->data;
	}
} //namespace my_list
#endif // TWO_WAY_LIST_H