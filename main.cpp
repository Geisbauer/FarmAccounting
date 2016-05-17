#include <algorithm>
#include <iostream>
#include <vector>
#include "Tier.h"
#include "Stall.h"

using namespace std;

int main(int argc, char* argv[])
{
	int auswahl = 1;
	int erg = -1;
	//Stall meineTiere;
	vector<Tier*>meineTiere(0);

	while(auswahl != 0)
	{
		cout << endl << endl;
		cout << "   ... Bitte waehle aus ..." << endl;
		cout << "_____________________________" << endl;
		cout << " 0 ... Programm beenden." << endl;
		cout << " 1 ... Datenbank einlesen." << endl;
		cout << " 2 ... Datenbank speichern." << endl;
		cout << " 3 ... Bestand auflisten." << endl;
		cout << "11 ... Schwein einstellen." << endl;
		cout << "12 ... Schwein verkaufen." << endl;
		cout << "13 ... Schwein loeschen." << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		/*
		cout << "21 ... Kuh einstellen." << endl;
		cout << "22 ... Kuh verkaufen." << endl;
		cout << "23 ... Milchtagesleistung verbuchen." << endl;
		cout << "31 ... Huhn einstellen."  << endl;
		cout << "32 ... Huhn verkaufen."  << endl;
		cout << "33 ... Eier verbuchen."  << endl;
		*/
		cin >> auswahl;

		switch(auswahl)
		{
			case 1:
			{
				cout << " 1 ... Datenbank einlesen" << endl;
				erg = einlesenVonPlatte(meineTiere, "FarmAccounting.txt");
				break;
			}
			case 2:
			{
				cout << " 2 ... Datenbank speichern" << endl;
				erg = sichernAufPlatte(meineTiere, "FarmAccounting.txt");
				break;
			}
		case 3:
			{
				cout << " 3 ... Bestand auflisten" << endl;
				cout << "Anzahl der Tiere: " << meineTiere.size() << endl;
				for_each(meineTiere.begin(),meineTiere.end(),&Tier::Print);
				break;
			}
		case 11:
			{
				Schwein* pSchwein = new Schwein();
				erg = pSchwein->schweinEinstellen(meineTiere);
				//delete pSchwein;
				break;
			}	
		case 12:
			{
				Schwein* pReferenzSchwein = new Schwein();
				erg = pReferenzSchwein->schweinVerkaufen(meineTiere);
				delete pReferenzSchwein;
				break;
			}
		case 13:
			{
				Schwein* pReferenzSchwein = new Schwein();
				erg = pReferenzSchwein->schweinLoeschen(meineTiere);
				delete pReferenzSchwein;
				break;
			}
		default:
			erg = -1;
		}

		if(auswahl != 0 && erg == -1)
		{
			cout << " Transaktion wurde nicht durchgefuehrt wegen fehlerhafter Eingabe.\nVersuche es nocheinmal ...";
		}
	}
	cout << " Das Programm wird beendet!" << endl;
	return 0;
}

