#ifndef MY_NODE_H
#define MY_NODE_H
namespace my_Node {

	template <typename Data>
	class Node
	{
	public:
		Data data;
		Node<Data>* p_next;
		Node(Data data = Data(), Node<Data>* p_next = nullptr) 
		{
			this->data = data;
			this->p_next = p_next;
		};
	};

	template<typename Data>
	class TwoWayNode
	{
	public:
		Data data;
		TwoWayNode<Data>* p_next;
		TwoWayNode<Data>* p_prev;
        TwoWayNode<Data>* node_adress;
	public:
        TwoWayNode(Data data = Data(), TwoWayNode<Data>* p_prev = nullptr,
                   TwoWayNode<Data>* p_next = nullptr)
             : data(data), p_prev(p_prev), p_next(p_next), node_adress(this){};
	};

	
} // namespace my_Node
#endif