/*
* File: Manager.cpp
* Author: Thanh Minh Truong
* Date:
* Description: This file is contains function definitions from Manager.h
*/

#include "Manager.h"

/*
* Description: print information of member 
* Input: data of struct Member 
* Output: information of member
*/
void getInfor(Member* member){
	printf("UID: %s\n", member->uid);
	printf("Room Number: %s\n", member->roomNumber);
	printf("Name: %s\n", member->name);
	printf("License Plate: %s\n", member->licensePlate);
	printf("\n");
}


/*
* Description: create new node for new data (member data from struct Member) which is used in linked list
* Input: member is Member data used to stored informatin member in every node
* Output: Return MemberNode pointer
*/
MemberNode* createMemberNode(Member member) {
	MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
	newNode->data = member;
	newNode->next = NULL;
	return newNode;
}

/*
* Description: Add Record new member information at the end of node
* Input: MemberNode, data of Member struct
* Output: New node with corresponding data
* Stauts: completing... (99%)
*/
void addNodeMember(MemberNode** list, Member member) {
	MemberNode* temp;
	temp = createMemberNode(member);

	// If array doesn't have any node yet
	if (*list == NULL) {
		*list = temp;
	}
	else {							// if array has some node
		MemberNode* p = *list;		// use p node instead of list node because we are using pointer, use list will change the structure of linked list
		while (p->next != NULL) {	// which mean the current node is not the last node
			p = p->next;			// check next node until it a last node
		}
		p->next = temp;				// change it next member point to address of new node have just create	
	}
}


void printAllMembers(MemberNode* list) {
    MemberNode* currentNode = list;
    while (currentNode != NULL) {
		getInfor(&(currentNode->data));
        currentNode = currentNode->next;
    }
	printf("\n----------------------------------------\n");
}

/*
* Description: Delete one nodd with uid's member
* Input: List, uid of residential which want to delete
* Output: List with remaining node
* Status: completing... (90%)
*/
void deleteNodeMember(MemberNode** list, const char* uidDel) {

	// p = first address of list 
	MemberNode* p = *list;
	// prev is temporary node is p - represent for previous node in list
	MemberNode* prev = NULL;

	// Browse through all node of list 
	while (p->next != NULL) {
		if (strcmp(p->data.uid, uidDel) == 0) {
			// is there a first node ?
			if (prev == NULL) {
				*list = p->next;
			}
			else {
				// Update next point of previous node 
				prev->next = p->next;
			}
			free(p);
			printf("Member with UID: %s deleted successfully \n", uidDel);	
			return;
		}

		prev = p;
		p = p->next;
	}
	printf("Member with UID %s not found.\n", uidDel);
}

/*
* Description: Edit information of member
* Input: List, uid of residential which want to edit
* Output: List
* Status: completing.... (52%)
*/
void editNodeMember(MemberNode** list, const char* uidEdit) {
	
	MemberNode* p = *list;

	// Use "for" loop to browse through all node 
	for (*list; p != NULL; p = p->next) {
		if (strcmp(p->data.uid, uidEdit) == 0) {
			printf("Information's member : \n");
			getInfor(&p->data);

			// Bo sung doan xu ly thay doi sau
		}
	}
}

int main() {
	MemberNode* list = NULL;

	Member member1 = { "UID001", "101", "John Doe", "ABC123" };
	Member member2 = { "UID002", "102", "Jane Smith", "XYZ789" };
	Member member3 = { "UID003", "103", "Michael Johnson", "DEF456" };
	Member member4 = { "UID004", "104", "John Smith", "GIH100" };
	Member member5 = { "UID005", "105", "Taylor Swith", "MNO101" };
	Member member6 = { "UID006", "106", "Maroon 5", "WVU102" };


	addNodeMember(&list, member1);
	addNodeMember(&list, member2);
	addNodeMember(&list, member3);
	addNodeMember(&list, member4);
	addNodeMember(&list, member5);
	addNodeMember(&list, member6);


	printAllMembers(list);
	editNodeMember(&list, "UID001");

	return 0;
}