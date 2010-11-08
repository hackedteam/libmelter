/* 
 * File:   IOManagerTest.h
 * Author: daniele
 *
 * Created on October 11, 2010, 5:11 PM
 */

#include <string>

#include "IOManager.h"
#include <gtest/gtest.h>

#include "Mock.h"

#include "Chunk.h"
#include "prototypes.h"

// forward declaration of mock classese test

namespace {
    
    class IOManagerTest : public ::testing::Test {
    protected:
        IOManagerTest() {}
        virtual ~IOManagerTest() {}
        
        virtual void SetUp() {
            io = new IOManager();
            
            offset = 31337;
            stringA = "test123";
            chunkA = new Chunk( stringA.c_str(), BufferDescriptor( offset, stringA.size() ) );
            emptyChunk = new Chunk();
        }
        
        virtual void TearDown() {
            delete io;
            delete emptyChunk;
        }
        
        
        Chunk *chunkA, *emptyChunk;
        std::string stringA;
        IOBuffer* buffer;
        std::size_t offset;
        IOManager* io;
    };
    
    // TESTS
    TEST_F(IOManagerTest, add_a_pending_operation) {
        MockIOOperation *op = new MockIOOperation();
        
        EXPECT_EQ( io->num_pending_operations(), 0 );
        io->queue_operation(op);
        EXPECT_EQ( io->num_pending_operations(), 1 );       
    }
    
    TEST_F(IOManagerTest, process_pending_executes_actions_then_clears_pending) {
        MockIOOperation *op = new MockIOOperation();

        io->queue_operation(op);
        ASSERT_EQ( io->num_pending_operations(), 1 );

        EXPECT_CALL(*op, execute(io))
                .Times(1);
        
        io->process_pending();
        EXPECT_EQ( io->num_pending_operations(), 0 );
    }

    TEST_F(IOManagerTest, empty) {
        EXPECT_EQ( true, io->empty() );
    }
}
