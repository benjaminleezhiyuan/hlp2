/*!******************************************************************
 * \file      listint.cpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Lab 08
 * \date      03-03-2023
 *
 * \brief
 * The cpp file contains the implementation of the ListInt class, 
 * which encapsulates a singly-linked list of int values.
 * it defines various member and helper functions
 *********************************************************************/
#include "listint.hpp"
#include <stdexcept>
#include <utility>
#include <iomanip>
namespace hlp2
{

  // Definition of static data member
  ListInt::size_type ListInt::object_counter{0};

  // Public static member function to access object_counter
  /*!*****************************************************************************
  \brief Public static member function to access object_counter
  \return The value of object_counter, which represents the number
   of ListInt objects that have been created
  *******************************************************************************/
  ListInt::size_type ListInt::object_count()
  {
    return object_counter;
  }

  // Private member function to create a new node
  /*!*****************************************************************************
  \brief Private member function to create a new node
  \param[in] data The value to be stored in the new node
  \return A pointer to the newly created node
  *******************************************************************************/
  ListInt::Node *ListInt::new_node(value_type data) const
  {
    return new Node(data);
  }

  /*!*****************************************************************************
  \brief Default constructor that creates an empty list
  *******************************************************************************/
  ListInt::ListInt() : head(nullptr), tail(nullptr)
  {
    object_counter++;
  }

  /*!*****************************************************************************
  \brief Copy constructor
  \param[in] other The list to be copied
  *******************************************************************************/
  ListInt::ListInt(const ListInt &other) : ListInt()
  {
    Node *cur = other.head;
    while (cur != nullptr)
    {
      push_back(cur->data);
      cur = cur->next;
    }
  }

  /*!*****************************************************************************
  \param[in] ilist The initializer list to be used to create the new list
  *******************************************************************************/
  ListInt::ListInt(std::initializer_list<value_type> ilist) : ListInt()
  {
    for (auto &elem : ilist)
    {
      push_back(elem);
    }
  }

  /*!*****************************************************************************
  \brief Destructor that deletes all nodes in the list
  *******************************************************************************/
  ListInt::~ListInt()
  {
    clear();
    object_counter--;
  }

  /*!*****************************************************************************
  \brief Copy assignment operator using copy-and-swap idiom
  \param[in] other The list to be assigned to this list
  \return A reference to this list after the assignment
  *******************************************************************************/
  ListInt &ListInt::operator=(ListInt other)
  {
    swap(other);
    return *this;
  }
  /*!*****************************************************************************
  \brief Copy assignment operator that takes an initializer list and creates a new list from its elements
  \param[in] ilist The initializer list to be used to create the new list
  \return A reference to this list after the assignment
  *******************************************************************************/
  ListInt &ListInt::operator=(std::initializer_list<value_type> ilist)
  {
    ListInt tmp(ilist);
    swap(tmp);
    return *this;
  }

  /*!*****************************************************************************
    \brief Overload of operator+ that concatenates two ListInt objects
    \param[in] other The list to be concatenated to this list
    \return A new list
    *******************************************************************************/
  ListInt ListInt::operator+(const ListInt &other) const
  {
    ListInt result(*this);
    Node *cur = other.head;
    while (cur != nullptr)
    {
      result.push_back(cur->data);
      cur = cur->next;
    }
    return result;
  }

  /*!*****************************************************************************
  \brief Overload of operator+ that concatenates a ListInt object and an initializer list
  \param [in] initializer_list list to concatenate to the list
  \return ListInt the concatenated list
  *******************************************************************************/
  ListInt ListInt::operator+(std::initializer_list<value_type> ilist) const
  {
    ListInt result(*this);
    for (auto &elem : ilist)
    {
      result.push_back(elem);
    }
    return result;
  }
  /*!*****************************************************************************
  \brief Concatenates an initializer list and a ListInt object
  \param ilist initializer list to concatenate to the list
  \param rhs ListInt object to concatenate the initializer list to
  \return ListInt the concatenated list
  *******************************************************************************/
  ListInt operator+(std::initializer_list<ListInt::value_type> ilist, const ListInt &rhs)
  {
    ListInt result(ilist);
    result += rhs;
    return result;
  }

  /*!*****************************************************************************
  \brief Friend overload of operator+ that concatenates an initializer list and a ListInt object
  \param other the ListInt object to concatenate to this list
  \return ListInt& a reference to this ListInt object
  *******************************************************************************/
  ListInt &ListInt::operator+=(ListInt &&other)
  {
    if (other.head != nullptr)
    {
      if (tail == nullptr)
      {
        head = other.head;
        tail = other.tail;
      }
      else
      {
        tail->next = other.head;
        tail = other.tail;
      }
      object_counter += other.object_counter; // increment counter by number of nodes in other list
      other.head = nullptr;
      other.tail = nullptr;
      object_counter++;
    }
    return *this;
  }

