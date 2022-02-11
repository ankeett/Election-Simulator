#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Simulation.h"

using namespace std;
int main()
{
    //Variable declaration
    Simulation election;
    
    string candidateName;
    string winningProbability;
    
    int votes;
    
    int noOfCandidate;
    
    //Seeding the random generator
    srand(time(NULL));
    
    
    cout<<"Welcome to the Election Simulation Created by Ankit Kafle!"<<endl;
    cout<<endl;
    
    do
    {
      cout << "How many Candidates do you want to enter in this election?"<<endl;
      cin>>noOfCandidate;
    } while(noOfCandidate < 1);
    
    for(int i = 0; i < noOfCandidate; i++)
    {
      cout<<"Enter the name of the candidate (" << i + 1 << ") :"<<endl;

      //Discarding the garbage value and letting user input
      while(cin.peek() == '\n')
      {
          cin.ignore();
      }
         
      getline(cin, candidateName);
      election.AddName(candidateName);
    }

    
    //Probability calculator
    int rngn = election.GetSizeofName();
    int endnum = 100;
    int sum = 0;
    int random;
    char reply;
    int predict;
    vector <int> casualRate;
    
    do
    {
      cout << "Do you want to manually input the prediction or let the computer do the magic? (i for input and m for magic)" << endl;
      cin >> reply;
     reply = tolower(reply);
    } while(!(reply == 'm' || reply == 'i'));

    if(reply == 'i')
    {
      for(int i = 0; i < rngn; i++)
      {
        cout << "Enter the prediction of Candidate " << i + 1 <<endl;
        cin >> predict;

        sum += predict;

        if(sum <= 100)
        {
          casualRate.push_back(predict);
        }
        else
        {
          cout << "Prediction over 100!" << endl;
          break;
        }
      }

      if( sum < 100)
  	  {
        cout << "The Prediction sum is not equal to 0. So, adding remaining to the last candidate." << endl;
	      casualRate.back() = casualRate.back() + 100 - sum;
	    }
    }

    else
    {
      for(int round = 0; round < rngn; round++)
	   {
	     casualRate.push_back(rand()% endnum + 1);

	    	endnum -= casualRate.at(round);
	      	sum += casualRate.at(round);
		
		   if(endnum == 0)
	    	{
		       break;
	    	}
	    }

      //The sum of the probability must be equal to 100%
	   if( sum < 100)
  	  {
	      casualRate.back() = casualRate.back() + 100 - sum;
	    }

    } //else statement


    //If the sum is already 100%, add predict zero to the remaining   
	  while((int) casualRate.size() != rngn)
	  {
		  casualRate.push_back(0);
	  }
		
    /*
	  for(int i = 0 ; i < (int) casualRate.size(); i++)
	  {
	  	cout << "Candidate "<< i +1 <<": "<<casualRate.at(i) << endl;
	  }
		*/
		
		//Adding the Probability rate inside the private class member vector
	  for(int i = 0; i < casualRate.size(); i++)
	  {
	    election.AddRate(casualRate.at(i));
	  }
    
    cout << endl;
    cout << "Enter number of votes:" << endl;
    cin >> votes;
    

    //Setting the no of votes to the private data member
    election.SetVotes(votes);

    //It calculates and gives the result of the election 
    election.PrintDetails();
    
    cout << endl;
    cout << "Thank you for using this Service!" << endl;
    return 0;
}
