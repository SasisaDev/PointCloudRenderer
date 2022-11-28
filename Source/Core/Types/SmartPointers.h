#pragma once

template <typename ObjType>
class TObject {
protected:
	ObjType* object;

	ObjType* SetObject(ObjType* ptr);
public:
	TObject() = default;
	TObject(ObjType* ptr);

	operator ObjType*() { return object; }
	ObjType* operator =(ObjType* ptr) { return SetObject(ptr); }
};
