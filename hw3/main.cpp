// deneme.cpp : Defines the entry point for the console application.
//Library definitions 
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


typedef struct veri {								//created a struct named veri
	int k;											//it contains int k and string v
	std::string v;
}v;

int i;												//number of collisions

// function definitions
int hLinearm1(v data);								//Linear Probing Hash funciton		
int hLinearm2(v data);
int hDoublem1(v data,int i);
int h1m1(int k);
int h1m2(int k);
int hDoublem2(v data,int i);
int h2m1(int k);
int h2m2(int k);
void insertLinearm1(v data);						//Insert Function of Linear Probing Hash
void insertLinearm2(v data);
void insertDoublem1(v data);
void insertDoublem2(v data);
std::string searchLinearm1(v data);					//Search Function of Linear Probing
std::string searchLinearm2(v data);
std::string searchDoublem1(v data);
std::string searchDoublem2(v data);
void printm1();										//Print the Hash table function
void printm2();

v table1[17863];
v table2[21929];									//created a variable named table type veri

int hLinearm1(v data) {								
	int hashed;										
	hashed = (data.k +i) % 17863;
	return hashed;									// hashed string and key pairs
}
int hLinearm2(v data) {
	int hashed;
	hashed = (data.k + i) % 21929;
	return hashed;
}

int hDoublem1(v data, int i) {
	int key = data.k;
	return (h1m1(key) + i * h2m1(key)) % 17863;
}
int h1m1(int k) {
	return k % 17863;
}
int h2m1(int k) {
	return 23 - (23 % 17863);
}

int hDoublem2(v data, int i) {
	int key = data.k;
	return (h1m2(key) + i * h2m2(key)) % 21929;
}
int h1m2(int k) {
	return k % 21929;
}
int h2m2(int k) {
	return 23 - (23 % 21929);
}


void insertLinearm1(v data) {					//Insert Function of Linear Probing Hash
	if (table1[hLinearm1(data)].k == -1) {		//Empty slot case
	table1[hLinearm1(data)] = data;
	}
	else {										//full slot case
		int indis = hLinearm1(data);
		while (table1[indis].k != -1) {
			indis++;
			i++;
			if (indis > 17863) {
			indis = 0;
			}
		}
	table1[indis]= data;
	}
}

void insertLinearm2(v data) {					//Insert Function of Linear Probing Hash
	if (table2[hLinearm2(data)].k == -1) {		//Empty slot case
		table2[hLinearm2(data)] = data;
	}
	else {										//full slot case
		int indis = hLinearm2(data);
		while (table2[indis].k != -1) {
			indis++;
			i++;
			if (indis > 21929) {
				indis = 0;
			}
		}
		table2[indis] = data;
	}
}

void insertDoublem1(v data) {
	if (table1[hDoublem1(data,i)].k == -1) {		//Empty slot case
		table1[hDoublem1(data,i)] = data;
	}
	else {										//full slot case
		int indis = hDoublem1(data,i);
		while (table1[indis].k != -1) {
			indis++;
			i++;
			if (indis > 17863) {
				indis = 0;
			}
		}
		table1[indis] = data;
	}
}

void insertDoublem2(v data) {
	if (table2[hDoublem2(data,i)].k == -1) {		//Empty slot case
		table2[hDoublem2(data,i)] = data;
	}
	else {										//full slot case
		int indis = hDoublem2(data,i);
		while (table2[indis].k != -1) {
			indis++;
			i++;
			if (indis > 21929) {
				indis = 0;
			}
		}
		table2[indis] = data;
	}
}

std::string searchLinearm1(v data) {						//Search Function of Linear Probing Hash
	if (table1[hLinearm1(data)].k == -1) {					//non existing data
		printf("olmayan deger araniyor");
		return "-1";
	}

	else if (table1[hLinearm1(data)].k == data.k && table1[hLinearm1(data)].v == data.v) {
		return table1[hLinearm1(data)].v;
	}

	else if (table1[hLinearm1(data)].k == data.k && table1[hLinearm1(data)].v != data.v) {
		int x = hLinearm1(data);
		while (table1[x].v != data.v) {					//Goes next slot until the value matches
			x = x++;
		}
		return table1[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
	}
	return "-1";
}

std::string searchLinearm2(v data) {						//Search Function of Linear Probing Hash
	if (table2[hLinearm2(data)].k == -1) {					//non existing data
		printf("olmayan deger araniyor");
		return "-1";
	}

	else if (table2[hLinearm2(data)].k == data.k && table2[hLinearm2(data)].v == data.v) {
		return table1[hLinearm2(data)].v;
	}

	else if (table1[hLinearm2(data)].k == data.k && table2[hLinearm2(data)].v != data.v) {
		int x = hLinearm2(data);
		while (table2[x].v != data.v) {					//Goes next slot until the value matches
			x = x++;
		}
		return table2[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
	}
	return "-1";
}

std::string searchDoublem1(v data) {
	//Search Function of Linear Probing Hash
	if (table1[hDoublem1(data, i)].k == -1) {					//non existing data
		printf("olmayan deger araniyor");
		return "-1";
	}
	//Not Collision and existing data
	else if (table1[hDoublem1(data, i)].k == data.k && table1[hDoublem1(data, i)].v == data.v) {
		return table1[hDoublem1(data, i)].v;
	}
	//Collision case
	else if (table1[hDoublem1(data, i)].k == data.k && table1[hDoublem1(data, i)].v != data.v) {
		int x = hDoublem1(data, i);
		while (table1[x].v != data.v) {					//Goes next slot until the value matches
			x = x++;
		}
		return table1[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
		return "-1";
	}

}

std::string searchDoublem2(v data) {						//Search Function of Linear Probing Hash
	if (table2[hDoublem2(data,i)].k == -1) {					//non existing data
		printf("olmayan deger araniyor");
		return "-1";
	}
	//Not Collision and existing data
	else if (table2[hDoublem2(data,i)].k == data.k && table2[hDoublem2(data,i)].v == data.v) {
		return table2[hDoublem2(data,i)].v;
	}
	//Collision case
	else if (table2[hDoublem2(data,i)].k == data.k && table2[hDoublem2(data,i)].v != data.v) {
		int x = hDoublem2(data,i);
		while (table2[x].v != data.v) {					//Goes next slot until the value matches
			x = x++;
		}
		return table2[x].v;
	}
	//Error case
	else {
		std::cout << "Error at search" << std::endl;
		return "-1";
	}
	
}





void printm1() {											//Print the table function
	for (int i = 0; i < 17865; i++) {
		std::cout << table2[i].k << " " << table2[i].v << std::endl;
	}
	std::cout << "collision count " << i << std::endl;
}

void printm2() {											//Print the table function
	for (int i = 0; i < 22000; i++) {
		std::cout << table2[i].k << " " << table2[i].v << std::endl;
	}
	std::cout << "collision count " << i << std::endl;
}

int main()
{
	v data;
	for (int i = 0; i < 22000; i++) {					//default -1 added to every slot in table
		table2[i].k = -1;
	}
	std::ifstream myfile;
	myfile.open("vocab.txt");
	if (!myfile.is_open()) {
		std::cout << "Error cannot read from the file";
	}
	std::string vocab;
	int line = 0;

	while (!myfile.eof()) {
		getline(myfile, vocab);
		data.v = vocab;
		data.k = line;
		insertDoublem2(data);
		line++;
	}
	
	//printm1();
	//printm2();
	
	

	system("pause");
	return 0;
}

