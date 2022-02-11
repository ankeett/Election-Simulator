#include <iostream>
#include "Simulation.h"
#include <vector>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>

//Mutator - adds name to the vector
void Simulation::AddName(string candidateName)
{
    Candidates.push_back(candidateName);
}

//Mutator - adds rate to the vector
void Simulation::AddRate(int rate)
{
    Probability.push_back(rate);
}

//Mutator - sets the vote from the input
void Simulation::SetVotes(int noOfVotes)
{
    this-> noOfVotes = noOfVotes;
}

//Calculating the votes through randomization using the probability rate
void Simulation::CalculateVotes()
{
    int r;
    int sum;

    //Filling the vector of votes with zero - Initialization
    for(int i = 0; i < Probability.size(); i++)
    {
      votes.push_back(0);
    }

    //Looping until we reach the no, of votes. It means every vote is randomized.
    for(int i = 0; i < noOfVotes; i++)
    {
      r = rand()% 100 + 1;
      sum = Probability.at(0);

      for(int i = 0; i < Probability.size(); i++ )
      {
        if(sum >= r)
        {
          votes.at(i) += 1;
          break;
        }

      
        //Increasing the sum value to recompare
        if(i < Probability.size() - 1)
        {
          sum += Probability.at(i + 1);
        }
        else
        {
          break;
        }
      

      }
    }
  
}

//Finding the winner of the election
void Simulation::FindWinner()
{
    int max;
	  int findMax = 0;
	  int runnerUp;
  	int findRunnerUp = 0;
	
	  max = votes.at(0);
	  runnerUp = 0;
	
	  for(int i = 1; i < (int) votes.size(); i++)
	  {
	      if(votes.at(i) > max)
	      {
	        max = votes.at(i);
	        findMax = i;
	      }
	    
	  }
	
  	for(int i = 0; i < (int) votes.size(); i++)
	  {
      if(votes.at(i) < max && votes.at(i) > runnerUp)
	      {
	        runnerUp = votes.at(i);
	        findRunnerUp = i;
	      }
	  }
	
	  //cout << "The runner up value is "<< runnerUp << " at position " << findRunnerUp << endl;
	
	
    //Run Off case
	  if(max < (50 * noOfVotes) / 100)
	  {
	    cout<<endl;
	    cout << "Since the maximum vote by the winner is not above 50%, conducting Run-off election" << endl;
	    cout << "Election is between " << Candidates.at(findMax) << " and " << Candidates.at(findRunnerUp) << endl;
	    cout << endl;
	    
	    //Calculating probability
	    Probability.at(findMax) = rand()%100 + 1;
	    Probability.at(findRunnerUp) = 100 - Probability.at(findMax);

      /*
      cout << Probability.at(findMax) << endl;
      cout << Probability.at(findRunnerUp) << endl;
      */

      //Changing the votes of winner and runner up to 0 for re-election
      votes.at(findMax) = 0;
      votes.at(findRunnerUp) = 0;

      //Finding votes for run-off case with 80% of total votes
      int r1;
      for(int i = 0; i < (80 * noOfVotes) / 100; i++)
      {
        r1 = rand()% 100 + 1;

        if(Probability.at(findMax) >= r1)
        {
          votes.at(findMax)++;
        }
        else
        {
          votes.at(findRunnerUp)++;
        }

      }
	    
	    //Visualization
      //Percentage table of the Election
      cout << endl;
      cout << "Data Visualization of the Candidates and thier winning Probability:" << endl;
        
      cout << setw(25) << left <<Candidates.at(findMax) << " ";
      for(int j =0; j < (int) Probability.at(findMax); j++)
        {
          cout << "|";
        }
      cout << endl;
            
      cout << setw(25) << left <<Candidates.at(findRunnerUp) << " ";
      for(int j =0; j < (int) Probability.at(findRunnerUp); j++)
        {
          cout << "|";
        }
      cout << endl;  
      cout << endl;

	    //creating a table
      cout << setw(33) << right << "Re-Election Results" << endl;
      cout << setw(20) << left  << "Candidates" << "|";
      cout << setw(23) << right << "No. of Votes" << endl;
   
      // Produce long line   
      cout << setfill('-') << setw(44) << "" << endl;
   
      // Reset fill character back to space
      cout << setfill(' ');
        
      //Filling the table with run off election results  
      cout << setw(20) << left  <<Candidates.at(findMax) << "|";
      cout << setw(23) << right <<votes.at(findMax);
      cout << endl;
        
      cout << setw(20) << left  <<Candidates.at(findRunnerUp) << "|";
      cout << setw(23) << right <<votes.at(findRunnerUp);
      cout << endl;
        
      //Printing out the details 
      cout << endl;
	    if(votes.at(findMax) > votes.at(findRunnerUp))
	    {
	      cout << "The winner of this Election is "<< Candidates.at(findMax)<<" with "<<votes.at(findMax)<<" votes."<<endl;
	    }
	    else
	    {
	      cout << "The winner of this Election is " << Candidates.at(findRunnerUp)<<" with " << votes.at(findRunnerUp) << " votes." << endl;
	    }
	    
	}
	else
	{
    cout << endl;
	  cout << "The winner of this Election is "<< Candidates.at(findMax) << " with "<<votes.at(findMax) << " votes." << endl;
	}  

}

void Simulation::PrintDetails()
{
    //Finding the total votes of each candidate
    CalculateVotes();
        
    //Percentage table of the Election
    cout << endl;
    cout << endl;
    cout << "Data Visualization of the Candidates and thier winning Probability:" << endl;
    for(int i =0; i < (int) Candidates.size(); i++ )
      {
        cout << setw(25) << left <<Candidates.at(i) << " ";
        for(int j =0; j < (int) Probability.at(i); j++)
          {
          cout<<"|";
          }
        cout<<endl;
        
      }


    //creating a table
    cout << endl;
    cout << setw(33) << right << "Election Results" << endl;
    cout << setw(20) << left  << "Candidates" << "|";
    cout << setw(23) << right << "No. of Votes" << endl;
  
    // Produce long line   
    cout << setfill('-') << setw(44) << "" << endl;

    // Reset fill character back to space
    cout << setfill(' ');
        
    for(int i =0; i < (int) Candidates.size(); i++)
      {
        cout << setw(20) << left  <<Candidates.at(i) << "|";
        cout << setw(23) << right <<votes.at(i) ;
        cout<<endl;
      }

    //Finding the winner and conducting run-off election if needed    
    FindWinner();
}

//Accessor - Gives the size of the name vector
int Simulation::GetSizeofName()
{
    return Candidates.size();
}

/*
//Give the size of the probability vector
int Simulation::GetSizeofRate()
{
    return Probability.size();
}
*/