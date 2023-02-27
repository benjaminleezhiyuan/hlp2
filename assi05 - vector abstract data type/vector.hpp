/*!******************************************************************
 * \file      vector.hpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par      
 * \date      28-02-2023
 * 
 * \brief  This file contains declarations for functions defined in vector.cpp
 *********************************************************************/

// make sure to have a file-level Doxygen documentation block AND
// function-level documentation block for each function that your
// client will be using!!!

////////////////////////////////////////////////////////////////////////////////
#ifndef VECTOR_HPP
#define VECTOR_HPP
////////////////////////////////////////////////////////////////////////////////
#include <cstddef>          // need this for size_t
#include <initializer_list> // need this for std::initializer_list<int>
#include <algorithm>
// read the specs to know which standard library headers cannot be included!!!

namespace hlp2
{

  class vector
  {
  public:
    // @todo: using declarations required!!!
    // types to declare: size_type, value_type,
    // reference, const_reference, pointer, const_pointer
    using value_type = int;
    using size_type = size_t;
    using pointer = value_type *;
    using reference = value_type&;
    using const_reference = const value_type&;
    using const_pointer = const value_type *;

  public:
    vector();                               // default ctor
    explicit vector(size_type n);           // non-default, conversion ctor
    vector(std::initializer_list<int> rhs); // non-default, conversion ctor
    vector(vector const &rhs);              // copy ctor
    ~vector();
    vector &operator=(vector const &);
    vector &operator=(std::initializer_list<int> rhs);
    reference operator[](size_type index);
    const_reference operator[](size_type index) const;

    /***************************************************************************/
    /*!
    \brief
    stores value at the back of the vector array

    \param value
    value to be stored at the end of the vector array

      */
    /**************************************************************************/
    void push_back(value_type value);

    /***************************************************************************/
    /*!
    \brief
    new memory for the vector array

    \param value
    the size of the new-ed memory
      */
    /**************************************************************************/
    void reserve(size_type newsize);

    /***************************************************************************/
    /*!
    \brief
    new memory for the vector array

    \param value
    the size of the new-ed memory
      */
    /**************************************************************************/
    void resize(size_type newsize);

    /***************************************************************************/
    /*!
    \brief
    check if (this)current object's data is empty

    \return bool
    true - vector array is empty
    false - vector array is not empty
      */
    /**************************************************************************/
    bool empty() const;

    /***************************************************************************/
    /*!
    \brief
    check last empty memory location

    \return vector::size_type
    (this)current object's sz
      */
    /**************************************************************************/
    size_type size() const;

    /***************************************************************************/
    /*!
    \brief
    check the max memory space

    \return vector::size_type
    (this)current object's space
      */
    /**************************************************************************/
    size_type capacity() const;

    /***************************************************************************/
    /*!
    \brief
    check the number of "growths"

    \return vector::size_type
    (this)current object's allocs
      */
    /**************************************************************************/
    size_type allocations() const;

    //==========
    // iterators 
    //==========

    /***************************************************************************/
    /*!
    \brief
    The start of an array

    \return vector::pointer
    pointer to the start of an array
      */
    /**************************************************************************/
    pointer begin(); // pointer to first element

    /***************************************************************************/
    /*!
    \brief
    The end of an array

    \return vector::pointer
    pointer to the end of an array
      */
    /**************************************************************************/
    pointer end();   // pointer to one past last element

    /***************************************************************************/
    /*!
    \brief
    The start of an array

    \return vector::const_pointer
    const pointer to the start of an array
      */
    /**************************************************************************/
    const_pointer begin() const;

    /***************************************************************************/
    /*!
    \brief
    The end of an array

    \return vector::const_pointer
    const pointer to the end of an array
      */
    /**************************************************************************/
    const_pointer end() const;

    /***************************************************************************/
    /*!
    \brief
    The start of an array

    \return vector::const_pointer
    const pointer to the end of an array
      */
    /**************************************************************************/
    const_pointer cbegin() const;

    /***************************************************************************/
    /*!
    \brief
    The end of an array

    \return vector::const_pointer
    const pointer to the end of an array
      */
    /**************************************************************************/
    const_pointer cend() const;

  private:
    size_type sz;     // the number of elements in the array
    size_type space;  // the allocated size (in terms of elements) of the array
    size_type allocs; // number of times space has been updated
    pointer data;     // the dynamically allocated array
  };

} // namespace hlp2

#endif // VECTOR_HPP
