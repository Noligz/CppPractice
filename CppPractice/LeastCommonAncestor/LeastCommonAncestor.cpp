#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
struct BiTreeNode{
	BiTreeNode(T data, BiTreeNode* left = NULL, BiTreeNode* right = NULL)
	{
		this->data = data;
		this->lchild = left;
		this->rchild = right;
	}
	BiTreeNode* lchild;
	BiTreeNode* rchild;
	T data;
};

template <typename T>
BiTreeNode<T>* CreateBiTree(istream& is)
{
	T data;
	is >> data;
	if (data == -1 || data == '*')
		return NULL;
	BiTreeNode<T>* lchild = CreateBiTree<T>(is);
	BiTreeNode<T>* rchild = CreateBiTree<T>(is);
	return new BiTreeNode<T>(data, lchild, rchild);
}

template <typename T>
BiTreeNode<T>* LCA(BiTreeNode<T>* root, T& a, T& b, bool& aFound, bool& bFound)
{
	if (root == NULL)
		return NULL;

	BiTreeNode<T>* left = LCA(root->lchild, a, b, aFound, bFound);
	BiTreeNode<T>* right = LCA(root->rchild, a, b, aFound, bFound);

	if (root->data == a)
	{
		aFound = true;
		return root;
	}
	if (root->data == b)
	{
		bFound = true;
		return root;
	}

	if (left != NULL && right != NULL)
		return root;
	return left != NULL ? left : right;
}

template <typename T>
BiTreeNode<T>* LCA(BiTreeNode<T>* root, T& a, T& b)
{
	bool aFound = false, bFound = false;
	BiTreeNode<T>* ret = LCA(root, a, b, aFound, bFound);
	if ((aFound && bFound) || (a == b && (aFound || bFound)))
		return ret;
	else
		return NULL;
}

template <typename T>
void DelBiTree(BiTreeNode<T>* &root)
{
	if (root == NULL)
		return;
	if (root->lchild != NULL)
		DelBiTree(root->lchild);
	if (root->rchild != NULL)
		DelBiTree(root->rchild);
	delete root;
	root = NULL;
}

void main()
{
	ifstream fin("TestCases.txt");
	if (!fin)
	{
		cerr << "Fail to read test case file! \n";
		system("pause");
		return;
	}

	int treeCount = 0;
	fin >> treeCount;
	for (int i = 0; i < treeCount; i++)
	{
		BiTreeNode<int>* bt = CreateBiTree<int>(fin);

		int testCaseCount = 0;
		fin >> testCaseCount;

		cout << "Testing tree #" << i + 1 << ":\n";
		for (int j = 0; j < testCaseCount; j++)
		{
			int a, b;
			fin >> a >> b;
			cout << "Case #" << j + 1 << ": ";// << a << " " << b << ", ";
			BiTreeNode<int>* lca = LCA(bt, a, b);
			if (lca != NULL)
				cout << lca->data << endl;
			else
				cout << "Not found. \n";
		}

		DelBiTree(bt);
	}
	fin.close();

	system("pause");
}