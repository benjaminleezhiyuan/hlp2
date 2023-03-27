/*!******************************************************************
 * \file      test.hpp
 * \author    Benjamin Lee
 * \par       DP email: benjaminzhiyuan.lee\@digipen.edu.sg
 * \par       Course: CSD1171
 * \par       Section: A
 * \par       Lab 10
 * \date      17-03-2023
 *
 * \brief     This file contains test cases for 5 attempts to divide by 
 *            zero.
 *********************************************************************/
#include <iostream>
#include <sstream>

namespace hlp2
{
    class division_by_zero : public std::exception {
public:
/*!******************************************************************
 * \brief  Construct a new division by zero object
 * 
 * \param numerator numerator for division
 *********************************************************************/
    division_by_zero(int numerator) {
        std::stringstream ss;
        ss << "Division by zero: " << numerator << " / 0!\n";
        message = ss.str();
        
    }

/*!******************************************************************
 * \brief  returns error message for division_by_zero
 * 
 * \return const char* 
 *********************************************************************/
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};

class invalid_input : public std::exception {
public:
/*!******************************************************************
 * \brief  exception thrown when input is invalid
 * 
 * \return const char* 
 *********************************************************************/
    const char* what() const noexcept override {
        return "Invalid input!";
    }
};

class stream_wrapper {
public:
    explicit stream_wrapper(std::istream &is) : is_(is) {}

/*!******************************************************************
 * \brief  Construct a new stream wrapper object
 * 
 * \param is 
 *********************************************************************/
    explicit stream_wrapper(std::istream &is) : is_(is) {}

/*!******************************************************************
 * \brief  overloaded operator>> for stream_wrapper class
 * 
 * \param value 
 * \return stream_wrapper& 
 *********************************************************************/
    template<typename T>
    stream_wrapper &operator>>(T &value) {
        if (!(is_ >> value)) {
            throw invalid_input();
        }
        return *this;
    }

private:
    std::istream &is_;
};

/*!******************************************************************
 * \brief  Test function for div_1
 * 
 * \param numerator 
 * \param denominator 
 * \param divide1 
 *********************************************************************/
    void test1(int numerator, int denominator, bool (*divide1)(int, int, int &))
    {
        int value;
        if (divide1(numerator, denominator, value))
        {
            std::cout << "Calling function #1; result: " << value << "." << std::endl;
        }
        else
        {
            std::stringstream ss;
            ss << "Division by zero: " << numerator << " / " << denominator;
            std::cout << "Calling function #1." << std::endl;
            throw division_by_zero(numerator);
        }
    }

/*!******************************************************************
 * \brief  Test function for div_2
 * 
 * \param numerator 
 * \param denominator 
 * \param divide2 
 *********************************************************************/
    template <typename F>
    void test2(int numerator, int denominator, F divide2)
    {
        std::pair<bool, int> result = divide2(numerator, denominator);
        if (result.first)
        {
            std::cout << "Calling function #2; result: " << result.second << "." << std::endl;
        }
        else
        {
            std::stringstream ss;
            ss << "Division by zero: " << numerator << " / " << denominator;
            std::cout << "Calling function #2." << std::endl;
            throw division_by_zero(numerator);
        }
    }

/*!******************************************************************
 * \brief  Test function for div_3
 * 
 * \param numerator 
 * \param denominator 
 * \param divide3 
 *********************************************************************/
    template <typename F>
    void test3(int numerator, int denominator, F divide3)
    {
        errno = 0;
        int value = divide3(numerator, denominator);
        if (errno)
        {
            std::cout << "Calling function #3; result: " << value << "." << std::endl;
        }
        else
        {
            std::stringstream ss;
            ss << "Division by zero: " << numerator << " / " << denominator;
            std::cout << "Calling function #3." << std::endl;
            throw division_by_zero(numerator);
        }
    }

/*!******************************************************************
 * \brief  Test function for div_4
 * 
 * \param numerator 
 * \param denominator 
 * \param divide4 
 *********************************************************************/
    template <typename F>
    void test4(int numerator, int denominator, F divide4)
    {
        int value = divide4(numerator, denominator);
        if (value != std::numeric_limits<int>::min())
        {
            std::cout << "Calling function #4; result: " << value << "." << std::endl;
        }
        else
        {
            std::stringstream ss;
            ss << "Division by zero: " << numerator << " / " << denominator;
            std::cout << "Calling function #4." << std::endl;
            throw division_by_zero(numerator);
        }
    }

/*!******************************************************************
 * \brief  Test function for div_5
 * 
 * \param numerator 
 * \param denominator 
 * \param divide5 
 *********************************************************************/
    template <typename F>
    void test5(int numerator, int denominator, F divide5)
    {
        try
        {
            int value = divide5(numerator, denominator);
            std::cout << "Calling function #5; result: " << value << "." << std::endl;
        }
        catch (const division_by_zero &e)
        {
            std::cout << "Calling function #5." << std::endl;
            throw;
        }
    }
}