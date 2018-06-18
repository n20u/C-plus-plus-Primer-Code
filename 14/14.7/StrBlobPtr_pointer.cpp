#include "StrBlobPtr.h"

class StrBlobPtr_pointer
{
	public:
		StrBlobPtr_pointer() = default;
		StrBlobPtr_pointer(StrBlobPtr *p) : pointer(p) {}
		StrBlobPtr* operator->() const
		{
			return pointer;
		}
	private:
		StrBlobPtr *pointer = nullptr;
};
