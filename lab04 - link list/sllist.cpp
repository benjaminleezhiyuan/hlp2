/*!*****************************************************************************
\file    sllist.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Lab 04
\date    27-01-23

\brief
This program creates a singly-linked list that encapsulates an int value into a node 
and allows you to insert, delete, find and empty the list.
**********************************************************************************/
#include "sllist.hpp"
// Other than sllist.hpp, you really don't have to include any other files except when testing your code.
// When you're ready to submit, don't include either of the following two headers: <forward_list> and <list>

// Private functions must be declared and defined in an anonymous namespace!!!

// See the spec for structure and interface definitions!!!
namespace
{
    // declaration in anonymous namespace of private function that creates
    // a node on heap and initializes it with data and pointer to successor
    hlp2::node *create_node(int value, hlp2::node *next = nullptr);
}

namespace hlp2
{
    struct node
    {
        int value;  // data portion
        node *next; // pointer portion
    };
    struct sllist
    {
        node *head;
    };

    /******************************************************************
     * @brief
     *accesses node data
     * @param p
     * pointer to node
     * @return int
     * return value of node
     *********************************************************************/
    int data(node const *p)
    {
        return p->value;
    }

    /******************************************************************
     * @brief
     * changes value of node
     * @param p
     * pointer to node
     * @param newval
     * new value of node
     *********************************************************************/
    void data(node *p, int newval)
    {
        p->value = newval;
    }

    /******************************************************************
     * @brief
     * Sets pointer to the next node
     * @param p
     * pointer to node
     * @return node*
     * pointer to next node
     *********************************************************************/
    node *next(node *p)
    {
        return p->next;
    }

    /******************************************************************
     * @brief
     *Sets pointer to const pointer to the next node
     * @param p
     * pointer to node
     * @return node const*
     * pointer const to next node
     *********************************************************************/
    node const *next(node const *p)
    {
        return p->next;
    }

    // return initialized sllist object allocated on free store
    /******************************************************************
     * @brief
     * create object of type sllist 
     * @return sllist*
     *********************************************************************/
    sllist *construct()
    {
        return new sllist{nullptr};
    }

    // add element to front of linked list
    /******************************************************************
     * @brief
     * The purpose of push_front() is to insert a new node object to the front of the linked list.
     * @param ptr_sll
     * pointer to sllist
     * @param value
     * value to be added to front of sllist
     *********************************************************************/
    void push_front(sllist *ptr_sll, int value)
    {
        ptr_sll->head = create_node(value, ptr_sll->head);
    }

    // return number of elements in linked list container
    /******************************************************************
     * @brief
     * returns the number of elements in the list and be used by clients to
     * determine the number of elements contained in the list
     * @param ptr_sll
     * pointer to sllist
     * @return size_t
     * number of elements in the list
     *********************************************************************/
    size_t size(sllist const *ptr_sll)
    {
        size_t cnt{};
        for (node *head = ptr_sll->head; head; head = next(head))
        {
            ++cnt;
        }
        return cnt;
    }

    /******************************************************************
     * @brief
     * deallocates memory from list object sllist
     * @param ptr_sll
     * pointer to sllist
     *********************************************************************/
    void destruct(sllist *ptr_sll)
    {
        node *p, *q;
        p = front(ptr_sll);
        while (p)
        {
            q = next(p);
            delete p;
            p = q;
        }
        delete ptr_sll;
    }

    /******************************************************************
     * @brief
     * This function declared as bool empty(sllist const *ptr_sll); returns true if the list pointed
     * to by ptr_sll has no elements. 
     * @param ptr_sll
     * pointer to ptr_sll
     * @return true
     * returns true if empty
     * @return false
     * returns false if not empty
     *********************************************************************/
    bool empty(sllist const *ptr_sll)
    {
        if (size(ptr_sll) == 0)
        {
            return true;
        }
        return false;
    }

    /******************************************************************
     * @brief
     * Function push_back(sllist *ptr_sll, int val) adds a new element with value val to the
     * end of the list container pointed to by ptr_sll , after its current last node.
     * @param ptr_sll
     * pointer to ptr_sll
     * @param value
     * adds value to the end of ptr_sll
     *********************************************************************/
    void push_back(sllist *ptr_sll, int value)
    {
        if (ptr_sll->head == nullptr)
        {
            ptr_sll->head = create_node(value);
            return;
        }

        // Reach the end.
        for (node *currNode = ptr_sll->head; currNode; currNode = next(currNode))
        {
            if (next(currNode) == nullptr)
            {
                // Create a new node at the next position of the current node.
                // The new node created will have its next position pointed to
                // nullptr.
                currNode->next = create_node(value); // Default param is nullptr
                return;
            }
        }
    }

