#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <queue>

template< typename T >
class BST
{
    struct BSTNode
    {
        T data;
        BSTNode *left;
        BSTNode *right;
    };

    static bool isEmpty( const BSTNode *t )
    {
        return t == nullptr;
    }

    static bool isLeaf( const BSTNode *t )
    {
        return !isEmpty(t)
                && isEmpty( t->left )
                && isEmpty( t->right );
    }

    static size_t size( const BSTNode *t )
    {
        if ( !isEmpty( t ) )
            return 1 + size( t->left ) + size( t->right );
        else return 0;
    }

    static BSTNode * insert( BSTNode *t, T data )
    {
        if ( isEmpty( t ))
            return new BSTNode{ data , nullptr , nullptr };
        else
        {
            if ( data < t->data )
                t->left = insert( t->left, data );
            else t->right = insert( t->right, data );
            return t;
        }
    }

    static bool find( const BSTNode *t, T data )
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

    static void inorder( const BSTNode *t )
    {
        if( !isEmpty( t ))
        {
            inorder( t->left );
            std::cout << t->data << " ";
            inorder( t->right );
        }
    }

    static void preorder( const BSTNode *t )
    {
        if( !isEmpty( t ))
        {
            std::cout << t->data << " ";
            preorder( t->left );
            preorder( t->right );
        }
    }

    static void postorder( const BSTNode *t )
    {
        if( !isEmpty( t ))
        {
            postorder( t->left );
            postorder( t->right );
            std::cout << t->data << " ";
        }
    }

    static void breadthfirst( const BSTNode *tree )
    {
        std::queue< const BSTNode * > q;
        q.push( tree );
        while( !q.empty())
        {
            auto t = q.front();
            q.pop();
            if( !isEmpty( t->left )) q.push( t->left );
            if( !isEmpty( t->right )) q.push( t->right );
            std::cout << t->data << " ";
        }
    }

    static void clear( BSTNode *t )
    {
        if ( !isEmpty( t ))
        {
            clear( t->left );
            clear( t->right );
            delete t;
        }
    }

    static BSTNode * remove( BSTNode *t, T data )
    {
        if ( isEmpty( t )) return nullptr;
        if ( data == t->data ) t = removeNode( t );
        else if ( data < t->data ) t->left = remove( t->left, data );
        else t->right = remove( t->right, data );
        return t;
    }

    static BSTNode * minNode( BSTNode *t )
    {
        auto min = t;
        while( min->left ) min = min->left;
        return min;
    }

    static BSTNode * removeNode( BSTNode *t )
    {
        if ( !isEmpty( t->left ) && !isEmpty( t->right ))
        {
            BSTNode *minRight = minNode( t->right );
            t->data = minRight->data;
            t->right = remove( t->right, t->data );
        } else
        {
            BSTNode *discard = t;
            if ( isLeaf( t )) t = nullptr;
            else if ( !isEmpty( t->left )) t = t->left;
            else t = t->right;
            delete discard;
        }
        return t;
    }

    static bool isBST( const BSTNode *t )
    {
        if (isEmpty( t ))
            return true;
        if ( !isEmpty( t->left ) && t->data < t->left->data)
            return false;
        if ( !isEmpty( t->right ) && t->data > t->right->data)
            return false;
        // check recursively for every node.
        return isBST( t->left ) && isBST( t->right );
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

    void preorder() const
    { preorder( root );}

    void inorder() const
    { inorder( root );}

    void postorder() const
    { postorder( root );}

    void breadthfirst() const
    { breadthfirst( root );}

    bool isBST() const
    { return isBST( root ); }
private:
    BSTNode *root = nullptr;
};

#endif // BST_HPP
