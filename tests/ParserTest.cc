/* 
 * File:   ParserTest.cpp
 * Author: daniele
 * 
 * Created on October 13, 2010, 10:44 AM
 */

#include <gtest/gtest.h>
#include "Chunk.h"
#include "Mock.h"

using ::testing::Return;

namespace {
    class ParserTest : public ::testing::Test {
    protected:
        ParserTest() {}
        virtual ~ParserTest() {}

        void SetUp() {
        }

        void TearDown() {
        }
    };
    
    TEST_F(ParserTest, test_first_action_returning_true) {
        MockParser parser;
        
        std::string data = "01234567890";
        Chunk chunk(data.c_str(), data.size());
        
        EXPECT_CALL(parser, parseFirst(chunk))
                .Times(1)
                .WillOnce(Return(true));
        
        EXPECT_TRUE( parser.call(chunk) );
    }
    
    TEST_F(ParserTest, test_first_action_returning_false) {
        MockParser parser;

        std::string data = "0123456789";
        Chunk chunk(data.c_str(), data.size());

        EXPECT_CALL(parser, parseFirst(chunk))
                .Times(1)
                .WillOnce(Return(false));
        
        EXPECT_FALSE( parser.call(chunk) );
    }
    
    TEST_F(ParserTest, expire_action) {
        MockParser parser;
        std::size_t original_num_registered_actions = parser.num_registered_actions();
        
        parser.expire_action();

        EXPECT_EQ( original_num_registered_actions -1 , parser.num_registered_actions() );
    }

    TEST_F(ParserTest, expiring_action_exposes_following_action) {
        MockParser parser;
        std::size_t original_num_registered_actions = parser.num_registered_actions();
        
        parser.expire_action();
        
        EXPECT_EQ( original_num_registered_actions -1, parser.num_registered_actions() );
        EXPECT_STREQ( "second", parser.tag().c_str() );
        EXPECT_TRUE( parser.descriptor() == BufferDescriptor(11, 10) );
    }
    
    TEST_F(ParserTest, tag) {
        MockParser parser;

        EXPECT_STREQ( "first", parser.tag().c_str() );
    }
    
    TEST_F(ParserTest, descriptor) {
        MockParser parser;
        
        EXPECT_TRUE( BufferDescriptor(0, 10) == parser.descriptor() );
    }
};
