#include <iostream>
#include <cmath>
#include "functions.h"

using std::cin;
using std::cout;
using std::endl;

// helper function for printing arrays
// local to this file only
template <typename T>
void print_array(T array[], size_t len) {
    cout << "[";
    if (len > 0) {
        cout << array[0];
    }
    for (size_t i = 1; i < len; ++i) {
        cout << ", " << array[i];
    }
    cout << "]";
}

void readForceValuesFromStdIn(double leftTeam[], double rightTeam[], const size_t noParticipants) {
    // TODO implement this
    unsigned int index = 0;
    int cnt = 0;
    while (index <= noParticipants / 2) {
        if (cnt == 0) {
            cin >> leftTeam[index];
            //cout << "Left[" << index << "] = " << leftTeam[index] << endl;
            cnt++;
        }
        else if (cnt == 1) {
            cin >> rightTeam[index];
            //cout << "Right[" << index << "] = " << rightTeam[index] << endl;
            cnt++;
        }
        else {
            cnt = 0;
            index++;
        }
    }
    
    // DEBUG statements (after processing since arrays are allocated, but not yet initialized)
    /*cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") noParticipants = " << noParticipants << endl;
    cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") leftTeam = ";
    print_array(leftTeam, noParticipants);
    cout << endl;
    cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") rightTeam = ";
    print_array(rightTeam, noParticipants);
    cout << endl;*/
}

bool validForces(const double forces[], const size_t noParticipants) {
    for (size_t i = 0; i < noParticipants; ++i) {
        if (forces[i] < 0) {
            return false;
        }
    }
    return true;
}

double calculateForce(const double leftTeam[], const double rightTeam[], const size_t noParticipants) {
    // DEBUG statements (before processing, since arrays should already be initialized)
    /*cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") noParticipants = " << noParticipants << endl;
    cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") leftTeam = ";
    print_array(leftTeam, noParticipants);
    cout << endl;
    cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") rightTeam = ";
    print_array(rightTeam, noParticipants);
    cout << endl;*/
    
    // TODO: implement this
    double leftForce = 0;
    double rightForce = 0;
    for (unsigned int i = 0; i < noParticipants; ++i)
    {
        leftForce += leftTeam[i];
        rightForce += rightTeam[i];
    }

    return leftForce - rightForce;
}

void printWinnerToStdOut(const char leftTeamName[], const char rightTeamName[], const double netForce) {
    // DEBUG statements (before processing, since arrays should already be initialized)
    /*cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") leftTeamName = " << leftTeamName << endl;
    cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") rightTeamName = " << rightTeamName << endl;
    cout << "[DEBUG] ("<<__FUNCTION__<<":"<<__LINE__<<") netForce = " << netForce << endl;
*/
    // TODO: implement this
    if (netForce > 5) {
        cout << leftTeamName << " wins!\n";
    }
    else if (netForce < -5) {
        cout << rightTeamName << " wins!\n";
    }
    else {
        cout << "Tie.\n";
    }
}