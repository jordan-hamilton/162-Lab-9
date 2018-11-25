#include "queueSim.hpp"

using std::cout;
using std::endl;
using std::queue;
using std::rand;
using std::unique_ptr;

void simulateQueue() {

  queue<int> buffer;

  int rounds = 0, addChance = 0, removeChance = 0;
  double avgLength = 0;

  unique_ptr<Menu> queueMenu (new Menu);

  rounds = queueMenu->getIntFromPrompt("\nHow many rounds would you like to simulate?", 1, 1000, false);
  addChance = queueMenu->getIntFromPrompt("What should the chance of adding a number to the buffer be?\n\
(Note: Only enter integers to express a percentage)", 1, 100, false);
  removeChance = queueMenu->getIntFromPrompt("What should the chance of removing a number from the buffer be?\n\
(Note: Only enter integers to express a percentage)", 1, 100, false);

  for (auto i = 0; i < rounds; i++) {

    int numToAdd = generateNumber(1000);

    cout << endl << "Round " << i + 1 << ": " << endl;

    if (generateNumber(100) <= addChance) {
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

int generateNumber(const int &max) {
  return rand() % max + 1;
}

double calcAverageLength(const double &prevRoundAvg, const int &round, const int &length) {
  return  (prevRoundAvg * (round - 1) + length) / round;
}

void outputQueueInfo(queue<int> queueToPrint) {

  if ( !queueToPrint.empty() ) {
    cout << "Contents: " << endl;

    while ( !queueToPrint.empty()) {
      cout << queueToPrint.front() << endl;
      queueToPrint.pop();
    }

  }

}
