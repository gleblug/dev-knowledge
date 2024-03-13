// write function that sort two sorted arrays

// write triple pointers merge sort (increase capacity of first array)

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>


template <typename T>
void merge_sort_template(std::vector<T> vec1, std::vector<T> vec2)
{

}

int main(int argc, char const *argv[])
{
    std::vector<uint16_t> vec1;    
    std::vector<uint16_t> vec2;    
    std::copy(std::istream_iterator<uint16_t>(std::cin), std::istream_iterator<uint16_t>(), std::back_inserter(vec1));
    std::copy(std::istream_iterator<uint16_t>(std::cin), std::istream_iterator<uint16_t>(), std::back_inserter(vec2));

    // merge_sort_template();
    std::copy(vec1.begin(), vec1.end(), std::ostream_iterator<uint16_t>(std::cout, " "));
    std::cout << std::endl;
    
    return 0;
}
