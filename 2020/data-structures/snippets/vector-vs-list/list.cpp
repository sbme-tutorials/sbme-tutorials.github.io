#include <iostream>

struct node
{
    double data;
    node* next;
};

node *pushFront( node *front , double data )
{
    return new node{ data , front };
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
