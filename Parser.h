/* 
* File:   Parser.h
* Author: daniele
*
* Created on October 12, 2010, 1:45 PM
*/

#ifndef PARSER_H
#define	PARSER_H

#include <map>
#include <string>
#include "prototypes.h"

class Chunk;

/**
* A Parser object is in charge for parsing incoming data and storing parsed data to be used by a Mangler object.
* The class must be inherited and all of its method implemented.
*/

#define REGISTER_PARSER(klass) \
class klass; \
	typedef bool (klass::* ParsingFunction)( Chunk& );

#define CURRENT_PARSER_DESCRIPTOR(parser) ( *( parser->actions.begin() ) ).first
#define CURRENT_PARSER_TAG(parser) ( *( parser->actions.begin() ) ).second.first
#define CURRENT_PARSER_FN(parser) ( *( parser->actions.begin() ) ).second.second

#define REGISTER_PARSE_ACTION(offset, size, tag, fn) do { actions.insert( std::make_pair(BufferDescriptor(offset, size), std::make_pair( tag, fn ) ) ); } while(0)
#define EXPIRE_PARSE_ACTION( parser ) do { parser->actions.erase( CURRENT_PARSER_DESCRIPTOR( parser ) ); } while (0)

#define ACTIONS_AVAILABLE( parser ) parser->actions.empty()
#define NUMBER_OF_ACTIONS(parser) parser->actions.size()

#define CALL_PARSER(result, parser, chunk) do {                              \
	ParsingFunction fn = CURRENT_PARSER_FN(parser);   \
	result = (parser->* fn)(chunk);                                          \
} while (0)

#define PARSER(klass) \
	std::map< BufferDescriptor, std::pair<std::string, ParsingFunction> > actions; \
	bool defective; \
	\
	virtual bool call( Chunk& chunk ) { \
	bool result = false; \
	CALL_PARSER(result, this, chunk); \
	return result; \
} \
	virtual std::string tag() { \
	return CURRENT_PARSER_TAG(this); \
} \
	virtual BufferDescriptor descriptor() { \
	return CURRENT_PARSER_DESCRIPTOR(this); \
} \
	virtual void expire_action() { \
	EXPIRE_PARSE_ACTION( this ); \
} \
	virtual std::size_t num_registered_actions() { return actions.size(); } \
	virtual bool is_defective() { return defective; } \

#endif	/* PARSER_H */
