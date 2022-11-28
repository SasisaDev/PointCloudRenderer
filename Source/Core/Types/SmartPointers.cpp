#include "SmartPointers.h"

template<typename ObjType>
ObjType* TObject<ObjType>::SetObject(ObjType* ptr)
{
	object = ptr;
	return object;
}

template<typename ObjType>
inline TObject<ObjType>::TObject(ObjType* ptr)
{
	object = ptr;
}