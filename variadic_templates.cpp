// variadic_templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <type_traits>
#include <tuple>

template <typename T>
void printn(T t)
{
    std::cout << t<<",";
}


template <typename T, typename ... T1>
void printn(T t, T1... rest)
{
    std::cout << t << ",";
    printn(rest...);
}

template<typename TUPLE, std::size_t ... indices>
void print_tuple_impl(TUPLE t, std::index_sequence<indices ...>)
{
    printn(std::get<indices>(t)...);
}

template<typename TUPLE>
void print_n_tuple(TUPLE&& t)
{
    print_tuple_impl(std::forward<TUPLE>(t), std::make_index_sequence<std::tuple_size<std::remove_reference_t<TUPLE>>::value>{});
}

int main()
{
    std::cout<<std::boolalpha;
    printn(1, 4.465, "Hello", true);
    // What about a tuple
    std::cout << "/n"; 
    auto new_tuple = std::make_tuple(1, 4.5, "Hello World", false);
    print_n_tuple(new_tuple);
}

