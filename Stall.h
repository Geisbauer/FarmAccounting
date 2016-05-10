// Stall.h
#pragma once
#ifndef STALL_H
#define STALL_H STALL_H

#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Tier.h"

int sichernAufPlatte(vector<Tier*>&, string);
int einlesenVonPlatte(vector<Tier*>&, string);

class Stall
{
	private:
		vector<Tier*>stallTiere;

	protected:

	public:
		Stall();
		~Stall();

	friend int einlesenVonPlatte(vector<Tier*>&, string);

	friend int einlesenVonPlatte(vector<Tier*>&, string);
};


#endif //#ifndef STALL_H