    /******************************************************************
     * @brief
     * Function remove_first(sllist *ptr_sll, int val) deletes the first element encountered with
     * the same value as second parameter val .
     * @param ptr_sll
     * pointer to ptr_sll
     * @param value
     * element value to be deleted from list.
     *********************************************************************/
    void remove_first(sllist *ptr_sll, int value)
    {
        // Edge case: Empty list. Return.
        if (empty(ptr_sll))
            return;

        node *p = front(ptr_sll), *q = next(p);

        /*use a second pointer q so that p and q point to consecutive elements
        with p always pointing to the element before the element pointed to by q.
        Hence, when q points to the removal element, p will point to the
        one-before-removal-element.*/

        // Edge case: The first element is the one that needs to be removed
        if (data(p) == value) // Check for first element
        {
            ptr_sll->head = q;
            delete p;
            return;
        }

        // Iterate through all elements in the sllist
        while (q != nullptr)
        {
            // Once we locate that the current(q) value is the same as
            if (data(q) == value)
            {
                p->next = next(q);
                delete q;
                return;
            }
            // Now p(p) will take current(q)'s place
            p = q;
            // Iterate current to the next node.
            q = q->next;
        }
    }

    /******************************************************************
     * @brief
     * Function insert declared as void insert(sllist *ptr_sll, int value, size_t position);
     * inserts a new element encapsulating data equal to parameter value into the list pointed to by
     * parameter ptr_sll at an index specified by parameter position 
     * @param ptr_sll
     * pointer to ptr_sll
     * @param value
     * value to be inserted
     * @param index
     * position to insert value
     *********************************************************************/
    void insert(sllist *ptr_sll, int value, size_t index)
    {
        // Edge case: list given is empty
        if (ptr_sll->head == nullptr)
        {
            ptr_sll->head = create_node(value);
            return;
        }

        // Edge case: index is 0. Insert at the front of the list
        if (index == 0)
        {
            push_front(ptr_sll, value);
            return;
        }

        node *q = ptr_sll->head;
        size_t i = 0;
        // Advance the pointer of p to the index before the one specified
        while (i < index - 1 && next(q) != nullptr)
        {
            q = next(q);
            i++;
        }

        // Insert a new node at the current position we have moved to
        q->next = create_node(value, next(q));
    }

    /******************************************************************
     * @brief
     * Return pointer to the first element of the list
     * @param ptr_sll
     * pointer to ptr_sll
     * @return node*
     * return pointer to the first element of the list or nullptr if the
     * list has zero elements.
     *********************************************************************/
    node *front(sllist *ptr_sll)
    {
        return ptr_sll->head;
    }

    /******************************************************************
     * @brief
     * Return pointer to the first element of the list
     * @param ptr_sll
     * pointer to ptr_sll
     * @return node*
     * return pointer to the first element of the list or nullptr if the
     * list has zero elements.
     *********************************************************************/
    node const *front(sllist const *ptr_sll)
    {
        return ptr_sll->head;
    }

    /******************************************************************
     * @brief
     *Function find declared as node* find(sllist *ptr_sll, int value); returns a pointer to the
     first element in the list pointed to by parameter ptr_sll whose data is equal to the second
     parameter value .
     * @param ptr_sll
     pointer to ptr_sll
     * @param value
     value of element to find in list
     * @return node*
     pointer to first element that equals to value.
     *********************************************************************/
    node *find(sllist const *ptr_sll, int value)
    {
        // Edge case: Empty list. Return.
        if (empty(ptr_sll))
            return nullptr;

        node *p = ptr_sll->head, *q = next(p);

        // Edge case: The first element is the one that is found
        if (data(p) == value) // Check for first element
        {
            return p;
        }
        while (q)
        {
            if (data(q) == value)
            {
                return q;
            }
            p = q;
            q = next(q);
        }
        return nullptr;
    }
}

namespace
{
    // define this private function in anonymous namespace!!!
    hlp2::node *create_node(int value, hlp2::node *next)
    {
        return new hlp2::node{value, next};
    }
}
