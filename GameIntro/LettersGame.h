#pragma once

#include <string>

using int32 = int;
using FText = std::string;
using FString = std::string;

/*
LettersGame �����
===������� ����===
* ���� ���������� ����� (6 ����) (!!!)
* ���� ���������� ������� �� ���������� ����� +++++++++++++++++++++++++++++++++++++++++++++++++++++
*** ���� � ������ ���� ��������� ������� (++), ����� ������ ����� (!!!!) ++++++++++++++++++++++++++++++++++++++
*** ����� ������������ � �������� (����������) !!!!!!!
* ��������� �� ��� ��� ���� �� ������� ����� (�������) ��� �� ���������� ������� (��������) +++++
*/


/* 
1. ������� strongly typed enum ��� �������� ������ ��������� ������, ������� ���� �����
1.5. ��������� ���� ������, ������� ����� �������������� (�� �������� ��� ��, ��� ������ ����� �� ����)
2. ���������� ������� ��������� ���, ����� ��� ���������� ���� ������
3. ���������, ��� �� �������������/��������.
*/
enum class EWordStatus
{
	None,			// Initial state
	OK,				// Everithing is OK
	Wrong_Length,	// Answer words length is incorrect
	Not_Lowercase	// We need word in lowercase to type in
};

class FLettersGame
{
	
public:
	FLettersGame();
	
	void Reset();										// ���������� ����
	EWordStatus ValidateAnswer(FString Answer) const;	// �������� �������� ������� ������
	bool AreYouWinningSon();							// ��������, �� ������� � ������ ������� ������

	int32 GetMaxTries() const;		// �������� ���������� ������� �� ������� ������
	int32 GetCurrentTry() const;	// �������� ����� ������� �������

	// GameIteration
	int32 CommitAnswer(FString);							// �������, ������� ��������� ���� ������ �� �������...


/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
private:
	int32 MaxTries = 6;			// maximum game loop iterations
	int32 CurrentTry = 1;		// current game loop iteration

	// Word to Find
	FString HiddenWord = "unreal";

	// Utilities
	bool IsLowercase(FString) const;

};