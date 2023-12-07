#include "intro_to_templates.h"
#include <iostream>


template<typename T>
void templates_tutorials::print_data_pointer(T t) {
	if constexpr (std::is_pointer<T>::value) {
		std::cout << *t << std::endl;
	}
	else {
		std::cout << t << std::endl;
	}
}

template<typename A, typename B, typename C>
void templates_tutorials::print_data(A a, B b, C c) {
	print_data_pointer(a);
	std::cout << std::endl;
	print_data_pointer(b);
	std::cout << std::endl;
	print_data_pointer(c);
	std::cout << std::endl;
}


template<typename A>
void templates_tutorials::print_data_pointer_custom(A a)
{
	if constexpr (templates_tutorials::is_pointer_custom<A>::value) {
		std::cout << "Should be here ................." << std::endl;
		std::cout << *a << std::endl;
	}
	else {
		std::cout << a << std::endl;
	}
}

template<typename T>
void templates_tutorials::constrained_printer(T t) {
	if constexpr (std::is_pointer<T>::value && std::is_floating_point<T>::value) {
		std::cout << *t << std::endl;
	}
	else {
		std::cout << t << std::endl;
	}
}

template<typename T>
void templates_tutorials::working_constrained_printer(T t) {
	using modified_pointer = typename strip_pointer<T>::type;
	if constexpr (std::is_pointer<T>::value && std::is_floating_point<modified_pointer>::value) {
		std::cout << *t << std::endl;
	}
	else {
		std::cout << t << std::endl;
	}
}

void templates_tutorials::driver() {

	// Generic and re-usable funcs
	std::cout << "**************** Templates generic example ****************" << std::endl;
	templates_tutorials::print_data(1, 2, 3);
	// Can handle different data types
	templates_tutorials::print_data(1, "hello", 45.67);
	std::cout << "********************************" << std::endl;
	std::cout << "**************** Templates passing by address ( is::pointer ) ****************" << std::endl;
	// What if we want to deal with pointers
	std::string hello = "Look at this!";
	// This produces the address of the variable
	templates_tutorials::print_data(&hello, 1, 2);

	// Okay, Now lets try to see how the is_pointer would be implemented -whats the logic behind it? - From scratch
	std::cout << "********************************" << std::endl;
	std::cout << "**************** Templates - Logic behind is_pointer ****************" << std::endl;
	std::string new_hello = "Actually! Look at this!";
	templates_tutorials::print_data_pointer_custom(&new_hello);
	// Hurray! That worked!
	// That being said, Lets try to bring in some more constraints into the print function i.e. only de-reference floating or double variables when passed by reference.
	std::cout << "********************************" << std::endl;
	std::cout << "**************** Templates - Meta functions ****************" << std::endl;
	float test = 56.78;
	templates_tutorials::constrained_printer(&test);
	// This won't work as expected becasue the is_floating_point function won't accept pointers. Hence we need to strip them out!
	std::cout << "**************** Templates - Meta functions - Fixed output for float  ****************" << std::endl;
	templates_tutorials::working_constrained_printer(&test);
	templates_tutorials::working_constrained_printer(&new_hello);
}
