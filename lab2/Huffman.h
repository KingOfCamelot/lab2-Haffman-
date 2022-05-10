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
	node_tree* parent, *left, *right;

	node_tree(char symbol, int value) 
	{
		this->symbol = symbol;
		this->value = value;
		this->bits = new ListOfNum<bool>();
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}

	node_tree()
	{
		this->symbol = NULL;
		this->value = NULL;
		this->bits = new ListOfNum<bool>();
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};

class Huffman_tree
{
public:
	node_tree* root = nullptr;
	ListOfNum<node_tree*>* list;

	node_tree* min_value()
	{
		node_list<node_tree*>* temp = list->head;
		node_list<node_tree*>* min = list->head;
		while (temp != NULL)
		{
			if (min->info->value >= temp->info->value) min = temp;
			temp = temp->next;
		}
		return min->info;
	}

	Huffman_tree(ListOfNum<node_tree*>* list) {
		this->root = NULL;
		this->list = list;
	}

	ListOfNum<node_tree*>* Encode_text() 
	{
		ListOfNum<node_tree*>* list = new ListOfNum<node_tree*>;
		ListOfNum<node_tree*>* list_2 = new ListOfNum<node_tree*>;
		node_tree* temp = root;
		while (temp != nullptr) 
		{
			if (temp->right != NULL) 
			{
				list_2->push_back(temp->right);
				node_list<bool>* temp_2 = temp->bits->head;
				while (temp_2 != NULL)
				{
					temp->right->bits->push_back(temp_2->info);
					temp_2 = temp_2->next;
				}
				temp->right->bits->push_back(1);
			}
			if (temp->left != NULL) 
			{
				node_list<bool>* temp_2 = temp->bits->head;
				while (temp_2 != NULL) {
					temp->left->bits->push_back(temp_2->info);
					temp_2 = temp_2->next;
				}
				temp->left->bits->push_back(0);
				temp = temp->left;
			}
			else 
			{
				list->push_back(temp);
				if (!list_2->isEmpty()) temp = list_2->pop_front();
				else temp = NULL;
			}
		}
		return list;
	}
};


ListOfNum<node_tree*>* table(String text) {
	red_black_tree<char, int>* map = new red_black_tree<char, int>();
	for (char symbol : text) map->insert(symbol, 1);
	ListOfNum<node_tree*>* list_node = new ListOfNum<node_tree*>;
	for (char symbol : text)
	{
		red_black_tree_node<char, int>* info = map->find(symbol);
		node_tree* node = new node_tree(info->key, info->value);
		bool is = 0;
		node_list<node_tree*>* temp = list_node->head;
		while (temp != NULL)
		{
			if (temp->info->symbol == symbol)
			{
				is = 1;
				break;
			}
			else temp = temp->next;
		}
		if (!is) list_node->push_back(node);
	}

	Huffman_tree* tree = new Huffman_tree(list_node);
	int size_list = list_node->get_size();
	while (size_list >= 2)
	{
		if (size_list >= 2) {
			node_tree* min = min_value();
			list->remove(min_value());
			node_tree* min_2 = min_value();
			list->remove(min_value());
			node_tree* node = new node_tree();
			node->value = min->value + min_2->value;
			min->parent = node;
			min_2->parent = node;
			node->left = min;
			node->right = min_2;
			root = node;
			list->push_back(node);
		}
	}

	list_node = tree->Encode_text();
	ListOfNum<node_tree*>* list_2 = new ListOfNum<node_tree*>();
	for (char symbol : text)
	{
		node_list<node_tree*>* temp = list_node->head;
		while (temp != NULL)
		{
			if (temp->info->symbol == symbol)
			{
				bool is = 0;
				node_list<node_tree*>* temp_2 = list_2->head;
				while (temp_2 != NULL)
				{
					if (temp_2->info->symbol == symbol)
					{
						is = 1;
						break;
					}
					else temp_2 = temp_2->next;
				}
				if (!is) list_2->push_back(temp->info);
				break;
			}
			else temp = temp->next;
		}
	}
	return list_2;
}


String encode(ListOfNum<node_tree*>* list, String text) {
	String result;
	for (char symbol : text)
	{
		node_list<node_tree*>* temp = list->head;
		while (temp != NULL)
		{
			if (temp->info->symbol == symbol)
			{
				node_list<bool>* temp_2 = temp->info->bits->head;
				while (temp_2 != NULL)
				{
					if (temp_2->info == 1) result = result + "1";
					else result = result +  "0";
					temp_2 = temp_2->next;
				}
				break;
			}
			else temp = temp->next;
		}
	}
	return result;
}

String DecodeString(ListOfNum<node_tree*>* list, String key) {
	Huffman_tree* tree = new Huffman_tree(list);
	int size_list = list->get_size();
	while (size_list >= 2)
	{
		if (size_list >= 2)
		{
			node_tree* min = min_value();
			list->remove(min_value());
			node_tree* min_2 = min_value();
			list->remove(min_value());
			node_tree* node = new node_tree();
			node->value = min->value + min_2->value;
			min->parent = node;
			min_2->parent = node;
			node->left = min;
			node->right = min_2;
			root = node;
			list->push_back(node);
		}
	}
	String result;
	int i = 0;
	while (i < key.quantity())
	{
		node_tree* temp = tree->root;
		while (temp->symbol == NULL)
		{
			if (key[i] == '0') temp = temp->left;
			else if (key[i] == '1') temp = temp->right;
			i++;
		}
		result = result + temp->symbol;
	}
	return result;
}