#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct student
{
		int id;
		char mob[11];
		char fname[15];
		char lname[15];
		char address[20];
		
}stu,check,list;


	void main()
	{
		
		int save,n,l;
		
		int a,choice;
		
	 


system("cls");
	system("color 4");
char d[25]="Password Protected ";
char ch,pass[20],password[20]="pratik";
int i=0,j;


for(j=0;j<20;j++)
{
Sleep(20);
printf("*");
}
for(j=0;j<20;j++)
{
Sleep(30);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(20);
printf("*");
}

printf("\nEnter Password:\n");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

printf("\nPassword match\n");

printf("Press any key to countinue.....");
getch();
system("cls");

	while(1)
		{
		system("color 4");
		printf(" \n");
		printf("\t\t\t\xB2\3  1.Add student :\n");
		printf("\t\t\t\xB2\3  2.View list : \n");
		printf("\t\t\t\xB2\3  3.Search student :\n");
		printf("\t\t\t\xB2\3  4.Delete : \n");
		printf("\t\t\t\xB2\3  5.Update : \n");
		printf("\t\t\t\xB2\3  6.Exit : \n");
		printf("Enter your choice : ");
		scanf("%d", &n);
		
	
	
	 	switch (n)
	 	{
	 		case 1:
	 			 
	 			{ 
	 			
	 			 	system("cls");
	 				printf(" \n");
	 				
	 					 FILE *ptr;
	 					  ptr=fopen("record.dat","a+");
	 				
	 			  	printf("Please enter Id : \n");
					scanf("%d",&stu.id );
					
					printf("Please Enter First Name : \n");
					scanf("%s",&stu.fname);
					
						printf("Please Enter Last Name : \n");
					scanf("%s",&stu.lname);
					
					
					printf("Please enter mobile number : \n");
					scanf("%s",&stu.mob);
					
					printf("Please enter Address : \n");
					scanf("%s",&stu.address);
					
					fprintf(ptr,"%d %s %s %s %s \n",stu.id, stu.fname, stu.lname,stu.mob, stu.address);
					 fclose(ptr);
					printf("Save record \n");
					
					printf("\n");
					printf("Press 1 Goto Main Menu... \n");
					
					scanf("%d",&save);
					
					system("cls");
					
	 				break;
	 				
				 }
	 	
		 	case 2 :
	 			
	 			{
	 				
	 				 FILE *view;
   				 	view=fopen("record.dat","r");
  					  int test=1;
  					system("cls");
 				   printf("\n id.NO.\tFIRSTR NAME\tLAST NAME\tPHONE\t\tADDRESS");

  			  while(fscanf(view,"%d %s %s %s %s",&stu.id, &stu.fname, &stu.lname, &stu.mob,&stu.address)>= test)
     		  {
           printf("\n   %d \t %s \t %s  \t%s  \t%s",stu.id,stu.fname,stu.lname,stu.mob,stu.address);
           
     		  }

  			  fclose(view);
  			  printf("\n\n Enter main menu press 1 or 0");
  			  scanf("%e");
  			  system("cls");
				break;   	
			 }
	 		
	 		
	 		case 3 :
	 			
	 			{
	 				
	 				FILE *ptr;
   					 int test=1;
   					 int save;
   					 int choice;
  					  ptr=fopen("record.dat","r");
  				  printf("\nDo you want to check record \n\nEnter 1 to check record:");
  			  scanf("%d",&choice);
    			if (choice==1)
  			  {   
				printf("Enter the  ID :");
    			  scanf("%d",&check.id);

        while (fscanf(ptr,"%d %s %s %s %s ",&stu.id, stu.fname, stu.lname, stu.mob, stu.address) !=EOF)
        {
            if(stu.id==check.id)
            {   
			system("cls");
                
			printf("\n   %d \t %s \t %s  \t%s  \t%s",stu.id,stu.fname,stu.lname,stu.mob,stu.address);  
			
			      
        	printf("\n");
					printf("Press 1 Goto Main Menu... \n");
					
					scanf("%d",&save);
					
					system("cls");
    				  fclose(ptr);
			 	  }
			 	
    		  }
			}
			else
   			  {
     		printf("\n\n Warning!! Incorrect Choice");
			printf(" \n\n Please press 'Enetr' key....\n");
			system("cls");
			getch();
		
			 }
     
	 		break;	
			 }
				 
				 
			case 4 :
			{
		
				   			
						
						   FILE *old,*newrec;
                           
                           old=fopen("record.dat","r");
                            newrec=fopen("new.dat","w");
                           printf("Enter the id. of the customer you want to delete:");
                           scanf("%d",&check.id);
                            while (fscanf(old,"%d %s %s %s %s ",&stu.id, &stu.fname, &stu.lname, &stu.mob, stu.address)!=EOF)
                          {
                            if(stu.id!=check.id)
                                fprintf(newrec,"\n   %d \t %s \t %s  \t%s  \t%s",stu.id,stu.fname,stu.lname,stu.mob,stu.address);

                 else
                  { 
                        printf("\nRecord deleted successfully!\n");
                        getch();
                  }
                   }
                     fclose(old);
                     fclose(newrec);
                      remove("record.dat");
                     rename("new.dat","record.dat");
				   
				   
                     system("cls");
					   break;
			 }	 
				 	
					 
					 
					 case  5:
					 	{
					 		
								int choice,test=0;
                                 FILE *old,*newrec;
                                old=fopen("record.dat","r");
                                newrec=fopen("new.dat","w");

                                printf("\nEnter the id you want to change:");
                                scanf("%d",&list.id);
                                while(fscanf(old,"\n %d %s %s %s %s ",&stu.id,&stu.fname,&stu.lname,&stu.mob,&stu.address)!=EOF)
                            {
                                if (stu.id==list.id)
                                {   
							
                                     printf("\nWhich information do you want to change?\n1.First name\n2.Last name\n3.MObile No\n4.Address \nEnter your choice:");
                                     scanf("%d",&choice);
                                    system("cls");
                                if(choice==1)
                                   {
								   printf("Enter the First  name:");
                                    scanf("%s",stu.fname);
                                     fprintf(newrec,"\n %d %s %s %s %s \n",stu.id,stu.fname,stu.lname,stu.mob,stu.address);
                
                                    printf("Changes saved!");
                				}
                				else if(choice==2)
                				{
                				printf("Enter the Last Name:");
                                    scanf("%s",stu.lname);	
                                     fprintf(newrec,"\n %d %s %s %s %s \n",stu.id,stu.fname,stu.lname,stu.mob,stu.address);
                
                                    printf("Changes saved!");
								}
								else if(choice==3)
								{
								printf("Enter the new Mobile No:");
                                    scanf("%s",&stu.mob);
									 fprintf(newrec,"\n %d %s %s %s %s \n",stu.id,stu.fname,stu.lname,stu.mob,stu.address);
                
                                    printf("Changes saved!");	
								}
                                    
               					 else if(choice==4)
               					 {
               					 	 printf("Enter the new Address:");
                                    scanf("%s",stu.address);
                                     fprintf(newrec,"\n %d %s %s %s %s \n",stu.id,stu.fname,stu.lname,stu.mob,stu.address);
                
                                    printf("Changes saved!");
               					 	
									}
                                    
                  
                                   
                
                                   
                                
            

                           }
                             else
                                    fprintf(newrec,"\n %d %s %s %s %s \n",stu.id,stu.fname,stu.lname,stu.mob,stu.address);
                             }
                              fclose(old);
                              fclose(newrec);
                              remove("record.dat");
                              rename("new.dat","record.dat"); 
                              
                              
                            printf("Record Updated.... \n Press 1 Goto Main Menu... ");
					
					        scanf("%d",&save);
					      
           
                              system("cls");
                              break;
						 }
	 		
	 		case 6 :
	 			{
				printf("Thank You.....");
				exit(0);          
			    }
	 		
			 
			 default : 
	 		printf("\n\n Warning!! Incorrect Choice");
			printf(" \n\n Please press 'Enetr' key....\n");
			getch();
			system("cls");
	 		
	 		
		 }
		
		}
	
 	} 
else
{

printf("\n\n Warning!! Incorrect Password");

printf(" \n\n Please press 'Enetr' key....");
getch();
main();
	}	
}
