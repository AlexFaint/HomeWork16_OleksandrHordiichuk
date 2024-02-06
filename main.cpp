#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct PlayerInfoStruct
{
	string PlayerName;
	float PlayerPower;
};

map<string, vector<PlayerInfoStruct>> ClanInfoMap;

void AddPlayerToClanList(const string& clanName, const string& playerName, float playerStrength)
{
	PlayerInfoStruct player = { playerName, playerStrength };
	ClanInfoMap[clanName].push_back(player);
}

void PrintPlayersInClan(const string& clanName) //Checing import of player by clan (Show who in the clan, NAME and POWER of player in the clan)
{
	if (ClanInfoMap.find(clanName) != ClanInfoMap.end()) 
	{
		cout << "Players in clan " << clanName << ":" << endl;
		for (const auto& player : ClanInfoMap[clanName])
		{
			cout << "Name: " << player.PlayerName << ", Strength: " << player.PlayerPower << endl;
		}
	}
	else {
		cout << "Clan not found." << endl;
	}
}

int GetPlayerCount(const string& clanName) // How many player in the clan
{	
	if (ClanInfoMap.find(clanName) != ClanInfoMap.end())
	{
		return ClanInfoMap[clanName].size();
	}	
	else
	{
		return 0;
	}
}

int ClanFight(const string& FirstClanName, const string& SecondClanName)
{
	float FirstsClanTotalPower = 0;
	float SecondClanTotallPower = 0;

	if (ClanInfoMap.find(FirstClanName) != ClanInfoMap.end())
	{
		for (const auto& player : ClanInfoMap[FirstClanName])
		{
			//Total Power of all first clan
			FirstsClanTotalPower = FirstsClanTotalPower + player.PlayerPower;
		}
	}
	else
	{
		cout << "Clan not found. " << endl;
	}	
	if (ClanInfoMap.find(SecondClanName) != ClanInfoMap.end())
	{
		for (const auto& player : ClanInfoMap[SecondClanName])
		{
			//Total Power of all second clan
			SecondClanTotallPower = SecondClanTotallPower + player.PlayerPower;
		}
	}
	else
	{
		cout << "Clan not found. " << endl;
	}

	if (FirstsClanTotalPower > SecondClanTotallPower)
	{
		return 1; // Winer First Clan
	}
	else if (FirstsClanTotalPower < SecondClanTotallPower)
	{
		return -1; // Winner Second Clan
	}
	else
	{
		return 0; // Draw
	}

}

int main()
{
	string ClanName;
	string PlayerName;
	float PlayerStrength;	
	int Input;	

	while (true)
	{

		cout << "\n1 - Add new Clan Player: " << endl;
		cout << "2 - Show list of Clan Players: " << endl;
		cout << "3 - Amount of Clan Player: " << endl;
		cout << "4 - Ressult Clan battle: " << endl;
		cout << "0 - Exit;" << endl;

		cin >> Input;

		switch (Input)
		{
		case 0:
		{
			return 0;
		}
		case 1: //Add new Clan Player
		{
			for (int i = 0; i < 1; ++i)
			{
				cout << "Enter Clan Name: ";
				cin >> ClanName;

				cout << "Enter Player Name: ";
				cin >> PlayerName;

				cout << "Enter Player Strength: ";
				cin >> PlayerStrength;

				AddPlayerToClanList(ClanName, PlayerName, PlayerStrength);
			}

			break;
		}
		case 2: //Show list of Clan Players
		{
			string SerchClanName;
			cout << "Enter Clan Name to print players: ";
			cin >> SerchClanName;

			PrintPlayersInClan(SerchClanName);
			break;
		}
		case 3: //Amount of Clan Player
		{
			string SearchAmountOfClanPlayer;
			cout << "Enter Clan Name to print amount of player: ";
			cin >> SearchAmountOfClanPlayer;

			int AmountOfPlayerInTheClan = GetPlayerCount(SearchAmountOfClanPlayer);

			cout << "In the clan " << SearchAmountOfClanPlayer << " : " << AmountOfPlayerInTheClan << " players." << endl;

			break;
		}
		case 4: //Ressult Clan battle
		{
			string FirstClanFightName;
			string SecondClanFightName;
			int ClanFightResult;

			cout << "Enter name of first clan: ";
			cin >> FirstClanFightName;
			cout << endl;

			cout << "Enter name of second clan: ";
			cin >> SecondClanFightName;
			cout << endl;

			ClanFightResult = ClanFight(FirstClanFightName, SecondClanFightName);

			switch (ClanFightResult)
			{
			case 1:
			{
				cout << FirstClanFightName << " is WINNER!!!" << endl;
				break;
			}
			case -1:
			{
				cout << SecondClanFightName << " is WINNER!!!" << endl;
				break;
			}
			case 0:
			{
				cout << "Draw";
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
	}

	return 0;
}