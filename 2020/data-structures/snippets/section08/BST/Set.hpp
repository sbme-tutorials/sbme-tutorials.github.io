#ifndef SET_HPP
#define SET_HPP

#include <iostream>

template< typename T >
class Set
{
    struct SetNode
    {
        T data;
        SetNode *left;
        SetNode *right;
    };

    static bool isEmpty( const SetNode *t )
    {
        return t == nullptr;
    }

    static bool isLeaf( const SetNode *t )
    {
        return !isEmpty(t)
                && isEmpty( t->left )
                && isEmpty( t->right );
    }

    static size_t size( const SetNode *t )
    {
        if ( !isEmpty( t ) )
            return 1 + size( t->left ) + size( t->right );
        else return 0;
    }

    static SetNode * insert( SetNode *t, T data )
    {
        if ( isEmpty( t ))
            return new SetNode{ data , nullptr , nullptr };
        else if ( data != t->data )
        {
            if ( data < t->data )
                t->left = insert( t->left, data );
            else t->right = insert( t->right, data );
        }
        return t;
    }

    static bool find( const SetNode *t, T data )
    {
        if ( isEmpty( t ))
            return false;
        else
        {
            if ( data == t->data )
                return true;
            else if ( data < t->data )
                return find( t->left , data );
            else return find( t->right , data );
        }
    }

    static void clear( SetNode *t )
    {
        if ( !isEmpty( t ))
        {
            clear( t->left );
            clear( t->right );
            delete t;
        }
    }

    static SetNode * remove( SetNode *t, T data )
    {
        if ( isEmpty( t )) return nullptr;
        if ( data == t->data ) t = removeNode( t );
        else if ( data < t->data ) t->left = remove( t->left, data );
        else t->right = remove( t->right, data );
        return t;
    }

    static SetNode * minNode( SetNode *t )
    {
        auto min = t;
        while( min->left ) min = min->left;
        return min;
    }

    static SetNode * removeNode( SetNode *t )
    {
        if ( !isEmpty( t->left ) && !isEmpty( t->right ))
        {
            SetNode *minRight = minNode( t->right );
            t->data = minRight->data;
            t->right = remove( t->right, t->data );
        } else
        {
            SetNode *discard = t;
            if ( isLeaf( t )) t = nullptr;
            else if ( !isEmpty( t->left )) t = t->left;
            else t = t->right;
            delete discard;
        }
        return t;
    }

    template< typename Function >
    static void forEach( SetNode *t , Function fn )
    {
        if( !isEmpty( t ))
        {
            forEach( t->left, fn );
            fn( t->data );
            forEach( t->right, fn );
        }
    }
public:
    bool isEmpty() const
    { return isEmpty( root );}

    size_t size() const
    { return size( root ); }

    void insert( T data )
    { root = insert( root , data );}

    bool find( T data ) const
    { return find( root , data );}

    void clear()
    {
        clear( root );
        root = nullptr;
    }

    void remove( T data )
    { root = remove( root , data );}

    template< typename Function >
    void forEach( Function fn ) const
    {
        forEach( root , fn );
    }

    void print () const
    {
        forEach( []( int x ){
           std::cout << x << " ";
        });
    }

private:
    SetNode *root = nullptr;
};

#endif // SET_HPP
