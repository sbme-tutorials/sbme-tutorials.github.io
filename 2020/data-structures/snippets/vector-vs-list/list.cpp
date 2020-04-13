#include <iostream>

struct node
{
    double data;
    node* next;
};

struct LL
{
    node *front;
};

/**
 * Below are function prototypes, their definitions are below the main funciton.
 * Note that in prototype we don't need to tell the compiler the variable name, just the type is needed.
 * For some functions there are two versions:
 *    one that operates directly on the front pointer.
 *    another one that operates on the struct object that contains the front pointer.
 */

node *pushFront( node * , double );
void pushFront( LL & , double ); // Function overloading

node *backNode( node * );

node *pushBack( node *, double );
void pushBack( LL & , double ); // Function overloading

node* nodeAt( LL &, int );

void printLL( node*  );
void printLL( LL & ); // Function overloading

bool isEmpty( node* );
bool isEmpty( LL & );




int main()
{

    node* l = nullptr; // Empty list
    // append elements with values 1^2 to 100^2
    for (int i=1; i<=10; ++i) {
        l = pushBack( l , i*i);
    }

    // print all elements followed by a space
    for (node *temp = l; temp != nullptr; temp = temp->next ) {
        std::cout << temp->data << ' ';
    }
}



node *pushFront( node *front , double data )
{
    return new node{ data , front };
}


void pushFront( LL &l , double data ) // Function overloading
{
    l.front = pushFront( l.front , data );
}

node *backNode( node *front )
{
    node *temp = front;
    while( temp->next != nullptr )
        temp = temp->next;
    return temp;
}

node *pushBack( node *front, double data )
{
    if( front == nullptr )
        return pushFront( front , data );
    else
    {
        node *back = backNode( front );
        back->next = new node{ data , nullptr };
        return front;
    }
}

void pushBack( LL &l , double data ) // Function overloading
{
    l.front = pushBack( l.front , data );
}

node* nodeAt( LL &list, int index )
{
    node* temp = list.front;
    for( int i = 0; i < index ; ++i )
        temp = temp->next;
    return temp;
}

void printLL( node* front )
{
    node *current = front;
    while( current != nullptr )
    {
        std::cout << current->data;
        current = current->next;
    }
}

void printLL( LL &l )// Function overloading
{
    printLL( l.front );
}

bool isEmpty( node *front )
{
    return front == nullptr;
}

bool isEmpty( LL &list )// Function overloading
{
    return isEmpty(list.front);
}
