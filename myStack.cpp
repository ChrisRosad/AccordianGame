/*
* Name: Christopher Rosado, 2001956343, Assignment One
* Description: stack type classs
* Input: none
* Output: none
*/
#include <cstdlib>
#include "myStack.h"

/* Description */
/*
* function_identifier: myStack()
* parameters: none
* description: constructor sets up the stack elements 
* capacity, and the size. setting the capacity 
* to five and using that to create a dynamic array.
* return value: constructor
*/
template <class type>
myStack<type>::myStack()
{
	this->capacity = 5;
	this->size = 0;
	this->stackElements = new type[capacity];
}
/* Description */
/*
* function_identifier: myStack(const myStack<type>& copy)
* parameters: const myStack<type>& copy
* description: calls the copyStack function and uses
* copy parameter to be the object for copyStack
* return value: none
*/
template <class type>
myStack<type>::myStack(const myStack<type>& copy)
{
	copyStack(copy);
}
/* Description */
/*
* function_identifier:  const myStack<type>& myStack<type>::operator=(const myStack<type>& rhs)
* parameters: const myStack<type>& rhs
* description: Calls the this->clearStack() and this->copyStack for the assignment 
* overload operator, allowing for the = sign to be used within the main easily. 
* return value: *this
*/
template <class type>
const myStack<type>& myStack<type>::operator=(const myStack<type>& rhs)
{
	if (this != & rhs)
	{
		//Your code goes here
		this->clearStack();
		this->copyStack(rhs);
	}

	return *this;
}
/* Description */
/*
* function_identifier: ~myStack()
* parameters: none
* description: The descructor calls clearStack function to
* clear this->stackElements and to deallocate all of the nodes
* return value: none
*/
template <class type>
myStack<type>::~myStack()
{
	this->clearStack();
}
/* Description */
/*
* function_identifier: push(const type& item)
* parameters: const type& item
* description: the push function will first check if the 
* stack is full, and if not the function will set the element
* to the current top spot of the dynamic array. Otherwise,
* it will create a new capacity and new dynamic array to 
* replace the old array once the items have been copied. 
* return value: none
*/
template <class type>
void myStack<type>::push(const type& item)
{
	if(size == capacity){
		capacity += 5;
		type *TmpNode = new type[capacity];
		for(int i = 0; i < size; i++)
			TmpNode[i] = stackElements[i];
		delete [] stackElements;
		stackElements = TmpNode;
		TmpNode = nullptr;
	}
	stackElements[size] = item;
	size++;
}
/* Description */
/*
* function_identifier: peek() const
* parameters: none 
* description: checks if stack is empty then it will 
* throw out an exception. If it is not empty then 
* it would return stackElements[size - 1].
* return value: stackElements[size - 1]
*/
template <class type>
type myStack<type>::peek() const
{
	if(this->isEmpty()){
		throw std::out_of_range("Out of Range");
	}else{
		return stackElements[size - 1];
	}
}
/* Description */
/*
* function_identifier: getSize() 
* parameters: none
* description: returns the size of the 
* current stack object.
* return value: size 
*/
template <class type>
std::size_t myStack<type>::getSize() const
{
	return size;
}
/* Description */
/*
* function_identifier: pop() 
* parameters: none
* description: The pop() function will subtract the size by one
* then it will return the stackElements[size] array instance.
* return value: stackElements[size]
*/
template <class type>
type myStack<type>::pop()
{
	size -= 1;
	return stackElements[size];
}
/* Description */
/*
* function_identifier: isEmpty()
* parameters: none
* description: boolean function that will check if the size is 
* equivalent to 0. if it is equal then it will return true, otherwise
* it would return false.
* return value: size == 0
*/
template <class type>
bool myStack<type>::isEmpty() const
{
	return size == 0;
}
/* Description */
/*
* function_identifier: clearStack()
* parameters: none
* description: the clearStack function will reset the values of 
* capacity and size. Then it will deallocate the stackElements 
* array. 
* return value: none
*/
template <class type>
void myStack<type>::clearStack()
{
	this->capacity = 0;
	this->size = 0;
	delete [] this->stackElements;
}
/* Description */
/*
* function_identifier: copyStack() 
* parameters: const myStack<type>& copyThisStack
* description: The copyStack function will set *this 
* size and capacity equal to CopyThisStack's parameters. 
* Then it creates stackElements for *this. After the 
* new stackElements is created it will copy all of the 
* elements of copythisStack and into this->stackElements
* return value: none
*/
template <class type>
void myStack<type>::copyStack(const myStack<type>& copyThisStack)
{
		this->size = copyThisStack.size;	
		this->capacity = copyThisStack.capacity;
		this->stackElements = new type [capacity];
		for(int i = 0; i < copyThisStack.size; i++){
			this->stackElements[i] = copyThisStack.stackElements[i];
		}
}

