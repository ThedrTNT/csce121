#include <iostream>
#include "functions.h"

using std::cout;
using std::endl;
using std::cin;

// anonymous namespace is only accessible in this file
namespace {
    const size_t MAX_NUM_PARTICIPANTS = 200;
    const size_t MAX_TEAM_NAME_LENGTH = 255;
}

int main()
{
    // read noParticipants from terminal
    size_t noParticipants = 0;
    cin >> noParticipants;

    // define an array for the name of the left team, and then read it from terminal
    char leftTeamName[MAX_TEAM_NAME_LENGTH+1];
    cin >> leftTeamName;
    
    // define an array for the name of the right team, and then read it from terminal
    char rightTeamName[MAX_TEAM_NAME_LENGTH+1];
    cin >> rightTeamName;
    
    // define arrays for the forces of the left and right teams (variable names are leftTeamForces and rightTeamForces)
    double leftTeamForces[MAX_NUM_PARTICIPANTS];
    double rightTeamForces[MAX_NUM_PARTICIPANTS];
    
    // read them from the terminal by calling function readForceValuesFromStdIn (see TODO in functions.cpp)
    readForceValuesFromStdIn(leftTeamForces, rightTeamForces, noParticipants);

    // TODO: check whether the inputs are valid
    if (!validForces(leftTeamForces, noParticipants) && !validForces(rightTeamForces, noParticipants))
    {
        cout << "Both teams have an invalid force!" << endl;
        return 1;
    }
    if (!validForces(rightTeamForces, noParticipants))
    {
        cout << rightTeamName << " has an invalid force!" << endl;
        return 1;
    }
    if (!validForces(leftTeamForces, noParticipants))
    {
        cout << leftTeamName << " has an invalid force!" << endl;
        return 1;
    }

    // compute the netforce (see TODO in functions.cpp)
    double netForce = calculateForce(leftTeamForces, rightTeamForces, noParticipants);

    // print the result (see TODO in functions.cpp)
    printWinnerToStdOut(leftTeamName, rightTeamName, netForce);


    return 0;
}
