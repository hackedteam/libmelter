/* 
 * File:   BufferDescriptorTest.h
 * Author: daniele
 *
 * Created on October 11, 2010, 2:31 PM
 */

#include <iostream>
#include <string>

#include "BufferDescriptor.h"
#include <gtest/gtest.h>

namespace {
    class BufferDescriptorTest : public ::testing::Test {
    protected:
        BufferDescriptorTest() {}
        virtual ~BufferDescriptorTest() {}

        virtual void SetUp()
        {
            _descriptor = new BufferDescriptor(31337, 100);
            _emptyDescriptor = new BufferDescriptor();
        }

        virtual void TearDown()
        {
            delete _descriptor;
            delete _emptyDescriptor;
        }

        BufferDescriptor* _descriptor;
        BufferDescriptor* _emptyDescriptor;
    };

    TEST_F(BufferDescriptorTest, offset) {
        EXPECT_EQ( _descriptor->offset(), 31337 );
    }

    TEST_F(BufferDescriptorTest, empty_offset_is_zero) {
        EXPECT_EQ( _emptyDescriptor->offset(), 0 );
    }

    TEST_F(BufferDescriptorTest, size) {
        EXPECT_EQ( _descriptor->size(), 100 );
    }

    TEST_F(BufferDescriptorTest, empty_size_is_zero) {
        EXPECT_EQ( _emptyDescriptor->size(), 0 );
    }

    TEST_F(BufferDescriptorTest, begin) {
        EXPECT_EQ( _descriptor->begin(), 31337 );
    }

    TEST_F(BufferDescriptorTest, empty_begin_is_zero) {
        EXPECT_EQ( _emptyDescriptor->begin(), 0 );
    }

    TEST_F(BufferDescriptorTest, end) {
        EXPECT_EQ( _descriptor->end(), 31437 );
    }

    TEST_F(BufferDescriptorTest, empty_end_is_zero) {
        EXPECT_EQ( _emptyDescriptor->begin(), 0 );
    }

    TEST_F(BufferDescriptorTest, contains_self) {
        BufferDescriptor descriptor(31337, 100);
        EXPECT_EQ( _descriptor->contains( descriptor ), true );
    }

    TEST_F(BufferDescriptorTest, contains_one_byte_after_begin) {
        BufferDescriptor descriptor(31337, 1);
        EXPECT_EQ( _descriptor->contains( descriptor ), true );
    }

    TEST_F(BufferDescriptorTest, contains_one_byte_before_end) {
        BufferDescriptor descriptor(31436, 1);
        EXPECT_EQ( _descriptor->contains( descriptor ), true );
    }

    TEST_F(BufferDescriptorTest, doesnt_contain_a_buffer_starting_at_begin_but_bigger) {
        BufferDescriptor descriptor(31337, 200);
        EXPECT_EQ( _descriptor->contains( descriptor ), false );
    }

    TEST_F(BufferDescriptorTest, doesnt_contain_a_buffer_crossing_begin) {
        BufferDescriptor descriptor(31336, 2);
        EXPECT_EQ( _descriptor->contains( descriptor ), false );
    }

    TEST_F(BufferDescriptorTest, doesnt_contain_a_buffer_crossing_end) {
        BufferDescriptor descriptor(31436, 2);
        EXPECT_EQ( _descriptor->contains( descriptor ), false );
    }

    TEST_F(BufferDescriptorTest, always_contain_an_empty_buffer) {
        BufferDescriptor descriptor(0, 0);
        EXPECT_EQ( _emptyDescriptor->contains( descriptor ), true );
    }

    TEST_F(BufferDescriptorTest, doesnt_contain_a_buffer_with_zero_offset) {
        BufferDescriptor descriptor(0, 2);
        EXPECT_EQ( _emptyDescriptor->contains( descriptor ), false );
    }

    TEST_F(BufferDescriptorTest, doesnt_contain_a_buffer_with_negative_offset) {
        BufferDescriptor descriptor(-1, 2);
        EXPECT_EQ( _emptyDescriptor->contains( descriptor ), false );
    }
}
