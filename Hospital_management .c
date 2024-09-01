#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "ANSI-color-codes.h"

void MainMenu();

void PatientMenu();
void addPatient();
void displayPatients();
void searchPatient();
void modifyPatient();
void deletePatient();

void StaffMenu();
void addStaff();
void displayStaff();
void searchStaff();
void modifyStaff();
void deleteStaff();

struct address
{
    char country[40];
    char province[40];
    char district[40];
    char Municipality[40];
    int wardNum;
};
struct patient
{
    char name[50];
    char guardian_name[50];
    int age;
    char bloodGroup[10];
    char gender;
    char regNum[40];
    struct address a;
    char phone[20];
    char disease[60];
};
struct staff
{
    char name[50];
    int age;
    char bloodGroup[10];
    char gender;
    char uid[10];
    struct address b;
    char ph[40];
    float salary;
};

int main()
{
    system("COLOR B0"); //sets the console background to sky blue and text color to black
    MainMenu();
    return 0;
}

void MainMenu()
{
    char choice;
    first:
    system("cls"); //clears the screen
    system("COLOR B0");
    printf("\n\t\t\t\t\t******************************");
    printf("\n\t\t\t\t\t  Hospital Management System");
    printf("\n\t\t\t\t\t******************************");
    printf("\n\n");
    printf(CYNB);
    printf("\n\t\t\t1. Patient\n");
    printf("\n\t\t\t2. Staff\n");
    printf("\n\t\t\t3. Exit\n");
    printf(reset);
    printf(REDB);
    printf("\n\n\t\t\t\tEnter your choice: ");
    fflush(stdin);
    choice=getche();
    printf(reset);
    switch(choice)
    {
        case '1':
            PatientMenu();
            break;
        case '2':
            StaffMenu();
            break;
        case '3':
            printf(CYNB);
            printf("\n\n\t\t\t\t\t******************************");
            printf("\n\t\t\t\t\t    Thanks For Visiting");
            printf("\n\t\t\t\t\t******************************");
            printf(reset);
            exit(0);
            break;
        default:
            goto first;
            break;
    }
    getch();
}

void PatientMenu()
{
    system("COLOR B0");
    char choice;
    
    while(1)
    {
        system("cls");
        printf("\n\t\t\t\t\tPatient Menu");
        printf("\n\n");
        printf("\n\n\t\t\t1. Add Patient");
        printf("\n\n\t\t\t2. Display Patient's Details");
        printf("\n\n\t\t\t3. Search Patient");
        printf("\n\n\t\t\t4. Modify Patient");
        printf("\n\n\t\t\t5. Delete Patient");
        printf("\n\n\t\t\t6. Main Menu");
        printf("\n\n\t\t\t\tEnter your choice: ");
        fflush(stdin);
        choice=getche();

        switch(choice)
        {
            case '1':
                addPatient();
                break;
            case '2': 
                system("cls");
                displayPatients();
                break;
            case '3':
                searchPatient();
                break;
            case '4':
                modifyPatient();
                break;
            case '5':
                deletePatient(); 
                break;
            case '6':
                system("cls");
                MainMenu();
        }
    }
}

void StaffMenu()
{
    char choice;

    while (1)
    {
        system("cls");
        system("COLOR B0");
        printf("\n\t\t\t\t\tStaff Menu");
        printf("\n\n");
        printf("\n\n\t\t\t1. Add Staff");
        printf("\n\n\t\t\t2. Display Staff's Details");
        printf("\n\n\t\t\t3. Search Staff");
        printf("\n\n\t\t\t4. Modify Staff");
        printf("\n\n\t\t\t5. Delete Staff");
        printf("\n\n\t\t\t6. Main Menu");
        printf("\n\n\t\t\t\tEnter your choice: ");
        fflush(stdin);
        choice=getche();

        switch(choice)
        {
            case '1':
                addStaff();
                break;
            case '2':
                displayStaff();
                break;
            case '3':
                searchStaff(); 
                break;
            case '4':
                modifyStaff(); 
                break;
            case '5':
                deleteStaff(); 
                break; 
            case '6':
                system("cls");
                MainMenu();
        }
    }
}

