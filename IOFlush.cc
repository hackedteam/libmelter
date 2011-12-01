/*
* IOFlush.cpp
*
*  Created on: Oct 7, 2010
*      Author: daniele
*/

#include <string>
#include <iostream>

#include <boost/bind.hpp>

#include "IOBuffer.h"
#include "IOFlush.h"
#include "IOManager.h"

IOFlush::IOFlush( std::size_t to_offset )
	: IOOperation(), _action(&IOManager::flush), _to_offset(to_offset)
{
}

IOFlush::~IOFlush()
{
}

void IOFlush::execute( IOManager* io )
{
	(io->*_action)(_to_offset);
}
