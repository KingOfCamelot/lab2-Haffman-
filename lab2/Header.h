#include "list.h"
#include "red_black_tree.h"
#include "string.h"
#include <iostream>

class node_tree
{
public:
	char symbol;
	int value;
	ListOfNum<bool>* bits;
	node_tree* parent = nullptr, *left = nullptr, *right = nullptr;
};

class Huffman_tree
{
public:
	node_tree* root = nullptr;
	ListOfNum<node_tree*>* list;
};