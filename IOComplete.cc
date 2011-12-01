/* 
* File:   IOComplete.cpp
* Author: daniele
* 
* Created on October 12, 2010, 9:48 AM
*/

#include "IOComplete.h"
#include "IOManager.h"

IOComplete::IOComplete( std::size_t size )
	: IOOperation(), _action(&IOManager::complete), _size(size)
{
}

IOComplete::~IOComplete() {
}

void IOComplete::execute(IOManager* io)
{
	(io->*_action)(_size);
}
