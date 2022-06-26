#pragma once
#include <string>
#include <cstdarg>

#define GENERATED_BODY(className) className(std::string objectName) : SObject(objectName) {} 

template <typename _T>
_T* NewObject(std::string ObjectName);

class SObject
{
public:
	SObject(const SObject&) = delete;
	void operator=(const SObject&) = delete;

	SObject(std::string objectName) : ObjectName(objectName){}

	std::string ObjectName;
};

template<typename _T>
inline _T* NewObject(std::string ObjectName)
{
	_T* Object = new _T(ObjectName);
	return Object;
}

#define NewObject(_class, name, ...) new _class (name, __VA_ARGS__)