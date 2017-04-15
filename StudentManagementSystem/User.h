#ifndef _USER_H_
#define _USER_H_	
#include "StructuredData.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function for showing menu's user
int menuStudent(Node<User>* user);
int menuLecturer(Data &data, Node<User>* user);
int menuAcedemicStaff(Data &data);
int menuAdminstrator(List<User> &listUser);

// Function for login
bool isExistedUser(string username, List<User> listUser);
Node<User>* isTruePassword(string username, string password, List<User> listUser);
int showMenu(Node<User>* user, Data &data);

// Function for modifying user information
int modifyUserInfo(Node<User> *user);
bool changePassword(string &password);
bool isCompleted();

#endif // !_USER_H_