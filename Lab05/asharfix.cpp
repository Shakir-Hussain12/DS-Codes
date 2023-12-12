#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val) : data(val), next(NULL) {}
    /*  ~node(){
          int val=this->data;
          if(this->next!=NULL){
              delete next;
              this->next=NULL;

          }
          cout<<"MEMORY FREE WITH DATA "<<val<<endl;
      }*/
      
    //don't delete Node because you will lose values if a node in between is deleted.
    // rather make a destructor in LinkedList and do this
    
//    ~LinkedList(node *temp){ // you will pass head from outside/
//		while(temp->next != NULL) {
//			node *temp = head;
//			head = head->next;
//			delete temp;
//			temp = NULL
//		}
	// share this code in whatsapp group, just in case you get this in exam
//	}
};
void apphend(node *&head, int data, int key)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    if (head->next == NULL)
    {
        newnode->next = head;
        head->next = NULL;
        head = newnode;
        return;
    }
    node *temp = head;
    for (int i = 1; i < key; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletE(node *&head, int key)
{
    if (key == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    node *temp = head;
    node *prev = temp;
    for (int i = 1; i < key; ++i)
    {
        if (i != 1)
            prev = prev->next;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

node *removeDuplicates(node *&head)
{
    // your code goes here
    if (head->next == NULL)
    {
        return head;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            node *temp1 = temp->next;
            temp->next = temp1->next;
            temp1->next = NULL;
            delete temp1;
            break;
        }
        temp = temp->next;
    }
    return head;
}
void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void bubblesort(node *&head, node *current, node *prev, int i, int j, int size)
{
    if (i >= size)
    {
        return;
    }
    
    if (head->data > head->next->data) {
    	node *temp = head->next;
    	head->next = head->next->next;
    	temp->next = head;
    	head = temp;	
	} else if (j < size - i - 1 && current->next->next != NULL) {
        prev = current; // prev -> head
        node *p1 = prev->next; // p1 -> head->next
        node *p2 = p1->next; // p2->head->next->next
        
        cout << p1->data << p2->data << endl;
        if (p1->data > p2->data) {   
            prev->next = p2;
            p1->next = p2->next;
            p2->next = p1;    
        }
        
        current = current->next;
        bubblesort(head, current, prev, i, j + 1, size);             
	} else {
		bubblesort(head, head, NULL, i + 1, 0, size);
	}
}

int main()
{
    node *head = NULL;
    apphend(head, 11, 0);
    apphend(head, 5, 0);
    apphend(head, 7, 2);
    apphend(head, 3, 3);
    apphend(head, 8, 4);
    display(head);
    node *prev=NULL;
    bubblesort(head, head, prev, 0, 0, 5);
    display(head);
}
