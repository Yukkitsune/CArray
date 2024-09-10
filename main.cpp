#include "CArr.h"

int main(int argc, const char* argv[])
{
    int enough_arguments = 3;
    if (argc != enough_arguments) { // Check arguments number
        std::cerr << "Not enough arguments :(" << std::endl;
        std::cerr << "Need: " << enough_arguments << " Given: " << argc << std::endl;
        return -1;
    }
    const std::string in = argv[1];
    const std::string out = argv[2];
    std::ifstream fin(in);
    std::ofstream fout(out);
    int cap = 0;
    if (!fin) { // Check if file in directory
        std::cerr << "File not found :(" << std::endl;
        return -2;
    }
    fin >> cap; // Fill capacity variable from file
    CArr first_CArr(cap); // Two CArr objects
    first_CArr.fill_arr_file(fin);
    CArr second_CArr(cap);
    second_CArr.fill_arr_file(fin);
    std::cout << "First CArr: ";
    first_CArr.print();
    fout << "First CArr: ";
    first_CArr.print_fout(fout);
    std::cout << "Second CArr: ";
    second_CArr.print();
    fout << "Second CArr: ";
    second_CArr.print_fout(fout);
    std::cout << "Summation of CArrs: ";
    CArr sum = first_CArr + second_CArr;
    sum.print();
    fout << "Summation of CArrs: ";
    sum.print_fout(fout);
    CArr random_CArr(cap);
    random_CArr.rand_arr();
    std::cout << "Random CArr: ";
    random_CArr.print();
    fout << "Random CArr: ";
    random_CArr.print_fout(fout);
    std::cout << "Prefix increment of CArr: " << std::endl;
    ++random_CArr;
    random_CArr.print();
    fout << "Prefix increment of CArr: ";
    random_CArr.print_fout(fout);
    std::cout << "Postfix increment of CArr: " << std::endl;
    random_CArr++;
    random_CArr.print();
    fout << "Postfix increment of CArr: ";
    random_CArr.print_fout(fout);
    std::cout << "Prefix decrement of CArr: " << std::endl;
    --random_CArr;
    random_CArr.print();
    fout << "Prefix decrement of CArr: ";
    random_CArr.print_fout(fout);
    std::cout << "Postfix decrement of CArr: " << std::endl;
    random_CArr--;
    random_CArr.print();
    fout << "Postfix decrement of CArr: ";
    random_CArr.print_fout(fout);
    std::cout << "Dubling the last element: " << std::endl;
    +random_CArr;
    random_CArr.print();
    fout << "Duble the last element: ";
    random_CArr.print_fout(fout);
    std::cout << "Delete the last element: " << std::endl;
    -random_CArr;
    random_CArr.print();
    fout << "Delete the last element: ";
    random_CArr.print_fout(fout);
    fin.close(); // Close files
    fout.close();
    return 0;
}
