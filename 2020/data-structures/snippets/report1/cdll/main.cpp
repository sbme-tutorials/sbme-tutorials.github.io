#include <iostream>
#include <list>
#include <random>
#include <cassert>

template< typename T >
class CircularDLL
{
public:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
    };

    CircularDLL()
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
        return front_->prev->data;
    }

    void pushFront( T value )
    {
        if(isEmpty())
        {
            front_ = new Node{ value , nullptr , nullptr };
            front_->next = front_;
            front_->prev = front_;
        }
        else
        {
            front_ = new Node{ value , front_ , front_->prev };
            front_->prev->next = front_;
            front_->next->prev = front_;
        }
    }

    void pushBack( T value )
    {
        if(isEmpty())
            pushFront( value );
        else
        {
            auto node = new Node{ value , front_ , front_->prev };
            front_->prev->next = node;
            front_->prev = node;
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
            if( front_ == front_->next ) // List size == 1
            {
                delete front_;
                front_ = nullptr;
            }
            else // List size >= 2
            {
                front_->prev->next = front_->next;
                front_->next->prev = front_->prev;
                auto temp = front_;
                front_ = front_->next;
                delete temp;
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
            if( front_ == front_->next ) // List size == 1
                popFront();
            else // List size >= 2
            {
                auto back = front_->prev;
                back->prev->next = front_;
                front_->prev = back->prev;
                delete back;
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
                while( temp != rm && temp->next != front_ )
                    temp = temp->next;
                if( temp != front_ )
                {
                    std::cout << "The pointer doesn't belong to the linked list! "
                              << "Crash!\n";
                    exit( 1 );
                }
                else
                {
                    rm->next->prev = rm->prev;
                    rm->prev->next = rm->next;
                    temp = rm->next;
                    delete rm;
                    return temp;
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
  Node *front_;
};



int main()
{
    CircularDLL< int > my_list;
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
