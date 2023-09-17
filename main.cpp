/*
* Name: Christopher Rosado, 2001956343, Assignment One
* Description: the program is using a custom type linked
* list and stack custom type to under go a game of 
* accordian. Taking 52 cards and seeing how far a 
* the set of cards can be stacked and organized based 
* off of the suit and face of the card. 
* Input: a set of 52 cards 
* Output: The finished game of accordian. The most steps
* possible that the game can take and the amount of stacks
* left.
*/
#include "LL.h"
#include "LL.cpp"
#include "myStack.h"
#include "myStack.cpp"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	string CardInput ="", Test = ""; //string value to hold all the cards values throughout the loop
    LL< myStack <string> > accordian; // Linked list stack that holds all cards
    LL< myStack<string> >::iterator it; //iterator for accordian
    myStack<string> CardStack; //Temp variable to use for tail inserts
    int AmtOfStacks = 0, DummyCounter = 0, sizeCheck = 0, DummyPossibility = 3; // int variables for tests
    bool NeighborHit = false, GameContinue = false, SomethingHit = false; //boolean variables meant to check status of game

    cin >>CardInput;
    while(!cin.eof()){
        CardStack.push(CardInput);
        accordian.tailInsert(CardStack);
        CardStack.pop();

        cin>>CardInput;
    }
    LL< myStack<string> >::iterator CurrentCard, Traverser; //CurrentCard stays at card and Traverser checks third and first neighbor

    //start of game, outer loop checks the condition of the game if it CurrentCard had reached the end of the card linked list
    while(true){
        //resets to false so game can actively check if there are no more cards left
        GameContinue = false;
        //resets the CurrentCard to beginning of linked list
        CurrentCard = accordian.begin();
        Traverser = CurrentCard;

        while(CurrentCard != accordian.end()){
            //for loop gets Traverser to third neighbor and if it hits accord.end()
            // it passes the i value to DummyCounter to check for the two possible outcomes for traverser
            // hitting the end
            NeighborHit = false;
            for(int i = 0; i < DummyPossibility; i++){
                if(Traverser != accordian.end()){
                    DummyCounter = 0;
                    Traverser--;
                }else{
                    DummyCounter = i;
                    break;
                }
            }
            //if statements check when the traverser hit the accordian.end() position
            //using DummyCounter as a check for the exact moment
            //if DummyCounter at 1 then it increments the position of CurrentCard
            //and sets up check with first neighbor 
            // if Current Card is at the end then it will break out due to only 
            //possible reason for that is that the game is at only one stack 
            if(DummyCounter == 1){
                if(CurrentCard == accordian.begin()){
                    CurrentCard++;
                    Traverser = CurrentCard;
                    Traverser--;
                    if(CurrentCard == accordian.end()){
                        GameContinue = false;
                        break;
                    }
                }
            }
            //this condition 
            if(DummyCounter == 2 || Traverser == accordian.end()){
                Traverser = CurrentCard;
                Traverser--;
            }
            //Checks for third neighbor
            if (((*CurrentCard).peek()[0] == (*Traverser).peek()[0]) || ((*CurrentCard).peek()[1] == (*Traverser).peek()[1])){
                (*Traverser).push((*CurrentCard).pop());
                        SomethingHit = true;
                        GameContinue = true;
                        NeighborHit = true;
                if((*CurrentCard).isEmpty()){
                        accordian.removeAtPosition(CurrentCard);
                }
                CurrentCard = Traverser;
            }
            //Checks for first neighbor 
                if(!NeighborHit){
                    Traverser = CurrentCard;
                    Traverser--;
                    if (((*CurrentCard).peek()[0] == (*Traverser).peek()[0]) || ((*CurrentCard).peek()[1] == (*Traverser).peek()[1])){
                        (*Traverser).push((*CurrentCard).pop());
                        GameContinue = true;
                        NeighborHit = true;
                        SomethingHit = true;
                        if((*CurrentCard).isEmpty()){
                            accordian.removeAtPosition(CurrentCard);
                        }
                        CurrentCard = Traverser;
                    }else{
                        if(SomethingHit && CurrentCard != accordian.begin()){ //checks whether to reset CurrentCard or to continue incrementing it
                            CurrentCard = accordian.begin();
                            Traverser = CurrentCard;
                        }else{
                            CurrentCard++;
                            Traverser = CurrentCard;
                            if(CurrentCard == accordian.end()){
                                break;
                            }
                        }
                        SomethingHit = false; //reset something hit so the CurrentCard can increment
                    }
                }

            }
            //checks if game can continue
            if(!GameContinue){
                break;
            }
        }
        //finds the amount of stacks left
                    for ( it = accordian . begin (); it != accordian . end (); it ++)
                        AmtOfStacks++;
                    cout<<AmtOfStacks<<" Stacks: ";
        //outputs the stacks remaining
                    for ( it = accordian . begin (); it != accordian . end (); it ++){
                            sizeCheck = (*it).getSize();
                             cout << (* it ). peek () << ":"<<sizeCheck<<" ";
                    }
                    cout<<endl;
    return 0;
}