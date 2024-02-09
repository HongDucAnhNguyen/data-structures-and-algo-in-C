#include <stdio.h>
#include "../Header Files/SLL_DS_functions.h"



int main() {

	Node* head = malloc(sizeof(Node));
	Node* node2 = malloc(sizeof(Node));


	head->data = 5;
	head->next_node_ptr = node2;


	node2->data = 10;
	node2->next_node_ptr = NULL;


	printf("Linked list is %s", is_empty(head) ? "empty\n" : "not empty\n");

	traverse_linked_list(head);

	insert_at_beginning(23, &head);
	traverse_linked_list(head);

	insert_at_end(45, head);
	traverse_linked_list(head);

	insert_at_index(11, 0, head, &head);
	traverse_linked_list(head);


	insert_at_index(34, 3, head, &head);
	traverse_linked_list(head);

	remove_at_end(head);
	traverse_linked_list(head);

	remove_at_beginning(&head, head);
	traverse_linked_list(head);

	find_element_by_value(10, head);
	traverse_linked_list(head);

	remove_at_index(3, head, &head);
	traverse_linked_list(head);



	remove_at_index(0, head, &head);
	traverse_linked_list(head);



	free_list(head);
	return 0;
}


bool is_empty(Node* head) {
	return (head == NULL);

}


void traverse_linked_list(Node* head) {
	Node* current_location = head;
	while (current_location != NULL) {
		printf("%d --> ", current_location->data);
		current_location = current_location->next_node_ptr;
	}
	printf("\n");
}

void free_list(Node* head) {

	Node* current_location = head;
	Node* next_node = NULL;
	while (current_location != NULL) {

		next_node = current_location->next_node_ptr;
		free(current_location);
		current_location = next_node;
	}
	if (next_node != NULL) {
		free(next_node);
	}
	printf("Linked list is freed from mem\n");

}



//-------------------INSERTION------------------------------//

void insert_at_beginning(int node_data, Node** ptr_to_head_ptr) {




	Node* new_node = malloc(sizeof(Node));


	new_node->data = node_data;

	//dereference to get head_ptr value which is head node's mem
	new_node->next_node_ptr = *ptr_to_head_ptr;


	//reassign headptr val to mem of new node
	*ptr_to_head_ptr = new_node;



}
void insert_at_end(int node_data, Node* head)
{

	Node* current_location = head;
	Node* new_node = malloc(sizeof(Node));
	new_node->data = node_data;
	new_node->next_node_ptr = NULL;



	while (current_location->next_node_ptr != NULL) {

		current_location = current_location->next_node_ptr;



	}
	current_location->next_node_ptr = new_node;


}


int insert_at_index(int node_data, int insert_index, Node* head, Node** ptr_to_head_ptr)
{

	if (insert_index == 0) {

		insert_at_beginning(node_data, ptr_to_head_ptr);
		return 0;
	}


	Node* node_retrieved = find_element_by_index(insert_index, head);
	if (node_retrieved == NULL) {
		printf("No matching nodes found\n");
		return 1;
	}


	Node* new_node = malloc(sizeof(Node));

	new_node->data = node_data;
	new_node->next_node_ptr = node_retrieved->next_node_ptr;

	node_retrieved->next_node_ptr = new_node;


	return 0;
}

//-------------------INSERTION------------------------------//





//-------------------FIND ELEMENT------------------------------//
Node* find_element_by_value(int node_data, Node* head) {

	int index_counter = 0;
	Node* current_location = head;
	while (current_location != NULL) {
		if (current_location->data == node_data) {
			printf("\nfound the first node with matching val at index: %d\n", index_counter);
			return current_location;
		}

		current_location = current_location->next_node_ptr;
		index_counter += 1;

	}


	printf("\nNo matching nodes found\n");
	return NULL;

}


Node* find_element_by_index(int node_index, Node* head) {

	int index_counter = 0;
	Node* current_location = head;
	while (current_location != NULL) {
		if (index_counter == node_index) {
			printf("\nfound node with matching index at address %p\n", current_location);
			return current_location;
		}

		current_location = current_location->next_node_ptr;
		index_counter += 1;
	}


	printf("\nNo matching nodes found\n");
	return NULL;

}
//-------------------FIND ELEMENT------------------------------//






//-------------------REMOVAL----------------------------------//

int remove_at_index(int remove_index, Node* head, Node** ptr_to_head_ptr)
{
	if (remove_index == 0) {
		remove_at_beginning(ptr_to_head_ptr, head);
		return 0;
	}


	Node* node_retrieved = find_element_by_index(remove_index, head);
	if (node_retrieved == NULL) {
		printf("\nNo matching nodes found\n");
		return 1;
	}



	Node* node_before_target_node = find_element_by_index(remove_index - 1, head);

	node_before_target_node->next_node_ptr = node_retrieved->next_node_ptr;


	free(node_retrieved);





	return 0;

}

void remove_at_end(Node* head)
{
	Node* current_location = head;
	while (current_location->next_node_ptr->next_node_ptr != NULL) {

		current_location = current_location->next_node_ptr;

	}
	free(current_location->next_node_ptr->next_node_ptr);
	current_location->next_node_ptr = NULL;

}

void remove_at_beginning(Node** ptr_to_head_ptr, Node* head)
{
	Node* prev_head_next = head->next_node_ptr;
	free(head);

	*ptr_to_head_ptr = prev_head_next;

}

//-------------------REMOVAL----------------------------------//


