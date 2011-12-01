/*
* BufferDescriptor.h
*
*  Created on: Sep 30, 2010
*      Author: daniele
*/

#ifndef BUFFERDESCRIPTOR_H_
#define BUFFERDESCRIPTOR_H_

#include <cstring>

/**
* BufferDescriptor is used to provide a consistent description of a buffer, identified by starting offset and size.
*/

class BufferDescriptor {
public:
	/**
	* Constructs a descriptor with offset and size set to 0.
	*/
	BufferDescriptor() : _offset(0), _size(0) {}

	/**
	* Constructs a buffer with the specified starting offset and size.
	* @param start_offset an absolute offset.
	* @param size the size in bytes.
	*/
	BufferDescriptor(std::size_t start_offset, std::size_t size)
		: _offset(start_offset), _size(size) {}

	virtual ~BufferDescriptor() {}

	/**
	* Tells the absolute offset of the buffer. May be zero if buffer wasn't taken out from a source buffer,
	* otherwise may indicate the original position within the source buffer.
	* @return the absolute offset.
	*/
	std::size_t offset() const { return _offset; }

	/**
	* Tells the size of the buffer, in bytes.
	* @return a size in bytes.
	*/
	std::size_t size() const { return _size; }

	/**
	* Tells the absolute offset at which the buffer begins.
	* @return an absolute offset.
	*/
	std::size_t begin() const { return offset(); }

	/**
	* Tells the absolute offset at which the buffer ends.
	* @return an absolute offset.
	*/
	std::size_t end() const { return offset() + size(); }

	/**
	* Tells if a specific buffer is contained within this buffer.
	* @param other a descriptor for the buffer to be tested.
	* @return true if the tested buffer is contained, false otherwise.
	*/
	bool contains(BufferDescriptor& other) const
	{
		if ( other.begin() >= begin() && other.end() <= end() )
			return true;
		return false;
	}

	bool operator==(BufferDescriptor const & another) const
	{
		return ( offset() == another.offset() && size() == another.size() );
	}

	bool operator<(BufferDescriptor const & another) const
	{
		return ( offset() < another.offset() );
	}

private:
	std::size_t _offset;
	std::size_t _size;
};

#endif /* BUFFERDESCRIPTOR_H_ */
