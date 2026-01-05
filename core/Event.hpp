#include <string>
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
    std::string description;
    
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
            this->description = description;
        }

        //getters:
        int get_id() const { return id; }
        int get_time_stamp() const { return time_stamp; }
        const Category get_category() const { return category; }
        const std::string& get_description() const { return description; }
};