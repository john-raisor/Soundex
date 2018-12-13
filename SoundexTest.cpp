
#include <gmock/gmock.h>
#include "Soundex.h"

/*
Save the first letter. Remove all occurrences of a, e, i, o, u, y, h, w.
Replace all consonants (include the first letter) with digits as in [2.] above.
Replace all adjacent same digits with one digit.
If the saved letter's digit is the same as the resulting first digit, remove the digit (keep the letter).
Append 3 zeros if result contains less than 3 digits. Remove all except first letter and 3 digits after it (This step same as [4.] in explanation above).
 */

using ::testing::Eq;
// fixture
class SoundEncodingFixture : public testing::Test
{
public:
	SoundEncodingFixture()
	{

	}

public:
	Soundex soundex;
};
TEST_F( SoundEncodingFixture, RetainsSoleLetterOfOneLetterWordA)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "A"), Eq( "A000"));
}

TEST_F( SoundEncodingFixture, RetainsSoleLetterOfOneLetterWordB)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "B"), Eq( "B000"));
}

TEST_F( SoundEncodingFixture, RetainsSoleLetterOfOneLetterWordZ)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "Z"), Eq( "Z000"));
}

TEST_F( SoundEncodingFixture, RetainsSoleLetterOfOneLetterWordC)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "C"), Eq( "C000"));
}

TEST_F( SoundEncodingFixture, RemovesLetterA)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "AA"), Eq( "A000"));
}

TEST_F( SoundEncodingFixture, PadsWithZerosThreeDigits)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "I"), Eq( "I000"));
}

TEST_F( SoundEncodingFixture, ReplaceConsonantB1)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "AB"), Eq( "A100"));
}

TEST_F( SoundEncodingFixture, ReplaceConsonantC2)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "AC"), Eq( "A200"));
}

TEST_F( SoundEncodingFixture, ReplaceConsonantT3)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "AT"), Eq( "A300"));
}

TEST_F( SoundEncodingFixture, ReplaceConsonantrr)
{
	// Arrange
	// Act, Assert
	ASSERT_THAT( soundex.Encode( "ARR"), Eq( "A600"));
}

