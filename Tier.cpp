// Tier.cpp
#include "Tier.h"

using namespace std;

Tier::Tier()
{
	kaufPreis = NAN;
	verkaufPreis = NAN;
}

Tier::~Tier()
{

}

int Tier::setzeStallStatus(enum stallStatus stallStatus)
{
	if(this->stallStatus == bestand)
	{
		this->stallStatus = stallStatus;
		return 0;
	}
	else //stallStatus "verkauft" kann nicht auf "bestand" geaendert werden. 
	{
		return -1;
	}
}

int Tier::setzeVerkaufPreis(float verkaufPreis)
{
	if(this->stallStatus == bestand)
	{
		this->verkaufPreis = verkaufPreis;
		return 0;
	}
	else //stallStatus muss noch auf "bestand" stehen, um verkaufPreis einzuspeichern;
	{
		return -1;
	}
}

int Tier::holeKaufPreis(float& kaufPreis) const
{
	kaufPreis = this->kaufPreis;
	return 0;
}

void Tier::Print(Tier* tier)
{
		cout << " Art: " << tier->art  << " Name: " << tier->name << endl;
		cout << " StallStatus: " << tier->stallStatus << endl;
		if (!isnan(tier->kaufPreis)) { cout << " KaufPreis: " << tier->kaufPreis << endl;};
		if (!isnan(tier->verkaufPreis)) { cout << " VerkaufPreis: " << tier->verkaufPreis << endl; };
}

bool Tier::operator()(const Tier* t) const
{
	return (t->name == name);
}

Schwein::Schwein()
{
	art = "";
	name = "";
	kaufPreis = NAN;
	verkaufPreis = NAN;
}

Schwein::~Schwein()
{
}

int Schwein::schweinEinstellen(vector<Tier*>& meineTiere)
{
	cout << "\nSchwein einstellen" << endl;
	this->art = "Schwein";
	cout << "Name?" << endl;
	cin >> this->name;
	cout << "Preis?" << endl;
	cin >> this->kaufPreis;
	this->stallStatus = bestand;

	meineTiere.push_back(this);

	return 0;
}

int Schwein::schweinVerkaufen(vector<Tier*>& meineTiere)
{
	float kaufPreis, verkaufPreis;
	cout << "\nSchwein verkaufen" << endl;
	cout << "Name?" << endl;
	cin >> this->name;

	vector<Tier*>::iterator meineTiereIter;
	meineTiereIter = find_if(meineTiere.begin(),meineTiere.end(),(*this));

	if(meineTiereIter != meineTiere.end())
	{
		cout << "Tier gefunden" << endl;
		cout << "Preis?" << endl;
		cin >> verkaufPreis;
		(*meineTiereIter)->holeKaufPreis(kaufPreis);
		cout << "Verkaufserfolg: " << (verkaufPreis - kaufPreis) << endl;
		(*meineTiereIter)->setzeVerkaufPreis(verkaufPreis);
		(*meineTiereIter)->setzeStallStatus(verkauft);
		return 0;
	}
	else
	{
		cout << "Tier nicht gefunden" << endl;
		return -1;
	}
}

int Schwein::schweinLoeschen(vector<Tier*>& meineTiere)
{
	cout << "Schwein loeschen" << endl;
	cout << "Name?" << endl;
	cin >> this->name;
	
	//vector<Tier*>::iterator meineTiereIter;
	//meineTiereIter = find_if(meineTiere.begin(),meineTiere.end(),(*this));
	auto meineTiereIter = find_if(meineTiere.begin(),meineTiere.end(),(*this));

	if(meineTiereIter != meineTiere.end())
	{
		cout << "Tier gefunden" << endl;
		delete (*meineTiereIter);
		meineTiere.erase(meineTiereIter);
		cout << "Neue Anzahl der Tiere: " << meineTiere.size() << endl;
		return 0;
	}
	else
	{
		cout << "Tier nicht gefunden" << endl;
		return -1;
	}
}