#include "class.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// PLAYER CLASS MEMBERS
player::player()
{
	name = "first last";
	hand= new card[5];
	bet = 0.0;
}


player::~player()
{
	name="";
	delete[] hand;				
	bet = 0.0;

}

void player::sethand(const card& a, int x)
{
	hand[x]= a;
}

ostream& operator<< (ostream& o, player& a)
{
	o << "name: " << a.name << "\n hand: "<<"\n"<< a.hand[0]<<a.hand[1]<<a.hand[2]<<a.hand[3]<< a.hand[4]<< "\t  bet: " << a.bet<< endl ;
}

ifstream& operator>> (ifstream& i , player& a)
{
	char* str1= new char[10];
	char* str2= new char[10];

	i >> str1 >> str2 ;

	strcat(str2," ");
	strcat(str2, str1);

	a.name=str2;
delete[] str1;
delete[] str2;
}


//CARD MEMBERS

card::card()
{
	suit="";
	rank="";
	location="";
	value=0;

}

card::~card()
{
	suit="";
	rank="";
	location="";
	value =0;
	
}

card::card(const card& t)
{

	suit = t.suit ;
	rank = t.rank ;
	location = t.location ;
	value = t.value;
}

void card::setlo(const string& a)
{
	location = a;
}

ostream& operator<< (ostream& o, card& a)
{
	o << "  suit: " << a.suit << "\t  rank: "<< a.rank <<"\t  location: " << a.location << endl;
}

ifstream& operator>> (ifstream& i , card& a)
{
	i >> a.suit >> a.rank >> a.value ;
	a.location = "unshuffled";
}

card& card::operator=( const card &cpy)
{
	suit = cpy.suit;
	rank = cpy.rank;
	value = cpy.value;
	location=cpy.location;
	
return *this;
}

 
bool card::operator>(const card& comp)const
{
	if (comp.value > value)
		{
			return true;
		
		}
	else
		{
			return false;}
		}

bool card::operator>=(const card& comp) const
{
	if(comp.value > value || comp.value== value)
		{
			return true;
		}
	else
		{ 
			return false;
		}
}

bool operator<(const card& comp1, const card& comp2) 
{
	if(comp1.value < comp2.value)
		{
			return true;
		}
	else
		{ 
			return false;
		}
}