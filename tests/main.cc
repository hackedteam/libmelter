/*
 * File:   runner.cpp
 * Author: daniele
 *
 * Created on Oct 11, 2010, 2:16:04 PM
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
