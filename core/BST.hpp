#include <iostream>
#include "Node.hpp"

class BST{
    Node *root;

    Node* insert_helper(Node* node, Event event) {
        if (node == nullptr) return new Node(event);

        if (event.get_time_stamp() < node->get_data().get_time_stamp())
            node->set_left(insert_helper(node->get_left(), event));

        else if (event.get_time_stamp() > node->get_data().get_time_stamp())
            node->set_right(insert_helper(node->get_right(), event));

        else
            std::cout << "Event with this timestamp already exists.\n";


        return node;
    }

    Node* search_helper(Node* root, int val){
        if(root == nullptr) return nullptr;

        else if(root->get_data().get_time_stamp() == val){
            return root;
        }

        else if(root->get_data().get_time_stamp() > val){
            return search_helper(root->get_left(), val);
        }

        else if(root->get_data().get_time_stamp() < val){
            return search_helper(root->get_right(), val);
        }
    }

    Node* delete_helper(Node* root, int val, bool& found) {
    if (root == nullptr) return nullptr;

    if (val < root->get_data().get_time_stamp())
        root->set_left(delete_helper(root->get_left(), val, found));
    else if (val > root->get_data().get_time_stamp())
        root->set_right(delete_helper(root->get_right(), val, found));
    else {
        found = true;  // value found
        // deletion cases
        if (root->get_left() == nullptr && root->get_right() == nullptr) {
            delete root;
            return nullptr;
        } else if (root->get_left() == nullptr) {
            Node* temp = root->get_right();
            delete root;
            return temp;
        } else if (root->get_right() == nullptr) {
            Node* temp = root->get_left();
            delete root;
            return temp;
        } else {
            Node* succ = root->get_right();
            while (succ->get_left() != nullptr)
                succ = succ->get_left();
            root->set_data(succ->get_data());
            root->set_right(delete_helper(root->get_right(),
                                          succ->get_data().get_time_stamp(),
                                          found));
        }
    }
    return root;
}

    void inorder_helper(Node* root){
        if (!root){
                return;
            }

            inorder_helper(root->get_left());
            std::cout << root->get_data().get_time_stamp();
            inorder_helper(root->get_right());
    }

    public:
        BST(Node *root = nullptr){
            this->root = root;
        }

        //setters:
        void set_root(Node *r){
            root = r;
        }

        //getters:
        Node* get_root(){
            return root;
        }

        void insert(Event event){
            root = insert_helper(root, event);
        }

        Event search_by_time_stamp(int val){
            Node *ans = search_helper(root, val);

            if(!ans){
                std::cout << "can't find any event with this timestamp";
                return Event();
            }

            else
                return ans->get_data();
        }

        void delete_(int val){
            bool found = false;
            root = delete_helper(root, val, found);
            if(!found) std::cout << "Value not found in the tree.\n";
        }

        void inorder_print(){
            inorder_helper(root);
            std::cout << std::endl;          
        }
};