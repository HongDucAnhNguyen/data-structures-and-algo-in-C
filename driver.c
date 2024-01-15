#include <stdio.h>
#include "SLL_DS_functions.h"



int main() {

	Node* head = malloc(sizeof(Node));
	Node* node2 = malloc(sizeof(Node));

	printf("memory of head node: %p\n", head);
	printf("memory of node2: %p\n", node2);

	head->data = 5;
	head->next_node_ptr = node2;


	node2->data = 10;
	node2->next_node_ptr = NULL;


	printf("Linked list is %s", is_empty(head) ? "empty\n" : "not empty\n");
	traverse_linked_list(head);

	find_element(0, head);




	free(head);
	free(node2);
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

}







int find_element(int node_data, Node* head) {

	Node* current_location = head;
	while (current_location != NULL) {
		if (current_location->data == node_data) {
			printf("\nfound node with matching val: %d, at address %p\n", current_location->data, current_location);
			return 0;
		}

		current_location = current_location->next_node_ptr;

	}


	printf("\nNo matching nodes found\n");
	return 1;

}