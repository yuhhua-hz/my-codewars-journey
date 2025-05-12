/*
Given an integer n return "odd" if the number of its divisors is odd. Otherwise return "even".

Note: big inputs will be tested.
Examples:

All prime numbers have exactly two divisors (hence "even").

For n = 12 the divisors are [1, 2, 3, 4, 6, 12] – "even".

For n = 4 the divisors are [1, 2, 4] – "odd".
*/

#include <string>
#include <cmath>

std::string oddity(long long int n) {
  
  // El truco de este problema consiste en verificar si 'n' es un cuadrado perfecto
  // Si es un cuadrado perfecto, ej 16=4², 64=8², entonces tiene un numero impar de divisores
  // n=16, 1*16, 2*8, 4*4 = 5 divisores -> odd
  // n=12, 1*12, 3*4, 6*2 = 6 divisores -> even
  // Para ello, calcular la raiz de n, y comprobar si la raiz potencia de 2 es n
  // Si es n entonces quiere decir que es un cuadrado perfecto -> odd, sino -> even
  
  long long int root = sqrt(n);
  return (pow(root,2) == n) ? "odd" : "even";
}
