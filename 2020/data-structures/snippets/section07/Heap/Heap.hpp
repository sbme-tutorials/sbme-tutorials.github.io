#ifndef HEAP_HPP
#define HEAP_HPP
#include <vector>
#include <iostream>

template< typename T >
class Heap
{
public:
    size_t size() const
    {
        return data.size();
    }

    void insert(T value)
    {
        data.push_back(value);
        size_t childIdx = size() - 1;
        siftUp( childIdx );
    }

    T extract()
    {
        if( data.empty())
        {
            std::cout << "Empty Heap!\n";
            exit( 1 ); // Crash
        }
        size_t child = size() - 1;
        std::swap(data[child], data[0]);
        int value = data.back();
        data.pop_back();
        siftDown(0);
        return value;
    }

    static Heap make( std::vector< T > data )
    {
        Heap h;
        h.data.swap( data ); // O(1)
        if( h.size() <= 1 ) return h;

        auto lastChild = h.size() - 1;
        for( int subHeap = parentIdx( lastChild ); subHeap >= 0 ; --subHeap )
            h.siftDown( subHeap );
        return h;
    }
private:
    void siftUp( size_t child )
    {
        auto parent = parentIdx(child);
        if( child > 0  && data[child] < data[parent])
        {
            std::swap(data[child], data[parent]);
            siftUp( parent );
        }
    }

    void siftDown( size_t parent)
    {
        size_t left = leftChildIdx(parent);
        size_t right = rightChildIdx(parent);
        size_t length = size();
        size_t minimum = parent;

        if (left < length && data[left] < data[minimum])
            minimum = left;

        if (right < length && data[right] < data[minimum])
            minimum = right;

        if (minimum != parent)
        {
            std::swap(data[minimum], data[parent]);
            siftDown( minimum);
        }
    }

    static size_t leftChildIdx(size_t parent)
    {
        return parent * 2 + 1;
    }

    static size_t rightChildIdx(size_t parent)
    {
        return parent * 2 + 2;
    }

    static size_t parentIdx(size_t child)
    {
        if (child % 2 == 1)
            return (child - 1) / 2;
        else
            return (child - 2) / 2;
    }
private:
    std::vector<T> data;
};


#endif // HEAP_HPP
