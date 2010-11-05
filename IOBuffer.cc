/*
 * IOBuffer.cpp
 *
 *  Created on: Sep 28, 2010
 *      Author: daniele
 */

#include <cassert>
#include <iostream>
#include <string>
#include <utility>

#include <boost/foreach.hpp>

#include "BufferObserver.h"
#include "IOBuffer.h"
#include "Chunk.h"

std::size_t IOBuffer::append( Chunk &a )
{
    _push_back(a);
    _notify();

    return a.size();
}

std::size_t IOBuffer::prepend( Chunk &a )
{
    _push_front(a);
    _offset -= a.size();

    return a.size();
}

void IOBuffer::_push_back( Chunk &a )
{
    _data.insert( _data.end(), a.ptr(), a.ptr() + a.size() );
}

void IOBuffer::_push_front( Chunk &a )
{
    _data.insert( _data.begin(), a.ptr(), a.ptr() + a.size() );
}

Chunk IOBuffer::pop( std::size_t size )
{
    if ( available(_offset) < size )
        return Chunk( _offset );
    
    Chunk c = Chunk( &_data[0], BufferDescriptor(_offset, size) );
    _data.erase( _data.begin(), _data.begin() + size);
    _offset += size;
    return c;
}

Chunk IOBuffer::range( BufferDescriptor descriptor )
{
    if ( ! this->descriptor().contains( descriptor ) )
        return Chunk( "", BufferDescriptor( descriptor.offset(), 0));
    
    std::size_t index = descriptor.offset() - _offset;
    return Chunk(&_data[index], BufferDescriptor(descriptor.offset(), descriptor.size()) );
}

Chunk IOBuffer::range( std::size_t start_offset, std::size_t size )
{
    return range( BufferDescriptor(start_offset, size) );
}

std::size_t IOBuffer::flush( std::size_t to_offset )
{
    assert( to_offset >= _offset );
    std::size_t size = to_offset - _offset;
    
    // if we don't have enough data for flushing, flush what's available
    if (size > this->size())
        size = this->size();
    
    _data.erase( _data.begin(), _data.begin() + size);
    _offset += size;
    
    return size;
}

std::size_t IOBuffer::available(std::size_t start_offset)
{
    // if the starting offset falls outside our buffer, return 0
    if (start_offset < _offset || start_offset > _offset + this->size())
        return 0;
    else
        return (_offset + _data.size()) - start_offset;
}

void IOBuffer::register_observer( ::prototype::BufferObserver& observer )
{
    //std::cout << "[IOBuffer] registering observer for source buffer." << std::endl;
    _observers.push_front( &observer );
}

void IOBuffer::remove_observer( ::prototype::BufferObserver& observer )
{
    _observers.remove( &observer );
}

void IOBuffer::_notify()
{
    BOOST_FOREACH( ::prototype::BufferObserver* observer, _observers )
        observer->update();
}

IOBuffer::IOBuffer()
: _offset(0)
{
}

IOBuffer::~IOBuffer()
{
}
