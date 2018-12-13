
#include <gmock/gmock.h>
#include <iostream>
#include <string>

using namespace std;

class Soundex
{
public:
	string Encode( const string &word)
	{
		return( word);
	}
};

/*
Save the first letter. Remove all occurrences of a, e, i, o, u, y, h, w.
Replace all consonants (include the first letter) with digits as in [2.] above.
Replace all adjacent same digits with one digit.
If the saved letter's digit is the same as the resulting first digit, remove the digit (keep the letter).
Append 3 zeros if result contains less than 3 digits. Remove all except first letter and 3 digits after it (This step same as [4.] in explanation above).
 */

using ::testing::Eq;
TEST( SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
	// Arrange
	Soundex soundex;
	//Act
	auto encode = soundex.Encode( "A");
	//Assert
	ASSERT_THAT( encode, Eq("A"));
}

