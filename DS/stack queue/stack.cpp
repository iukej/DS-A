#include <iostream>

struct node{
    node* prev_node;
    //char data[20];
    std::string data;
};

class Stack{
    private:
        node* current_node;
    public:
        Stack(){
            current_node = NULL;
        }

        void push_node(std::string input){

            node* prior_node = current_node;  //Store value so i can attach it to the new node
            current_node = new node();
            current_node->prev_node = prior_node;

            current_node->data = input;
            std::cout << "node with following data inserted: " << current_node->data << std::endl;
        };

        void pop_node(){
            std::cout << "node removed: " << current_node->data << std::endl;
            node* prior_node_address = current_node->prev_node;
            delete(current_node);
            current_node = prior_node_address;
            std::cout << "new node top (prior node)" << current_node->data << std::endl;
        }
        
        void print_current(){
            std::cout << "current node value: " << current_node->data << std::endl;
        };
            

};


int main(){
    Stack dishes;

    std::string first = "first node";
    std::string second = "second node";
    dishes.push_node(first);
    dishes.push_node(second);
    //dishes.print_current();
    dishes.pop_node();



    return 1;

}


