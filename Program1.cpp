//
// Created by Aliza Meller on 11/3/21.
//
#include <iostream>
#include <new>
#include <fstream>
#include <list>
#include <cstring>
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

    virtual void insertEndNode(T val) {
        Node* endNode = new Node(val, NULL);
        if (!size++) {
             head = tail = endNode;
             return;
         }
        tail->setNext(endNode);
        tail = endNode;
        return;
    };

    virtual Node removeStartNode() { //pop
        Node removedNode = *head;
        head = removedNode.getNext();
        size = size - 1;
        return removedNode;
    }

public:
    string getName() const {
        return name;
    };

    int getSize() const {
        return size;
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
        }
    }
};

template <typename T>
class Stack:public SimpleList<T> {
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

template <typename T>
SimpleList<T>* findList(char* listName, list<SimpleList<T> *> masterList) {
    for(auto const& i : masterList) {
        if (i->getName() == listName){
            return i;
        }
    }
    return NULL;
};

template <typename T>
void createList(char* listName, list<SimpleList<T> *>* pmasterList, char* thirdWord, ofstream* outFile) {
    SimpleList<T>* pList;
    pList = findList(listName, *pmasterList);
    if (pList) {
        *outFile << "ERROR: This name already exists!" << endl;
        return;
    }
    SimpleList<T>* newList;
    if (!strcmp(thirdWord, "stack")){
        newList = new Stack<T> (listName);
    } else if (!strcmp(thirdWord, "queue")){
        newList = new Queue<T> (listName);
    }
    pmasterList->push_back(newList);

    return;
}

template <typename T>
void pushList(char* listName, list<SimpleList<T> *>* pmasterList, T thirdWord, ofstream* outFile) {
    SimpleList<T>* pList;
    pList = findList(listName, *pmasterList);
    if (!pList) {
        *outFile << "ERROR: This name does not exist!" << endl;
        return;
    }
    pList->push(thirdWord);

    return;
}

template <typename T>
void popList(char* listName, list<SimpleList<T> *>* pmasterList, ofstream* outFile) {
    SimpleList<T>* pList;
    pList = findList(listName, *pmasterList);
    if (!pList) {
        *outFile << "ERROR: This name does not exist!" << endl;
        return ;
    }

    if (!(pList->getSize())) {
        *outFile << "ERROR: This list is empty!" << endl;
        return;
    }
    T val;
    val = pList->pop();
    *outFile << "Value popped: " << val << endl;
    return;
}

int main () {
    ifstream inFile;
    ofstream outFile;
    string inputFileName;
    string outputFileName;

    cout << "Enter name of input file: ";
    cin >> inputFileName;
    cout << "Enter name of output file: ";
    cin >> outputFileName;

    inFile.open(inputFileName);
    outFile.open(outputFileName);

    string line;
    char *commandWord;
    char *listName;
    char *thirdWord;

    list<SimpleList<int> *> listSLi;
    list<SimpleList<double> *> listSLd;
    list<SimpleList<string> *> listSLs;

    int iv;
    double dv;
    string sv;

    while (getline(inFile, line)) {
        outFile << "PROCESSING COMMAND: " << line << endl;
        commandWord = strtok(strdup(line.c_str()), " ");
        listName = strtok(NULL, " ");
        thirdWord = strtok(NULL, " ");

        if (!strcmp(commandWord, "create")) {
            if (listName[0] == 'i') {
                createList(listName, &listSLi, thirdWord, &outFile);
            } else if (listName[0] == 'd') {
                createList(listName, &listSLd, thirdWord, &outFile);
            } else if (listName[0] == 's') {
                createList(listName, &listSLs, thirdWord, &outFile);
            }

        } else if (!strcmp(commandWord, "push")) {
            if (listName[0] == 'i') {
                iv = atoi(thirdWord);
                pushList(listName, &listSLi, iv, &outFile);
            } else if (listName[0] == 'd') {
                dv = atof(thirdWord);
                pushList(listName, &listSLd, dv, &outFile);
            } else if (listName[0] == 's') {
                sv = string(thirdWord);
                pushList(listName, &listSLs, sv, &outFile);
            }

        } else if (!strcmp(commandWord, "pop")) {
            if (listName[0] == 'i') {
                popList(listName, &listSLi, &outFile);
            } else if (listName[0] == 'd') {
                popList(listName, &listSLd, &outFile);
            } else if (listName[0] == 's') {
                popList(listName, &listSLs, &outFile);
            }
        }
    }
    outFile.close();
    return 0;
};