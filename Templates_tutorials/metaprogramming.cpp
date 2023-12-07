#include "metaprogramming.h"

// type checker implementation - run time version. Again no loops here. Uses recursion
bool metaprogramming::type_checker(const std::string & search, const std::vector<std::string> & V, size_t start_search) {
	if (V[start_search] == search) {
		return true;
	}
	else {
		if (start_search == V.size() -1) {
			return false;
		}
		else {
			return type_checker(search, V, start_search += 1);
		}
	}
}

template<bool status, typename THEN, typename ELSE>
struct if_ {};

// Template specialisation for true conditon, uses the type as THEN( or the next statement)
template<typename THEN, typename ELSE>
struct if_<true, THEN, ELSE> {
	using type= THEN;
};

// Template specialisation for true conditon, uses the type as ELSE( or the statement after that)
template<typename THEN, typename ELSE>
struct if_<false, THEN, ELSE> {
	using type = ELSE;
};

void metaprogramming::driver_runtimeversion()
{
	const std::vector<std::string> vec_{ "int","char","double","float" };
	const char* type = "int";
	std::cout << " Element " << type << " status  -  " << metaprogramming::type_checker(type, vec_);
	const char* type2 = "long";
	std::cout << " Element " << type2 << " status  -  " << metaprogramming::type_checker(type2, vec_);
}

// Contains type is a template that uses a meta if to decide if a particular type SEARCH is in the TUPLE list containing different data types
// Should not use any loops or if conditions
// Should be single line code
template<typename SEARCH, typename TUPLE, size_t start_search = 0>
struct contains_type :
	if_ < //CONDITION - Uses the is_same stl to check if search and std::tuple_element are same
		std::is_same<SEARCH, std::tuple_element_t<start_search, TUPLE>>::value,
		// THEN - Return true
		std::true_type,
		// ELSE - Follows the same logic of run-time implementation using recursion
		typename if_ < //CONDITION 
			(start_search == std::tuple_size<TUPLE>::value - 1),
			//THEN - Returns false
			std::false_type,
			//ELSE - Recursion with updated start_search value
			contains_type<SEARCH, TUPLE, start_search+1>
		>::type
	>::type	
{};

void metaprogramming::testing_meta_if_template()
{
	using result1 = if_ <(10 > 5), int, float>::type;
	static_assert(std::is_same_v<int, int>, "Meta function failed.... Try again!");

	using result2 = if_ <(10 < 5), float, double>::type;
	static_assert(std::is_same_v<double, double>, "Meta function failed.... Try again!");
	// This is so cool. But this only lets you check for types.
}

void metaprogramming::driver_compiletimeversion()
{
	std::tuple<int, bool, float> test_tuple;
	std::cout << "Checking if integer is in the list...." << std::endl;
	std::cout << std::boolalpha << contains_type<int, decltype(test_tuple)>::value << std::endl;
	std::cout << "Checking if double is in the list...." << std::endl;
	std::cout << std::boolalpha << contains_type<double, decltype(test_tuple)>::value << std::endl;
}