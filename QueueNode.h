#pragma once
template<class elementType>
class QueueNode
{
public:
	/* info 
	* @pre None.
	* @post 
	* @throw 
	*/
	QueueNode(void);
	/* info 
	* @pre None.
	* @post 
	* @throw 
	*/
	elementType item;
	/* info 
	* @pre None.
	* @post 
	* @throw 
	*/
	QueueNode *next;
	~QueueNode(void);
};

