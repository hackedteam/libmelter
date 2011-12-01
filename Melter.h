/*
 * Melter.h
 *
 *  Created on: Oct 4, 2010
 *      Author: daniele
 */

#ifndef MELTER_H_
#define MELTER_H_

#include "BufferObserver.h"
#include "prototypes.h"

class Chunk;
class IOManager;

class Melter : public ::prototype::BufferObserver
{
public:

    /**
     * Create a new Melter using the specified parser e mangler.
     * @param parser
     * @param mangler
     */
    Melter(::prototype::Parser& parser, ::prototype::Mangler& mangler);
    virtual ~Melter();

    /**
     *
     */
    void update();
	/**
	 *
	 */
	bool isDefective();

    /**
     * Set defective state of Melter. Default argument is true.
     * When in defective state, Melter deregisters itself as observer of the input buffer, and
     * writes are sent directly to output buffer.
     * @param state true to enable defetive state.
     */
    void setDefective(bool state = true);
    
    /**
     * Feed new data for the parser/mangler to process.
     * @param data pointer to buffer containing data to be fed.
     * @param len number of bytes of data in buffer.
     * @return number of bytes written.
     */
    std::size_t write( char const * data, std::size_t len );

    /**
     * Feed a chunk for the parser/mangler to process.
     * @param chunk chunk of data to append.
     * @return number of bytes written.
     */
    std::size_t write( Chunk &chunk );

    /**
     * Check if buffer is empty.
     * @return true if empty, false otherwise.
     */
    bool empty();
    
    /**
     * Gets any available output.
     * @return a chunk of data.
     */
    Chunk read();

private:
    IOManager* _io;

    ::prototype::Parser& _parser;
    ::prototype::Mangler& _mangler;

    bool _defective;
};

#endif /* MELTER_H_ */
