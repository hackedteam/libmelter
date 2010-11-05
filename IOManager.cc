/*
 * IOManager.cpp
 *
 *  Created on: Oct 1, 2010
 *      Author: daniele
 */

#include <string>
#include <iostream>

#include <boost/foreach.hpp>

#include "Chunk.h"
#include "IOManager.h"
#include "IOBuffer.h"
#include "IOFlush.h"
#include "IOOperation.h"

IOManager::IOManager()
{
    _input = new IOBuffer();
    _output = new IOBuffer();
}

IOManager::~IOManager()
{
    delete _input;
    delete _output;
}

bool IOManager::available( BufferDescriptor descriptor )
{
    return _input->contains( descriptor );
}

void IOManager::register_source_observer( ::prototype::BufferObserver& observer )
{
    _input->register_observer(observer);
}

void IOManager::remove_source_observer( ::prototype::BufferObserver& observer )
{
    _input->remove_observer(observer);
}

std::size_t IOManager::append_to_input( Chunk& c )
{
    return _input->append( c );
}

Chunk IOManager::read_for_parsing( BufferDescriptor descriptor )
{
    return _input->range(descriptor);
}

Chunk IOManager::read_from_output()
{
    Chunk chunk = _output->pop( _output->available( _output->offset() ) );
    return chunk;
}

void IOManager::queue_operation( ::prototype::IOOperation* operation )
{
    _pending_operations.push_front(operation);
}

void IOManager::queue_flush( std::size_t to_offset )
{
    queue_operation( new IOFlush( to_offset) );
}

void IOManager::process_pending()
{
    BOOST_FOREACH( ::prototype::IOOperation& command, _pending_operations ) {
        command.execute(this);
    }
    _pending_operations.clear();
}

void IOManager::flush(std::size_t to_offset)
{
    _input->flush(to_offset);
}

void IOManager::complete(std::size_t size)
{
    Chunk chunk = Chunk(_input->ptr(), size);
    _output->append( chunk );
}

void IOManager::append( Chunk& chunk )
{
    _output->append( chunk );
}
