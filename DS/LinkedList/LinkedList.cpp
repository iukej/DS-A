

#include <iostream>


struct node{
char data;
node* next_node;
};

class linkedList{
private:
	node *tail, *head;
public:
	linkedList(){
		tail = NULL;
		head = NULL;
	} 

	int nextEntry(char input){
		node* new_node;
		new_node -> data = input;
		new_node -> next_node = NULL; 
	
		if(tail != NULL){
			tail -> next_node = new_node;
			tail = new_node;		
		}
		else{
			tail = new_node;
			head = new_node->next_node;	
		};
	return 0;		
	};
};

int main(){
	linkedList ll;
	ll.nextEntry('h');
	return 0;
};
