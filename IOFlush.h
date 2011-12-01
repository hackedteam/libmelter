/*
* IOFlush.h
*
*  Created on: Oct 7, 2010
*      Author: daniele
*/

#ifndef IOFLUSH_H_
#define IOFLUSH_H_

#include <cstring>
#include "IOOperation.h"

class IOBuffer;
class IOManager;

class IOFlush: public IOOperation
{
public:
	/**
	* Constructs a deferred flush operation.
	* @param to_offset an absolute offset.
	*/
	IOFlush( std::size_t to_offset );
	virtual ~IOFlush();

	/**
	* Executes the flush operation on the specified IOManager object.
	* @param io pointer to an IOManager object.
	*/
	virtual void execute( IOManager* io );

private:
	IOOffsetAction _action;
	std::size_t _to_offset;
};

#endif /* IOFLUSH_H_ */
