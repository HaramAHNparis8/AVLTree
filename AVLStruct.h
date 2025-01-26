#ifndef AVLSTRUCT_H
#define AVLSTRUCT_H

typedef int element_t


typedef struct Node{
	
	element_t data;
	
	struct Node* Parent;
	struct Node* L;
	struct Node* R;

}Node_t;


#endif
