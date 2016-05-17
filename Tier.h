// Tier.h
#ifndef TIER_H
#define TIER_H TIER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;

enum stallStatus{bestand = 0, verkauft = 1};

class Tier
{
private:

protected:
	string art;
	string name;
	//int t, m, j;char p1, p2;
	stallStatus stallStatus;
	float kaufPreis;
	float verkaufPreis;
	//struct tm kaufDatum;
	//struct tm verkaufDatum;
public:
	Tier();
	~Tier();
	int setzeStallStatus(enum stallStatus);
	int setzeVerkaufPreis(float);
	int holeKaufPreis(float&) const;
	static void Print(Tier*);
	bool operator()(const Tier*) const;

};

class Schwein : public Tier
{
private:

public:
	Schwein();
	~Schwein();
	int schweinEinstellen(vector<Tier*>&);
	int schweinVerkaufen(vector<Tier*>&);
	int schweinLoeschen(vector<Tier*>&);
};

/*
class Kuh : public Tier
{
private:

protected:
	map<struct tm, float>milchTagesleistung;

public:
	Kuh();
	~Kuh();
	int kuhEinstellen(Kuh*);
	int kuhVerkaufen(Kuh*);
}
*/

#endif //#ifndef TIER_H