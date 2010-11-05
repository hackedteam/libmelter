/*
 * Command.h
 *
 *  Created on: Oct 7, 2010
 *      Author: daniele
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <iostream>
#include "prototypes.h"

class Chunk;
class IOManager;

typedef void (IOManager::* IOOffsetAction)(std::size_t);
typedef void (IOManager::* IOChunkAction)(Chunk& chunk);

class IOOperation : public ::prototype::IOOperation
{
public:
    IOOperation();
    virtual ~IOOperation();
    
    /**
     * Execute the action implemented by the IOOperation on a specific IOManager.
     * @param io object on which the operation will be executed.
     */
    virtual void execute( IOManager* io );
};

#endif /* COMMAND_H_ */
