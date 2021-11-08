//
// Created by Aliza Meller on 11/3/21.
//
#include <iostream>
#include <new>
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

        void setNext(Node* ptr) {
            next = ptr;
        }

        //data and next getters
        T getData() const {
            return data;
        }

        Node* getNext() const {
            return next;
        }

        Node(T x, Node* y) {
            data = x;
            next = y;
        }
    };

    string name;
    Node* head;
    Node* tail;
    int size;

public:
//protected:
    virtual void insertStartNode(T val) { //push stack
        Node* startNode = new Node(val, head);
        head = startNode;
        if (size == 0) {  //same as !size
          tail = head;
        }
        size = size + 1;
        return;
    }

    virtual void insertEndNode(T val) { //push queue
        Node* endNode = new Node(val, NULL);
        tail->setNext(endNode);
       // tail->next = &endNode; //change the next attribute of the node that tail points to, to ...
        tail = endNode;
        if (size == 0) {
            head = tail;
        }
        size = size + 1;
        return;
    }

    virtual Node removeStartNode() { //pop
        Node removedNode = *head;
        head = head->getNext();
        size = size - 1;
        return removedNode;
    }

//public:
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

    void displayList() const {
        cout << "Name of the list is " << name << endl;
        cout << "Size of the list is " << size << endl;
        Node* tmpNode = head;
        int num;

        for (int x = 0; x < size; x++){
            num = tmpNode->getData();
            tmpNode = tmpNode->getNext();
            cout << num << endl;
        };
    }
};

int main (){
    SimpleList<int> myList("Adin");
    myList.insertStartNode(2);
    myList.insertEndNode(3);
    myList.insertStartNode(4);
    myList.insertStartNode(5);
    myList.displayList();
    return 0;
};