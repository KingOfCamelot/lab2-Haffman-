#include <iostream>
#include "string.h"
#include "Huffman.h"
#include "list.h"
using namespace std;

int main()
{
	String text = "Political power comes";
	ListOfNum<node_tree*>* example = table(text);
	cout << "Size text: " << text.quantity();
	cout << "Memory: " << 8 * text.quantity();
	String temp = encode(example, text);
	cout << "Encode Text: " << temp;

	String text_2 = "No matter how many books you read";
	ListOfNum<node_tree*>* example = table(text);
	cout << "Size text: " << text.quantity();
	cout << "Memory: " << 8 * text.quantity();
	String temp = encode(example, text);
	cout << "Encode Text: " << temp;

	String text_3 = "How can 800 million people live";
	ListOfNum<node_tree*>* example = table(text);
	cout << "Size text: " << text.quantity();
	cout << "Memory: " << 8 * text.quantity();
	String temp = encode(example, text);
	cout << "Encode Text: " << temp;
}