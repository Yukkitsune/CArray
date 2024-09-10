#pragma once
#include <fstream>
#include <algorithm>
#include <iostream>
#include <ctime>
class CArr {
private:
    int* p = nullptr;
    int cap = 0;
public:
    CArr(int* p, int cap); // Full constructor
    CArr(int cap); // The constructor allocates memory without initialization
    CArr(); // The constructor of the empty CArr
    CArr(const CArr& arr); // The copy constructor
    CArr(CArr&& arr) noexcept; // the move constructor
    void print(); // Print object to console
    void print_fout(std::ostream& out);
    int& operator [](int index); // Overloading operator []
    CArr& operator = (const CArr& v2);
    CArr& operator = (CArr&& v2) noexcept;
    ~CArr();
    friend std::istream& operator >> (std::istream& in, CArr& arr); // Reading from stream
    friend std::ostream& operator << (std::ostream& out, CArr& arr); // Input in stream
    CArr& operator ++ (); //Prefix increment
    CArr operator ++ (int); // Postfix increment
    CArr& operator -- (); //Prefix decrement
    CArr operator -- (int); // Postfix decrement
    CArr& operator + (); // Dubling the last element
    CArr& operator - (); // Deleting the last element
    CArr operator + (CArr& second_arr);
    void sort_arr();
    void rand_arr(); // Filling CArr with random numbers
    void fill_arr_file(std::ifstream& in); // Filling CArr from file
};
