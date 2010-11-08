/* 
 * File:   MelterTest.cpp
 * Author: daniele
 * 
 * Created on October 14, 2010, 5:32 PM
 */

#include <gtest/gtest.h>
#include "Mock.h"
#include "Chunk.h"
#include "IOManager.h"
#include "Melter.h"

using ::testing::An;
using ::testing::Return;

namespace {
    class MelterTest : public ::testing::Test {
    protected:
        MelterTest() {}
        virtual ~MelterTest() {}
        
        void SetUp() {
            melter = new Melter(parser, mangler);
        }
        
        void TearDown() {
            delete melter;
        }
        
        MockParser parser;
        MockMangler mangler;
        Melter* melter;
    };
    
    TEST_F(MelterTest, matching_chunk_parser_then_mangler_called) {
        std::string testString = "0123456789";
        
        EXPECT_CALL(parser, parseFirst(An<Chunk&>()))
                .Times(1)
                .WillOnce(Return(true));
        
        EXPECT_CALL(mangler, mangleFirst(An<IOManager&>(), An<Chunk&>()))
                .Times(1)
                .WillOnce(Return(true));
        
        melter->write(testString.c_str(), testString.size());
        
        EXPECT_STREQ("second", parser.tag().c_str());
    }
    
    TEST_F(MelterTest, nonmatching_chunk_does_not_trigger_melter) {
        std::string testString = "012345678";
        
        EXPECT_CALL(parser, parseFirst(An<Chunk&>()))
                .Times(0);

        EXPECT_CALL(mangler, mangleFirst(An<IOManager&>(), An<Chunk&>()))
                .Times(0);
        
        melter->write(testString.c_str(), testString.size());
        
        EXPECT_STREQ("first", parser.tag().c_str());
    }
    
    // TODO test con parser ma senza azioni mangle associate
    TEST_F(MelterTest, chunk_is_parsed_but_no_mangling_associated) {
        
    }
}
