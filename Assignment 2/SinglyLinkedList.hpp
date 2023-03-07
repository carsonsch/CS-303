#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include "Node.hpp"

template <typename T>
class SinglyLinkedList
{
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();
        void push_front(const T& data);
        void push_back(const T& data);
        void pop_front();
        void pop_back();
        T front() const;
        T back() const;
        bool empty() const;
        void insert(size_t index, const T& new_item);
        bool remove(size_t index);
        size_t find(const T& find_item);
        void print() const;
        size_t item_count() const;

    private:
        Node<T>* head;
        Node<T>* tail;
        size_t num_items;
        
        Node<T>* get_node_at_index(size_t index) const;
};

#include "SinglyLinkedList.tc"

#endif