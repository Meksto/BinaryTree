#include <iostream>

template <typename T>
class bTree
{
public:
	bTree();

	void add(T data);

private:
	
	template <typename T>
	class Node
	{
	public:
	
		Node(T data = T(), Node *left = nullptr, Node *right = nullptr)
		{
			this->left = left;
			this->right = right;
			this->data = data;
		}
		T data;
		Node *left;
		Node *right;
	};

	int Size;
	Node<T>* root;
};

template <typename T>
bTree<T>::bTree() 
{
	root = nullptr;
	Size = 0;
}

template<typename T>
void bTree<T>::add(T data)
{
	if (root == nullptr)
	{
		root = new Node<T>(data);
		Size++;
		return;
	}

	Node<T>* current = root;
	Node<T>* prev = nullptr;
	while (current != nullptr)
	{
		prev = current;

		if (current->data > data)
		{
			current = current->left;
			continue;
		}
		else
		{
			current = current->right;
			continue;
		}

	}
	if (data > prev->data)
	{
		prev->right = new Node<T>(data);

	}
	else
	{
		prev->left = new Node<T>(data);
	}
	Size++;
	return;



}



int main()
{
	bTree<int> tree;

	tree.add(10);
	tree.add(15);
	tree.add(5);
	tree.add(20);


	return 0;
}