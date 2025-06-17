/*
Background
Pat Programmer is worried about the future of jobs in programming because of the advance of AI tools like ChatGPT, and he decides to become a chef instead! So he wants to be an expert at flipping pancakes.

A pancake is characterized by its diameter, a positive integer.
Given a stack of pancakes, you can insert a spatula under any pancake and then flip, which reverses the order of all the pancakes on top of the spatula.

Task
Write a function that takes a stack of pancakes and returns a sequence of flips that arranges them in order by diameter, with the largest pancake at the bottom and the smallest at the top. The pancakes are given as a list of positive integers, with the left end of the list being the top of the stack.

Based on Problem 4.6.2 in Skiena & Revilla, "Programming Challenges".

Example
Consider the stack [1,5,8,3]. One way of achieving the desired order is as follows:

The 8 is the biggest, so it should be at the bottom. Put the spatula under it (position 2 in the list) and flip.
This transforms the stack into [8,5,1,3], with the 8 at the top. Then flip the entire stack (spatula position 3).
This transforms the stack into [3,1,5,8], which has the 8 at the bottom.
And since the 5 is in the correct position as well, now flip the 1 and 3 (spatula position 1).
The stack is now [1,3,5,8], as desired. The function should return [2,3,1].

Note
You don't have to find the shortest sequence of flips. That is a hard problem - see https://en.wikipedia.org/wiki/Pancake_sorting. However, don't include unnecessary flips, in the following sense:

If two consecutive flips leave the stack in the same state, they should be omitted.
For example, [2,3,2,2,1] also arranges [1,5,8,3] correctly, but 2,2 is unnecessary.
Flipping only the top pancake doesn't achieve anything.
Performance should not be a issue. If Pat can flip 1,000 pancakes with diameters between 1 and 1,000, he thinks he can get a job!
*/

#include <vector>

namespace Ola {
  
  // Funcion auxiliar flipear desde rango pos_ini a pos_end
  void flip(std::vector<int>& stack, int pos_ini, int pos_end) {
    while (pos_ini < pos_end) {
      int temp = stack[pos_ini];
      stack[pos_ini] = stack[pos_end];
      stack[pos_end] = temp;
      pos_ini++; pos_end--;
    }

  }

  // Funcion auxiliar busca el maximo de una lista y devuelve su indice
  int findMaxIndex(std::vector<int>& stack, int end) {
    int maxIndex = 0;
    for (int i = 1; i <= end; ++i) {
      if (stack[i] > stack[maxIndex]) {
        maxIndex = i;
      }
    }
    return maxIndex;
  }
  
} // namespace Ola

std::vector<int> flipPancakes(std::vector<int>& stack) {
  
  std::vector<int> flip {};
  
  int n = stack.size() - 1;
  
  // Reducir en cada iteracion el stack despues de poner el pancake en su sitio
  for (int i = n; i > 0; --i) {
    int maxIndex = Ola::findMaxIndex(stack, i);
    
    // Si el pancake mas grande ya esta en la posicion 0
    if (maxIndex == 0) {
      // Flipear desde 0 a la posicion maxima correspondiente y seguir con la siguiente iteracion
      Ola::flip(stack, 0, i);
      flip.push_back(i);
      continue;
    }
    
    // Si el pancake esta en su sitio saltar a la siguiente iteracion
    if (i == maxIndex) continue;
    
    // Si el pancake no esta en su sitio, traerlo a la posicion mas baja 0 y flipear desde alli
    if (i != maxIndex) {
      // Traer a la posicion 0 el maximo  y registrar el flip
      Ola::flip(stack, 0, maxIndex);
      flip.push_back(maxIndex);
      
      // Traer a la posicion de abajo/ultima el pancake y registrar
      Ola::flip(stack, 0, i);
      flip.push_back(i);
    }
    
  }
  
  return flip;
  
}
