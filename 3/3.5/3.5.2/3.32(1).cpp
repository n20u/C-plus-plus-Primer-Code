#include <iostream>
#include <cstddef>

using std::cout; using std::endl;

int main()
{
	int arr[10];
	
	for (size_t i = 0; i < 10; ++i)
	    arr[i] = i;
	    
	int arr1[10];
	
	for (size_t i = 0; i < 10; ++i)
	    arr1[i] = arr[i];
	    
	for (auto i : arr1)
	    cout << i << " ";
	cout << endl;
	
	return 0;
}
