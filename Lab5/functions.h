#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void readForceValuesFromStdIn(double leftTeam[], double rightTeam[], const size_t noParticipants);
bool validForces(const double forces[], const size_t noParticipants);
double calculateForce(const double leftTeam[], const double rightTeam[], const size_t noParticipants);
void printWinnerToStdOut(const char leftTeamName[], const char rightTeamName[], const double netForce);

#endif