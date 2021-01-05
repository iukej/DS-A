#include <iostream>

using namespace std;

struct node{
    int key;
    char value[20];
    node *parent;
    node *left_child;
    node *right_child;
};

struct childvalues{
    int left_child_key;
    int right_child_key;
};

class Tree{
    private:
        node *root_node;
        node *current_node;
    public:
        Tree(){             //need constructor
            root_node = NULL;
            current_node = root_node;
        };

        childvalues ImmediateFamily(int currentKey, int searchKey){
            childvalues children;
            children.left_child_key = current_node->lef;
            children.right_child_key = 2;
            return children;
        };

        //void insert_node(int key, char data){
        //};
};

int main(){
    Tree spruce;

    //childvalues testing;


    int left_key, right_key;
    childvalues children;
    children =  spruce.ImmediateFamily(1,1);
    left_key =  children.left_child_key;
    right_key = children.right_child_key;
    cout << "left key: " << left_key << endl;
    cout << "right key: " << right_key << endl;

    return 1;
};
