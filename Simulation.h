#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>

using namespace std;

class Simulation 
{
    private:

    vector<string> Candidates;
    vector<int> Probability;
    vector <int> votes;
    int noOfVotes;
    
    public:
    
    //Mutator
    void AddName(string candidateName);
    void AddRate(int rate);
    void SetVotes(int noOfVotes);
    
    //Accessor
    int GetSizeofName();
    //int GetSizeofRate();
    
    //Print the details 
    void CalculateVotes();
    void FindWinner();
    void PrintDetails();
};
#endif