void addPatient(){
    FILE *fp;
    fp= fopen("patient.DAT", "ab+");
    char next;
    char reg[40];
    struct patient p;
    next= 'Y';
    system("cls");
    while (next == 'y' || next == 'Y')
    {
        first:
        printf("\n\n\tRegistration Number of Patient: ");
        scanf("%s", reg);
        rewind(fp);
        while(fread(&p,sizeof(p),1,fp)==1){
            if(strcmp(p.regNum, reg)==0){
                printf("\n\n---------------------------------------------------------------------------------");
                printf("\n\n\tThis Registration Number already exists!!. Enter another one!!");
                printf("\n\n---------------------------------------------------------------------------------");
                goto first;
            }
        }
            if(fread(&p, sizeof(p),1,fp)==0) {
                strcpy(p.regNum, reg);
                printf("\n\n\tFull Name of the Patient: ");
                scanf("%s", p.name);
                printf("\n\n\tName of Patient's Guardian: ");
                scanf("%s", p.guardian_name);
                printf("\n\n\tPatient's Age: ");
                scanf("%d", &p.age);
                printf("\n\n\tPatient's Blood Group: ");
                scanf("%s", p.bloodGroup);
                printf("\n\n\tGender of the Patient(m for male f for female): ");
                fflush(stdin);
                p.gender=getche();
                printf("\n\n\tPatient's Phone Number: ");
                scanf("%s", p.phone);
                printf("\n\n\tAddress of the Patient:");
                printf("\n\t\tCountry: ");
                scanf("%s", p.a.country);
                printf("\n\t\tProvince: ");
                scanf("%s", p.a.province);
                printf("\n\t\tDistrict: ");
                scanf("%s", p.a.district);
                printf("\n\t\tMunicipality: ");
                scanf("%s", p.a.Municipality);
                printf("\n\t\tWard Number: ");
                scanf("%d", &p.a.wardNum);
                printf("\n\n\tDiseases that Patient wants the treatment of: ");
                scanf("%s", p.disease);
            }
        fwrite(&p,sizeof(p),1,fp);  //writes above's details in a file fp using structure 'p' which is opened in a binary form                                                                             
        printf("\n------------------------------------------------------------------------------------------");
        printf("\n\n\tWould you like to add another patient(Y/N): ");
        fflush(stdin);
        next=getche();
        printf("\n------------------------------------------------------------------------------------------");
    }
    fclose(fp);
}

void displayPatients(){
    FILE *fp;
    fp = fopen("patient.DAT", "rb");
    struct patient p;

    system("cls");
     if (fp == NULL)
     {
        printf("\n\n\tError opening file!!");
        return;
     }
    rewind(fp);
     while (fread(&p,sizeof(p),1,fp)==1)
     {
        printf("\n============================================================================================================");
        printf("\n\t\t\t\t\t\tPATIENT'S LISTS");
        printf("\n============================================================================================================");
        printf("\n\n\tRegistration Number of Patient: %s", p.regNum);
        printf("\n\n\tFull Name of the Patient: %s", p.name);
        printf("\n\n\tName of Patient's Guardian: %s", p.guardian_name);
        printf("\n\n\tPatient's Age: %d", p.age);
        printf("\n\n\tPatient's Blood Group: %s", p.bloodGroup);
        printf("\n\n\tGender of the Patient: %c", p.gender);
        printf("\n\n\tPatient's Phone Number: %s", p.phone);
        printf("\n\n\tAddress of the Patient:");
        printf("\n\t\tCountry: %s", p.a.country);
        printf("\n\t\tProvince: %s", p.a.province);
        printf("\n\t\tDistrict: %s", p.a.district);
        printf("\n\t\tMunicipality: %s", p.a.Municipality);
        printf("\n\t\tWard Number: %d", p.a.wardNum);
        printf("\n\n\tDiseases that Patient wants the treatment of: %s", p.disease);
     }
    fclose(fp);
    getch();
}

