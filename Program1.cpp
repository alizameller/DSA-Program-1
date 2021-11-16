//
// Created by Aliza Meller on 11/3/21.
//
#include <iostream>
#include <new>
#include <fstream>
using namespace std;

template <typename T> //class T?
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

protected:
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

public:
    string getName() const {
        return name;
    };
   virtual void push(T val) = 0;
   virtual T pop() = 0;

    SimpleList(string listName) {
        name = listName;
        head = NULL;
        tail = NULL;
        size = 0;
    }

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
template <typename T>
class Stack:public SimpleList<T>{
public:
    Stack(string listName): SimpleList<T>(listName){

    };
    void push(T val) {
        this->insertStartNode(val);
    };
    T pop(){
      return this->removeStartNode().getData();
    };
};
template <typename T>
class Queue:public SimpleList<T> {
public:
    Queue(string listName): SimpleList<T>(listName){

    };
    Queue queue(string listName);
    void push(T val) {
        this->insertEndNode(val);
    };
    T pop(){
        return this->removeStartNode().getData();
    };
};

int main (){
    string inputFileName;
    string outputFileName;
    cout << "Enter name of input file: " << endl;
    cin >> inputFileName;
    cout << "Enter name of output file: " << endl;
    cin >> outputFileName;

    string line;
    ifstream inFile(inputFileName);
    ofstream outFile(outputFileName);
    while (getline(inFile, line)){
        outFile << "PROCESSING COMMAND: " << line << endl;

    };
    outFile.close();

    //prompt user for input file and output file
    //read input file
    //loop to parse through the entire file line by line
        //display processing message
        //if first word is create, read third word and create respective list
            //if list already exists, display error message
            //if list does not exist, create list
        //if first word is push, check if the list exists
            //if not, display error message
            //if yes, read value (second word) and read list (third word), push to respective list
        //if first word is pop, check if list exists
            //if not, display error message
            //if yes, check if list is empty
                //if yes, display error message
                //if not, pop from respective list and display "Value Popped" message

    //Stack<int> myList("Adin");
    //myList.push(2);
    //myList.displayList();
    //return 0;
};
