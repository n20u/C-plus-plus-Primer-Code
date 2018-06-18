#include <string>

class TreeNode
{
	public:
		TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
		TreeNode(const TreeNode &rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
		TreeNode& operator=(const TreeNode&);
		~TreeNode()
		{
			if(--*count == 0)
			{
				if(left)
				{
					delete left;
					left = nullptr;
				}
				if(right)
				{
					delete right;
					right = nullptr;
				}
				delete count;
				count = nullptr;
			}
		}
	private:
		std::string value;
		int *count;
		TreeNode *left;
		TreeNode *right;
};

TreeNode& TreeNode::operator=(const TreeNode &rhs)
{
	if(--*count == 0)
	{
		if(left)
		{
			delete left;
		}
		if(right)
		{
			delete right;
		}
		delete count;
	}
	left = rhs.left;
	right = rhs.right;
	count = rhs.count;
	return *this;
}
class BinStrTree
{
	public:
		BinStrTree() : root(new TreeNode()) {}
		BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) {}
		BinStrTree& operator=(const BinStrTree&);
		~BinStrTree()
		{
			delete root;
		}
	private:
		TreeNode *root;
};

BinStrTree& BinStrTree::operator=(const BinStrTree &bst)
{
	auto newr = new TreeNode(*bst.root);
	delete root;
	root = newr;
	return *this;
}
