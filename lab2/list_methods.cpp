#include <iostream>
#include "list.h"

using namespace std;

void ListOfNum::push_back(int Num)
{
    node* elem = new node;
    elem->info = Num;
    if (head == nullptr)
    {
        head = elem;
        LastItem = elem;
        elem->next = nullptr;
    }
    else
    {
        LastItem->next = elem;
        LastItem = elem;
    }
    size++;
}
void ListOfNum::push_front(int Num)
{
    node* elem = new node;
    elem->info = Num;
    if (head == nullptr)
    {
        head = elem;
        LastItem = elem;
        elem->next = nullptr;
    }
    else
    {
        elem->next = head;
        head = elem;
    }
    size++;
}
void ListOfNum::pop_back()
{
    if (head == nullptr) throw invalid_argument("List empty");
    node* temp = head;
    node* prev = NULL;
    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev) prev->next = NULL;
    else head = NULL;
    if (temp) delete temp;
    size--;
}
void ListOfNum::pop_front()
{
    if (head == nullptr) throw invalid_argument("List empty");
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        LastItem = nullptr;
    }
    else
    {
        node* first = head->next;
        delete head;
        head = first;
    }
    size--;
}
void ListOfNum::remove(int index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    CurrentItem = head;
    node* previositem = 0;
    for (int i = 0; i < index; ++i)
    {
        previositem = CurrentItem;
        CurrentItem = CurrentItem->next;
    }
    previositem->next = CurrentItem->next;
    size--;
    delete CurrentItem;
}
int ListOfNum::at(int index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    int i = 0;
    node* tmp_ptr = head;
    while (i < index)
    {
        tmp_ptr = tmp_ptr->next;
        i++;
    }
    CurrentItem->info = tmp_ptr->info;
    return tmp_ptr->info;
}
bool ListOfNum::contains(int Num)
{
    node* current = head;
    while (current)
    {
        if (current->info == Num) return true;
        current = current->next;
    }
    return false;
}
int ListOfNum::get_size()
{
    if (isEmpty())
    {
        CurrentItem->info = 0;
        return 0;
    }
    node* tmp_ptr = head;
    while (tmp_ptr->next != nullptr)
    {
        tmp_ptr = tmp_ptr->next;
        size++;
    }
    CurrentItem->info = size;
    return size;
}
void ListOfNum::set(int index, int value)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    CurrentItem = head;
    for (int i = 1; i <= index; ++i)
    {
        if (i == index) CurrentItem->info = value;
        CurrentItem = CurrentItem->next;
    }
}
bool ListOfNum::isEmpty()
{
    return head == nullptr;
}
void ListOfNum::clear()
{
    if (head != nullptr)
    {
        while (head != nullptr)
        {
            pop_back();
        }
    }
}
void ListOfNum::insert(int value, int index)
{
    if (index > get_size()) throw invalid_argument("Your index > size of list");
    if (index <= 0) throw invalid_argument("Your index <= 0");
    node* newel = new node;
    newel->info = value;
    if (index == 1)
    {
        newel->next = head;
        head = newel;
    }
    else
    {
        node* before = head;
        for (int i = 0; i < index - 1; i++)
            before = before->next;

        newel->next = before->next;
        before->next = newel;
    }
    size++;
}