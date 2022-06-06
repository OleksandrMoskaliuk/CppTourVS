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

	
} // namespace my_Node
#endif