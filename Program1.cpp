//
// Created by Aliza Meller on 11/3/21.
//
#include <iostream>
using  std::string;

template <class T>

class simpleList{
private:
    class Node {
    private:
        T data;
        Node* next;

    public:
        T getData(){ //might not need this
            return data;
        }
        Node(T x, Node* y) {
            data = x;
            next = y;
        };
    };

    string name;
    Node* head;
    Node* tail;
    int size;

protected:
    virtual void insertStartNode(T val){ //push stack
        Node startNode(val, head);
        head = &startNode;
        return;
    };
    virtual void insertEndNode(T val){ //push queue
        Node endNode(val, NULL);
        tail -> next = &endNode;
        tail = &endNode;
        return;
    };
    virtual Node removeStartNode(){ //pop
        Node removedNode = *head;
        head = head -> next;
        return removedNode;
    };

public:
    string getName() const {
        return name;
    };
    virtual void push() = 0;
    virtual Node pop() = 0;

    simpleList(string listName) {
        name = listName;
    };
};