/*!*****************************************************************************
\file    sllist.cpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Lab 04
\date    27-01-23

\brief

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
     *
     * @param p
     * @return int
     *********************************************************************/
    int data(node const *p)
    {
        return p->value;
    }

    /******************************************************************
     * @brief
     *
     * @param p
     * @param newval
     *********************************************************************/
    void data(node *p, int newval)
    {
        p->value = newval;
    }

    /******************************************************************
     * @brief
     *
     * @param p
     * @return node*
     *********************************************************************/
    node *next(node *p)
    {
        return p->next;
    }

    /******************************************************************
     * @brief
     *
     * @param p
     * @return node const*
     *********************************************************************/
    node const *next(node const *p)
    {
        return p->next;
    }

    // return initialized sllist object allocated on free store
    /******************************************************************
     * @brief
     *
     * @return sllist*
     *********************************************************************/
    sllist *construct()
    {
        return new sllist{nullptr};
    }

    // add element to front of linked list
    /******************************************************************
     * @brief
     *
     * @param ptr_sll
     * @param value
     *********************************************************************/
    void push_front(sllist *ptr_sll, int value)
    {
        ptr_sll->head = create_node(value, ptr_sll->head);
    }

    // return number of elements in linked list container
    /******************************************************************
     * @brief
     *
     * @param ptr_sll
     * @return size_t
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
     *
     * @param ptr_sll
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
     *
     * @param ptr_sll
     * @return true
     * @return false
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
     *
     * @param ptr_sll
     * @param value
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
     *
     * @param ptr_sll
     * @param value
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
     *
     * @param ptr_sll
     * @param value
     * @param index
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
     *
     * @param ptr_sll
     * @return node*
     *********************************************************************/
    node *front(sllist *ptr_sll)
    {
        return ptr_sll->head;
    }

    /******************************************************************
     * @brief
     *
     * @param ptr_sll
     * @return node const*
     *********************************************************************/
    node const *front(sllist const *ptr_sll)
    {
        return ptr_sll->head;
    }

    /******************************************************************
     * @brief
     *
     * @param ptr_sll
     * @param value
     * @return node*
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
