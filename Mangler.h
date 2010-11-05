/* 
 * File:   Mangler.h
 * Author: daniele
 *
 * Created on October 12, 2010, 2:40 PM
 */

#ifndef MANGLER_H
#define	MANGLER_H

#include <map>
#include <string>
#include "prototypes.h"

class Chunk;
class IOManager;

#define REGISTER_MANGLER(klass)                                 \
    class klass;                                                \
    typedef bool (klass::* ManglingFunction)( IOManager&, Chunk& );

#define REGISTER_MANGLE_ACTION(tag, fn) do { actions.insert( std::make_pair(tag, fn) ); } while(0)

#define MANGLER(klass)                                          \
    std::map< std::string, ManglingFunction > actions;          \
                                                                \
    virtual bool call( IOManager& io, std::string tag, Chunk& chunk ) { \
        if ( actions.find(tag) == actions.end() ) return false; \
        ManglingFunction fn = this->actions[tag];               \
        bool result = (this->* fn)(io, chunk);                  \
        return result;                                          \
    }                                                           \
                                                                \
    virtual std::size_t num_registered_actions() { return actions.size(); }

#endif	/* MANGLER_H */

