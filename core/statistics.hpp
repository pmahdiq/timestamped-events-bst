#pragma once

#include "BST.hpp"

class Statistics{
    int hight_of_tree;
    float  average_of_nodes;
    public:
        //constractur
        Statistics(){
            //defalt
        }

        //setters
        void set_high_of_tree(int hight){
            if(hight >= 0)
            this->hight_of_tree = hight;
            else{
                std::invalid_argument("hight off a tree can't be negetive");
            }
        }

        void set_average_of_nodes(float average){
            if(average >= 0)
            this->average_of_nodes = average;
            else{
                std::invalid_argument("average of nodes can't be negetive");
            }
        }

        //getters
        int get_hight_off_tree(){
            return hight_of_tree;
        }

        float get_average_of_nodes(){
            return average_of_nodes;
        }

        //helpers
        void update_hight_helper(int &counter,Node* root){
            if (!root){
                return;
            }
            counter ++;
            
            update_hight_helper(counter, root);
            counter --;
            
            std::cout << root->get_data().get_time_stamp();
            
            update_hight_helper(counter, root);
            counter --;
        }

        void update_average_helper(int &counter, int &average, Node* root){
            if (!root){
                return;
            }
            counter ++;
            average = counter + average / 2;
            
            update_hight_helper(counter, root);
            counter --;
            
            std::cout << root->get_data().get_time_stamp();
            
            update_hight_helper(counter, root);
            counter --;
        }

        //calculating methods
        void update_hight_of_tree(BST &bst){
            int counter = 0;
            update_hight_helper(counter, bst.get_root());
            set_high_of_tree(counter);
        }

        void update_average_of_nodes(BST &bst){
            if(!bst.get_root()) return;
            int counter = 0;
            int average = bst.get_root()->get_data().get_time_stamp();

            average_of_nodes = average;
        }

        void computing_and_print(BST &bst){     //later can split them apart
            update_average_of_nodes(bst);
            update_hight_of_tree(bst);

            std::cout << "      ***Statistics***" << std::endl;
            std::cout << "Hight of the tree : " << hight_of_tree << std::endl;
            std::cout << "Avrage of nodes : " << average_of_nodes << std::endl;
            std::cout << "Count of inserts : " << bst.get_count_insert() << std::endl;
            std::cout << "Count of deletes : " << bst.get_count_delete() << std::endl;

        }

};