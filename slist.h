#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"

using namespace std;
template <class T>
class SListIterator : public Iterator<T> {     
    public: 
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++(){
            this->current = this->current->next;
        };
};

template <typename Tr>
class SList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;
      
    private:
        Node<T>* head;
        Operation cmp;
        int nodes;
              
    public:
        SList() {
            head = nullptr;
            nodes = 0;
        };

        bool find(T search, Node<T> **&pointer) {
            pointer = &head;
            while((*pointer) != nullptr){
                if(cmp(search, (*pointer)->data))
                {
                    if((*pointer)->data == search)
                    {
                       return true;
                    }

                    else
                    {
                     return false;
                    }
                }


                pointer = &((*pointer)->next);

            }
        }
             
        bool insert(T data) {
            Node<T> **pointer;
            if(find(data, pointer))
            {
                return false;
            }
            else
            {
                auto *node = new Node<T>(data);
                auto *temp = *pointer;
                (*pointer) = node;
                node = temp;
                return true;
            }
        }
             
        bool remove(T item) {
            // TODO
        }  
             
        iterator begin() {
            // TODO
        }
             
        iterator end() {
            // TODO
        }
             
        ~SList() {
            if (head) {
                head->killSelf();
            } 
        }         
};

#endif