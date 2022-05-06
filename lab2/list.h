#ifndef ADD_H
#define ADD_H
#include <iostream>

struct node { int info; struct node* next; };

class ListOfNum
{
private: size_t size;
public:
    node* CurrentItem;
    node* head = NULL;
    node* LastItem;
    ListOfNum()
    {
        size = 0;
        int Value = 1;
        if (head == NULL)
        {
            head = new node;
            head->info = Value++;
            head->next = NULL;
            LastItem = head;
        }
    }
    void push_back(int Num);
    void push_front(int Num);
    void pop_back();
    void pop_front();
    void insert(int value, int index);
    bool contains(int num);
    int at(int index);//get elem
    void remove(int index);
    int get_size();
    void clear();
    void set(int index, int value);
    bool isEmpty();
};
#endif