/*
 * File:   ManglerTest.cpp
 * Author: daniele
 *
 * Created on Nobember 02, 2010, 16:50 PM
 */

#include <gtest/gtest.h>
#include "Chunk.h"
#include "Mock.h"
#include "IOManager.h"

using ::testing::_;
using ::testing::An;
using ::testing::Return;

namespace {
    class ManglerTest : public ::testing::Test {
    protected:
        ManglerTest() {}
        virtual ~ManglerTest() {}

        void SetUp() {
        }

        void TearDown() {
        }
        
    };

    TEST_F(ManglerTest, mangler_calls_first_action) {
        MockMangler mangler;
        IOManager io;
        std::string tag = "first";
        
        std::string data = "01234567890";
        Chunk chunk(data.c_str(), data.size());
        
        EXPECT_CALL(mangler, mangleFirst(An<IOManager&>(), chunk))
                .Times(1)
                .WillOnce(Return(true));
        
        EXPECT_TRUE( mangler.call(io, tag, chunk) );
    }
    
    TEST_F(ManglerTest, mangler_calls_second_action) {
        MockMangler mangler;
        IOManager io;
        std::string tag = "second";
        
        std::string data = "01234567890";
        Chunk chunk(data.c_str(), data.size());
        
        EXPECT_CALL(mangler, mangleSecond(An<IOManager&>(), chunk))
                .Times(1)
                .WillOnce(Return(true));
        
        EXPECT_TRUE( mangler.call(io, tag, chunk) );
    }
};
