#pragma once

#include "BST.hpp"
#include "statistics.hpp"


class Panel{
    BST bst;
    Statistics status;
    void insert_event(){
            bst.set_event_id_counter(bst.get_event_id_counter() + 1);
            int id = bst.get_event_id_counter();
            Category category;
            int choice_category,timestaps;
            std::string discription;
        
            std::cout << "  ***Inserting a event***" << std::endl;
        
            std::cout << "Choose the category: " << std::endl;
            std::cout << "1.Work" << std::endl;
            std::cout << "2.Study" << std::endl;
            std::cout << "3.Personal" << std::endl;
            std::cout << "4.Health" << std::endl;
            std::cout << "5.Other" << std::endl;
        
            std::cin >> choice_category;
            std::cout << std::endl;
        
            switch (choice_category)
            {
            case 1:
                category = Category::WORK;
                break;
            case 2:
                category = Category::STUDY;
                break;
            case 3:
                category = Category::PERSONAL;
                break;
            case 4:
                category = Category::HEALTH;
                break;
            case 5:
                category = Category::OTHER;
                break;
            default:
                std::invalid_argument("invalid choice!");
                break;
            }
        
            std::cout << "Please inter the timestamp : ";
            std::cin >> timestaps;
            
            std::cout << "Please inter the caption : ";
            std::cin >> discription;
            
            Event event = Event(id, timestaps, category, discription);
            bst.insert(event);
        }
        
        void search_by_timestamp(){
            int time_stamp;
            
            std::cout << "Please inter the timestap";
            std::cin >> time_stamp;
        
            Event event = bst.search_by_time_stamp(time_stamp);
            event.print();
        }
        
        void delete_event(){
            int time_stamp;
        
            std::cout << "Please inter the timestap";
            std::cin >> time_stamp;
        
            bst.delete_(time_stamp);
        }
        
        void show_event_in_range(){
            int t1, t2;
            
            std::cout << "Please inter t1: " << std::endl;
            std::cin >> t1;
            std::cout << "Please inter t2: " << std::endl;
            std::cin >> t2;
        
            std::vector<Event> events = bst.get_events_between(t1, t2);
        
            for (Event event : events){
                event.print();
            }
        }
        
        void find_closest_event(){
            int t;
        
            std::cout << "Please inter t: " << std::endl;
            std::cin >> t;
        
            Event event = bst.get_closest_event(t);
            event.print();
        }
        
        void count_categorys_between(){
            int t1, t2;
        
            std::cout << "Please inter t1" << std::endl;
            std::cin >> t1;
            std::cout << "Please inter t2" << std::endl;
            std::cin >> t2;
        
            bst.count_category(t1, t2);
        }
        
        void show_tree_status(){
            status.computing_and_print(bst);
        }
public:
    void show_menu(){
        while(true){
            std::cout << "1.Insert a Event" << std::endl;
            std::cout << "2.Search By TimeStamp" << std::endl;
            std::cout << "3.Delete Event" << std::endl;
            std::cout << "4.Show Event In Time Range" << std::endl;
            std::cout << "5.Find Closet Event" << std::endl;
            std::cout << "6.Show Tree Statistics" << std::endl;
            std::cout << "7.Count categorys between t1 and t2" << std::endl;
            std::cout << "8.Exit" << std::endl;

            int choice;
            
            std::cin >> choice;
            switch (choice)
            {
                case 1:
                
                break;
            
            default:
                break;
            }
        }
    }

};