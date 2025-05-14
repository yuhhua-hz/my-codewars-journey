/*
Task

Given a string str, reverse it and omit all non-alphabetic characters.
Example

For str = "krishan", the output should be "nahsirk".

For str = "ultr53o?n", the output should be "nortlu".
Input/Output

    [input] string str

A string consists of lowercase latin letters, digits and symbols.

    [output] a string
*/

#include <cctype> // isalpha()
#include <algorithm> // std::reverse

std::string reverse_letter(const std::string &str)
{
  std::string output {};
  for (auto c : str) {
    if (isalpha(c)) {
      output += c;
    }
  }
  std::reverse(output.begin(), output.end());
  return output;
}
