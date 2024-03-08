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
Member* inputInfor(Member* member);
void display(Member* member);
void addNodeMember(MemberNode** list, Member member);
void deleteNodeMember(MemberNode** list, const char* uidDel);
void editNodeMember(MemberNode** list, const char* uidEdit);

int searchByUID(Member* member, const char* uidMem);
int searchByLicenseplate(Member* member, const char* lcpMem);
void searchMember(int (*searchMember)(MemberNode*, const char*), MemberNode* list, const char* info);
#endif // !_MANAGE_H
