#include "stackSim.hpp"

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::unique_ptr;

/************************************************************************************************
** Description: This function creates a pointer to a menu object to prompt the user for a word,
** then iterates through the entered string to push each character to the top of a stack. A
** while loop appends the first character in the stack to the string and removes it until the
** stack is empty. After the stack is empty, the string is displayed to the user as a palindrome.
************************************************************************************************/
void createPalindrome() {

  string palindromeString;

  stack<char> reverseString;

  unique_ptr<Menu> stackMenu ( new Menu("Enter a word and we'll create a palindrome:") );

  palindromeString = stackMenu->getStrFromPrompt(true);

  cout << endl << "Palindrome:" << endl;

  for (string::iterator charToAdd = palindromeString.begin(); charToAdd != palindromeString.end(); charToAdd++) {
    reverseString.push(*charToAdd);
  }

  while ( !reverseString.empty() ) {
    palindromeString += reverseString.top();
    reverseString.pop();
  }

  cout << palindromeString << endl;


}
