/*!******************************************************************
 * \file      listint.hpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Lab 08
 * \date      03-03-2023
 *
 * \brief
 * This file defines and implements a class ListInt that encapsulates a singly-linked list of int values.
 *********************************************************************/
#ifndef LISTINT_H
#define LISTINT_H

#include <cstddef>
#include <iostream>
#include <initializer_list>
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
        using value_type = int;
        using size_type = std::size_t;

        // Default constructor
        ListInt();

        // Copy constructor
        ListInt(const ListInt &other);

        // Constructor that takes an initializer list
        ListInt(std::initializer_list<value_type> ilist);

        // Destructor
        ~ListInt();

        // Copy assignment operator
        ListInt &operator=(ListInt other);

        // Copy assignment operator that takes an initializer list
        ListInt &operator=(std::initializer_list<value_type> ilist);

        // Concatenate two ListInt objects using operator+
        ListInt operator+(const ListInt &other) const;

        // Concatenate a ListInt object and an initializer list using operator+
        ListInt operator+(std::initializer_list<value_type> ilist) const;

        // Concatenate an initializer list and a ListInt object using operator+
        friend ListInt operator+(std::initializer_list<value_type> ilist, const ListInt &rhs);

        // Concatenate another ListInt object to this list using the += operator
        ListInt &operator+=(const ListInt &other);

        // Concatenate an rvalue reference to another ListInt object to this list using the += operator
        ListInt &operator+=(ListInt &&other);

        // Overload of operator[] that returns a reference to the data of the node at index i
        value_type &operator[](size_t i);

        // Const overload of operator[] that returns a const reference to the data of the node at index i
        const value_type &operator[](size_t i) const;

        // Add a value to the front of the list
        void push_front(value_type value);

        // Add a value to the back of the list
        void push_back(value_type value);

        // Remove the front node and return its data
        value_type pop_front();

        // Erase all nodes in the list
        void clear();

        // Exchange the contents of the list with another list
        void swap(ListInt &other);

        // Return the number of nodes in the list
        size_t size() const;

        // Return true if the list is empty, false otherwise
        bool empty() const;

        // Return the current value of object_counter
        static size_type object_count();

        // Overload of operator<< that outputs the list to an ostream
        friend std::ostream &operator<<(std::ostream &os, const ListInt &rhs);

    private:
        // Definition of the Node struct
        struct Node
        {
            value_type data;
            Node *next;

            // Constructor
            Node(value_type value) : data(value), next(nullptr) {}
        };

        Node *head;
        Node *tail;

        // Static member to keep track of the number of ListInt objects created
        static size_type object_counter;

        // Private member function to create a new node
        Node *new_node(value_type data) const;
    };

    std::ostream &operator<<(std::ostream &os, const ListInt &rhs);
#endif /* LISTINT_H */
}