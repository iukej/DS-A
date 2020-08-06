#include <iostream>
using namespace std;

struct node{
	node* next_node;
	char data;
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
		node* new_node = new node;
		new_node -> data = input;
		new_node -> next_node = NULL;
		
		if(tail != NULL){
			tail -> next_node = new_node;
			tail = new_node;		
		}
		else{
			tail = new_node;
			head = new_node;
		};

	return 0;		
	};

	int showList(){
		node *placeholder = new node;		
		placeholder = head;	

		while ( placeholder != NULL){
			cout << placeholder -> data;
			placeholder = placeholder->next_node;	
		};
	cout << "\n";
	return 0;
	};	

};

int main(){
	linkedList ll;

	ll.nextEntry('t');
	ll.nextEntry('e');
	ll.nextEntry('s');
	ll.nextEntry('t');
	
	ll.showList();
	
	
	return 0;


};
