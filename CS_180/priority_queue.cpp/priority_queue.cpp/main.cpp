//
//  main.cpp
//  priority_queue.cpp
//
//  Created by Max Smiley on 4/27/21.
//

#include <iostream>

#define MAXLEN 10000

struct p_queue
{
    int length = 0;
    int heap[MAXLEN];
    
    //Given the index of a node, returns the index of its parent
    //If root node, returns -1. Assumes a valid index is given
    int get_parent(int index)
    {
        
    }
    
    //Given the index of a node, returns its first child
    //If no child, returns -1. Assume a valid index is given
    int get_child_1(int index)
    {
        
    }
    
    //Given the index of a node, return its second child
    //If no child, returns -1. Assume a valid index is given
    int get_child_2()
    {
        
    }
    
    //Given a value, pushes it into the heap
    //Rebalances and alters length
    void push(int val)
    {
        
    }
    
    //Pops the smalles (root node) from heap
    //Rebalances and alters length
    int pop()
    {
        
    }
    
    //Helper rebalance function
    //Recursively calls itself until hits root node or heap is balanced
    void rebalance(int index)
    {
        
    }
    
    //Prints
    void print()
    {
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
