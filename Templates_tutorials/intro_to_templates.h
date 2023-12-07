#pragma once
class templates_tutorials
{
	template<typename T>
	struct is_pointer_custom {
		static constexpr bool value = false;
	};

	template<typename T>
	struct is_pointer_custom<T*> {
		static constexpr bool value = true;
	};

	template<typename T>
	struct strip_pointer {
		using type = T;
	};

	template<typename T>
	struct strip_pointer<T*> {
		using type = T;
	};
public:

	template<typename A, typename B, typename C>
	void print_data(A, B, C);

	template<typename T>
	void print_data_pointer(T);

	template<typename T>
	void constrained_printer(T);

	template<typename T>
	void working_constrained_printer(T);

	template<typename A>
	void print_data_pointer_custom(A );
	
	void driver();
};

