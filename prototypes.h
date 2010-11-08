/* 
 * File:   interfaces.h
 * Author: daniele
 *
 * Created on November 3, 2010, 12:25 PM
 */

#ifndef INTERFACES_H
#define	INTERFACES_H

#include <string>
#include <boost/utility.hpp>
#include "BufferDescriptor.h"

class IOBuffer;
class IOManager;
class Chunk;
class BufferObserver;

namespace prototype {

class BufferObserver : boost::noncopyable
{
public:
    virtual ~BufferObserver() {}
    
    /**
     * Function called each time new data will be available in the observed buffer.
     */
    virtual void update() = 0;
};

class IOOperation : boost::noncopyable {
public:
    virtual ~IOOperation() {}
    virtual void execute( IOManager* io ) = 0;
};

class Parser {
public:
    virtual ~Parser() {}

     /**
     * Call the first action registered.
     *
     * @param chunk data on which the action will operate.
     * @return return true if action is completed, false if reparsing needed.
     */
    virtual bool call( Chunk& chunk ) = 0;

    /**
     * Returns a tag identifying the current action.
     * @return a string.
     */
    virtual std::string tag() = 0;

    /**
     * Returns a descriptor identifying the current action.
     * @return a BufferDescriptor.
     */
    virtual BufferDescriptor descriptor() = 0;

    /**
     * Removes the action described by descriptor from the queue.
     * @param descriptor a descriptor identifying the action.
     */
    virtual void expire_action() = 0;
};

class Mangler {
public:
    virtual ~Mangler() {}

    /**
     * Calls the current managler operation, if any available for the specified tag, on the selected chunk.
     * @param io a reference to an IOManager object.
     * @param tag a tag identifying the managling operation to be run.
     * @param chunk a reference to a Chunk.
     * @return true if the action is expired and can be unregistered
     */
    virtual bool call( IOManager& io, std::string tag, Chunk& chunk ) = 0;
};

} // namespace

#endif	/* INTERFACES_H */
