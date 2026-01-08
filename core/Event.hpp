#pragma once

#include <iostream>
#include <stdexcept>

enum class Category {
    WORK,
    STUDY,
    PERSONAL,
    HEALTH,
    OTHER
};

class Event{
    int id, time_stamp;
    Category category;
    std::string discription;
    
    public:
        Event(){
            //default constractur
        }

        Event(int id, int time_stamp, Category category, std::string description = ""){
            set_id(id);
            set_time_stamp(time_stamp);
            set_category(category);
            set_description(description);
        }
        //setters:
        void set_id(int id){
                if(id < 0) throw std::invalid_argument("id can't be negative");
                this->id = id;
        }
        void set_time_stamp(int time_stamp){
            if(time_stamp < 0) throw std::invalid_argument("time_stamp can't be negative");
            this->time_stamp = time_stamp;
        }
        void set_category(const Category){
            this->category = category;
        }
        void set_description(const std::string& description){
            this->discription = description;
        }

        //getters:
        int get_id() const { return id; }
        int get_time_stamp() const { return time_stamp; }
        const Category get_category() const { return category; }
        const std::string& get_description() const { return discription; }

        //methods
        void print(){
            std::cout << "event id : " << id << std::endl;
            std::cout << "event category : " << static_cast<int>(category) << std::endl; //can use mapping for printing as string
            std::cout << "time stamp: " << time_stamp << std::endl;
            std::cout << "discription : " << discription << std::endl;
        }
};