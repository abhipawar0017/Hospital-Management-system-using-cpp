#include <iostream> 
#include <ctime> 
#include <cstdlib> 
#include <stdio.h> 
#include <string.h> 
using namespace std; 
struct patient 
{ 
int patient_id; 
char first_name[20]; 
char last_name[20]; 
char patient_phonenumber[10]; 
int patient_age; 
char patient_gender[8]; 
struct patient *next; 
}; 
struct patient *header, *last_partner; 
bool checking = true; 
int array[20] = {0}, v = 0; 
bool check_id(int ch) 
{ 
for (int y = 0; y < v; y++) 
{ 
if (ch == array[y]) 
{ 
return true; 
} 
} 
return false; 
}; 
class Doctor 
{ 
public: 
void add() 
{ 
patient *pat; 
pat = new patient; 
cout << "Enter Patient ID" << endl; 
cin >> pat->patient_id; 
cout << "Enter Patient First Name" << endl; 
cin >> pat->first_name; 
cout << "Enter Patient Last name" << endl; 
cin >> pat->last_name; 
cout << "Enter Patient Age" << endl; 
cin >> pat->patient_age; 
cout << "Enter Patient Gender" << endl; 
cin >> pat->patient_gender; 
cout << "Enter Patient Contact " << endl; 
cin >> pat->patient_phonenumber; 
pat->next = NULL; 
array[v] = pat->patient_id; 
v++; 
if (checking) 
{ 
header = pat; 
last_partner = pat; 
checking = false; 
} 
else 
{ 
last_partner->next = pat; 
last_partner = pat; 
 } 
 } 
 void addSampleData1() 
 { 
 patient *pat; 
 pat = new patient; 
 pat->patient_id = 101; 
 strcpy(pat->first_name, "Raja"); 
 strcpy(pat->last_name, "Ram"); 
 pat->patient_age = 60; 
 strcpy(pat->patient_gender, "Male"); 
 strcpy(pat->patient_phonenumber, "987654321"); 
 pat->next = NULL; 
 array[v] = pat->patient_id; 
 v++; 
 if (checking) 
 { 
 header = pat; 
 last_partner = pat; 
 checking = false; 
 } 
 else 
 { 
 last_partner->next = pat; 
 last_partner = pat; 
 } 
 } 
 void addSampleData2() 
 { 
 patient *pat; 
 pat = new patient; 
 pat->patient_id = 102; 
 strcpy(pat->first_name, "Rama"); 
 strcpy(pat->last_name, "Raj"); 
 pat->patient_age = 56; 
 strcpy(pat->patient_gender, "Male"); 
 strcpy(pat->patient_phonenumber, "123456789"); 
 pat->next = NULL; 
 array[v] = pat->patient_id; 
 v++; 
 if (checking) 
 { 
 header = pat; 
 last_partner = pat; 
 checking = false; 
 } 
 else 
 { 
 last_partner->next = pat; 
 last_partner = pat; 
 } 
 } 
 void show() 
 { 
 int z; 
 patient *cur = NULL, *previous = NULL; 
 previous = header; 
 cur = header; 
 int change; 
 cout << "Enter Patient ID" << endl; 
 cin >> change; 
 if (check_id(change)) 
{ 
while (cur->patient_id != change) 
{ 
previous = cur; 
cur = cur->next; 
} 
cout << "The Patient First Name" << endl; 
cout << cur->first_name << endl; 
cout << "The Patient Last Name" << endl; 
cout << cur->last_name << endl; 
cout << "The Patient ID" << endl; 
cout << cur->patient_id << endl; 
cout << "The Patient Age" << endl; 
cout << cur->patient_age << endl; 
cout << "The Patient Gender" << endl; 
cout << cur->patient_gender << endl; 
} 
else 
{ 
cout << "ID not present" << endl; 
} 
} 
void deleteList() 
{ 
int counter = 0; 
patient *cur = NULL, *previous = NULL; 
previous = header; 
cur = header; 
int change; 
cout << "Enter the ID: "; 
cin >> change; 
 if (check_id(change)) 
 { 
 while (cur->patient_id != change) 
 { 
 previous = cur; 
 cur = cur->next; 
 } 
 previous->next = cur->next; 
 free(cur); 
 for (int v = 0; v < v; v++) 
 { 
 if (array[v] == change) 
 { 
 for (int y = v; y < v; y++) 
 { 
 array[y] = array[y + 1]; 
 } 
 v--; 
 } 
 } 
 cout << "SUCCESSFULLY DELETED THE RECORD\n"; 
 } 
 else 
 cout << "ID not present" << endl; 
 } 
 void update_menu() 
 { 
 cout << "Enter 1 Patient First Name" << endl; 
 cout << "Enter 2 Patient Last Name" << endl; 
 cout << "Enter 3 Patient ID" << endl; 
 cout << "Enter 4 Patient Age" << endl; 
 cout << "Enter 5 Patient Gender" << endl; 
 } 
 void update_data() 
 { 
 patient *cur = NULL, *previous = NULL; 
 cur = header; 
 previous = header; 
 int patient_id, change; 
 cout << "Enter ID" << endl; 
 cin >> patient_id; 
 if (check_id(patient_id)) 
 { 
 while (cur->patient_id != patient_id) 
 { 
 previous = cur; 
 cur = cur->next; 
 } 
 update_menu(); 
 cout << "Choose Number" << endl; 
 cin >> change; 
 if (change == 1) 
 { 
 cout << "Enter First Name" << endl; 
 cin >> cur->first_name; 
 } 
 else if (change == 2) 
 { 
 cout << "Enter Last Name" << endl; 
 cin >> cur->last_name; 
 } 
 else if (change == 3) 
{ 
cout << "Enter ID" << endl; 
cin >> cur->patient_id; 
} 
else if (change == 4) 
{ 
cout << "Enter Age" << endl; 
cin >> cur->patient_age; 
} 
else if (change == 5) 
{ 
cout << "Enter Gender" << endl; 
cin >> cur->patient_gender; 
} 
} 
else 
cout << "ID not present" << endl; 
} 
}; 
void display_menu_Patients() 
{ 
cout << "|=================================|" << endl; 
cout << "| 1. Add Patient Record |" << endl; 
cout << "|=================================|" << endl; 
cout << "Enter the number you want to Choose:" << endl; 
} 
void display_menu_Receptionist() 
{ 
cout << "|=================================|" << endl; 
cout << "| 1. Add Patient Record |" << endl; 
cout << "| 2. Show Record of Patient |" << endl; 
cout << "| 3. Update Patient Record |" << endl; 
cout << "| 4. Delete Patient Record |" << endl; 
cout << "|=================================|" << endl; 
cout << "Enter the number you want to Choose:" << endl; 
} 
void display_menu_Doctor() 
{ 
cout << "|=================================|" << endl; 
cout << "| 1. Add Patient Record |" << endl; 
cout << "| 2. Show Record of Patient |" << endl; 
cout << "|=================================|" << endl; 
cout << "Enter the number you want to Choose:" << endl; 
} 
void menu() 
{ 
cout << "|=================================|" << endl; 
cout << "| 1. To Patients Menu |" << endl; 
cout << "| 2. To Receptionist Menu |" << endl; 
cout << "| 3. To Doctor Menu |" << endl; 
cout << "|=================================|" << endl; 
cout << "Enter the number you want to Choose:" << endl; 
} 
int main() 
{ 
struct cl_patient *header = NULL; 
Doctor m; 
m.addSampleData1(); 
m.addSampleData2(); 
menu(); 
int num; 
cin >> num; 
 int v = 0; 
 if (num == 1) 
 { 
 v = 0; 
 do 
 { 
 display_menu_Patients(); 
 cin >> v; 
 if (v == 1) 
 m.add(); 
 cout << "*********************************" << endl; 
 cout << "Your Apponiments is booked!" << endl; 
 cout << "Thank You!!" << endl; 
 cout << "*********************************" << endl; 
 } while (0); 
 } 
 else if (num == 2) 
 { 
 v = 0; 
 do 
 { 
 display_menu_Receptionist(); 
 cin >> v; 
 if (v == 1) 
 m.add(); 
 else if (v == 2) 
 m.show(); 
 else if (v == 3) 
 m.update_data(); 
 else if (v == 4) 
 m.deleteList(); 
 char ch; 
 cout << "*********************************" << endl; 
 cout << "Enter a Q to exit OR Enter C to continue the code & M for main menu" << endl; 
 cout << "*********************************" << endl; 
 cin >> ch; 
 if (ch == 'Q') 
 { 
 break; 
 } 
 if(ch=='M') 
 { 
  menu(); 
 } 
 } while (1); 
 } 
 else if (num == 3) 
 { 
 v = 0; 
 do 
 { 
 display_menu_Doctor(); 
 cin >> v; 
 if (v == 1) 
 m.add(); 
 else if (v == 2) 
 m.show(); 
 char ch; 
 cout << "*********************************" << endl; 
 cout << "Enter a Q to exit OR Enter C to continue the code  & M for main menu" << endl; 
 cout << "*********************************" << endl; 
 cin >> ch; 
if (ch == 'Q') 
{ 
menu(); 
} 
if(ch=='M') 
{ 
} 
menu(); 
} while (1); 
} 
return 0; 
} 
