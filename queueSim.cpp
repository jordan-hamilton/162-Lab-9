#include "queueSim.hpp"

using std::cout;
using std::endl;
using std::queue;
using std::rand;
using std::unique_ptr;


/***********************************************************************************************
** Description: This method declares a queue of integers, and initializes integers for the
** number of rounds over which to simulate a buffer, as well as the percentage chance of adding
** and removing a randomly generated number to that buffer, and the average length of the buffer
** over the course of the simulation. A menu object prompts the user for the number of rounds
** and chances of adding or removing values, then a while loop generates a random number between
** 1 and 1000 to add to the end of the buffer using push if a randomly generated number is less
** than or equal to the user-provided chance of adding a number to the buffer. Another random
** number is generated to determine if a number should be removed from the front of the buffer,
** if the random number is less than or equal to the user-provided chance of removing a number.
** The average is updated and output along with the entire contents of the buffer after each
** round of the simulation.
***********************************************************************************************/
void simulateQueue() {

  queue<int> buffer;

  int rounds = 0, addChance = 0, removeChance = 0;
  double avgLength = 0;

  unique_ptr<Menu> queueMenu (new Menu);

  rounds = queueMenu->getIntFromPrompt("\nHow many rounds would you like to simulate?", 1, 1000, false);
  addChance = queueMenu->getIntFromPrompt("What should the chance of adding a number to the buffer be?\n\
(Note: Only enter integers to express a percentage)", 0, 100, false);
  removeChance = queueMenu->getIntFromPrompt("What should the chance of removing a number from the buffer be?\n\
(Note: Only enter integers to express a percentage)", 0, 100, false);

  for (int i = 0; i < rounds; i++) {

    cout << endl << "Round " << i + 1 << ": " << endl;

    if (generateNumber(100) <= addChance) {
      int numToAdd = generateNumber(1000);
      buffer.push(numToAdd);
    }

    if (generateNumber(100) <= removeChance) {

      if ( !buffer.empty() ) {
        buffer.pop();
      }

    }

    outputQueueInfo(buffer);
    avgLength = calcAverageLength( avgLength, i + 1, buffer.size() );
    cout << "The average length of the buffer is " << avgLength << endl;

  }

}


/***********************************************************************************************
** Description: Takes a constant reference to an integer for the maximum random value to return,
** then generates and returns a random integer between 1 and that value.
***********************************************************************************************/
int generateNumber(const int &max) {
  return rand() % max + 1;
}


/***********************************************************************************************
** Description: Takes a constant reference to a double indicating the average length of the
** queue before this method was called, as well as a constant reference to an integer for the
** current round of the buffer simulation and a constant reference to an integer representing
** the current length of the buffer. The numbers are then plugged into a formula to return the
** updated average as a double to assign to the avgLength variable.
***********************************************************************************************/
double calcAverageLength(const double &prevRoundAvg, const int &round, const int &length) {
  return  (prevRoundAvg * (round - 1) + length) / round;
}


/***********************************************************************************************
** Description: Takes a queue of integers by value and if the queue is not empty, a while loop
** displays the queue's contents, using the front method to display the first value and pop to
** then remove the integer at the front of the queue.
***********************************************************************************************/
void outputQueueInfo(queue<int> queueToPrint) {

  if ( !queueToPrint.empty() ) {
    cout << "Contents: " << endl;

    while ( !queueToPrint.empty()) {
      cout << queueToPrint.front() << endl;
      queueToPrint.pop();
    }

  }

}
