#include <iostream>

using namespace std;

struct node{
    int key;
    string value;
    node *parent;
    node *left_child;
    node *right_child;
};

class Tree{
    private:
    public:
        node *root_node;
        Tree(){                                                  //need constructor
            root_node = NULL;
        };

        void insert_node(int key, string value){
            if (not root_node){
                root_node = new node;
                root_node -> key = key;
                root_node -> value = value;
                return;
            }
            node* current_node = root_node;

            bool placed = false;                        // W/o recursion for now
            
            while (not placed){
                if ( key > current_node->key){                    //if keyval > existing node, check right subtree
                    if (not current_node->right_child){           ////if empty, add it. if not traverse the new subtree
                        current_node->right_child = new node;
                        current_node->right_child->key = key;
                        current_node->right_child->value = value; 
                        placed = true;
                    }else{
                        current_node = current_node->right_child;
                        continue;
                    }
                } else{
                    if (not current_node->left_child){           //if keyval < exiting node, check left subtree
                        current_node->left_child = new node;     // if empty, add it. if not traverse the new subtree
                        current_node->left_child->key = key;
                        current_node->left_child->value = value; 
                        placed = true;
                    }else{
                        current_node = current_node->left_child;
                        continue;
                    }
                }
                

            }
        };

};

int main(){
    Tree spruce;
    int root_key = 45;
    string root_val = "first";

    spruce.insert_node(root_key, root_val);
    cout << "root key: " << spruce.root_node -> key << endl;
    cout << "root val: " << spruce.root_node -> value << endl;

    int secondKey = 17;
    string secondVal = "second";
    spruce.insert_node(secondKey, secondVal);


    int thirdKey = 999;
    string thirdval = "third";
    spruce.insert_node(thirdKey, thirdval);

    cout << "second: " << spruce.root_node->left_child->value << endl;
    cout << "third: " << spruce.root_node->right_child->value << endl;


    return 1;
};
