#include <iostream>
#include <string>
#include <list>

class TodoItem {
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description) {
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }
    void setCompleted(bool val) { completed = val; }

};

int main() {
    char input_option;
    int input_id;
    std::string input_description;
    std::string version = "v0.2.0";
    std::list <TodoItem> todoItems;
    std::list <TodoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    TodoItem test;

    test.create("this is a test");
    todoItems.push_back(test);

    while(1) {
        system("cls");
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl << std::endl;

        for(it = todoItems.begin(); it != todoItems.end(); it++) {
            
            std::string completed = it->isCompleted() ? "Done" : "Not done"; 
            
            std::cout << it-> getId() << " | " << it->getDescription() << " | " 
            << completed << std::endl;
        }

        if(todoItems.empty()) {
            std::cout << "Add your first todo!" << std::endl;

        }

        std::cout << "\n\n";

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "\nchoice: ";

        std::cin >> input_option;

       
        if(input_option == 'q') {
            std::cout << "Have a great day now ! :)" << std::endl;
            break;
        } else if(input_option == 'a') {
            std::cout << "Add a new descprition: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            TodoItem newTask;
            newTask.create(input_description);
            todoItems.push_back(newTask);
            
        } else if(input_option == 'c') {
            std::cout << "Enter id to mark completed: ";
            std::cin >> input_id;

            for(it = todoItems.begin(); it != todoItems.end(); it++) {
                if(input_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            
            }
        }
    }
    return 0;

}

