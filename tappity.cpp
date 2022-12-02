#include "tappity.h"
/**
 * Class for tappity
 **/

// Constructor sets the reference phrase
tappity::tappity(std::string reference) {
  reference_ = reference;
  input_ = "";
}

// Provide the input to be compared to the reference. Before this
// function is called, the input should be considered an empty string
void tappity::entry(std::string input) { input_ = input; }

// Compares the length of the reference to that of the input and
// returns the absolute value of the difference, or 0 if they are the
// same length
int tappity::length_difference() { return abs(input_.length() - reference_.length()); }

// Compares the content of the reference to that of the input and
// calculates the accuracy of matching characters. If the two strings
// are identical, accuracy should be 100. However, for each
// corresponding character that does not match in the same location,
// the percentage of corresponding characters should be returned.
// For example, if the reference and input have 10 letters and the input
// matches 8 of the corresponding reference characters, the function
// should return 80. When input does not have the same number of
// characters as the reference, the accuracy should represent the percent
// of matching characters between the shorter and longer strings. For
// example, if one string has 8 characters matching the corresponding
// locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy() {
  int max_length = std::max(reference_.length(), input_.length());
  int min_length = std::min(reference_.length(), input_.length());
  if (max_length == 0) {
    return 100.0;
  }

  int matches = 0;

  for (int i = 0; i < min_length; i++) {
    if (reference_[i] == input_[i]) {
      matches++;
    }
  }
  double accuracy = (matches / double(max_length)) * 100.0;
  return accuracy;
}
