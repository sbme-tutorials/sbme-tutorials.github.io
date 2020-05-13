#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>

template< typename K, typename V >
class Map
{
    struct MapNode
    {
        K key;
        V value;
        MapNode *left;
        MapNode *right;
    };

    static bool isEmpty( const MapNode *m )
    {
        return m == nullptr;
    }

    static bool isLeaf( const MapNode *m )
    {
        return !isEmpty(m)
                && isEmpty( m->left )
                && isEmpty( m->right );
    }

    static size_t size( const MapNode *m )
    {
        if ( !isEmpty( m ) )
            return 1 + size( m->left ) + size( m->right );
        else return 0;
    }

    static MapNode * insert( MapNode *m, K key, V value )
    {
        if ( isEmpty( m ))
            return new MapNode{ key, value , nullptr , nullptr };
        else if ( key != m->key )
        {
            if ( key < m->key )
                m->left = insert( m->left, key , value );
            else m->right = insert( m->right, key , value );
        }
        return m;
    }

    static bool find( const MapNode *m, K key )
    {
        if ( isEmpty( m ))
            return false;
        else
        {
            if ( key == m->key )
                return true;
            else if ( key < m->key )
                return find( m->left , key );
            else return find( m->right , key );
        }
    }

    static V &at( MapNode *m , K key )
    {
        if ( isEmpty( m ))
        {
            std::cout << "Key not found!\n";
            exit( 1 );
        }
        else
        {
            if ( key == m->key )
                return m->value;
            else if ( key < m->key )
                return at( m->left , key );
            else return at( m->right , key );
        }
    }

    static void clear( MapNode *m )
    {
        if ( !isEmpty( m ))
        {
            clear( m->left );
            clear( m->right );
            delete m;
        }
    }

    static MapNode * remove( MapNode *m, K data )
    {
        if ( isEmpty( m )) return nullptr;
        if ( data == m->key ) m = removeNode( m );
        else if ( data < m->key ) m->left = remove( m->left, data );
        else m->right = remove( m->right, data );
        return m;
    }

    static MapNode * minNode( MapNode *m )
    {
        auto min = m;
        while( min->left ) min = min->left;
        return min;
    }

    static MapNode * removeNode( MapNode *m )
    {
        if ( !isEmpty( m->left ) && !isEmpty( m->right ))
        {
            MapNode *minRight = minNode( m->right );
            m->key = minRight->key;
            m->right = remove( m->right, m->key );
        } else
        {
            MapNode *discard = m;
            if ( isLeaf( m )) m = nullptr;
            else if ( !isEmpty( m->left )) m = m->left;
            else m = m->right;
            delete discard;
        }
        return m;
    }

    template< typename Function >
    static void forEach( MapNode *m , Function fn )
    {
        if( !isEmpty( m ))
        {
            forEach( m->left, fn );
            fn( m->key , m->value );
            forEach( m->right, fn );
        }
    }
public:
    bool isEmpty() const
    { return isEmpty( root );}

    size_t size() const
    { return size( root ); }

    void insert( K key, V value )
    { root = insert( root , key , value );}

    bool find( K key ) const
    { return find( root , key );}

    void clear()
    {
        clear( root );
        root = nullptr;
    }

    void remove( K key )
    { root = remove( root , key );}

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

    V &at( const K &k )
    {
        return at( root, k );
    }

    V &operator[]( const K &k )
    {
        if( !find( k ))
            insert( k , V() );
        return at( k );
    }

private:
    MapNode *root = nullptr;
};

#endif // MAP_HPP
