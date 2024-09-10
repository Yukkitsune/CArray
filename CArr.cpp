#include "CArr.h";

CArr::CArr(int* p, int cap) { // Full constructor
    this->cap = cap;
    this->p = new int[cap];
    for (int i = 0; i < cap;++i) {
        this->p[i] = p[i];
    }
    this->sort_arr();
}
CArr::CArr(int cap) :cap(cap) { // The constructor allocates memory without initialization
    p = new int[cap];
}
CArr::CArr() { // The constructor of the empty CArr
    p = nullptr;
    cap = 0;
}
CArr::CArr(const CArr& Arr) { // The copy constructor
    cap = Arr.cap;
    p = new int[cap];
    for (int i = 0; i < cap; ++i) {
        p[i] = Arr.p[i];
    }
}
CArr::CArr(CArr&& Arr) noexcept { // the move constructor
    std::swap(p, Arr.p);
    std::swap(cap, Arr.cap);
}
void CArr::print() { // Print object to console
    std::cout << "capacity " << cap << " --> ";
    for (int i = 0; i < cap; ++i) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "----------" << std::endl;
}
int& CArr::operator [](int index) { // Overloading operator []
    return p[index];
}
CArr& CArr::operator = (const CArr& v2) { // Overloading operator = lvalue
    if (this != &v2) {
        cap = v2.cap;
        if (p != nullptr) delete[] p;
        p = new int[cap];
        for (int i = 0; i < cap; ++i) p[i] = v2.p[i];
    }
    return *this;
}
CArr& CArr::operator = (CArr&& v2) noexcept { // Overloading operator = rvalue 
    if (this != &v2) {
        std::swap(p, v2.p);
        std::swap(cap, v2.cap);
    }
    return *this;
}
CArr::~CArr() { // Destructor
    if (p != nullptr) delete[] p;
}
CArr& CArr::operator ++ (){ //Prefix increment
    for (int i = 0; i < this->cap; ++i) ++p[i];
    return *this;
}
CArr CArr::operator ++ (int) { // Postfix increment
    CArr temp_obj(this->p, this->cap);
    for (int i = 0; i < this->cap; ++i) {
        p[i]++;
    }
    return temp_obj;
}
CArr& CArr::operator -- () { // Prefix decrement
    for (int i = 0; i < this->cap; ++i) --p[i];
    return *this;
}
CArr CArr::operator -- (int) { // Postfix decrement
    CArr temp_obj(this->p, this->cap);
    for (int i = 0; i < this->cap; ++i) {
        p[i]--;
    }
    return temp_obj;
}
CArr& CArr::operator +() { // Duble last number
    if (p != nullptr) {
        cap += 1;
        int* temp = new int[cap];
        std::copy(p, p + cap - 1, temp);
        temp[cap - 1] = p[cap - 2];
        delete[] p;
        p = temp;
        temp = nullptr;
    }
    return *this;
}
CArr& CArr::operator -() { // Delete last number
    if (p != nullptr) {
        cap -= 1;
        int* temp = new int[cap];
        std::copy(p, p + cap, temp);
        delete[]p;
        p = temp;
        temp = nullptr;
    }
    return *this;
}
void CArr::sort_arr() { // Sort arr 
    for (int j = 1; j < cap;++j) {
        bool sorted = true;
        for (int i = 0; i < cap - j; ++i) {
            if (p[i] > p[i + 1]) {
                std::swap(p[i], p[i + 1]);
                sorted = false;
            }   
        }
        if (sorted) break;
    }
}

CArr CArr::operator + (CArr& second_arr) { // Summation of CArrs as intersection of multisets
    CArr temp(cap);
    int i = 0, j = 0, k = 0;
    while (i < cap) {
        while (j < cap) {
            if (p[i] == second_arr.p[j]) {
                temp[k] = p[i];
                second_arr.p[j] = -1;
                k += 1;
                i += 1;
                j = 0;
            }
            else {
                j += 1;
            }
        }
        i += 1;
        j = 0;
    }
    CArr result(k);
    for (int m = 0; m < k; ++m) {
        result[m] = temp[m];
    }
    result.sort_arr();
    return result;
}
void CArr::rand_arr() {
    srand(time(0));
    for (int i = 0; i < cap; ++i) {
        p[i] = rand() % 100;
    }
    this->sort_arr();
}
void CArr::fill_arr_file(std::ifstream& in) { // Filling massives data from the file
    for (int i = 0; i < cap; ++i) {
        in >> p[i];
    }
    this->sort_arr();
}
std::istream& operator >> (std::istream& in, CArr& Arr) { // Overloading operation >>
    if (Arr.p != nullptr) { Arr.cap = 0; delete[] Arr.p; }
    int len_temp;
    in >> len_temp;
    int* p_temp = new int[len_temp];
    for (int i = 0; i < len_temp; ++i) {
        in >> p_temp[i];
    }
    CArr Arr_in(p_temp, len_temp);
    len_temp = 0;
    delete[] p_temp;
    return in;
}
std::ostream& operator << (std::ostream& out, CArr& Arr) { // Overloading operation <<
    out << "capacity " << Arr.cap << " --> ";
    for (int i = 0; i < Arr.cap; ++i) {
        out << Arr.p[i] << " ";
    }
    out << "\n";
    return out;
}
void CArr::print_fout(std::ostream& out) { // print object to file
    out << "capacity " << cap << " --> ";
    for (int i = 0; i < cap; ++i) {
        out << p[i] << " ";
    }
    out << "\n";
}

