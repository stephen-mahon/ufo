#include <iostream>
#include "ufo_functions.hpp"


int main() {

  greet();

  std::string codeword = "codecdemy";
  std::string answer =   "_________";
  int misses = 0;
  bool guess = false;

  std::vector<char> incorrect;
  char letter;

  while(misses < 7 and codeword != answer) {
    display_misses(misses);
    display_status(incorrect, answer);

    std::cout << "\nPlease enter your guess: ";
    std::cin >> letter;

    for(int i = 0; i < codeword.size(); i++) {
      if (letter == codeword[i]) {
        answer[i] = letter;
        guess = true;
      }
    }
    if(guess == true) {
      std::cout << "Correct!\n";
    } else {
      incorrect.push_back(letter);
      std::cout << "Incorrect! The tractor beam pulls the person in further.";
      misses++;
    }
    guess = false;
  }

  end_game(answer, codeword);

}
