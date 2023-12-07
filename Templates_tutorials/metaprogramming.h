#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
/// <summary>
/// The task is to find whether a particular type exists in a container like a vector or tuple. So we need to write a metafunction for the tuple
/// A run time version - before creating meta template functions lets create a run time version with vectors
/// </summary>
class metaprogramming
{

public:
	bool type_checker(const std::string &, const std::vector <std::string>&, size_t start_from = 0);

	void driver_compiletimeversion();

	void testing_meta_if_template();

	void driver_runtimeversion();
};

