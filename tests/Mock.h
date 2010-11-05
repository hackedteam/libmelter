/* 
 * File:   Mock.h
 * Author: daniele
 *
 * Created on November 3, 2010, 3:01 PM
 */

#ifndef MOCK_H
#define	MOCK_H

#include <gmock/gmock.h>
#include "Chunk.h"
#include "IOManager.h"
#include "Mangler.h"
#include "Parser.h"
#include "prototypes.h"

class MockBufferObserver : public ::prototype::BufferObserver {
public:
    virtual ~MockBufferObserver() { }
    MOCK_METHOD0(update, void());
};

class MockIOOperation : public ::prototype::IOOperation {
public:
    virtual ~MockIOOperation() {}
    MOCK_METHOD1(execute, void( IOManager* ));
};

REGISTER_PARSER(MockParser);
class MockParser : public ::prototype::Parser {
public:
    PARSER(MockParser);

    virtual ~MockParser() {}
    MockParser() {
        // REGISTER_PARSE_ACTION( <offset>, <size>, <tag>, <fn> )
        REGISTER_PARSE_ACTION( 0, 10, "first", &MockParser::parseFirst );
        REGISTER_PARSE_ACTION( 11, 10, "second", &MockParser::parseSecond );
        REGISTER_PARSE_ACTION( 21, 10, "third", &MockParser::parseThird);
    }
    
    MOCK_METHOD1(parseFirst, bool(Chunk&));
    MOCK_METHOD1(parseSecond, bool(Chunk&));
    MOCK_METHOD1(parseThird, bool(Chunk&));
};

REGISTER_MANGLER(MockMangler);
class MockMangler : public ::prototype::Mangler {
public:
    MANGLER(MockMangler);

    virtual ~MockMangler() {}
    MockMangler() {
        REGISTER_MANGLE_ACTION("first", &MockMangler::mangleFirst);
        REGISTER_MANGLE_ACTION("second", &MockMangler::mangleSecond);
    }
    
    MOCK_METHOD2(mangleFirst, bool(IOManager&, Chunk&));
    MOCK_METHOD2(mangleSecond, bool(IOManager&, Chunk&));
};

#endif	/* MOCK_H */

