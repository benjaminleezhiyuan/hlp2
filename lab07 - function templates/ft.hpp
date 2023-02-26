/*!*****************************************************************************
\file    ft.hpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Lab 07
\date    24-02-23

\brief
 This file contains declaration and definition of 13 functions using templates
**********************************************************************************/

//-------------------------------------------------------------------------
#ifndef FT_H
#define FT_H
//-------------------------------------------------------------------------
#include <iostream>
// Do not add any other header files. Otherwise, your submission
// will not compile!!!

namespace hlp2
{
  // DECLARE (not define!!!) and DOCUMENT in ALPHABETIC ORDER the function
  // templates you'll be defining. There are *13* function templates to be
  // declared and defined.

  // I'm providing the declaration and documentation for swap here:
  /*!******************************************************************
   * \brief
   * Counts number of elements in range that equate to specific value
   *
   * \param first
   * Start of range
   *
   * \param last
   * End of range
   *
   * \param value
   * Value to count in range
   *
   * \return std::iterator_traits<T1>::difference_type
   * Number of elements in range equal to value.
   *********************************************************************/
  template <typename T1, typename T2>
  typename std::iterator_traits<T1>::difference_type
  count(T1 first, T1 last, const T2 &value);

  /*!******************************************************************
   * \brief
   * Copy elements in range to another range
   *
   * \param first
   * Start of range
   *
   * \param last
   * End of range
   *
   * \param first2
   * Start of second range
   *
   * \return T2
   * Iterator to the end of the second range.
   *********************************************************************/
  template <typename T1, typename T2>
  T2 copy(T1 first, T1 last, T2 first2);

  /*!******************************************************************
   * \brief
   * Displays the elements that are encapsulated within the ranges.
   *
   * \param first
   * First element to display
   *
   * \param last
   * Last element to display
   *********************************************************************/
  template <typename T>
  void display(const int *begin, const int *end);

  /*!******************************************************************
   * \brief
   * Compares elements between 2 ranges
   *
   * \param first1
   * Start of first range
   *
   * \param last1
   * End of first range
   *
   * \param first2
   * Start of second range
   *
   * \param last2
   * End of second range
   *
   * \return true
   * Return true if elements of both ranges are equal
   *
   * \return false
   * Else return false
   *********************************************************************/
  template <typename T1, typename T2>
  bool equal(T1 first1, T1 last1, T2 first2);

  /*!******************************************************************
   * \brief
   * Assigns value to all elements in the range
   *
   * \param first
   * Start of range
   *
   * \param last
   * End of range
   *
   * \param value
   * Value to be filled
   *********************************************************************/
  template <typename T1, typename T2>
  void fill(T1 first, T1 last, const T2 &value);

  /*!******************************************************************
   * \brief
   * Finds specified element in a range of elements
   *
   * \param first
   * Start of range
   *
   * \param last
   * End of range
   *
   * \param val
   * Value to find in range
   *
   * \return T1
   * Iterator to first element in range that equates to val.
   * If no element exists return last.
   *********************************************************************/
  template <class T1, class T2>
  T1 find(T1 first, T1 last, const T2 &val);

  /*!******************************************************************
   * \brief
   * Finds the smallest element in the range
   *
   * \param first
   * Start of range
   *
   * \param last
   * End of range
   *
   * \return T
   * Iterator to the smallest value in range.
   *********************************************************************/
  template <typename T>
  T min_element(T first, T last);

  /*!******************************************************************
   * \brief
   * Finds the largest element in the range
   *
   * \param first
   * Start of range
   *
   * \param last
   * End of range
   *
   * \return T
   * Iterator to the largest value in range.
   *********************************************************************/
  template <typename T>
  T max_element(T first, T last);

  /*!******************************************************************
   * \brief
   * Removes specified elements from a range
   *
   * \param first
   * Start of range
   *
   * \param last
   * End of range
   *
   * \param value
   * Element to be removed
   *
   * \return T1
   * New updated range of values with elements removed.
   *********************************************************************/
  template <typename T>
  T *remove(T *begin, T *end, T value);

  /*!******************************************************************
   * \brief
   * Assigns new value to elements in the range that match specified value.
   *
   * \param first
   * Start of range
   *
   * \param last
   * End of range
   *
   * \param old_value
   * Value to be replaced
   *
   * \param new_value
   * New value to replace old value
   *********************************************************************/

  template <typename T1, typename T2>
  void replace(T1 first, T1 last, const T2 &old_value, const T2 &new_value);

