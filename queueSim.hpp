/*********************************************************************
** Description: Header file for the queue buffer simulation.
*********************************************************************/

#ifndef QUEUESIM_HPP
#define QUEUESIM_HPP

#include <memory>
#include <queue>

#include "Menu.hpp"

void simulateQueue();
int generateNumber(const int &max);
double calcAverageLength(const double &prevRoundAvg, const int &round, const int &length);
void outputQueueInfo(std::queue<int> bufferToPrint);

#endif
