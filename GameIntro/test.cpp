#include "test.h"
#include <iostream>


// setup base values
void PrintIntroText(FText IntroText)
{

	constexpr int32 SOME_VALUE = 1;
	//int SomeValue = 0;
	int32 SomeValue{};

	std::cout << IntroText;
	std::cout << std::endl;
	std::cout << "I know Kung-Fu " << SOME_VALUE << " times!\n";

	return;
}

// get information from player
FString GetPlayerName(int32 TryCount)
{
	FString PlayerInput = "";
	std::cout << "Try #" << TryCount << ": Please, enter your Name: ";
	getline(std::cin, PlayerInput);
	std::cout << "Player <" << PlayerInput << "> ready!" << std::endl;

	return PlayerInput;
}

bool GetPlayerResponse()
{
	FString PlayerResponse = "";

	std::cout << "Say yes or no (y/n): ";
	getline(std::cin, PlayerResponse);

	return (PlayerResponse[0] == 'y') || (PlayerResponse[0] == 'Y');
}

bool GameTick()
{

	// Some TIck Logic
	bool result = GetPlayerResponse();

	std::cout << "BEFORE Branching ";

	if (result)
	{
		std::cout << " TRUE " << std::endl << std::endl;
		return true;
	}
	else
	{
		std::cout << " FALSE ";
	}

	std::cout << " AFTER Branching ";

	return false;
}

bool TestCode()
{
	FTestStruct TestVar;
	FTestClass TestVar2;

	std::cout << "Struct Testing\n";
	std::cout << TestVar.MemberVar_0 << " " << TestVar.MemberVar_1 << " " << TestVar.MemberVar_2 << " " << TestVar.GetSomeValue() << "\n\n";

	std::cout << "Class Testing\n";
	std::cout << TestVar2.GetMemberVar_0() << "\n\n";

	return false;
}
