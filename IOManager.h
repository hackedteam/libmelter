/*
 * IOManager.h
 *
 *  Created on: Oct 1, 2010
 *      Author: daniele
 */

#ifndef IOMANAGER_H_
#define IOMANAGER_H_

#include <list>
#include <boost/ptr_container/ptr_list.hpp>

#include "BufferDescriptor.h"
#include "BufferObserver.h"
#include "IOBuffer.h"
#include "prototypes.h"

class Chunk;
class IOOperation;

class IOManager
{
public:
    IOManager();
    virtual ~IOManager();

    /**
     * Check if a specific Chunk is available from the input buffer.
     * @param descriptor A descriptor for the chunk of data to be checked for availability
     * @return true if chunk is available, false otherwise.
     */
    bool available( BufferDescriptor descriptor );

    /**
     * Appends a Chunk to the input buffer.
     * @param c the Chunk to be appended.
     * @return number of bytes appended.
     */
    std::size_t append_to_input( Chunk& c );
    
    /**
     * Checks if output buffer is empty (if true, use read_from_output to get data).
     * @return true if there is data to read, false if empty.
     */
    bool empty() { return _output->empty(); }
    
    /**
     * Reads all the available data from the output buffer.
     * @return A Chunk of data.
     */
    Chunk read_from_output();

    /**
     * Reads a specific Chunk from the input buffer.
     * @param descriptor descriptor for the Chunk to be read.
     * @return A Chunk of data.
     */
    Chunk read_for_parsing( BufferDescriptor descriptor );

    /**
     * Queues an IO operation to be executed later.
     * @param operation A pointer to the IOOperation to be queued.
     */
    void queue_operation( ::prototype::IOOperation* operation );

    /**
     * Returns the number of pending operations.
     * @return number of pending operations.
     */
    std::size_t num_pending_operations() { return _pending_operations.size(); }
    
    /**
     * Queues a flush operation for deferred execution.
     * @param to_offset
     */
    void queue_flush( std::size_t to_offset );
    
    /**
     * Processes all pending IO operations in order of insertion.
     */
    void process_pending();

    /**
     * Registers a BufferObserver object whose update() method will be called when new data is available
     * in the input buffer.
     * @param observer The BufferObserver object to be notified.
     */
    void register_source_observer( ::prototype::BufferObserver& observer );

    /**
     * Unregister a BufferObserver object previously registered calling register_source_observer.
     * @param observer The BufferObserver object to be deregistered.
     */
    void remove_source_observer( ::prototype::BufferObserver& observer );

    /**
     * Tells the input buffer to discard all the data up to the specified offset.
     * @param to_offset
     */
    void flush(std::size_t to_offset);

    /**
     * Moves data up to the specified offset from the input buffer to the output buffer.
     * @param size
     */
    void complete(std::size_t size);

    /**
     * Appends some data to the output buffer.
     * @param chunk The Chunk of data to be appended.
     */
    void append( Chunk& chunk );

    /**
     * Returns a const reference to the input buffer.
     * @return An IOBuffer reference.
     */
    IOBuffer& input() const { return *_input; }

     /**
     * Returns a const reference to the output buffer.
     * @return An IOBuffer reference.
     */
    IOBuffer& output() const { return *_output; }

    bool operator==(IOManager const & another ) const {
        bool input = (_input == another._input);
        bool output = (_output == another._output);
        
        return ( input && output );
    }
    
private:
   IOBuffer* _input;
   IOBuffer* _output;
   
   boost::ptr_list< ::prototype::IOOperation > _pending_operations;
};

#endif /* IOMANAGER_H_ */