void searchPatient(){
    system("cls");
    FILE *fp;
    struct patient p;
    char reg[20];
    char another;
    another = 'Y';

    fp = fopen("patient.DAT", "rb+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
while(another == 'Y' || another == 'y')
{
    printf("\n\n\tEnter the Registration Number of Patient to search: ");
    scanf("%s", reg);

    rewind(fp);
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if (strcmp(p.regNum, reg)==0)
        {
            printf("\n------------------------------------------------------------------------------------------");
            printf("\n\t\t\t\tPATIENT FOUNDED");
            printf("\n------------------------------------------------------------------------------------------");
            printf("\n\n\tRegistration Number of Patient: %s", p.regNum);
            printf("\n\n\tFull Name of the Patient: %s", p.name);
            printf("\n\n\tName of Patient's Guardian: %s", p.guardian_name);
            printf("\n\n\tPatient's Age: %d", p.age);
            printf("\n\n\tPatient's Blood Group: %s", p.bloodGroup);
            printf("\n\n\tGender of the Patient: %c", p.gender);
            printf("\n\n\tPatient's Phone Number: %s", p.phone);
            printf("\n\n\tAddress of the Patient:");
            printf("\n\t\tCountry: %s", p.a.country);
            printf("\n\t\tProvince: %s", p.a.province);
            printf("\n\t\tDistrict: %s", p.a.district);
            printf("\n\t\tMunicipality: %s", p.a.Municipality);
            printf("\n\t\tWard Number: %d", p.a.wardNum);
            printf("\n\n\tDiseases that Patient wants the treatment of: %s", p.disease);

        }
    }
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\t\tDo you Want to Search another Patient(Y/N): ");
    another=getche();
    printf("\n------------------------------------------------------------------------------------------");
}
    fclose(fp);
}

void modifyPatient(){
     FILE *fp;
    struct patient p;
    char reg[40];
    char another;
    another = 'Y';
    system("cls");

    fp = fopen("patient.DAT", "rb+");
    
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

while(another == 'Y' || another == 'y')
{
    printf("\n\n\tEnter the Registration Number of the patient to be Modified: ");
    scanf("%s", reg);
    rewind(fp);
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if (strcmp(p.regNum, reg)==0)
        {
            fflush(stdin);
            printf("\n\n\tModify the Registration Number of the patient to be Modified: ");
            scanf("%s", p.regNum);
            printf("\n\n\tModify Full Name of the Patient: ");
            scanf("%s", p.name);
            printf("\n\n\tModify Name of Patient's Guardian: ");
            scanf("%s", p.guardian_name);
            printf("\n\n\tModify Patient's Age: ");
            scanf("%d", &p.age);
            printf("\n\n\tModify Patient's Blood Group: ");
            scanf("%s", p.bloodGroup);
            printf("\n\n\tModify Gender of the Patient(m for male f for female): ");
            p.gender=getche();
            printf("\n\n\tModify Patient's Phone Number: ");
            scanf("%s", p.phone);
            printf("\n\n\tModify Address of the Patient:");
            printf("\n\t\tCountry: ");
            scanf("%s", p.a.country);
            printf("\n\t\tProvince: ");
            scanf("%s", p.a.province);
            printf("\n\t\tDistrict: ");
            scanf("%s", p.a.district);
            printf("\n\t\tMunicipality: ");
            scanf("%s", p.a.Municipality);
            printf("\n\t\tWard Number: ");
            scanf("%d", &p.a.wardNum);
            printf("\n\n\tModify Diseases that Patient wants the treatment of: ");
            scanf("%s", p.disease);
            fseek(fp,-sizeof(p),SEEK_CUR);
            fwrite(&p,sizeof(p),1,fp);
            break;
        }
    }
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\t\tDo You Want to Modify another Patient(Y/N): ");
    another=getche();
    printf("\n------------------------------------------------------------------------------------------");
}
    fclose(fp);
}

void deletePatient(){
    FILE *fp, *temp;
    struct patient p;
    char reg[40];
    char another;
    another = 'Y';
    system("cls");

    fp = fopen("patient.DAT", "rb+");
    temp = fopen("temp.DAT", "wb+");
    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

while(another == 'Y' || another == 'y')
{
    printf("\n\t\tEnter the Registration Number of the patient to be deleted: ");
    scanf("%s", reg);
    rewind(fp);
    while(fread(&p,sizeof(p),1,fp)==1)
    {
        if (strcmp(p.regNum, reg)!=0)
        {
            fwrite(&p,sizeof(p),1,temp);
        }
        else
        {
            printf("\n\n\t\tPATIENT HAS BEEN DELETED SUCESSFULLY!!");
        }
    }
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\t\tDo You Want to Delete another Patient(Y/N): ");
    another=getche();
    printf("\n------------------------------------------------------------------------------------------");
}
    fclose(fp);
    fclose(temp);

        remove("patient.DAT");
        rename("temp.DAT", "patient.DAT");
        printf("\n\t\tPatient Deleted Sucessfully!!");
}       

