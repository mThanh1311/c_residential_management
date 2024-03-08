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
void display(Member* member){
	printf("UID: %s\n", member->uid);
	printf("Room Number: %s\n", member->roomNumber);
	printf("Name: %s\n", member->name);
	printf("License Plate: %s\n", member->licensePlate);
	printf("\n");
}


void printAllMembers(MemberNode* list) {
	MemberNode* p = list;
	while (p != NULL) {
		display(&(p->data));
		p = p->next;
	}
	printf("\n----------------------------------------\n");
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
* Description: Enter the information of member  
* Input: data of struct Member
* Output: member
*/
Member* inputInfor(Member* member) {
	printf("\nUID: "); 
	fgets(member->uid, sizeof(member->uid), stdin);
	printf("\nRoom number: "); 
	fgets(member->roomNumber, sizeof(member->roomNumber), stdin);
	printf("\nName: "); 
	fgets(member->name, sizeof(member->name), stdin);
	printf("\nLicense plate: "); 
	fgets(member->licensePlate, sizeof(member->licensePlate), stdin);
	return member;
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
* Status: completing.... (85%)
*/
void editNodeMember(MemberNode** list, const char* uidEdit) {
	
	MemberNode* p = *list;

	// Use "for" loop to browse through all node 
	for (*list; p != NULL; p = p->next) {
		if (strcmp(p->data.uid, uidEdit) == 0) {

			// Bo sung doan xu ly thay doi sau
			printf("What is your changes ?\n");
			inputInfor(&p->data);

			printf("\nInformation's member after change: \n");
			display(&p->data);
			printAllMembers(p);
		}
	}

	// Not found this member information
	printf("Member with UID %s not found.\n", uidEdit);
}

/*
* Description: Searching information of member by using UID  
* Input: Member Node, uid
* Output: corresponding information or not found this information
*/
int searchByUID(MemberNode* list, const char* uidMem) {

	MemberNode* p = list;

	// Browse through all node for list MembeNode 
	// Comparing the uid of member data with uid which want to find
	for (p; p != NULL; p = p->next) {
		// True
		if (strcmp(p->data.uid, uidMem) == 0) {
			display(&p->data);
			return 1;
		}
	}

	//False
	return 0;
}

/*
* Description: Searching information of member by using Licnese plate
* Input: Member Node, license plate information
* Output: corresponding information or not found this information
*/
int searchByLicenseplate(MemberNode* list, const char* lcpMem) {

	MemberNode* p = list;

	// Browse through all node for list MembeNode 
	// Comparing the license plate of member data with license plate which want to find
	for (p; p != NULL; p = p->next) {
		// True
		if (strcmp(p->data.licensePlate, lcpMem) == 0) {
			display(&p->data);
			return 1;
		}
	}

	// False
	return 0;
}

/*
* Description: Using function pointer to shorten function calls
* Input: Search function based on one information, list, information we need to find
* Output: display this data or print not found
*/
void searchMember(int (*searchMember)(MemberNode*, const char*), MemberNode* list, const char* info) {
	MemberNode* p = list;

	while (p != NULL) {
		if ((searchMember(p, info)) == 1) {
			return;
		}
		else {
			p = p->next;
		}
	}
	// If not found
	printf("\nWe cannot found this information! Please try again\n");
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


	searchMember(searchByUID, list, "UID003");

	return 0;
}