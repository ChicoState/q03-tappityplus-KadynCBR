/**
 * Unit Test suite
 **/

#include <gtest/gtest.h>

#include "tappity.h"

class tappityTest : public ::testing::Test {
 protected:
  tappityTest() {}
  virtual ~tappityTest() {}
  virtual void SetUp() {}
  virtual void TearDown() {}
};

TEST(tappityTest, Construction_with_empty) {
  tappity t = tappity("");
  ASSERT_TRUE(true);
}

TEST(tappityTest, length_difference_empty_both) {
  tappity t = tappity("");
  ASSERT_EQ(t.length_difference(), 0);
}

TEST(tappityTest, length_difference_empty_entry) {
  tappity t = tappity("foobar");
  ASSERT_EQ(t.length_difference(), 6);
}

TEST(tappityTest, length_difference_empty_reference) {
  tappity t = tappity("");
  t.entry("foobar");
  ASSERT_EQ(t.length_difference(), 6);
}

TEST(tappityTest, length_difference_same) {
  tappity t = tappity("foobar");
  t.entry("foobar");
  ASSERT_EQ(t.length_difference(), 0);
}

TEST(tappityTest, accuracy_empties) {
  tappity t = tappity("");
  t.entry("");
  ASSERT_DOUBLE_EQ(t.accuracy(), 100);
}

TEST(tappityTest, accuracy_reference_longer) {
  tappity t = tappity("reference1");
  t.entry("refer");
  ASSERT_DOUBLE_EQ(t.accuracy(), 50);
}

TEST(tappityTest, accuracy_input_longer) {
  tappity t = tappity("refer");
  t.entry("reference1");
  ASSERT_DOUBLE_EQ(t.accuracy(), 50);
}

TEST(tappityTest, accuracy_same) {
  tappity t = tappity("reference");
  t.entry("reference");
  ASSERT_DOUBLE_EQ(t.accuracy(), 100);
}

TEST(tappityTest, accuracy_reference_half_accuracy) {
  tappity t = tappity("0123456789");
  t.entry("012");
  ASSERT_DOUBLE_EQ(30, t.accuracy());
}

TEST(tappityTest, accuracy_spotted_correct) {
  tappity t = tappity("abcdefghij");
  t.entry("a0c0e0g0i0");
  ASSERT_DOUBLE_EQ(50, t.accuracy());
}

TEST(tappityTest, accuracy_spotted_correct_inverse) {
  tappity t = tappity("a0c0e0g0i0");
  t.entry("abcdefghij");
  ASSERT_DOUBLE_EQ(50, t.accuracy());
}