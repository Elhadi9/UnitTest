#include <gtest/gtest.h>
#include "Box.h"

// Test fixture for Box class
class BoxTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset object count before each test
        Box::objectCount = 0;
    }
};

// Positive Test Case: Default constructor
TEST_F(BoxTest, DefaultConstructor) {
    Box box;
    EXPECT_EQ(box.Volume(), 8.0); // 2.0 * 2.0 * 2.0
    EXPECT_EQ(Box::getCount(), 1);
}

// Positive Test Case: Parameterized constructor
TEST_F(BoxTest, ParameterizedConstructor) {
    Box box(3.3, 1.2, 1.5);
    EXPECT_DOUBLE_EQ(box.Volume(), 5.94); // 3.3 * 1.2 * 1.5
    EXPECT_EQ(Box::getCount(), 1);
}

// Positive Test Case: Multiple objects
TEST_F(BoxTest, MultipleObjects) {
    Box box1(3.3, 1.2, 1.5);
    Box box2(8.5, 6.0, 2.0);
    EXPECT_DOUBLE_EQ(box1.Volume(), 5.94);
    EXPECT_DOUBLE_EQ(box2.Volume(), 102.0);
    EXPECT_EQ(Box::getCount(), 2);
}

// Edge Case: Zero dimensions
TEST_F(BoxTest, ZeroDimensions) {
    Box box(0.0, 0.0, 0.0);
    EXPECT_EQ(box.Volume(), 0.0);
    EXPECT_EQ(Box::getCount(), 1);
}

// Edge Case: Negative dimensions
TEST_F(BoxTest, NegativeDimensions) {
    Box box(-3.3, -1.2, -1.5);
    EXPECT_NEAR(box.Volume(), -5.94, 1e-9); // -3.3 * -1.2 * -1.5
    EXPECT_EQ(Box::getCount(), 1);
}

// Edge Case: Large dimensions
TEST_F(BoxTest, LargeDimensions) {
    Box box(1e6, 1e6, 1e6);
    EXPECT_DOUBLE_EQ(box.Volume(), 1e18); // 1e6 * 1e6 * 1e6
    EXPECT_EQ(Box::getCount(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
