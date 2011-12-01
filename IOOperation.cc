/*
* Command.cpp
*
*  Created on: Oct 7, 2010
*      Author: daniele
*/
#include <stdexcept>
#include "IOOperation.h"

IOOperation::IOOperation()
{
}

IOOperation::~IOOperation()
{
}

void IOOperation::execute( IOManager* io )
{
	throw std::runtime_error("Not implemented!");
}
