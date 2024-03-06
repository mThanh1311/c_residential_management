/*
* File: Manager.h
* Author: Thanh Minh Truong
* Date: 
* Description: This file contains all functions use for this project
*/
#ifndef _MANAGE_H
#define _MANAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Member {
	char uid[9];			// UID of RFID ( 9 characters)
	char roomNumber[20];	// Room number
	char name[50];			// Name 
	char licensePlate[20];	// License plate
} Member;

typedef struct MemberNode {
	Member data;
	struct MemberNode* next;
} MemberNode;


MemberNode* createMemberNode(Member member);
void getInfor(Member* member);
void addNodeMember(MemberNode** list, Member member);
void deleteNodeMember(MemberNode** list, const char* uidDel);
void editNodeMember(MemberNode** list, const char* uidEdit);
#endif // !_MANAGE_H
