#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

using namespace std;

template <typename T>
class DListIterator : public Iterator<T> {     
    public: 
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++();
        DListIterator<T> operator--();
};

template <typename Tr>
class DList {     
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
    public:
        DList() {
            head = tail = nullptr;
            nodes = 0;
        };

        void push_front(T data) {
            Node<T> *temp = new Node<T>(data);
            if(nodes == 0)head = tail = temp;
            else{
                head->prev=temp;
                temp->next=head;
                head = temp;
            }
            nodes++;
        }

        void print(){
            auto *temp = head;
            for (int i = 0; i < nodes; ++i) {
                cout << temp -> data << " ";
                temp = temp -> next;
            }
        }

        void push_back(T data) {
            Node<T> *temp = new Node<T>(data);
            if(nodes == 0)head = tail = temp;
            else{
                tail->next=temp;
                temp->prev=tail;
                tail = temp;
            }
            nodes++;
        }
             
        void pop_front() {
            auto *temp = head;
            if(nodes == 0){throw "Error";}
            else {
                head->next->prev=NULL;
                head=head->next;
                delete temp;
                }
            nodes--;

        }
             
        void pop_back() {
            // TODO
        }
             
        iterator begin() {
            // TODO
        }
             
        iterator end() {
            // TODO
        }
             
        ~DList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif