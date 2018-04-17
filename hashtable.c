/*
 ============================================================================
 Name        : testdynamic.c
 Author      : Ehab_medhat
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX  10
struct node
{
	int key;
	int value;
	struct node *next;
};
void init_array();
struct arrayitem
{

	struct node *head;
	/* head pointing the first element of Linked List at an index of Hash Table */

	struct node *tail;
	/* tail pointing the last element of Linked List at an index of Hash Table */

};

struct arrayitem array[MAX] ;
int size = 0;         /* Determines the no. of elements present in Hash Table */
int max = MAX;
void remove_element(int key)
{
	int index = hashcode(key);
	struct node *list = (struct node*) array[index].head;

	if (list == NULL)
        {
		printf("This key does not exists\n");

	}
        else
        {
		int find_index = find(list, key);

		if (find_index == -1)
                {
			printf("This key does not exists\n");

		}
                else
                {
 			struct node *temp = list;
			if (temp->key == key)
                        {

  				array[index].head = temp->next;
				printf("This key has been removed\n");
				return;
			}

			while (temp->next->key != key)
                        {
 				temp = temp->next;
			}

  			if (array[index].tail == temp->next)
                        {
				temp->next = NULL;
				array[index].tail = temp;

			}
                        else
                        {
				temp->next = temp->next->next;

			}

			printf("This key has been removed\n");

		}

	}

}

void display()
{
	int i = 0;
	for (i = 0; i < max; i++)
        {
		struct node *temp = array[i].head;
		if (temp == NULL)
                {
			printf("array[%d] has no elements\n", i);

		}
                else
                {
			printf("array[%d] has elements-: ", i);
			while (temp != NULL)
                        {
				printf("key= %d  value= %d\t", temp->key, temp->value);
				temp = temp->next;
			}
			printf("\n");

		}
	}
}
struct node* get_element(struct node *list, int find_index)
{
	int i = 0;
	struct node *temp = list;
	while (i != find_index)
        {
		temp = temp->next;
		i++;
	}
	return temp;
}
int find(struct node *list, int key)
{
	int retval = 0;
	struct node *temp = list;
	while (temp != NULL)
        {
		if (temp->key == key)
                {
			return retval;
		}
  		temp = temp->next;
		retval++;
	}
	return -1;

}
int hashcode(int key)
{
	return (key % max);
}

void insert(int key, int value)
{
  	float n = 0.0;
	/* n => Load Factor, keeps check on whether rehashing is required or not */

	int index = hashcode(key);

	/* Extracting Linked List at a given index */
	struct node *list = (struct node*) array[index].head;

	/* Creating an item to insert in the Hash Table */
	struct node *item = (struct node*) malloc(sizeof(struct node));
	item->key = key;
	item->value = value;
	item->next = NULL;

	if (list == NULL)
        {
		/* Absence of Linked List at a given Index of Hash Table */

		printf("Inserting %d(key) and %d(value) \n", key, value);
		array[index].head = item;
		array[index].tail = item;
		size++;

	}
        else
        {
		/* A Linked List is present at given index of Hash Table */

		int find_index = find(list, key);
		if (find_index == -1)
                {
			/*
			 *Key not found in existing linked list
			 *Adding the key at the end of the linked list
			*/

			array[index].tail->next = item;
			array[index].tail = item;
			size++;

		}else
                 {
			/*
			 *Key already present in linked list
			 *Updating the value of already existing key
			*/

			struct node *element = get_element(list, find_index);
			element->value = value;

		}

	}



}
int size_of_array()
{
	return size;
}

int main(void) {
	//array = (struct arrayitem*) malloc(max * sizeof(struct arrayitem*));
	init_array();
int choice, key, value, n, c;
	//system("cls");

	//array = (struct arrayitem*) malloc(max * sizeof(struct arrayitem*));
	init_array();

	do {
		printf("Implementation of Hash Table in C chaining with Singly Linked List \n\n");
		printf("MENU-: \n1.Inserting item in the Hash Table"
                              "\n2.Removing item from the Hash Table"
                              "\n3.Check the size of Hash Table"
                              "\n4.To display a Hash Table"
		       "\n\n Please enter your choice -: ");

 		scanf("%d", &choice);

		switch(choice)
                {

		case 1:

		      printf("Inserting element in Hash Table\n");
		      printf("Enter key and value-:\t");
		      scanf("%d %d", &key, &value);
		      insert(key, value);

		      break;

		case 2:

		      printf("Deleting in Hash Table \nEnter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);

		      break;

		case 3:

		      n = size_of_array();
		      printf("Size of Hash Table is-:%d\n", n);

		      break;

		case 4:

		      display();

		      break;

		default:

		       printf("Wrong Input\n");

		}

		printf("\nDo you want to continue-:(press 1 for yes) and q to quit \t");
		scanf("%d", &c);

	}while(c == 1);

	//getch();
	return 1 ;
	printf("HelloWorld \n"); /* prints Hello World */
	return EXIT_SUCCESS;
}
void init_array()
{
	int i = 0;
	for (i = 0; i < max; i++)
        {
		array[i].head = NULL;
		array[i].tail = NULL;
	}

}

