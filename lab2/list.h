#ifndef ADD_H
#define ADD_H
#include <iostream>

template<typename T>
struct node { T info; struct node* next; };

template<typename T>
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
    void push_back(T Num);
    void push_front(T Num);
    void pop_back();
    void pop_front();
    void insert(T value, size_t index);
    bool contains(T num);
    int at(T index);
    void remove(T index);
    int get_size();
    void clear();
    void set(size_t index, T value);
    bool isEmpty();
};
#endif