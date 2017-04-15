#ifndef _ACEDEMICSTAFF_H_
#define _ACEDEMICSTAFF_H_
#include "StructuredData.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void outputStd(Node<User>* std);

void output(List<User> l);

void readFile(ifstream &f, List<User> &l);

void deleteStd(ifstream &f, List<User> &l);

void addStudent(List<User> &l);

void outfile(List<User> &l, string fileOut);
#endif // !_ACEDEMICSTAFF_H_
