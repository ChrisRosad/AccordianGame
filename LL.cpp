/*
* Name: Christopher Rosado, 2001956343, Assignment One
* Description: Linked list type class
* Input: none
* Output: none
*/
#include "LL.h"

/* Description */
/*
* function_identifier: operator++(int)
* parameters: int 
* description: will set the iterator to the next node of the link
* list. Then it will return that position 
* return value: iterator current
*/
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++(int)
{
	iterator current(position);
	position = position->next;

	return current;
}
/* Description */
/*
* function_identifier: operator++()
* parameters: none
* description: will move the node position to the next node and then will
* return the *this value that contains the next position. 
* return value: *this
*/
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator++()
{
	position = position->next;

	return *this;
}
/* Description */
/*
* function_identifier: operator--(int) 
* parameters: none
* description: Creates a current iterator with the position of 
* the current position of the *this iterator and then will return
* the current iterator
* return value: iterator current
*/
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--(int)
{
	iterator current(position);
	position = position->prev;

	return current;
}
/* Description */
/*
* function_identifier: operator--
* parameters: 
* description: uses the position of *this to 
* go back once and then will return *this. Allowing
* for the iterator to go back.
* return value: *this
*/
template <class type>
typename LL<type>::iterator LL<type>::iterator::operator--()
{
	position = position->prev;

	return *this;
}
/* Description */
/*
* function_identifier: LL()
* parameters: none
* description: The constructor will start to set up
* the dummy node, create a new node and then having 
* the prev and next node of dummy to equal dummy
* return value: none
*/
template <class type>
LL<type>::LL()
{
	this->dummy = new node;
	this->dummy->next = dummy;
	this->dummy->prev = dummy;

}
/* Description */
/*
* function_identifier: LL(const LL<type>& copy)
* parameters: const LL<type>& copy
* description: The copy constructor will set up the dummy
* node and then will create the dummy node like in the original
* constructor but then will call this copyList and uses the parameter
* as the value for *this to copy.
* return value: none
*/
template <class type>
LL<type>::LL(const LL<type>& copy)
{
	this->dummy = new node;
	this->dummy->next = dummy;
	this->dummy->prev = dummy;
	copyList(copy);
}
/* Description */
/*
* function_identifier: operator=(cosnt LL<type>& rhs)
* parameters: const LL<type>& rhs
* description: The operator overload will first check 
* if *this and rhs are not equal and if not then the 
* function will call the clearlist() to empty out this 
* linked list and then will have this copy rhs using the 
* copyList(rhs) function.
* return value: *this
*/
template <class type>
const LL<type>& LL<type>::operator=(const LL<type>& rhs)
{
	if (this != &rhs)
	{
		//Your code goes here
		this->clearList();
		this->copyList(rhs);
	}

	return *this;
}
/* Description */
/*
* function_identifier: ~LL()
* parameters: none
* description: will first clear the list using
* the clearlist function and then will deallocate the
* dummy node.
* return value: none
*/
template <class type>
LL<type>::~LL()
{
	clearList();
	delete dummy;
}
/* Description */
/*
* function_identifier: headInsert(const type& item)
* parameters: const type& item
* description: it creates a new node and 
* the node takes the item object. Then it will
* check if dummy->next is equal to dummy and if it 
* is then the new node will connect to the dummy node. 
* Otherwise a new node called NavNode will find
* the node connected to the dummy->next pointer. Then
* the program will have the new node be connected as the 
* head and attach all necessary pointers to the new and old node
* return value: none
*/
template <class type>
void LL<type>::headInsert(const type& item)
{
	node *tmpNode = new node;
	tmpNode->item = item;
	if(dummy->next == dummy){
		tmpNode->next = dummy;
		dummy->prev = tmpNode;
		tmpNode->prev = dummy;
		dummy->next = tmpNode;
	}else{
		node *NavNode = dummy->next; //navigational node 
		tmpNode->next = NavNode;
		NavNode->prev = tmpNode;
		dummy->next = tmpNode;
		tmpNode->prev = dummy;
		NavNode = nullptr;
	}
	tmpNode = nullptr;
}
/* Description */
/*
* function_identifier: tailInsert(const type& item)
* parameters: const type& item
* description: the function will create a new node called
* tmpNode, then tmpNode->item will equal to item. Then it will
* check if dummy->prev is equal to dummy, if it is then the 
* tmpNode and dummy will connect the prev and next pointers to 
* one another. Otherwise the function will create a new node
* to navigate to the tail end of the linked list and will be a
* guide for the function to place tmpNode as the new tail end 
* securely.
* return value: none
*/
template <class type>
void LL<type>::tailInsert(const type& item)
{
	node *tmpNode = new node;
	tmpNode->item = item;
	if(dummy->prev == dummy){
		
		tmpNode->next = dummy;
		dummy->prev = tmpNode;
		tmpNode->prev = dummy;
		dummy->next = tmpNode;
	}else{
		node *NavNode = dummy->prev;
		NavNode->next = tmpNode;
		dummy->prev =  tmpNode;
		tmpNode->next = dummy;
		tmpNode->prev = NavNode;
		NavNode = nullptr;

	}
	tmpNode = nullptr;
}
/* Description */
/*
* function_identifier: headRemove()
* parameters: none
* description: The headRemove function will create a 
* node called Del that is meant for finding and deleting
* the head node. It first checks if there is only one node
* in the linked list and if so it will connect dummys pointers
* to itself and then will deallocate Del. Otherwise 
* the function will set dummy->next to equal the node next to 
* the head node(making that the new head node) and will disconnect
* the old head node and deallocate it. 
* return value: none
*/
template <class type>
void LL<type>::headRemove()
{
	node *Del = dummy->next;
	if(dummy->prev == Del){
		dummy->next = dummy;
		dummy->prev = dummy;
	}else{
		dummy->next = Del->next;
		dummy->next->prev = dummy;
	}
	delete Del;
	Del = nullptr;
}
/* Description */
/*
* function_identifier: tailRemove()
* parameters: none
* description: The tailRemove function will create a 
* node called Del that is meant for finding and deleting
* the head node. It first checks if there is only one node
* in the linked list and if so it will connect dummys pointers
* to itself and then will deallocate Del. Otherwise 
* the function will set dummy->prev to equal the node next to 
* the tail nodeand will disconnect the old tail node and deallocate it. 
* return value: none
*/
template <class type>
void LL<type>::tailRemove()
{
	node *Del = dummy->prev;
	if(dummy->next == Del){
		dummy->next = dummy;
		dummy->prev = dummy;
	}else{
		dummy->prev = Del->prev;
		Del->prev->next = dummy;
	}
	delete Del;
	Del = nullptr;
}
/* Description */
/*
* function_identifier: removeAtPosition(LL<type>::iterator& it)
* parameters: LL<type>::iterator& it
* description: The function sets up a node to equal to the position
* of it. Then it starts to go through a series of checks, first is to 
* check if it is at the dummy node in which we do not continue due to 
* dummy node should not removed until deallocation of the entire list.
* Then the function creates to nodes to secure the list after deletion 
* of the specific node. Then the function checks if the nodes are either at
* the end of the list or the beginning, and if so it will called either tailRemove
* or headremove. Then setting it.position to the position that is equivalent
* to the prev position it had. Otherwise the function will set the nodes to be
* to equal one another, excluding the node meant for deletion. Then it sets
* the iterator to be at the next node and then will delete the node.
* return value: none
*/
template <class type>
void LL<type>::removeAtPosition(LL<type>::iterator & it)
{
	node *tmpNode = it.position;
	if(tmpNode == dummy)
		return;
	
	node *NxtNode = tmpNode->next;
	node *PrvNode = tmpNode->prev;
	if(NxtNode == dummy){
		tailRemove();
		it.position = PrvNode;	
	}else if(PrvNode == dummy){
		headRemove();
		it.position = NxtNode;
	}else{
		PrvNode->next = NxtNode;
		NxtNode->prev = PrvNode;
		it.position = NxtNode;
		delete tmpNode;
	}

	tmpNode = NxtNode = PrvNode = nullptr;
}
/* Description */
/*
* function_identifier: clearList()
* parameters: none
* description: Within the function there is a while loop that
* will check if dummy-> is equal to dummy and if not the function
* called headRemove() to get rid of all the nodes within the linked
* list until only dummy remains.
* return value: none
*/
template <class type>
void LL<type>::clearList()
{
	while(dummy->next != dummy){
		headRemove();
	}
}
/* Description */
/*
* function_identifier: copyList(const LL<type>& copyThisList)
* parameters: const LL<type>& copyThisList
* description: The function starts with creating a new node
* and setting to to equal copyThisList dummy->next which would 
* be the head node. Then there is a while loop that checks if CopyNode
* is equal to copyThisList's dummy node and if not it will do a tail 
* insert into the *this's Linked list. 
* return value: none
*/
template <class type>
void LL<type>::copyList(const LL<type>& copyThisList)
{
	node *CopyNode = copyThisList.dummy->next;
	while(CopyNode != copyThisList.dummy){
		this->tailInsert(CopyNode->item);
		CopyNode = CopyNode->next;
	}
}