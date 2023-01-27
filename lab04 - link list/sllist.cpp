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

    int data(node const *p) { return p->value; }
    void data(node *p, int newval) { p->value = newval; }
    node *next(node *p) { return p->next; }
    node const *next(node const *p) { return p->next; }

    // return initialized sllist object allocated on free store
    sllist *construct()
    {
        return new sllist{nullptr};
    }

    // add element to front of linked list
    void push_front(sllist *ptr_sll, int value)
    {
        ptr_sll->head = create_node(value, ptr_sll->head);
    }

    // return number of elements in linked list container
    size_t size(sllist const *ptr_sll)
    {
        size_t cnt{};
        for (node *head = ptr_sll->head; head; head = next(head))
        {
            ++cnt;
        }
        return cnt;
    }

    void destruct(sllist *ptr_sll)
    {
        node *p, *q;
        p = ptr_sll->head;
        while (p != NULL)
        {
            q = p->next;
            delete p;
            p = q;
        }
        delete ptr_sll;
    }

    bool empty(sllist const *ptr_sll)
    {
        if (size(ptr_sll) == 0)
        {
            return true;
        }
        return false;
    }

    void push_back(sllist *ptr_sll, int value)
    {
        // use create_node to create a new node with value val
        hlp2::node *new_node = create_node(value);

        // if the list is empty, make new_node the first node
        if (ptr_sll->head == nullptr)
        {
            ptr_sll->head = new_node;
        }
        else
        {
            // traverse the list to find the last node
            hlp2::node *current = ptr_sll->head;
            while (current->next != nullptr)
            {
                current = current->next;
            }

            // add new_node to the end of the list
            current->next = new_node;
        }
    }
    void remove_first(sllist *ptr_sll, int value)
    {
    }
    void insert(sllist *ptr_sll, int value, size_t index)
    {
    }
    node *front(sllist *ptr_sll)
    {
    }
    node const *front(sllist const *ptr_sll)
    {
    }
    node *find(sllist const *ptr_sll, int value)
    {
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