void addStaff(){
    FILE *fs;
    fs= fopen("staff.DAT", "ab+");
    struct staff s;
    char uid[40];
    char another;
    another = 'Y';
    system("cls");
    while (another=='Y' || another=='y')
    {
        start:
        printf("\n\n\tUID of the Staff: ");
        scanf("%s", uid);
        rewind(fs);
        while(fread(&s,sizeof(s),1,fs)==1){
            if(strcmp(s.uid, uid)==0){
            printf("\n\n------------------------------------------------------------------------------------------");
            printf("\n\n\tThis Uid already exists. Please Enter another Uid!!");
            printf("\n\n------------------------------------------------------------------------------------------");
            goto start;
            }
        }
        if(fread(&s,sizeof(s),1,fs)==0){
        strcpy(s.uid,uid);
        printf("\n\n\tName of the staff: ");
        scanf("%s", s.name);
        printf("\n\n\tAge of the staff: ");
        scanf("%d", &s.age);
        printf("\n\n\tGender of the Staff('m' for male 'f' for female): ");
        s.gender=getche();
        printf("\n\n\tStaff's Blood Group: ");
        scanf("%s", s.bloodGroup);
        printf("\n\n\tStaff's Phone Number: ");
        scanf("%s", s.ph);
        printf("\n\n\tAddress of the Staff:");
        printf("\n\t\tCountry: ");
        scanf("%s", s.b.country);
        printf("\n\t\tProvince: ");
        scanf("%s", s.b.province);
        printf("\n\t\tDistrict: ");
        scanf("%s", s.b.district);
        printf("\n\t\tMunicipality: ");
        scanf("%s", s.b.Municipality);
        printf("\n\t\tWard Number: ");
        scanf("%d", &s.b.wardNum);
        printf("\n\n\tSalary of the Staff: ");
        scanf("%f", &s.salary);
        }
        fwrite(&s,sizeof(s),1,fs);
        printf("\n------------------------------------------------------------------------------------------");
        printf("\n\n\tWould you like to add details of another Staff(Y/N): ");
        another=getche();
        printf("\n------------------------------------------------------------------------------------------");
    }
    fclose(fs);
}

void displayStaff(){
    system("cls");
    struct staff s;
    FILE *fs;
    fs = fopen("staff.DAT", "rb+");

    if (fs != NULL)
    {
        rewind(fs);
        while (fread(&s,sizeof(s),1,fs)==1)
        {
            printf("\n============================================================================================================");
            printf("\n\t\t\t\t\t\tStaff'S LISTS");
            printf("\n============================================================================================================");
            printf("\n\n\tUID of the Staff: %s", s.uid);
            printf("\n\n\tName of the staff: %s", s.name);
            printf("\n\n\tAge of the staff: %d", s.age);;
            printf("\n\n\tGender of the Staff('m' for male 'f' for female): %c", s.gender);
            printf("\n\n\tStaff's Blood Group: %s", s.bloodGroup);
            printf("\n\n\tStaff's Phone Number: %s", s.ph);
            printf("\n\n\tAddress of the Staff:");
            printf("\n\t\tCountry: %s", s.b.country);
            printf("\n\t\tProvince: %s", s.b.province);
            printf("\n\t\tDistrict: %s", s.b.district);
            printf("\n\t\tMunicipality: %s", s.b.Municipality);
            printf("\n\t\tWard Number: %d", s.b.wardNum);
            printf("\n\n\tSalary of the Staff: %.2f", s.salary);
        }
    }
    fclose(fs);
    getch();
}

