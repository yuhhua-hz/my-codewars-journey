/*
Digital root is the recursive sum of all the digits in a number.

Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.

Examples
    16  -->  1 + 6 = 7
   942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
*/

int count_digit(int n) {
  int digit_count = 0;
  while (n > 0) {
    n = n / 10;
    digit_count++;
  }
  
  return digit_count;
  
}


int digital_root(int n) {
  int digit, output = 0;
  int total_digit = count_digit(n);
  
  for (int i = 0; i < total_digit; ++i) {
    digit = n % 10;
    n = n / 10;
    output += digit;
  }
  
  // Si la suma final es mas de 2 digitos recursiva
  if (output >= 10) return digital_root(output);
  else return output;
}