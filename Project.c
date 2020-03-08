#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Structure*/
struct date{
    int d,m,y;
}date;
struct employee{
    char firstname[100],lastname[100],email[100],status[50],position[50];
    int id,year,tel;
    struct date Sdate;
};
typedef struct employee employee;
//Function
employee info[1000];
char fname[100]={"file.txt"};
#define MAX 256

//
void AddEmployee(int x);
void DisplayInfo();
void updateInfo();
void deleteInfo();
//Main Program
int main(){
    int select,n,i=1;
    while(i>0){
        printf("--------------------------\n");
        printf("---------(Menu)-----------\n");
        printf("  1. Add new employee\n");
        printf("  2. Display information for all employees working\n");
        printf("  3. Update information\n");
        printf("  4. Delete an employee information\n");
        printf("  5. Display information of a specific employee\n");
        printf("  6. Show all employees sorted by started working date in descending order\n");
        printf("  7. Show all employees sorted by position in ascending order\n");
        printf("  8. Exit\n");
        printf(">>>>>> Select (1-8): "); scanf("%d",&select);
        if(select==1){
            printf(">>>Input among of employee: "); scanf("%d",&n);
            AddEmployee(n);
        }else if(select==2){
            DisplayInfo();
        }else if(select==3){
            updateInfo();
        }else if(select==4){
            deleteInfo();
        }else if(select==5){
            //
        }else if(select==6){
            //
        }else if(select==7){
            //
        }else if(select==8){
            break;
        }
        i++;
    }
}
//Block Code of Function
void AddEmployee(int x){
    FILE *file;
    file=fopen(fname,"a");
    for(int i=0;i<x;i++){
        printf(">>>>Employee %d<<<<\n",i+1);
        printf("\tFirst name: "); scanf("%s",&info[i].firstname);
        printf("\tLast name: "); scanf("%s",&info[i].lastname);
        printf("\tID: "); scanf("%d",&info[i].id);
        printf("\tBirth's year: "); scanf("%d",&info[i].year);
        printf("\tPhone number: "); scanf("%d",&info[i].tel);
        printf("\tStart working date: \n");
        printf("\t\t_Day: "); scanf("%d",&info[i].Sdate.d);
        printf("\t\t_Month: "); scanf("%d",&info[i].Sdate.m);
        printf("\t\t_Year: "); scanf("%d",&info[i].Sdate.y);
        printf("\tPosition: "); scanf("%s",&info[i].position);
        printf("\tStatus: "); scanf("%s",&info[i].status);
        printf("\tEmail: "); scanf("%s",info[i].email);
        fprintf(file,"%s %s %d %d %d %d %d %d %s %s %s\n",info[i].firstname,info[i].lastname,info[i].id,info[i].year,info[i].tel,info[i].Sdate.d,info[i].Sdate.m,info[i].Sdate.y,info[i].position,info[i].status,info[i].email);
    }
    fclose(file);
}
void DisplayInfo(){
    FILE *file;
    char str[11][100];
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("Name\t\tID\tBirth's year\tTelephone\tStart Date\tPosition\tStatus\t\tEmail\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    file=fopen(fname,"r");//Take data from file
        while(fscanf(file,"%s %s %s %s %s %s %s %s %s %s %s",str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7],str[8],str[9],str[10])!=EOF){
            printf("%s %s\t%s\t%s\t\t%s\t%s/%s/%s\t%s\t\t%s\t \t%s\n",str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7],str[8],str[9],str[10]);
        }
    printf("------------------------------------------------------------------------------------------------------------\n");
    fclose(file);
}
void updateInfo(){
    FILE *file;
    char str[11][100];
    int i=0;
    int id,a;
    file=fopen(fname,"r");
        while(fscanf(file,"%s %s %s %s %s %s %s %s %s %s %s",str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7],str[8],str[9],str[10])!=EOF){
            strcpy(info[i].firstname,str[0]);
            strcpy(info[i].lastname,str[1]);
            info[i].id=atoi(str[2]);
            info[i].year=atoi(str[3]);
            info[i].tel=atoi(str[4]);
            info[i].Sdate.d=atoi(str[5]);
            info[i].Sdate.m=atoi(str[6]);
            info[i].Sdate.y=atoi(str[7]);
            strcpy(info[i].position,str[8]);
            strcpy(info[i].status,str[9]);
            strcpy(info[i].email,str[10]);
            i++;
        }
    fclose(file);
    //User input id to update
    printf("Enter employee ID: "); scanf("%d",&id);
    i=0;//cuz value i++;
    //printf("%d",info[0].id);
        for(i=0;i<4;i++){
            if(info[i].id==id){
                printf("\nPlease input to update information: \n");
                printf("\tFirst name: "); scanf("%s",&info[i].firstname);
                printf("\tLast name: "); scanf("%s",&info[i].lastname);
                //printf("\tID: "); scanf("%d",&info[i].id);
                printf("\tBirth's year: "); scanf("%d",&info[i].year);
                printf("\tPhone number: "); scanf("%d",&info[i].tel);
                printf("\tStart working date: \n");
                printf("\t\t_Day: "); scanf("%d",&info[i].Sdate.d);
                printf("\t\t_Month: "); scanf("%d",&info[i].Sdate.m);
                printf("\t\t_Year: "); scanf("%d",&info[i].Sdate.y);
                printf("\tPosition: "); scanf("%s",&info[i].position);
                printf("\tStatus: "); scanf("%s",&info[i].status);
                printf("\tEmail: "); scanf("%s",info[i].email);
            }
        }
    file=fopen(fname,"w");
        for(i=0;i<4;i++){
            fprintf(file,"%s %s %d %d %d %d %d %d %s %s %s\n",info[i].firstname,info[i].lastname,info[i].id,info[i].year,info[i].tel,info[i].Sdate.d,info[i].Sdate.m,info[i].Sdate.y,info[i].position,info[i].status,info[i].email);
        }
    fclose(file);
}
void deleteInfo()
{
        int i=0,id, ctr = 0;
        char ch;
        FILE *file;
        FILE *file_tmp;
        char str[11][100];
        char temp[] = "tmp.txt";
        file= fopen(fname, "r");
        file_tmp= fopen(temp, "w"); // open the temporary file in write mode
        printf(" Input the line you want to remove : ");
        scanf("%d", &id);
        // copy all contents to the temporary file except the specific line
        while(fscanf(file,"%s %s %s %s %s %s %s %s %s %s %s",str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7],str[8],str[9],str[10])!=EOF){
            strcpy(info[i].firstname,str[0]);
            strcpy(info[i].lastname,str[1]);
            info[i].id=atoi(str[2]);
            info[i].year=atoi(str[3]);
            info[i].tel=atoi(str[4]);
            info[i].Sdate.d=atoi(str[5]);
            info[i].Sdate.m=atoi(str[6]);
            info[i].Sdate.y=atoi(str[7]);
            strcpy(info[i].position,str[8]);
            strcpy(info[i].status,str[9]);
            strcpy(info[i].email,str[10]);

            if (info[i].id==id)
            {
                continue;
                /* skip the line at given line number */
            }else{
                fprintf(file_tmp,"%s %s %d %d %d %d %d %d %s %s %s\n",info[i].firstname,info[i].lastname,info[i].id,info[i].year,info[i].tel,info[i].Sdate.d,info[i].Sdate.m,info[i].Sdate.y,info[i].position,info[i].status,info[i].email);
            }
        }
        fclose(file);
        fclose(file_tmp);
        remove(fname);  		// remove the original file
        rename(temp, fname); 	// rename the temporary file to original name
}


