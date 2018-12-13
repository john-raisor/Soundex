//
// Created by johnraisor on 12/13/2018.
//

#ifndef FIRSTEXAMPLE_SOUNDEX_H
#define FIRSTEXAMPLE_SOUNDEX_H


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Soundex
{

private:
	string ZeroPad( const string &word) const
	{
		return( (word + "000").substr( 0, 4));
	}
	string Encode1( char c)
	{
		switch( c)
		{

		}
	}
	unordered_map<char,string> CodeForLetter;
public:
	Soundex()
	{
		CodeForLetter['A']="";
		CodeForLetter['B']="1";
		CodeForLetter['C']="2";
		CodeForLetter['D']="3";
		CodeForLetter['E']="";
		CodeForLetter['F']="1";
		CodeForLetter['G']="2";
		CodeForLetter['H']="";
		CodeForLetter['I']="";
		CodeForLetter['J']="2";
		CodeForLetter['K']="2";
		CodeForLetter['L']="4";
		CodeForLetter['M']="5";
		CodeForLetter['N']="5";
		CodeForLetter['O']="";
		CodeForLetter['P']="1";
		CodeForLetter['Q']="2";
		CodeForLetter['R']="6";
		CodeForLetter['S']="2";
		CodeForLetter['T']="3";
		CodeForLetter['U']="";
		CodeForLetter['V']="1";
		CodeForLetter['W']="";
		CodeForLetter['X']="2";
		CodeForLetter['Y']="";
		CodeForLetter['Z']="2";
	}

	string Encode( const string &word) const
	{
		ostringstream wd = word;
		string FirstLetter = wd.left.substr( 0, 1);
		wd = wd.substr( 1);
		ostringstream enc = "";
		while( wd.length() > 0)
		{
			enc = enc + CodeForLetter.find( wd[ 0])->second;
			wd = wd.substr( 1);
		}
		return( ZeroPad( FirstLetter + enc));
	}
};

/*
Save the first letter. Remove all occurrences of a, e, i, o, u, y, h, w.
Replace all consonants (include the first letter) with digits as in [2.] above.
	Replace consonants with digits as follows (after the first letter):
	b, f, p, v → 1
	c, g, j, k, q, s, x, z → 2
	d, t → 3
	l → 4
	m, n → 5
	r → 6

Replace all adjacent same digits with one digit.
If the saved letter's digit is the same as the resulting first digit, remove the digit (keep the letter).
Append 3 zeros if result contains less than 3 digits. Remove all except first letter and 3 digits after it (This step same as [4.] in explanation above).
 */


#endif //FIRSTEXAMPLE_SOUNDEX_H
