/* 
* File:   IOComplete.h
* Author: daniele
*
* Created on October 12, 2010, 9:48 AM
*/

#ifndef IOCOMPLETE_H
#define	IOCOMPLETE_H

#include <cstring>
#include <boost/function.hpp>
#include "IOOperation.h"

class IOBuffer;
class IOManager;

class IOComplete : public IOOperation
{
public:
	/**
	* Constructs a deferred complete() action.
	* @param to_offset absolute offset.
	*/
	IOComplete( std::size_t to_offset );
	virtual ~IOComplete();

	/**
	* Executes the complete() action on the specified IOManager object.
	* @param io pointer to an IOManager object.
	*/
	virtual void execute( IOManager* io );
private:
	IOOffsetAction _action;
	std::size_t _size;
};

#endif	/* IOCOMPLETE_H */

