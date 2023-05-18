#pragma once

#include <string>

using FText = std::string;
using FString = std::string;
using int32 = int;


enum class EStatus
{
	None,
	OK
};


struct FTestStruct
{
	int32 MemberVar_0 = 1;
	bool MemberVar_1 = false;
	int32 MemberVar_2 = 2;

	int32 GetSomeValue()
	{
		return 5;
	}
};

class FTestClass
{
	int32 MemberVar_0 = 1;
	bool MemberVar_1 = false;
	int32 MemberVar_2 = 2;

public:
	
	int32 GetMemberVar_0()
	{
		return MemberVar_0;
	}
};

void PrintIntroText(FText IntroText);
FString GetPlayerName(int32 TryCount);
bool GetPlayerResponse();
bool GameTick();

bool TestCode();