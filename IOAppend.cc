/* 
* File:   IOAppend.cpp
* Author: daniele
* 
* Created on October 12, 2010, 10:18 AM
*/

#include "IOAppend.h"
#include "IOManager.h"

IOAppend::IOAppend( Chunk& chunk )
	: IOOperation(), _action(&IOManager::append), _chunk(chunk)
{
}

IOAppend::~IOAppend() {
}

void IOAppend::execute( IOManager* io )
{
	(io->*_action)(_chunk);
}

