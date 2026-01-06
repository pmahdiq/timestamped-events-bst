#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "Node.hpp"

class BST{
    Node *root;

    //helpers
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

    void get_events_between_helper(Node* root, int t1, int t2, std::vector<Event>& result) {
        if (!root) return;

        get_events_between_helper(root->get_left(), t1, t2, result);

        int ts = root->get_data().get_time_stamp();
        if (ts >= t1 && ts <= t2)
            result.push_back(root->get_data());

        get_events_between_helper(root->get_right(), t1, t2, result);
}


    public:
        //constractur
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

        //basic methods
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

        //practical methods
        std::vector<Event> get_events_between(int t1, int t2) {
            std::vector<Event> result;

            get_events_between_helper(root, t1, t2, result);
            return result;
        }

        Event get_closest_event(int t){
            if(!root){
                std::invalid_argument("BST has no root");
            }
            
            Node* pre;
            Node* curr = root;

            while(!curr && curr->get_data().get_time_stamp() == t){
                int ts = curr->get_data().get_time_stamp();

                if(ts < t){
                    pre = curr;
                    curr = curr->get_right();
                }

                else{
                    pre = curr;
                    curr = curr->get_left();
                }
            }

            if(curr->get_data().get_time_stamp() == t){
                Event l,r,p,c;
                c = curr->get_data();
                if(curr->get_left()){
                    l = curr->get_left()->get_data();
                }
                if(curr->get_right()){
                    r = curr->get_right()->get_data();
                }
                p = pre->get_data();

                Event canditate[3] = {r ,l, p};
                int min = abs(c.get_time_stamp() - r.get_time_stamp());
                int i = 0;
                for(int x = 0;x < 3;x++){
                   if(abs(t - canditate[x].get_time_stamp()) < min){
                    i = x;
                   } 
                }

            return canditate[i];
            }
            else{
                std::cout << "failure to find t";
                return Event();
            }
        }
        
        void countCategory(long long t1, long long t2) {
            std::vector<Event> events = get_events_between(t1, t2);

            // initialize counts
            std::map<Category, int> cnt;
            cnt[Category::HEALTH] = 0;
            cnt[Category::OTHER] = 0;
            cnt[Category::PERSONAL] = 0;
            cnt[Category::STUDY] = 0;
            cnt[Category::WORK] = 0;

            for (Event e : events) {
                cnt[e.get_category()]++;
            }

            // print
            std::cout << "Category A = " << cnt[Category::HEALTH] << '\n';
            std::cout << "Category B = " << cnt[Category::OTHER] << '\n';
            std::cout << "Category C = " << cnt[Category::PERSONAL] << '\n';
            std::cout << "Category D = " << cnt[Category::STUDY] << '\n';
            std::cout << "Category E = " << cnt[Category::WORK] << '\n';
        }

    };