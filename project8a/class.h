#include <iostream>
#include <fstream>
using namespace std;

////////////////////////////////////////////////////////////////////
class card
{
	friend bool operator<(const card&, const card&);
	public:

		card();
		card(const card&);
		~card();
		void setlo(const string&);
		 card& operator=(const card&);
         bool operator==(const card&) const;
         bool operator>(const card&) const;
         bool operator>=(const card&) const;
		 friend ostream& operator<<(ostream&, card&);
         friend ifstream& operator>>(ifstream&, card&);

	private:
	string suit;
	string rank;
	string location;
	int value;
};

class player
{
	public:
		player();
		~player();
		 void sethand(const card&, int);
		 friend ostream& operator<<(ostream&, player&);
         friend ifstream& operator>>(ifstream&, player&);

	private:
	string name;
	card* hand;
	float bet;
	
};



