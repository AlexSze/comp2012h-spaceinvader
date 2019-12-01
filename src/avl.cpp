#include <iostream>
using namespace std;

template <typename T>
int AVL<T>::height() const{
	return is_empty() ? -1 : root->height;
}

template <typename T>
int AVL<T>::bfactor() const{
	return is_empty() ? 0: right_subtree().height() - left_subtree().height();
}

template <typename T>
void AVL<T>::fix_height() const{
	if (!is_empty()){
		int left_avl_height = left_subtree().height();
		int right_avl_height = right_subtree().height(); root->height = 1 + max(left_avl_height, right_avl_height);
	}
}

template <typename T>
void AVL<T>::rotate_left(){
	AVLnode* b = right_subtree().root;
	right_subtree()=b->left;
	b->left=*this;
	fix_height();
	this->root=b;
	fix_height();
}

template <typename T>
void AVL<T>::rotate_right(){
	AVLnode* b = left_subtree().root;
	left_subtree() = b->right;
	b->right = *this;
	fix_height();
	this->root = b;
	fix_height();
}


template <typename T>
void AVL<T>::balance(){
	if (is_empty())
		return; fix_height();
	int balance_factor = bfactor();
	if (balance_factor == 2){
		if (right_subtree().bfactor() < 0)
			right_subtree().rotate_right();
		return rotate_left();
	}
	else if (balance_factor == -2){
		if (left_subtree().bfactor() > 0)
			left_subtree().rotate_left();
		return rotate_right;
	}
}

template <typename T>
const T& AVL<T>::find_min() const{
	const AVL& left_avl = left_subtree();
	if (left_avl.is_empty())
		return root->value;
	return left_avl.find_min();
}

template <typename T>
bool AVL<T>::contains(const T& x) const{
	if (is_empty())
		return false;
	else if (x == root->value)
		return true;
	else if (x < root->value)
		 return left_subtree().contains(x);
	else return right_subtree().contains(x);
}

template <typename T>
void AVL<T>::print(int depth = 0){
	if (is_empty())
		return;

	root->right.print(depth+1);

	for (int j = 0; j < depth; j++)
		cout << '\t';
	cout << root->value << endl;

	root->left.print(depth+1);
}

template <typename T>
void AVL<T>::insert(const T& x){
	if (is_empty())
		root = new AVLnode(x);
	else if (x > root->value)
		right_subtree().insert(x);
	else if (x < root->value)
		left_subtree().insert(x);

	balance();
}

template <typename T>
void AVL<T>::remove(const T& x){
	if (is_empty())
		return;

	if (x < root->value)
		left_subtree().remove(x);
	else if (x > root->value)
		right_subtree().remove(x);
	else{
		AVL& left_avl = left_subtree();
		AVL& right_avl = right_subtree();

		if (!left_avl.is_empty() && !right_avl.is_empty()){
			root->value = right_avl.find_min();
			right_avl.remove(root->value);
		else{
			AVLnode* node_to_remove = root;
			*this = left_avl.is_empty() ? right_avl : left_avl;

			right_avl.root = left_avl.root = nullptr;
			delete node_to_remove;
		}
	}

		balance();
}
