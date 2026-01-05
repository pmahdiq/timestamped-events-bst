#include "Event.hpp"

class Node{
    Node *left, *right;
    Event data;

    public:
        Node(Event data):
            set_data(data)

        //setters:
        set_data(Event data){
            this->data = data
        }

        set_right(Node *r){
            right = r
        }

        set_left(Node *l){
            left = l
        }

        //getters:
        Event get_data(){
            return data
        }

        *Node get_right(){
            return right 
        }

        *Node get_left(){
            return left
        }
};