  /*!*****************************************************************************
  \brief Concatenates another ListInt object to this list using the += operator
  \param other the ListInt object to concatenate to this list
  \return ListInt& a reference to this ListInt object
  *******************************************************************************/
  ListInt &ListInt::operator+=(const ListInt &other)
  {
    Node *cur = other.head;
    while (cur != nullptr)
    {
      push_back(cur->data);
      cur = cur->next;
    }
    return *this;
  }

  /*!*****************************************************************************
  \brief Overload of operator[] that returns a reference to the data of the node at index i
  \param i the index of the node to access
  \return value_type& a reference to the data of the node at index i
  *******************************************************************************/
  ListInt::value_type &ListInt::operator[](size_t i)
  {
    Node *cur = head;
    for (size_t j = 0; j < i; ++j)
    {
      cur = cur->next;
    }
    return cur->data;
  }

  /*!*****************************************************************************
  \brief Const overload of operator[] that returns a const reference to the data of the node at index i
  \param i the index of the node to access
  \return const value_type& a const reference to the data of the node at index i
  *******************************************************************************/
  const ListInt::value_type &ListInt::operator[](size_t i) const
  {
    Node *cur = head;
    for (size_t j = 0; j < i; ++j)
    {
      cur = cur->next;
    }
    return cur->data;
  }

  // Member function that adds a value to the front of the list
  /*!*****************************************************************************
  \brief Adds a value to the front of the list
  \param value the value to add to the front of the list
  *******************************************************************************/
  void ListInt::push_front(value_type value)
  {
    Node *new_head = new_node(value);
    new_head->next = head;
    head = new_head;
    if (tail == nullptr)
    {
      tail = head;
    }
  }

  // Member function that adds a value to the back of the list
  // Member function that adds a value to the back of the list
  /*!*****************************************************************************
  \brief Adds a value to the back of the list
  \param value the value to add to the back of the list
  *******************************************************************************/
  void ListInt::push_back(value_type value)
  {
    Node *new_tail = new_node(value);
    if (tail == nullptr)
    {
      head = new_tail;
      tail = new_tail;
    }
    else
    {
      tail->next = new_tail;
      tail = new_tail;
    }
  }

  /*!*****************************************************************************
  \brief Removes the front node and returns its data
  \return the data of the front node
  \throws std::out_of_range if the list is empty
  *******************************************************************************/
  ListInt::value_type ListInt::pop_front()
  {
    if (head == nullptr)
    {
      throw std::out_of_range("pop_front on empty ListInt");
    }
    value_type result = head->data;
    Node *old_head = head;
    head = head->next;
    delete old_head;
    if (head == nullptr)
    {
      tail = nullptr;
    }
    return result;
  }

  /*!*****************************************************************************
  \brief Erases all nodes in the list
  *******************************************************************************/
  void ListInt::clear()
  {
    Node *cur = head;
    while (cur != nullptr)
    {
      Node *next = cur->next;
      delete cur;
      cur = next;
    }
    head = nullptr;
    tail = nullptr;
  }

  /*!*****************************************************************************
  \brief Exchanges the contents of the list with another list
  \param other the list to exchange contents with
  *******************************************************************************/
  void ListInt::swap(ListInt &other)
  {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
  }

  /*!*****************************************************************************
  \brief Returns the number of nodes in the list
  \return the number of nodes in the list
  *******************************************************************************/
  size_t ListInt::size() const
  {
    size_t result = 0;
    Node *cur = head;
    while (cur != nullptr)
    {
      ++result;
      cur = cur->next;
    }
    return result;
  }

  /*!*****************************************************************************
  \brief Returns true if the list is empty, false otherwise
  \return true if the list is empty, false otherwise
  *******************************************************************************/
  bool ListInt::empty() const
  {
    return head == nullptr;
  }

  // This function definition is provided:
  ////////////////////////////////////////////////////////////////////////////////
  // Function: operator<<
  //  Purpose: Output the list into an ostream object
  //   Inputs: os - ostream object
  //           list - the List to output
  //  Outputs: Returns an ostream object.
  ////////////////////////////////////////////////////////////////////////////////
  std::ostream &operator<<(std::ostream &os, const ListInt &rhs)
  {
    // Start at the first node
    ListInt::Node *pnode = rhs.head;

    // Until we reach the end of the list
    while (pnode != 0)
    {
      os << std::setw(4) << pnode->data; // print the data in this node
      pnode = pnode->next;               // move to the next node
    }

    os << std::endl; // extra newline for readability
    return os;
  }
}