  /*!******************************************************************
   * \brief
   * Adds all values in specified range
   *
   * \param first
   * Start of range
   *
   * \param last
   * End of range
   *
   * \return T1
   * Result of adding all elements in the range
   *********************************************************************/
  template <typename T>
  T sum(T *first, T *last);

  /***************************************************************************/
  /*!
  \brief
   Swaps two objects. There is no return value but the two objects are
   swapped in place.

  \param lhs
    Reference to the first object to swap.

  \param rhs
   Reference to the second object to swap.
  */
  /**************************************************************************/
  template <typename T>
  void swap(T &lhs, T &rhs);

  /*!******************************************************************
   * \brief
   * Defines a range of elements from a sequence to be swapped with elements
   * from another sequence.
   *
   * \param first1
   * Start of range to be swapped.
   *
   * \param last1
   * last of range to be swapped.
   *
   * \param first2
   * Start of element to be swapped from second sequence.
   *********************************************************************/
  template <class T1, class T2>
  T2 swap_ranges(T1 first1, T1 last1, T2 first2);

  // Provide DEFINITIONS for each function template declared above ...
  template <typename T1, typename T2>
  typename std::iterator_traits<T1>::difference_type
  count(T1 first, T1 last, const T2 &value)
  {
    typename std::iterator_traits<T1>::difference_type count = 0;
    for (; first != last; ++first)
    {
      if (*first == value)
      {
        ++count;
      }
    }
    return count;
  }

  template <class T1, class T2>
  T2 copy(T1 first, T1 last, T2 first2)
  {
    while (first != last)
    {
      *first2 = *first;
      ++first2;
      ++first;
    }
    return first2;
  }

  template <typename T>
  void display(T begin, T end)
  {
    // Iterate through all elements in the range
    while (begin < end)
    {
      // Print out current value
      std::cout << *begin;
      // iterate to the next element
      ++begin;
      // Print a comma if it's not the last element
      if (begin < end)
        std::cout << ", ";
    }
    // Print a newline at the end of the line.
    std::cout << "\n";
  }

  template <typename T1, typename T2>
  bool equal(T1 first1, T1 last1, T2 first2)
  {
    for (; first1 != last1; first1++)
    {
      if (!(*first1 == *first2))
      {
        return false;
      }
      first2++;
    }
    return true;
  }

  template <typename T1, typename T2>
  void fill(T1 first, T1 last, const T2 &val)
  {
    while (first != last)
    {
      *first = val;
      ++first;
    }
  }

  template <class T1, class T2>
  T1 find(T1 first, T1 last, const T2 &val)
  {
    while (first != last)
    {
      if (*first == val)
        return first;
      ++first;
    }
    return last;
  }

  template <typename T>
  T min_element(T first, T last)
  {
    if (first == last)
    {
      return last;
    }
    T min = first;
    for (; first != last; first++)
    {
      if (*first < *min)
      {
        min = first;
      }
    }
    return min;
  }

  template <typename T>
  T max_element(T first, T last)
  {
    if (first == last)
    {
      return last;
    }
    T max = first;
    for (; first != last; first++)
    {
      if (*max < *first)
      {
        max = first;
      }
    }
    return max;
  }

  template <typename T>
  T *remove(T *begin, T *end, T value)
  {
    //Create a pointer dest to point at first value
    T *dest = begin;
    //Iterate through the range
    while (begin < end)
    {
      //If the current element is not the same as value
      if (*begin != value)
      {
        if (dest != begin) //avoid self-assignment
        //Assign the current element to the new range
          *dest = *begin;
        //Iterate destination range
        ++dest;
      }
      //Iterate source range
      ++begin;
    }
    //Return the pointer to the new end
    return dest;
  }

  template <typename T1, typename T2>
  void replace(T1 first, T1 last, const T2 &old_value, const T2 &new_value)
  {
    while (first != last)
    {
      if (*first == old_value)
      {
        *first = new_value;
      }
      ++first;
    }
  }

  template <typename T>
  T sum(T *first, T *last)
  {
    T sum = *first;
    first++;
    for (; first < last; first++)
    {
      sum += *first;
    }
    return sum;
  }

  template <typename T>
  void swap(T &lhs, T &rhs)
  {
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
  }

  template <typename T1, typename T2>
  T2 swap_ranges(T1 first1, T1 last1, T2 first2)
  {
    while (first1 != last1)
    {
      swap(*first1, *first2);
      ++first1;
      ++first2;
    }
    return first2;
  }
}

#endif
//-------------------------------------------------------------------------
