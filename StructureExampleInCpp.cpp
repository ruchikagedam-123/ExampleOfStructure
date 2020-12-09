/******************************************************************************  22C:030/115 Programming Techniques and Data Structures
Fall 1999/00
Homework Assignment 2 : Linked Lists
DUE DATE: 9/29/99 (40 points) NOTE: NO LATE ASSIGNMENTS WITHOUT PRIOR PERMISSION!
*******************************************************************************/
//It include answers for Question 1, 2, 3.
//Solution:
#include <iostream>

using namespace std;

struct Node
{
    typedef int Item;
    Item data;
    Node *next;
    //Constructor
    Node(int n):data(n), next(NULL) {
        
    }
};

class Linked_list
{
public:
    Node *head,*tail;
public:
    //Constructor 
    Linked_list()
    {
        head = NULL;
        tail = NULL;
    }


    //To add nodes in Linked_list
    void add_node(int n)
    {
        //Created one temparary node
        Node *tmp = new Node(n);
        //Add the value in it
        tmp->data = n;
        //And link for the next item is set as NULL just for now
        tmp->next = NULL;

        //If head is NULL then node added at the begining
        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        //Otherwise node gets added at the end of the current node
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    //To access the head where the current pointer is.
    Node* gethead()
    {
        return head;
    }

    //Static methods used to call the method without creating object and this display method is used to show the data
     static void display(Node *head)
    {
        //If head is null it will print NULL
        if(head == NULL)
        {
            cout << " NULL" << endl;
        }
        //Otherwise print the current data of the node
        else
        {
            cout << head->data;
            //This line used to call the method until head found to be NULL
            display(head->next);
        }
    }

    //Static methods used to call the method without creating object and this concatenate method is used to concatenate the two list 
   static void concatenate(Node* h1, Node* h2 )
    {
        //If head of first list and second list are not NULL then concatenation is possible
        if( h1 != NULL && h2!= NULL )
        {
            //if End of first list is found then start concatenate with second list
            if (h1->next == NULL)
                h1->next = h2;
            //Otherwise repeate the same steps until found the end of the first list    
            else
                concatenate(h1->next,h2);
        }
        else
        {
            cout << "Either a or b is NULL\n";
        }
    }
    
     //Static methods used to call the method without creating object and this insertInOrder method is used to insert the item in the list 
   static void insertInOrder(Node* head_ptr, int value)
    {
        Node *temp ;
        // if head pointer is either NULL or the value is greater the the current value then Inserting value at the head of the list.
        if(head_ptr == NULL || head_ptr->data > value)
        {
            temp = new Node(value);
            temp->next = head_ptr;
            head_ptr = temp;
            return;
        }
        // Inserting value anywhere else specially at the end bcz value is greater than the all those values present in the list.
        temp = head_ptr;
        // Moving to the point where insertion need to be done.
        while( temp->next != NULL && temp->next->data < value )
        {
            temp = temp->next;
        }
        Node *temp2= new Node(value);
        temp2->next =  temp->next;
        temp->next = temp2;
}

    //Finding median of the linked list
   static void findMedian(Node* head) 
{ 
    Node* single_ptr = head; //For one taking step forwqard and helps to find the middle in the list
    Node* double_ptr = head; //for two steps foprward in the list
    Node* previous_ptr = head; //to hold previous pointer
  
  //If head is not null then steps forward
    if (head != NULL) { 
        //This loop iterate to keep track of the single pointer and double pointer
        while (double_ptr != NULL && double_ptr->next != NULL) { 
            //This line make a two steps forward and store it in double_ptr
            double_ptr = double_ptr->next->next; 
  
            // previous of single pointer 
            previous_ptr = single_ptr;
            //This line make a one steps forward and store it in sinlge_ptr
            single_ptr = single_ptr->next; 
        } 
  
        // if the below condition is true linked list 
        // contain odd Node 
        // simply return middle element 
        if (double_ptr != NULL) 
            cout << "Median is : " << single_ptr->data; 
  
        // else linked list contain even element 
        else
            cout << "Median is : "<< float(single_ptr->data + previous_ptr->data) / 2; 
    } 
} 
};



int main()
{
    Linked_list a ;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    
   Linked_list b;
    b.add_node(5);
    b.add_node(6);
    b.add_node(7);
    b.add_node(8);
    //Que 1. Write a function to concatenate two linked lists. Given lists l1 = (2, 3, 1) and l2 = (4, 5), after return from
    //concatenate(l1,l2) the list l1 should be changed to be l1 = (2, 3, 1, 4, 5). Your function should not change l2 and 
    //should not directly link nodes from l1 to l2 (i.e. the nodes inserted into l1 should be copies of the nodes from l2.)
    //Linked_list::concatenate(a.gethead(),b.gethead());
    
     //Will be used to displaylist 
    Linked_list::display(a.gethead());
    
    //Que 2. Write a function to insert a number into a sorted linked list. Assume the list is sorted from smallest to largest value.
    //After insertion, the list should still be sorted. Given the list l1 = (3, 17, 18, 27) and the value 20, on return l1 be 
    //the list (3, 17, 18, 20, 27).
    Linked_list::insertInOrder(a.gethead(), 3);
    
    //Will be used to displaylist 
    Linked_list::display(a.gethead());
    
    //Que 3. Write a function to return the median value in a sorted linked list. 
    //If the length i of the list is odd, then the median is the ceiling(i/2) member. 
    //For example, given the list (1, 2, 2, 5, 7, 9, 11) as input, your function should return the value 5. 
    //If the length of the list is even, then the median is the mean of the i/2 and (i/2)+1 members. 
    //Thus, the median of the sorted list (2, 4, 8, 9) is (4+8)/2. Finally, define the median of an empty list to be 0.
    Linked_list::findMedian(a.gethead());
   
    
    return 0;
}


//It include answer for Question 4.
//Solution: 
#include <iostream>

using namespace std;

struct Node
{
    typedef int Item;
    Item data;
    Node *next;
    //Constructor
    Node(int n):data(n), next(NULL) {
        //Empty Constructor
    }
};
struct LinkedList 
{ 
    Node *head; 
    LinkedList() 
    { 
        head = NULL; 
    } 
    //This method add the Nodes in the lisrt
    void push(int data) 
    { 
        Node *temp = new Node(data); //create new node with value in the 'data'
        temp->next = head;          //And points to the next node
        head = temp; 
    } 
    //This Function is to reverse the linked list 
    void reverse() 
    { 

        Node *current = head;                    // Here, Initialized current
        Node *prev = NULL, *next = NULL;        // previous and next pointers 
  
        //Until current pointer found NULL reverse the pointer from Current pointer to previous pointer
        while (current != NULL) 
        { 
            // Store next pointer
            next = current->next; 
  
            // Reverse current node's pointer 
            current->next = prev; 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
    } 
  
    //This Function is to print list 
    void print() 
    { 
        Node *temp = head; 
        while (temp != NULL) 
        { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
    } 
}; 
  
int main() 
{ 
  
    LinkedList ll; 
    ll.push(20); 
    ll.push(4); 
    ll.push(15); 
    ll.push(85); 
  
    cout << "Original linked list"<<endl; 
    ll.print(); 
  
    ll.reverse(); 
    cout<<endl;
   
    cout << "After Reversing the Linked list is: "<<endl; 
    ll.print(); 
    return 0; 
}

