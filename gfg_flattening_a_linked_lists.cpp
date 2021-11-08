//* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node * mergeTwoLinkedLists(Node *, Node *);

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL)
   {
       return root;
   }
   
   root->next = flatten(root->next);
   
   root = mergeTwoLinkedLists(root, root->next);
   
   return root;
}

Node *mergeTwoLinkedLists(Node *l, Node *r)
{
    Node *temp = new Node(0);
    
    Node *res = temp;
    
    while(l != NULL && r != NULL)
    {
        if(l->data > r->data)
        {
            temp->bottom = r;
            temp = temp-> bottom;
            r = r->bottom;
        }
        else
        {
            temp->bottom = l;
            temp = temp-> bottom;
            l = l->bottom;
        }
    }
    
    if(l)
    {
        temp->bottom = l;
    }
    else
    {
        temp->bottom = r;
    }
    
    return res->bottom;
}

