#pragma once
#include <string>

#define GENERATED_BODY(className) className(std::string objectName) : SObject(objectName) {} 

template <typename _T>
_T* NewObject(std::string ObjectName);

class SObject
{
public:
	SObject(std::string objectName) : ObjectName(objectName){}

	std::string ObjectName;
};

template<typename _T>
inline _T* NewObject(std::string ObjectName)
{
	_T* Object = new _T(ObjectName);
	return Object;
}
