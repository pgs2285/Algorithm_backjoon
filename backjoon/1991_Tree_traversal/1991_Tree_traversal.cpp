#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
	string data;
	Node* left = nullptr;
	Node* right = nullptr;
};

void inorder(Node* parent)
{
	if (parent == nullptr) return;
	inorder(parent->left);
	if (parent->data != ".")cout << parent->data;
	inorder(parent->right);
}

void preorder(Node* parent)
{
	if (parent == nullptr) return;
	if (parent->data != ".")cout << parent->data;
	preorder(parent->left);
	preorder(parent->right);

}

void postorder(Node* parent)
{
	if (parent == nullptr) return;
	postorder(parent->left);
	postorder(parent->right);
	if (parent->data != ".")cout << parent->data;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	unordered_map<string, Node*> nodeList;
	Node* parent = new Node();
	
	int N;
	std::cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		string p, r, l;
		Node* left = new Node();
		Node* right = new Node();
		cin >> p >> l >> r;
		if (i == 0)
		{
			parent->data = p;
			parent->left = left;
			parent->right = right;
			nodeList[p] = parent;
		}
		left->data = l;
		right->data = r;
		nodeList[r] = right;
		nodeList[l] = left;
		nodeList[p]->left = left;
		nodeList[p]->right = right;
	}
	preorder(parent);
	std::cout << "\n";
	inorder(parent);
	std::cout << "\n";
	postorder(parent);

}

