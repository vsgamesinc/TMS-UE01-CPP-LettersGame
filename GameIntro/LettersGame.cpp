#include "LettersGame.h"




FLettersGame::FLettersGame()
{
	Reset();
}

void FLettersGame::Reset()
{
	MaxTries = 6;
	CurrentTry = 1;

	return;
}

int32 FLettersGame::CommitAnswer(FString Answer)
{
	int32 result = 0;
	int32 HiddenWordLength = HiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		if (Answer[i] == HiddenWord[i])
		{
			result += 1;
		}
		else
		{
			// ...
		}
	}

	CurrentTry++;

	return result;
}

EWordStatus FLettersGame::ValidateAnswer(FString Answer) const
{
	if (Answer.length() != HiddenWord.length())
	{
		return EWordStatus::Wrong_Length;
	}
	else if (!IsLowercase(Answer))
	{
		return EWordStatus::Not_Lowercase;
	}
	else
	{
		return EWordStatus::OK;
	}
}

bool FLettersGame::AreYouWinningSon()
{
	return false;
}


int32 FLettersGame::GetMaxTries() const { return MaxTries; }
int32 FLettersGame::GetCurrentTry() const { return CurrentTry; }

bool FLettersGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))			// !islower('k') -!true = false; !islower('K') - !false = true
		{
			return false;
		}
	}
	/*
	for (int i = 0; i < Word.length(); i++)
	{
		Word[i]
	}
	*/

	return true;
}
