/*
You are going to be given a non-empty string. Your job is to return the middle character(s) of the string.

    If the string's length is odd, return the middle character.
    If the string's length is even, return the middle 2 characters.

Examples:

"test" --> "es"
"testing" --> "t"
"middle" --> "dd"
"A" --> "A"
*/

std::string get_middle(std::string input) 
{
  // return the middle character(s)
  if (input.length() % 2 == 0) return input.substr(input.length()/2 - 1, 2);
  else return input.substr(input.length()/2, 1);
}
