//
// Created by Aliza Meller on 11/3/21.
//

#include <iostream>
using  std::string;

template <class T>

class SimpleList{
private:
    class Node {
    private:
        T data;
        Node* next;
    };

    string name;
    Node* head;
    Node* tail;
    int size;

protected:
    virtual void insertStartNode(){
        return; };
    virtual void insertEndNode(){
        return; };
    virtual Node removeStartNode(){
        return nanl; };

public:
    string retrieveName() {
    };
    virtual void push() = 0;
    virtual Node pop() = 0;

};