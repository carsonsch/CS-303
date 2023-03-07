#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node
{
    public:
        Node(Node<T>* next, T value);
        T get_value() const;
        Node<T>* get_next() const;
        void set_next(Node<T>* new_next);

    private:
        Node<T>* next;
        T value;
};

#include "Node.tc"

#endif