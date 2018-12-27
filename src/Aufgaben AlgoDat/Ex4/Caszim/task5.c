// Cazim Hysi 14-731-939

#include <stdio.h>
#include <stdlib.h>

struct tree_node {
	int key;
	struct tree_node* lchild;
	struct tree_node* rchild;
};

typedef struct tree_node* TreeNode;
typedef TreeNode* Tree;

TreeNode newTreeNode(int key)
{
	TreeNode t = (TreeNode) malloc(sizeof(struct tree_node));
	if (t == NULL)
	{
		fprintf(stderr, "Error: out of memory!");
		exit(-1);
	}
	t->key = key;
	t->lchild = NULL;
	t->rchild = NULL;
	return t;
}

void insert(Tree t, int key)
{
	if (*t == NULL)
	{
		TreeNode new_node = newTreeNode(key);
		*t = new_node;
	}
	else {
		if (key < (*t)->key) {
			insert(&(*t)->lchild, key);
		} else if (key > (*t)->key) {
			insert(&(*t)->rchild, key);
		} else {
			return;
		}
	}
}

void delete_node(TreeNode node)
{
	if (node == NULL)
		return;
	else
	{
		delete_node(node->lchild);
		delete_node(node->rchild);
		free(node);
		node = NULL;
	}
}

void deleteTree(Tree root)
{
	if (root == NULL)
		return;
	else
	{
		delete_node(*root);
		*root = NULL;
	}
}

void print_tree_helper(TreeNode root)
{
	if (root == NULL)
		return;
	if (root->lchild != NULL) {
		printf("%d -- %d\n", root->key, root->lchild->key);
		fflush(stdout);
	}
	if (root->rchild != NULL) {
		printf("%d -- %d\n", root->key, root->rchild->key);
		fflush(stdout);
	}
	print_tree_helper(root->lchild);
	print_tree_helper(root->rchild);
}

void printTree(Tree root)
{
	printf("graph g {\n");
	print_tree_helper(*root);
	printf("}\n");
}

void printInOrder(Tree root)
{
	printf("graph g {\n");
	print_tree_helper(*root);
	printf("}\n");
}

TreeNode lca(TreeNode root, int n1, int n2)
{
	if (n1 < root->key) {
		if (n2 < root->key) {
			return lca(root->lchild, n1, n2);
		} else {
			return root;
		}
	} else if (n1 > root->key) {
		if (n2 > root->key) {
			return lca(root->rchild, n1, n2);
		} else {
			return root;
		}
	} else {
		return root;
	}
}

int main(int argc, const char* argv[])
{
	TreeNode lca1;
	TreeNode lca2;

	TreeNode dummy1 = NULL;
	Tree root1 = &dummy1;

	insert(root1, 7);
	insert(root1, 5);
	insert(root1, 6);
	insert(root1, 1);
	insert(root1, 9);
	insert(root1, 10);
	insert(root1, 8);

	printInOrder(root1);

	lca1 = lca(*root1, 8, 9);
	lca2 = lca(*root1, 1, 6);

	printf("Lowest Common Ancestor of nodes %d and %d is node %d\n",
				8, 9, lca1->key);
	printf("Lowest Common Ancestor of nodes %d and %d is node %d\n",
				1, 6, lca2->key);
	deleteTree(root1);
}
