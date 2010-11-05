/*
 * Chunk.h
 *
 *  Created on: Sep 28, 2010
 *      Author: daniele
 */

#ifndef CHUNK_H_
#define CHUNK_H_

#include <vector>
#include "BufferDescriptor.h"

class Chunk
{
public:
        /**
         * Constructs an empty buffer, with no data, offset and size set to 0.
         * It's possibile to specify a custom offset for consistency when returning an empty chunk.
         * @param offset an offset
         */
	Chunk( std::size_t offset = 0 );
        
        /**
         * Construct a chunk of data.
         * @param data a buffer of bytes.
         * @param descriptor a descriptor containing the absolute offset and the size of the data.
         */
	Chunk(char const * data, BufferDescriptor descriptor);

        /**
         * Construct a chunk of data.
         * @param data a buffer of bytes.
         * @param size the size of the data contained in the buffer.
         */
        Chunk(char const * data, std::size_t size);
        
	virtual ~Chunk();

        /**
         * Gives a pointer to the data contained in the buffer.
         * @return a pointer to buffer.
         */
	char* ptr() { return &_data[0]; }

        /**
         * Gives a reference to internal vector (used for storing data).
         * @return a reference to vector<char>
         */
        const std::vector<char>& vector() const { return _data; }
        
        /**
         * Gives a pointer to const data.
         * @return a pointer to const.
         */
        char const * const_ptr() { return &_data[0]; }
        
        /**
         * Tells the offset of the Chunk.
         * @return an absolute offset.
         */
	std::size_t offset() { return _descriptor.offset(); }
        
        /**
         * Tells the size of the data contained in the Chunk.
         * @return a size in bytes.
         */
	std::size_t size() { return _descriptor.size(); }

        bool equal(const Chunk& another) const
        {
            bool descriptor_equal = ( descriptor() == another.descriptor() );
            bool content_equal = ( vector() == another.vector() );
            return ( descriptor_equal && content_equal );
        }
        
        /**
         * Tells the descriptor of the Chunk.
         * @return a buffer descriptor.
         */
	BufferDescriptor descriptor() const { return _descriptor; }

        bool operator==(Chunk const & another)
        {
            return equal(another);
        }
        
private:
	std::vector<char> _data;
	BufferDescriptor _descriptor;
};

#if 0
template <typename T>
class CastedChunk : public Chunk {
    T& casted_data() { return static_cast<T>( this->ptr() ); }
};
#endif

#endif /* CHUNK_H_ */
