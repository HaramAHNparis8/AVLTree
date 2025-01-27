#include <stdio.h>
#include AVLStruct.h
#include <stdlib.h>
 

element_t Height(Node_t* node){

    element_t leftDepth, rightDepth;    

    if (node == NULL){ 
		
		return 0;
	}
	
    
    leftDepth = Height(node->Left);
    rightDepth = Height(node->Right);
	
    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

element_t CalculateBalanceFactor(Node* node){

    return Height(node->Left) - Height(node->Right);

}

Node* LL(Node* node){

    Node* childNode = node -> L;
    node -> Left = childNode -> R;
    if (childNode -> R != NULL){
        
	childNode -> R -> Parent = node;
    }
	
    childNode -> R = node;
    childNode -> Parent = node -> Parent;
    node->Parent = childNode;
	
    return childNode;
}


Node* LR(Node* node){

    node -> L = RR(node -> L);
    return LL(node);
}

Node* RL(Node* node){

    node -> R = LL( node -> R);
    return RR(node);
}
Node* AVLSet(Node* node){

    int depth = CalculateBalanceFactor(node);
    if (depth >= 2)
    {
        depth = CalculateBalanceFactor(node->Left);
        if (depth >= 1)
        {
            //LL : Left Left
            node = LL(node);
        }
        else
        {
            //LR : Left Right
            node = LR(node);
        }
    }
    else if (depth <= -2)
    {
        depth = CalculateBalanceFactor(node->Right);
        if (depth <= -1)
        {
            //RR : Right Right
            node = RR(node);
        }
        else
        {
            //RL : Right Left
            node = RL(node);
        }
    
    }
	
    return node;
}

