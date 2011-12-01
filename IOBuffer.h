/*
* IOBuffer.h
*
*  Created on: Sep 28, 2010
*      Author: daniele
*/

#ifndef IOBUFFER_H_
#define IOBUFFER_H_

#include <cstring>
#include <list>
#include <vector>

#include "BufferDescriptor.h"
#include "BufferObserver.h"
#include "prototypes.h"

class Chunk;

class IOBuffer
{
public:
	/**
	* Registers an observer to be notified when the buffer is updated with new data.
	* @param observer the object to be notified (must inherit from BufferObserver).
	*/
	void register_observer( ::prototype::BufferObserver& observer );

	/**
	* Deregisters an observer.
	* @param observer the object to be removed (must inherit from BufferObserver).
	*/
	void remove_observer( ::prototype::BufferObserver& observer );

	/**
	* Appends data to the buffer.
	* @param chunk chunk of data to be appended.
	*/
	std::size_t append( Chunk &chunk );

	/**
	* Prepends data to the buffer.
	* @param chunk chunk of data to be prepended.
	*/
	std::size_t prepend( Chunk &chunk );

	/**
	* Gets a chunk containing all available data in the buffer.
	* Offset will always be equal to the starting offset of the buffer (even if buffer is empty).
	* @param size number of bytes.
	* @return a chunk containing the data.
	*/
	Chunk pop( std::size_t size );

	/**
	* Get data from the buffer at the descriptor specified range
	* @param descriptor descriptor specifying the range.
	* @return a chunk containing the data.
	*/
	Chunk range( BufferDescriptor descriptor );

	/**
	* Get data from the buffer at the range specified using an absolute offset and size.
	* @param start_offset starting offset.
	* @param size size in bytes.
	* @return a chunk containing the data.
	*/
	Chunk range( std::size_t start_offset, std::size_t size);

	/**
	* Discards data from the buffer up to the specified absolute offset.
	* @param to_offset an offset.
	* @return number of bytes flushed.
	*/
	std::size_t flush( std::size_t to_offset );

	/**
	* Returns the size available starting at the specified offset.
	* @param start_offset an offset.
	* @return available number of bytes.
	*/
	std::size_t available(std::size_t start_offset);

	/**
	* Gives a pointer to the start of the buffer.
	* @return a pointer if buffer is not empty, otherwise NULL.
	*/
	char* ptr() { if (this->size() == 0) return NULL; return &_data[0]; }

	/**
	* Tells if buffer is empty.
	* @return true if empty, false otherwise.
	*/
	bool empty() const { return _data.size() == 0 ? true : false; }

	/**
	* Tells the size of the buffer in bytes.
	* @return available number of bytes.
	*/
	std::size_t size() const { return _data.size(); }

	/**
	* Tells the current offset in the buffer.
	* @return an absolute offset.
	*/
	std::size_t offset() const { return _offset; }

	/**
	* Gives a descriptor of the buffer.
	* @return a BufferDescriptor.
	*/
	BufferDescriptor descriptor() { return BufferDescriptor(_offset, _data.size()); }

	/**
	* Checks if a specified buffer is contained in this buffer.
	* @param descriptor a descriptor for the buffer to be checked.
	* @return true if the buffer is contained, false otherwise.
	*/
	bool contains( BufferDescriptor descriptor ) { return this->descriptor().contains( descriptor ); }
	//std::string to_string() { return std::string("buffer ") + descriptor().to_string(); }

	/**
	* Builds an empty buffer.
	*/
	IOBuffer();
	virtual ~IOBuffer();

private:
	void _notify();

	void _push_back( Chunk &a );
	void _push_front( Chunk &a );

	std::vector<char> _data;
	std::size_t _offset;

	std::list< ::prototype::BufferObserver* > _observers;
};

#endif /* IOBUFFER_H_ */
