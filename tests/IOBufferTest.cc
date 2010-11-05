/* 
 * File:   IOBufferTest.h
 * Author: daniele
 *
 * Created on October 11, 2010, 2:56 PM
 */

#include <string>
#include <iostream>

#include <gtest/gtest.h>
#include "Chunk.h"
#include "IOBuffer.h"
#include "Mock.h"

namespace {
    
    class IOBufferTest : public ::testing::Test {
    protected:
        IOBufferTest()
        : stringA("AAAA"), stringB("BB")
        {
        }
        
        virtual ~IOBufferTest() {}
        
        virtual void SetUp()
        {
            chunkA = new Chunk(stringA.c_str(), stringA.size());
            chunkB = new Chunk(stringB.c_str(), stringB.size());
            buffer = new IOBuffer();
        }
        
        virtual void TearDown()
        {
            delete chunkA;
            delete chunkB;
            delete buffer;
        }

        
        Chunk *chunkA, *chunkB;
        const std::string stringA, stringB;
        IOBuffer* buffer;
    };

    /* remove_observer */
    TEST_F(IOBufferTest, observer_survives_removal) {
        MockBufferObserver observer;
        buffer->register_observer(observer);
        buffer->remove_observer(observer);
    }
    
    /* append */
    TEST_F(IOBufferTest, append_to_empty_buffer_triggers_updates) {
        MockBufferObserver observer;
        buffer->register_observer(observer);

        EXPECT_CALL(observer, update())
                .Times(1);
        
        buffer->append(*chunkA);
        EXPECT_EQ( buffer->size(), chunkA->size() );
    }
    
    TEST_F(IOBufferTest, append_to_non_empty_buffer_triggers_updates) {
        MockBufferObserver observer;
        buffer->register_observer(observer);

        EXPECT_CALL(observer, update())
                .Times(2);

        buffer->append(*chunkA);
        buffer->append(*chunkB);
        
        EXPECT_EQ( buffer->size(), chunkA->size() + chunkB->size() );
    }
    
    /* prepend */
    TEST_F(IOBufferTest, prepend) {
        buffer->prepend(*chunkA);
        
        EXPECT_EQ( memcmp(chunkA->ptr(), buffer->ptr(), chunkA->size()), 0 );
    }
    
    /* pop */
    TEST_F(IOBufferTest, popping_from_empty_buffer_returns_empty_chunk_with_offset) {
        Chunk chunk = buffer->pop(10);

        EXPECT_EQ( chunk.descriptor().offset(), buffer->offset() );
        EXPECT_EQ( chunk.size(), 0 );
    }
    
    /* range */
    TEST_F(IOBufferTest, range) {
         Chunk chunk = buffer->range( buffer->offset(), buffer->size() );
         
         EXPECT_EQ( buffer->offset(), chunk.offset() );
         EXPECT_EQ( buffer->size(), chunk.size() );
    }

    TEST_F(IOBufferTest, invalid_range_return_chunk_of_zero_size_and_request_offset) {
         Chunk chunk = buffer->range( 31337, 1 );
         EXPECT_EQ( chunk.offset(), 31337 );
         EXPECT_EQ( chunk.size(), 0 );
    }

    /* flush */
    TEST_F(IOBufferTest, flushing_an_empty_buffer_does_nothing) {
        char* ptr = buffer->ptr();
        std::size_t offset = buffer->offset();
        std::size_t size = buffer->size();

        buffer->flush( 31337 );
        
        EXPECT_EQ( offset, buffer->offset() );
        EXPECT_EQ( size, buffer->size() );
        EXPECT_EQ( ptr, buffer->ptr() );
    }
    
    TEST_F(IOBufferTest, flush) {
        buffer->append(*chunkA);
        
        std::size_t offset = 2;
        ASSERT_TRUE( offset < stringA.size() );
        
        buffer->flush( offset );
        EXPECT_EQ( buffer->offset(), offset );
        EXPECT_EQ( memcmp( buffer->ptr(), stringA.c_str() + offset, stringA.size() - offset ), 0 );
    }
    
    /* available */
    TEST_F(IOBufferTest, asking_for_available_offset_after_returns_zero) {
        // make sure offset falls within buffer
        EXPECT_EQ( 0, buffer->available(31337));
    }

    TEST_F(IOBufferTest, asking_for_available_offset_before_returns_zero) {
        EXPECT_EQ( 0, buffer->available(-1));
    }
    
    TEST_F(IOBufferTest, asking_for_available_zero_offset_returns_size) {
        buffer->append(*chunkA);
        EXPECT_EQ( buffer->size(), buffer->available(0) );
    }

    TEST_F(IOBufferTest, asking_for_available_offset_falling_within_buffer_returns_diff_size) {
        buffer->append(*chunkA);

        std::size_t start_offset = 2;
        std::size_t diff_size = chunkA->size() - start_offset;

        EXPECT_EQ( diff_size, buffer->available( start_offset ) );
    }
    
    /* ptr */
    TEST_F(IOBufferTest, asking_for_ptr_to_empty_buffer_returns_zero) {
        ASSERT_EQ( NULL, buffer->ptr() );
    }
    
    TEST_F(IOBufferTest, asking_for_ptr_to_buffer_returns_something) {
        buffer->append(*chunkA);
        ASSERT_TRUE( NULL != buffer->ptr() );
    }

    /* offset */
    TEST_F(IOBufferTest, offset_to_empty_buffer_returns_zero) {
        ASSERT_EQ( 0, buffer->offset() );
    }

    TEST_F(IOBufferTest, offset_to_unused_buffer_returns_zero) {
        buffer->append(*chunkA);
        ASSERT_EQ( 0, buffer->offset() );
    }
}
