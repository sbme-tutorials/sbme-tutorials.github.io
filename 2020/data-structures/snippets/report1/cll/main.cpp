#include <iostream>
#include <list>
#include <random>
#include <cassert>

template< typename T >
class CircularLL
{
public:
    struct Node
    {
        T data;
        Node *next;
    };

    CircularLL()
    {
        front_ = nullptr;
    }

    bool isEmpty() const
    {
        return front_ == nullptr;
    }

    int size() const
    {
        if( isEmpty()) return 0;
        else
        {
            auto temp = front_;
            int counter = 0;
            while( temp->next != front_ )
            {
                ++counter;
                temp = temp->next;
            }
            return counter + 1; // Because last element not counted.
        }
    }

    T front() const
    {
        if(isEmpty())
        {
            std::cout << "List is empty!\n";
            exit( 1 ); // Crash
        }
        return front_->data;
    }

    T back() const
    {
        if(isEmpty())
        {
            std::cout << "List is empty!\n";
            exit( 1 ); // Crash
        }
        return backNode()->data;
    }

    void pushFront( T value )
    {
        if(isEmpty())
        {
            front_ = new Node{ value , nullptr };
            front_->next = front_;
        }
        else
        {
            auto back = backNode();
            front_ = new Node{ value , front_ };
            back->next = front_;
        }
    }

    void pushBack( T value )
    {
        if(isEmpty())
            pushFront( value );
        else
        {
            auto back = backNode();
            back->next = new Node{ value , front_ };
        }
    }

    void popFront()
    {
        if(isEmpty())
        {
            std::cout << "List is empty!\n";
            exit( 1 ); // Crash
        }
        else
        {
            if( front_ == front_->next  ) // List size == 1
            {
                delete front_;
                front_ = nullptr;
            }
            else // List size >= 2
            {
                auto back = backNode();
                front_= front_->next;
                delete back->next;
                back->next = front_;
            }
        }
    }

    void popBack()
    {
        if(isEmpty())
        {
            std::cout << "List is empty!\n";
            exit( 1 ); // Crash
        }
        else
        {
            if( front_ == front_->next  ) // List size == 1
                popFront();
            else // List size >= 2
            {
                auto temp = front_;
                while( temp->next->next != front_ )
                    temp = temp->next;
                delete temp->next;
                temp->next = front_;
            }
        }
    }

    /**
     * Remove a node pointed to by `rm`
     * and return the pointer of the next node.
     */
    Node *remove( Node *rm )
    {
        if(isEmpty())
        {
            std::cout << "List is empty!\n";
            exit( 1 ); // Crash
        }
        else
        {
            if( front_ == rm )
            {
                popFront();
                return nullptr;
            }
            else // List size >= 2
            {
                auto temp = front_;
                while( temp->next != rm && temp->next != front_ )
                    temp = temp->next;
                if( temp->next != rm )
                {
                    std::cout << "The pointer doesn't belong to the linked list! "
                              << "Crash!\n";
                    exit( 1 );
                }
                else
                {
                    temp->next = rm->next;
                    delete rm;
                    return temp->next;
                }

            }
        }
    }

    void clear()
    {
        while(!isEmpty())
            popFront();
    }

    /**
     * This function is made to test the list content
     * against another list.
     */
    bool isEqual( const std::list< T > &l ) const
    {
        if(isEmpty() && l.empty())
            return true;
        if( size() != l.size())
            return false;

        auto it1 = front_;
        auto it2 = l.cbegin();
        while( it1->next != front_ )
        {
            if( it1->data != *it2 )
                return false;
            it1 = it1->next;
            it2 = std::next( it2 );
        }
        return it1->data == *it2; // Because last node not tested.
    }
private:
    Node *backNode()
    {
        auto temp = front_;
        while( temp->next != front_ )
            temp = temp->next;
        return temp;
    }

  Node *front_;
};



int main()
{
    CircularLL< int > my_list;
    std::list< int > std_list;


    std::mt19937 sampler; // random number sampler
    std::uniform_int_distribution<int> udist(0,500); // distribution

    // Test push back (n=500).
    for( int i = 0; i < 500 ; ++i)
    {
        auto x = udist(sampler);
        my_list.pushBack( x );
        std_list.push_back( x );
        assert( my_list.isEqual( std_list ));
    }

    // Test push front (n=500).
    for( int i = 0; i < 500 ; ++i)
    {
        auto x = udist(sampler);
        my_list.pushFront( x );
        std_list.push_front( x );
        assert( my_list.isEqual( std_list ));
    }

    // Test pop back (n=50)
    for( int i = 0; i < 50 ; ++i)
    {
        my_list.popBack();
        std_list.pop_back();
        assert( my_list.isEqual( std_list ));
    }

    // Test pop front (n=50)
    for( int i = 0; i < 50 ; ++i)
    {
        my_list.popFront();
        std_list.pop_front();
        assert( my_list.isEqual( std_list ));
    }

    my_list.clear();
    std_list.clear();
    assert( my_list.isEqual( std_list ));


    // Test push back (n=500).
    for( int i = 0; i < 500 ; ++i)
    {
        auto x = udist(sampler);
        my_list.pushBack( x );
        std_list.push_back( x );
        assert( my_list.isEqual( std_list ));
    }

    // Test push front (n=500).
    for( int i = 0; i < 500 ; ++i)
    {
        auto x = udist(sampler);
        my_list.pushFront( x );
        std_list.push_front( x );
        assert( my_list.isEqual( std_list ));
    }

    std::cout << "All tests passed!";
}
