#include <iostream>
using namespace std;

template <typename T>
class AVL{
	private:
		struct AVLnode{
			T value;
			int height;
			AVL left;
			AVL right;
			AVLnode(const T& x):value(x), height(0), left(), right(){}
		};

		AVLnode* root = nullptr;
		AVL& right_subtree() { return root->right; }
		AVL& left_subtree() { return root->left; }
		const AVL& right_subtree() const { return root->right; }
		const AVL& left_subtree() const { return root->left; }

		int height() const;
		int bfactor() const;
		void fix_height() const;
		void rotate_left();
		void rotate_right();
		void balance();

	public
		AVL()=default;
		~AVL(){delete root;}	//delete AVL
		bool is_empty() const { return root == nullptr; }
		const T& find_min() const; // Find the minimum value in an AVL
		bool contains(const T& x) const; // Search an item
		void print(int depth = 0) const; // Print by rotating -90 degrees
		void insert(const T& x); // Insert an item in sorted order
		void remove(const T& x); // Remove an item
}

