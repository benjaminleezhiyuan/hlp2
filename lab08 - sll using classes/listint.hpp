// Provide include guards
// Don't include either of the following two headers: <forward_list> and <list>
// You may need to include <cstddef> for size_t [which is the largest unsigned type from the C standard library]
#include <cstddef>
#include <vector>
// All names from here on must be in namespace hlp2.
// Don't add any names that are private to the implementation source file listint.cpp in this file.
// Necessary declarations are described in the spec.

// Ensure every member function declared in class ListInt has a header!!!

// Declare this as a friend function in class ListInt:
namespace hlp2
{
    class ListInt
    {
    public:
        // type aliases
        using size_type = std::size_t;
        using value_type = int;
        using reference = value_type &;
        using const_reference = const value_type &;
        using pointer = value_type *;
        using const_pointer = const value_type *;

    private:
        struct Node
        {
            int data;   // the actual data in the node
            Node *next; // pointer to the next Node
        };
        Node *head{nullptr};  // pointer to the head of the list
        Node *tail{nullptr};  // pointer to the last node
        size_type counter{0}; // number of nodes on the list
        Node *new_node(value_type data) const;

    public:
        // interface
        friend std::ostream &operator<<(std::ostream &os, const ListInt &rhs);

        static size_type object_count();

        bool empty() const;

        size_type size() const
        {
            size_type count = 0;
            Node *current = head;
            while (current != nullptr)
            {
                ++count;
                current = current->next;
            }
            return count;
        }

        // three ctors:
        ListInt() : head(nullptr), tail(nullptr), counter(0)
        {
        }

        ListInt(const ListInt &other) : ListInt()
        {
            *this += other;
        }

        ListInt(std::initializer_list<value_type> ilist) : ListInt()
        {
            for (auto &&element : ilist)
            {
                push_back(element);
            }
        }

        // destructor
        ~ListInt()
        {
            clear();
        }

        // copy assignment with another ListInt object
        ListInt &operator=(ListInt other)
        {
            std::swap(head, other.head);
            std::swap(tail, other.tail);
            std::swap(counter, other.counter);
            return *this;
        }

        // copy assignment with std::initializer_list<value_type>
        ListInt &operator=(std::initializer_list<value_type> ilist)
        {
            ListInt temp(ilist);
            *this = temp;
            return *this;
        }

        // operator += overload: concatenates with nodes of another ListInt container
        ListInt &operator+=(const ListInt &other)
        {
            for (auto &&element : other)
            {
                push_back(element);
            }
            return *this;
        }

        // operator += overload: concatenates with std::initializer_list<value_type>
        ListInt &operator+=(std::initializer_list<value_type> ilist)
        {
            for (auto &&element : ilist)
            {
                push_back(element);
            }
            return *this;
        }

        // operator [] overload: returns int data of node at position i in linked list
        reference operator[](size_type i)
        {
            return const_cast<reference>(static_cast<const ListInt &>(*this)[i]);
        }

        // operator [] overload: const overload of above function
        const_reference operator[](size_type i) const
        {
            if (i >= counter)
            {
                throw std::out_of_range("ListInt index out of range");
            }
            auto current = head;
            for (size_type j = 0; j < i; ++j)
            {
                current = current->next;
            }
            return current->data;
        }

        // push_front: adds value_type to front of the list
        void push_front(const_reference value)
        {
            auto new_node = new Node{value, head};
            head = new_node;
            if (tail == nullptr)
            {
                tail = head;
            }
            ++counter;
        }

        // push_back: uses tail data member to efficiently add value_type to back of the list
        void push_back(const_reference value)
        {
            auto new_node = new Node{value, nullptr};
            if (tail == nullptr)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                tail->next = new_node;
                tail = new_node;
            }
            ++counter;
        }

        // pop_front: returns the value of node at front of the list and then destroys this front node
        value_type pop_front()
        {
            if (head == nullptr)
            {
                throw std::runtime_error("pop_front called on empty ListInt");
            }
        }

        // Operator overloads
        ListInt operator+(const ListInt &rhs) const
        {
            ListInt result(*this);
            result += rhs;
            return result;
        }

        ListInt operator+(const std::initializer_list<value_type> &rhs) const
        {
            ListInt result(*this);
            result += rhs;
            return result;
        }

        friend ListInt operator+(const std::initializer_list<value_type> &lhs, const ListInt &rhs)
        {
            ListInt result;
            result += lhs;
            result += rhs;
            return result;
        }

    private:
        // data encapsulated here
        void clear()
        {
            while (head != nullptr)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            counter = 0;
        }
        static size_type object_counter;
    };

    // Initialize static member variable
    ListInt::size_type ListInt::object_counter = 0;

    // Definition of static member function
    ListInt::size_type ListInt::object_count()
    {
        return object_counter;
    }

    ListInt::size_type ListInt::size() const
{
    size_type count = 0;
    Node *current = head;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

bool ListInt::empty() const
{
    return head == nullptr;
}
}