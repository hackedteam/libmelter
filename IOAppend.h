/* 
 * File:   IOAppend.h
 * Author: daniele
 *
 * Created on October 12, 2010, 10:18 AM
 */

#ifndef IOAPPEND_H
#define	IOAPPEND_H

#include "IOOperation.h"
#include "Chunk.h"

class IOManager;

class IOAppend : public IOOperation {
public:
    /**
     * Constructs a deferred append operation.
     * @param chunk reference to the Chunk to be appended.
     */
    IOAppend( Chunk& chunk );
    virtual ~IOAppend();

    /**
     * Executes the append action on the specified IOManager object.
     * @param io pointer to an IOManager object.
     */
    virtual void execute( IOManager* io );
private:

    IOChunkAction _action;
    Chunk _chunk;
};

#endif	/* IOAPPEND_H */

