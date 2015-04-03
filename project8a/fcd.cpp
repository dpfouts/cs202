//Project 8 Five Card Draw
//Davis Pfouts 


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include "class.h"
using namespace std;

int main()
{
	//deck for cards unshuffled
	card* dptr=NULL;
	dptr= new card[52];

	ifstream fin;
	ofstream fout;
	fin.clear();
	fin.open("deck");
//read in deck unshuffled
	for(int i=0; i<52; i++)	
{
	fin>>dptr[i];
	dptr[i].setlo("unshuffled");
}
	
	fin.close();

//create aray for all players at table
	player* table = new player[8];

	fin.clear();
	fin.open("players");
//read in players
for (int i=0 ; i<8; i++)
{
	fin>> table[i];
}
//p holds number of players
int p;
cout<< "SELECT NUMBER OF PLAYERS (2-8):";
cin>> p;						
//deck array for shuffled cards
card* deck = new card[52];
// array for stock pile
card* stock=new card[52-(4*p)];
//array for discard pile
card* discard= new card[10];

//these ints are used in the dealing of cards to maintain position in decks
int k=0;
int d=0;


	//MENUE
char choice;
	while (choice != 7)
	{
		cout<< ".....FIVE CARD DRAW..... \n";
		cout<< "============================ \n" << "\n";
		cout<< "1) Print Deck \n";
		cout<< "2) Print Table \n";
		cout<< "3) Shuffle Deck \n";
		cout<< "4) Print Shuffled Deck \n";
		cout<< "5) Deal \n";
		cout<< "6) Print Stock and Discard Pile \n";
		cout<< "7) QUIT \n";
		cout<< "Please Enter Your Selection: \n";
		cin>> choice;
		cout<< endl;

	switch (choice)
	{
case '1'://this prints the unshuffled deck array
for(int i=0; i<52; i++)
	{
		cout<<dptr[i];
	}
break;

case '2':// prints out all the data for the players at the table
for (int i=0; i<p; i++)	
	{
		cout<< table[i];
	}						
break;

case '3'://this creates a new deck of shuffled cards insureing no cards are repeated
for(int i=0; i<52; i++)
	{
		deck[i]=dptr[i];
		deck[i].setlo("shuffled");
	}
//here is where i actually shuffle the deck	
for (int i=0; i<(52-1); i++) 
	{
    	int r = i + (rand() % (52-i)); 
        card temp = deck[i]; 
        deck[i] = deck[r]; 
        deck[r] = temp;
    }

cout<< "Deck Shuffled! \n";

break;

case'4'://prints the new array of shuffled cards called deck
for(int i=0; i<52; i++)
	{
		cout<<deck[i]<< "\n";
	}
break;

case '5':
k=0;//resets to 0 so you can deal more than once
for(int i=0; i<5; i++)
	{
		for(int j=0 ; j<p; j++)
			{	
				deck[k].setlo("in hand");
				table[j].sethand(deck[k],i);
				k++;
			}
	}
//discards one card after dealing the players hands
deck[k].setlo("discard pile");
discard[0]= deck[k];
k++;
//next few lines put all unused cards into the stock pile
d=0;
for(int i=k; i<52; i++)
	{
		deck[i].setlo("stock pile");
		stock[d]= deck[i];
		k++;
		d++;
	}
cout<<"CARDS DEALT PRINT TABLE TO SEE HANDS"<< endl;
break;

case '6'://prints the stock pile array as well as the discard pile
cout<< "Stock Pile:\n";
// this loop sizes the stock pile based on how many players int p from beginning of program
for (int i=0; i <51-(p*5); i++)
	{
		cout<< stock[i]<<endl;
	}

cout<<"Discard Pile: \n";
cout<< discard[0]<<endl;
break;

case '7':// seven fufills the requirement to end the program from the menue
	cout<< "Goodbye" << endl;
	choice = 7;
break;

	default: cout<< choice << "  is not a valid entry \n";
		 cout<< endl;
	break;


	}

}

//test area for unsued functions
if(dptr[0]>dptr[1]){
	cout<< dptr[0]<< " is greater than "<< dptr[1]<<endl;
}
else{ cout<<dptr[0]<< " is less than "<< dptr[1]<<endl;}

if(dptr[0]>=dptr[1]){
	cout<< dptr[0]<<" is greater than or equal to "<< dptr[1]<< endl;
}
else{ cout<< dptr[0]<<" is less than"<< dptr[1]<<endl;}

dptr[0]<dptr[1];


//deleting pointers
	delete[] discard;
	delete[] dptr;
	delete[] deck;
	delete[] stock;

	return 0;

}