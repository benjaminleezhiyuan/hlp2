/*!*****************************************************************************
\file    ft.hpp
\author  Benjamin Lee Zhi Yuan
\par     DP email: benjaminzhiyuan.lee
\par     Course: CSD1171
\par     Section: A
\par     Lab 07
\date    24-02-23

\brief

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
   * Displays the elements that are encapsulated within the ranges.
   *
   * \param first
   * First element to display
   *
   * \param last
   * Last element to display
   *********************************************************************/
  template <typename T>
  void display(T first, T last);

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
  template <typename T1, typename T2>
  T1 remove(T1 first, T1 last, const T2 &value);

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
 * Copy elements in range to another range
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
 * 
 * \param first 
 * \param last 
 * \param value 
 *********************************************************************/
  template <typename T1, typename T2>
  void fill(T1 first, T1 last, const T2& value);

  // Provide DEFINITIONS for each function template declared above ...

  template <typename T>
  void swap(T &lhs, T &rhs)
  {
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
  }

  template <typename T>
  void display(T first, T last)
  {
    for (T it = first; it != last; ++it)
    {
      std::cout << *it << ", ";
    }
    std::cout << std::endl;
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

  template <typename T1, typename T2>
  T1 remove(T1 first, T1 last, const T2 &value)
  {
    T1 result = first;
    for (; first != last; ++first)
    {
      if (*first != value)
      {
        *result++ = *first;
      }
    }
    return result;
  }

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

  template <typename T1, typename T2>
  void fill(T1 first, T1 last, const T2& val)
  {
    while (first != last)
    {
      *first=val;
      ++first;
    }
  }
}

#endif
//-------------------------------------------------------------------------
