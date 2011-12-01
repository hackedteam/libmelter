/*
* BufferObserver.h
*
*  Created on: Sep 30, 2010
*      Author: daniele
*/

#ifndef BUFFEROBSERVER_H_
#define BUFFEROBSERVER_H_

#if 0

#include <boost/utility.hpp>

#include "BufferDescriptor.h"

class Chunk;
class IOManager;

/**
* A virtual class used to implement objects willing to observe a buffer and be notified upon new data availability.
* A class inheriting from BufferObserver must implement its own update() method, which will be called each time
* new data will be available in the observed buffer.
*/

class BufferObserver : boost::noncopyable
{
public:
	/**
	* Function called each time new data will be available in the observed buffer.
	*/
	virtual void update();

	BufferObserver();
	virtual ~BufferObserver();
};

#endif

#endif /* BUFFEROBSERVER_H_ */
