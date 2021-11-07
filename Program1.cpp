//
// Created by Aliza Meller on 11/3/21.
//
#include <iostream>
using namespace std;

template <class T>
class SimpleList {
private:
    class Node {
    private:
        T data;
        Node *next;

    public:
        //data and next setters
        void setData(T val) {
            data = val;
        }

        void setNext(Node *ptr) {
            next = ptr;
        }

        //data and next getters
        T getData() const {
            return data;
        }

        Node *getNext() const {
            return next;
        }

        Node(T x, Node *y) {
            data = x;
            next = y;
        }
    };

    string name;
    Node *head;
    Node *tail;
    int size;

protected:
    virtual void insertStartNode(T val) { //push stack
        Node startNode(val, head);
        head = &startNode;
        return;
    }

    virtual void insertEndNode(T val) { //push queue
        Node endNode(val, NULL);
        tail->next = &endNode;
        tail = &endNode;
        return;
    }

    virtual Node removeStartNode() { //pop
        Node removedNode = *head;
        head = head->next;
        return removedNode;
    }

public:
    string getName() const {
        return name;
    };
   // virtual void push() = 0;
   // virtual Node pop() = 0;

    SimpleList(string listName) {
        name = listName;
        head = NULL;
        tail = NULL;
        size = 0;
    };
};

int main (){
    SimpleList<int> myList('Adin');
  return 0;
};