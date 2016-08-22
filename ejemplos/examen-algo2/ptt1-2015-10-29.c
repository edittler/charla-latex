#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id_attr;
	char value[17];
} tInfo;

typedef struct node {
	struct node *next;
	struct node *prior;
	char* firstname;
	tInfo attributes[3];
	union {
		short id_sith;
		long id_jedi;
	} number;
	enum {unknown=0,light=1,dark=2} side;
} tNode;

void func(int a,int b, int c) {
	if (a+b+c > 0) {
		func(c-2,b-2,a-2);
		printf("%d\n",a);
		func(a-1,b-1,c-1);
		printf("%d\n%d\n",b,a);
	}
}

int main (int argc, char** argv) {
	tNode* a;
	tNode* b;
	tNode* c;

	a=malloc(sizeof(tNode)); b=malloc(sizeof(tNode)); c=malloc(sizeof(tNode));

	a->next=b; a->firstname="Luke"; a->prior=c;
	b->next=c; b->firstname="Obi Wan"; b->prior=a;
	c->next=a; c->firstname="Anakin"; c->prior=b;

	*a=*b;

	a->firstname="Vader";

	printf("%s %s %s\n",a->firstname,b->firstname,c->firstname);

	func(2,3,4);
	return 0;
}
