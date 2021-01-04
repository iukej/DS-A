#include <iostream>

struct node{
    node* prev_node;
    //char data[20];
    std::string data;
};

class Stack{
    private:
    public:
        node* current_node;
        Stack(){
            current_node = NULL;
        }

        void push_node(std::string input){

            node* prior_node = current_node;  //Store value so i can attach it to the new node
            current_node = new node();
            current_node->prev_node = prior_node;

            //node* addition = new node();  //Of course I need to do this, If I don't have the new node part,
                                        //i've declared a pointer but never actually created the structure. obviously.
                                        //And that's why this works when there's no pointer
                                        //
                                        //Also, () after new initilizes with value in (). 0 if nothing.

            current_node->data = input;
            std::cout << "node with following data inserted: " << current_node->data << std::endl;
        };

        void pop_node(){
            std::cout << "node removed: " << current_node->data << std::endl;
            current_node = current_node->prev_node;
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



//I think at compile time, you'd know globally instantiated variables, like a MAX_SIZE buffer way up top. But you wouldn't do this for, i.e., program input from a user using the program. You'd have to physically be running the program to get that input, so you can't decide how much space to allocate for it until run time. In that case, it totally makes sense to not allocate until you're physically executing the program.
//
//Also this allows you to do it within the heap as opposed to the stack, which gives you way more space to play with.

//https://stackoverflow.com/questions/21350478/what-does-memory-allocated-at-compile-time-really-mean 
//Has nice Explanations
//



//Questions:
//Why do i have to allocate memory for the new node struct? Isn't everything in there known at compile time? A char array of 20 elements, and a pointer which would be 8 bytes? what more is there to know?
//    Is the disctinction that the pointer is to an object of itself? I'm not sure what else it'd be.
