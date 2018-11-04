//******************************************************************************
//
//Kenna Draxton
//CSC 215
//skynet assignment 4 players

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()

{
    // Seed random number
    srand(static_cast<unsigned int>(time(0)));
    
    // initiate variables for binary
   
    int binarySearchGridHighNumber = 64;
    int binarySearchGridLowNumber = 1;
    int binaryTargetLocationPrediction = 0;
    int enemyLocation = rand() % 64 + 1;
    int binaryTries = 0;
    bool isTargetFoundByBinaryAI = false;
    
    //initiate variables for human search
    bool isEnemyFoundHuman = false;
    int humanTargetLocationPrediction = 0;
    int humanNumberGuessCount = 0;
   
    //initiate variables for linear search
    int linearTargetLocationPrediction = 0;
    int aiLienarNumberGuess = rand() % 64 + 1;
    bool isEnemyFoundLinear = false;
    int linearNumberGuessCount = 0;
    int index = 0;
    
   //initiate variables for random search
    int randomTargetLocationPrediction =0;
    int randomNumberGuessCount =0;
    bool isEnemyFoundRandom = false;
    
    
    
    
    
    // Welcome to user **************************************************************************************************
    cout << "\nWelcome to skynet HK-Aerial Enemy Search\n";
    cout << "\nThe mission will be for each player to find the enemy!! Hooman, you are up first!!!!\n";
    
    
    // ********************************************** Human Search Start **********************************************
    
     do
     {
         //human intro
         cout << "make your guess between 1 and 64..." << endl;
         
         //left in for eay checking of program
         cout << "CHEAT - Target is located at location #" << enemyLocation << endl;
         
         //ask for the human guess, console in
         cout << "Please enter target prediction between 1 and 64: ";
         cin >> humanTargetLocationPrediction;
         cout << "Skynet HK Human Aerial attempt number" << ++humanNumberGuessCount << " attempts"<< endl;
         
         // if human AI prediction is too high and present to user the current guess
         if (humanTargetLocationPrediction > enemyLocation)
         {
             cout << "attempt too high, guess lower\n";
             
         }
         // if human AI Prediction is too low
         // it will change the low number
         else if (humanTargetLocationPrediction < enemyLocation)
         {
             cout << "attempt too low, guess higher\n";
             
         }
         else if(humanTargetLocationPrediction == enemyLocation)
         {
             // Flip the found flag so that it stops the loop
             isEnemyFoundHuman = true;
             cout << "You've hit the target!\n";
             cout << "Target was located at location #" << enemyLocation << endl;
             cout << "Your target prediction was at location #" << humanTargetLocationPrediction << endl;
             cout<< "\nOn Skynet HK-Aerial attempt number "<< humanNumberGuessCount << ".\n" << endl;
             cout << "******************************************************"<< endl;
             
         }
         else
         {
             //this prints if there is an Error
             cout << "\n **** Error in target results!***** " << endl;
         }
         
     }while (!isEnemyFoundHuman);
    
    cout << "Binary Player is up next\n" << endl;
    // ********************************************** Human Search end **********************************************
    
    // ********************************************** Binary Search Start **********************************************
    //start the loop here, binary search location guess
    do
    {
        
        binaryTargetLocationPrediction = ((binarySearchGridHighNumber - binarySearchGridLowNumber) / 2) + binarySearchGridLowNumber;
        
        //displays the enemy location to us but not the AI computer
        cout << "\nThe enemy is hiding at location #" << enemyLocation << endl;
        cout <<  "The #" << ++binaryTries <<  " prediction was at target location #" << binaryTargetLocationPrediction << endl;
        
        // if Binary AI prediction is too high and present to user the current guess
        if (binaryTargetLocationPrediction > enemyLocation)
        {
            cout << "attempt too high\n";
            cout << "The current low number is " << binarySearchGridLowNumber << endl;
            cout << "The current high number is " << binarySearchGridHighNumber << endl;
            
            //this takes the current guess and changes the high number so then later in the
            // loop it will use that as the new high number and narrow down the search area
            binarySearchGridHighNumber = binaryTargetLocationPrediction -1;
            
            cout << "The new high number is " << binarySearchGridHighNumber << endl;
            
        }
        // if Binary AI Prediction is too low
        // it will change the low number
        else if (binaryTargetLocationPrediction < enemyLocation)
        {
            cout << "attempt too low\n";
            cout << "The current low number is " << binarySearchGridLowNumber << endl;
            cout << "The current high number is " << binarySearchGridHighNumber << endl;
            binarySearchGridLowNumber = binaryTargetLocationPrediction + 1;
            cout << "The new low number is " << binarySearchGridLowNumber << endl;
        }
        else if(binaryTargetLocationPrediction == enemyLocation)
        {
            // Flip the found flag so that it stops the loop
            isTargetFoundByBinaryAI = true;
            cout << "You've hit the target!\n";
            cout<< "\nOn Skynet HK-Aerial attempt number "<< binaryTries << "." << endl;
            cout << "*********************************************************"<< endl;
            cout << "Linear Search AI is up next....."<< endl;
        }
        else
        {
            //this prints if there is an Error
            cout << "\n **** Error in target results!***** " << endl;
        }
        //this says that the loop will continue as long as the boolean is false
    }while (!isTargetFoundByBinaryAI);
    
    
    // ********************************************** Binary Search End **********************************************
    
   
    
    
    // ********************************************** Linear Search Start **********************************************
    
    
    do
    {
        cout << "\nmake your guess between 1 and 64...";
        
        
        //ask for the linear guess, console in
        // Hey this is one way to increment
        //++linearTargetLocationPrediction;
        // This is a more readable way
        
        linearTargetLocationPrediction = linearTargetLocationPrediction + 1;
        
        
        
        cout << "Linear Target guess equals: " << linearTargetLocationPrediction;
        cout << "Skynet HK linear Aerial attempt number" << ++linearNumberGuessCount << "attempts"<< endl;
        
        // if linear AI prediction is too high and present to user the current guess
        if (linearTargetLocationPrediction > enemyLocation)
        {
            cout << "attempt too high, guess lower\n";
            
        }
        // if linear AI Prediction is too low
        // it will change the low number
        else if (linearTargetLocationPrediction < enemyLocation)
        {
            cout << "attempt too low, guess higher\n";
            
        }
        else if(linearTargetLocationPrediction == enemyLocation)
        {
            // Flip the found flag so that it stops the loop
            isEnemyFoundLinear = true;
            cout << "You've hit the target!\n";
            cout << "Target was located at location #" << enemyLocation << endl;
            cout << "Your target prediction was at location #" << linearTargetLocationPrediction << endl;
            cout<< "\nOn Skynet HK-Aerial attempt number "<< linearNumberGuessCount << "." << endl;
            cout << "******************************************************"<< endl;
            cout << "Random Search AI is up next"<< endl;
        
            
        }
        else
        {
            //this prints if there is an Error
            cout << "\n **** Error in target results!***** " << endl;
        }
        
    }while (!isEnemyFoundLinear);
           
            // ********************************************** Linear Search End **********************************************
            
            // ********************************************** Random Search Start **********************************************
            //random number search
    do
    {
        cout << "\nmake your guess between 1 and 64...";
        
        
        //ask for the linear guess, console in
        // Hey this is one way to increment
        //++linearTargetLocationPrediction;
        // This is a more readable way
        
        randomTargetLocationPrediction = rand() % 64 + 1;
        
        
        
        cout << "random Target guess equals: " << randomTargetLocationPrediction;
        cout << "Skynet HK random Aerial attempt number" << ++randomNumberGuessCount << "attempts"<< endl;
        
        // if random AI prediction is too high and present to user the current guess
        if (randomTargetLocationPrediction > enemyLocation)
        {
            cout << "attempt too high, guess lower\n";
            
        }
        // if random AI Prediction is too low
        // it will change the low number
        else if (randomTargetLocationPrediction < enemyLocation)
        {
            cout << "attempt too low, guess higher\n";
            
        }
        else if(randomTargetLocationPrediction == enemyLocation)
        {
            // Flip the found flag so that it stops the loop
            isEnemyFoundRandom = true;
            cout << "You've hit the target!\n";
            cout << "Target was located at location #" << enemyLocation << endl;
            cout << "Your target prediction was at location #" << randomTargetLocationPrediction << endl;
            cout<< "\nOn Skynet HK-Aerial attempt number "<< randomNumberGuessCount << "." << endl;
            
        }
        else
        {
            //this prints if there is an Error
            cout << "\n **** Error in target results!***** " << endl;
        }
        
    }while (!isEnemyFoundRandom);
    
            
        // ********************************************** Random Search End **********************************************
            
            
        // ********************************************** Report Results Start **********************************************
            //this ends the program saying that everything works

cout << "******************************************************"<< endl;
cout << "Good work everyone!"<< endl;
cout << "You found the enemy in " << humanNumberGuessCount << " tries"<< endl;
cout << "Binary AI found the enemy in " << binaryTries << " tries" << endl;
cout << "Linear AI found the enmy in "<< linearNumberGuessCount << " tries" << endl;
    cout << "Random AI found the enemy in "<< randomNumberGuessCount << " tries" << endl;

            
        // ********************************************** Report Results End **********************************************
return 0;

}

            
            
         
        
        
        
        