void searchStaff() {
    system("cls");
    FILE *fs;
    struct staff s;
    char uId[40];
    char another;
    another = 'Y';

    fs = fopen("staff.DAT", "rb+");
    if (fs == NULL) {
        printf("Error opening file!\n");
        return;
    }
while(another == 'Y' || another == 'y')
{
    printf("\n\t\tEnter Staff ID to search: ");
    scanf("%s", uId);
    
    while (fread(&s,sizeof(s),1,fs)==1)
    {
        if (strcmp(s.uid, uId)==0)
        {
            printf("\n\n\t\t\tSTAFF FOUND");
            
            printf("\n\n\tUID of the Staff: %s", s.uid);
            printf("\n\n\tName of the staff: %s", s.name);
            printf("\n\n\tAge of the staff: %d", s.age);;
            printf("\n\n\tGender of the Staff('m' for male 'f' for female): %c", s.gender);
            printf("\n\n\tStaff's Blood Group: %s", s.bloodGroup);
            printf("\n\n\tStaff's Phone Number: %s", s.ph);
            printf("\n\n\tAddress of the Staff:");
            printf("\n\t\tCountry: %s", s.b.country);
            printf("\n\t\tProvince: %s", s.b.province);
            printf("\n\t\tDistrict: %s", s.b.district);
            printf("\n\t\tMunicipality: %s", s.b.Municipality);
            printf("\n\t\tWard Number: %d", s.b.wardNum);
            printf("\n\n\tSalary of the Staff: %.2f", s.salary);

        }
    }
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\n\tWould you like to search another Staff: ");
    another=getche();
    printf("\n------------------------------------------------------------------------------------------");
}
    fclose(fs);
}

void modifyStaff(){
    system("cls");
    FILE *fs;
    struct staff s;
    char uId[40];
    char another;
    another = 'Y';
    fs = fopen("staff.DAT", "rb+");
    if (fs == NULL) {
        printf("Error opening file!\n");
        return;
    }
while(another == 'Y' || another == 'y')
{
    printf("\n\t\tEnter the ID of the Staff to be Modified: ");
    scanf("%s", uId);
    rewind(fs);
    while(fread(&s,sizeof(s),1,fs)==1)
    {
        if (strcmp(s.uid, uId)==0)
        {
                printf("\n\n\tModify UID of the Staff: ");
                scanf("%s", s.uid);
                printf("\n\n\tModify Name of the staff: ");
                scanf("%s", s.name);
                printf("\n\n\tModify Age of the staff: ");
                scanf("%d", &s.age);
                printf("\n\n\tModify Gender of the Staff('m' for male 'f' for female): ");
                s.gender=getche();
                printf("\n\n\tModify Staff's Blood Group: ");
                scanf("%s", s.bloodGroup);
                printf("\n\n\tModify Staff's Phone Number: ");
                scanf("%s", s.ph);
                printf("\n\n\tModify Address of the Staff:");
                printf("\n\t\tCountry: ");
                scanf("%s", s.b.country);
                printf("\n\t\tProvince: ");
                scanf("%s", s.b.province);
                printf("\n\t\tDistrict: ");
                scanf("%s", s.b.district);
                printf("\n\t\tMunicipality: ");
                scanf("%s", s.b.Municipality);
                printf("\n\t\tWard Number: ");
                scanf("%d", &s.b.wardNum);
                printf("\n\n\tModify Salary of the Staff: ");
                scanf("%f", &s.salary);
                fseek(fs,-sizeof(s),SEEK_CUR);
                fwrite(&s,sizeof(s),1,fs);
                break;
        }
    }
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\n\tWould you like to modify another Staff(Y/N): ");
    another=getche();
    printf("\n------------------------------------------------------------------------------------------");
}
    fclose(fs);
}

void deleteStaff(){
    system("cls");
     FILE *fs, *temp;
    struct staff s;
    char uId[40];
    char another;
    another = 'Y';
    fs = fopen("staff.DAT", "rb");
    temp = fopen("temp.DAT", "wb+");
    if (fs == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }
while(another == 'Y' || another == 'y')
{
    printf("\n\t\tEnter the ID of the Staff to be deleted: ");
    scanf("%s", uId);
    rewind(fs);
    while(fread(&s,sizeof(s),1,fs)==1)
    {
        if (strcmp(s.uid, uId)!=0)
        {
            fwrite(&s,sizeof(s),1,temp);
        }
        else
        {
            printf("\n\n\t\tSTAFF HAS BEEN DELETED SUCESSFULLY!!");
        }
    }
    printf("\n------------------------------------------------------------------------------------------");
    printf("\n\n\tWould you like to delete another Staff(Y/N): ");
    another=getche();
    printf("\n------------------------------------------------------------------------------------------");
   }
    fclose(fs);
    fclose(temp);

        remove("staff.DAT");
        rename("temp.DAT", "staff.DAT");
}