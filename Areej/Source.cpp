#include <iostream>
using namespace std;

int *arr = new int[10];
int moeez = 0;
int SPACE = 5;
class Node
{
	friend class BST;
	int data;
	Node *left;
	Node *right;

public:
	Node()
	{
		data = 0;
		left = right = nullptr;
	}
};

class BST
{
	Node *root;
	int count;
	int lcount;

public:
	BST()
	{
		root = nullptr;
		count = lcount = 0;
	}
	Node *get_root()
	{
		return this->root;
	}

	void copyConstructor(Node *copy, Node *&r)
	{
		if (copy != nullptr)
		{
			r = new Node;
			r->data = copy->data;
			r->left = r->right = nullptr;
			copyConstructor(copy->left, r->left);
			copyConstructor(copy->right, r->right);
		}
	}
	BST(const BST &copy)
	{
		copyConstructor(copy.root, root);
	}

	void insert(Node *&r, int d)
	{
		if (r == nullptr)
		{
			r = new Node;
			r->data = d;
			r->left = r->right = nullptr;
		}
		else
		{
			if (d < r->data)
				insert(r->left, d);
			else if (d > r->data)
				insert(r->right, d);
		}
	}
	void insert(int d)
	{
		insert(root, d);
	}

	void InorderPrint(Node *r)
	{
		if (r != nullptr)
		{
			InorderPrint(r->left);
			cout << r->data << endl;
			InorderPrint(r->right);
		}
	}
	void InorderPrint()
	{
		InorderPrint(root);
	}

	Node *search(Node *&r, int key)
	{
		if (r == nullptr)
		{
			return nullptr;
		}
		else if (r->data == key)
		{
			return r;
		}
		else if (r->data > key)
		{
			return search(r->left, key);
		}
		else
			return search(r->right, key);
	}
	Node *search(int key)
	{
		Node *curr = search(root, key);
		return curr;
	}

	int pathSums(Node *&r, int sum)
	{
		if (r == nullptr)
		{
			return 0;
		}
		sum = sum + r->data;
		if (r->left == nullptr && r->right == nullptr)
		{
			arr[moeez] = sum;
			moeez++;
			return sum;
		}
		return pathSums(r->left, sum) + pathSums(r->right, sum);
	}
	void pathSums()
	{
		cout << pathSums(root, 0);
	}

	bool isEqual(Node *&r1, Node *&r2)
	{
		if (r1 == nullptr && r2 == nullptr)
		{
			return true;
		}
		else if (r1 == nullptr || r2 == nullptr)
		{
			return false;
		}
		else
		{
			if (r1->data == r2->data && isEqual(r1->left, r2->left) && isEqual(r1->right, r2->right))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	bool operator==(BST t)
	{
		if (isEqual(t.root, root))
		{
			cout << "EQAUL!" << endl;
			return true;
		}
		else
		{
			cout << "EQAUL!" << endl;
			return false;
		}
	}

	int findAncestor(Node *&r, int d)
	{
		if (r == nullptr)
			return -1;
		if (r->left->data == d)
			return r->data;
		if (r->right->data == d)
			return r->data;
		if (r->data > d)
			return findAncestor(r->left, d);
		else
			return findAncestor(r->right, d);
	}
	void findAncestor(int key)
	{
		cout << findAncestor(root, key);
	}

	void destroy(Node *r)
	{
		if (r != nullptr)
		{
			destroy(r->left);
			destroy(r->right);
			delete r;
		}
	}
	~BST()
	{
		destroy(root);
	}
	int height(Node *temp)
	{
		if (temp == NULL)
			return -1;
		int left_h = 0;
		int right_h = 0;
		left_h = height(temp->left);
		right_h = height(temp->right);
		if (left_h > right_h)
			return left_h + 1;
		return right_h + 1;
	}
	void delete_level(Node *temp, int manzil)
	{
		if (temp == NULL)
		{
			return;
		}
		int flag = 0;
		if (manzil == 0)
		{
			cout << "Deleting value: " << temp->data << endl;
			temp->left = NULL;
			temp->right = NULL;
			delete temp;
			flag = 1;
		}
		delete_level(temp->left, manzil - 1);
		if (manzil - 1 == 0)
			temp->left = NULL;
		delete_level(temp->right, manzil - 1);
		if (manzil - 1 == 0)
			temp->right = NULL;
	}

	void trim_from_k(int k)
	{
		cout << "HEHe" << endl;
		cout << "k: " << k << endl;
		int height = this->height(this->root);
		cout << "Height: " << height << endl;
		for (int i = height; i > k; i--)
		{
			cout << "Deleting level: " << i << endl;
			delete_level(root, i);
		}
	}

	void print2d(Node *temp, int space)
	{
		if (temp == NULL)
			return;
		space += SPACE;
		print2d(temp->right, space);
		cout << endl;
		for (int i = SPACE; i < space; i++)
			cout << ' ';
		cout << temp->data << endl;
		print2d(temp->left, space);
	}
};
int main()
{
	BST tree;
	tree.insert(10);
	tree.insert(12);
	tree.insert(9);
	tree.insert(8);
	tree.insert(13);
	tree.insert(7);
	tree.insert(14);
	tree.print2d(tree.get_root(), 5);
	cout << "-----TREE 1-----" << endl;
	tree.InorderPrint();
	cout << endl;
	cout << "THE SUM OF PATHS IS: " << endl;
	tree.pathSums();
	cout << endl;
	cout << "Height of the tree: " << tree.height(tree.get_root()) << endl;
	cout << "Enter the k th level you want to trim: ";
	int k;
	cin >> k;
	tree.trim_from_k(k);
	tree.print2d(tree.get_root(), 5);
	tree.InorderPrint();
	// BST tree2;
	// tree2.insert(3);
	// tree2.insert(5);
	// tree2.insert(21);
	// tree2.insert(71);
	// tree2.insert(4);
	// tree2.insert(44);
	// cout << "-----TREE 2-----" << endl;
	// tree2.InorderPrint();
	// cout << endl;
	// cout << "ARE THE TWO TREES EQUAL? " << endl;
	// if (tree == tree2)
	// 	cout << "Yes they are!\n";
	// else
	// 	cout << "Nope!\n";
	return 0;
}