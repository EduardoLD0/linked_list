#include <stdio.h>
#include <stdlib.h>

typedef struct list list;

struct list
{
	int value;
	struct list* next;
	
	void (*appendleft)(list *, list*);
	void (*printlist)(list *);
	void (*delete)(list *, list *);
};

void printlist(list *self)
{
	list* ptr = self;
	printf("[");
	while(ptr)
	{
		printf(" %d ", ptr->value);
		ptr = ptr->next;
	}
	printf("]\n");
}

void delete(list *self, list *entry)
{
	list* ptr = self;
	while(ptr->next != entry)
	{
		ptr = ptr->next;
	}
	ptr->next = entry->next;
}

int main()
{
	list* hola = malloc(sizeof(list));
	list* element = malloc(sizeof(list));
	list* element2 = malloc(sizeof(list));
	hola->printlist = printlist;
	hola->delete = delete;
	hola->value = 4;
	hola->next = element;
	element->value = 3;
	element->next = element2;
	element2->value = 2;
	hola->printlist(hola);
	hola->delete(hola, element);
	hola->printlist(hola);
	return 0;
}
