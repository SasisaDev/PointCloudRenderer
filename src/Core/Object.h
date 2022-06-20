#pragma once
#include <string>

class SObject
{
public:
	SObject() {}

	SObject(const SObject&) = delete;
	SObject& operator =(const SObject&) = delete;

	std::string ObjectName;
};