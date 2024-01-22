#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

struct user{
  char * firstName;
  char * lastName;
  char * middleName;
  char * email;
  char * phoneNum;
  int uid;
};

char * mallocString();
struct user setuserData();
void printCustomers(struct user * input, int custNum);
void freeDatabase(struct user * input);

int main()
{
   int num;
   int i;
   num = 0;

   struct user * userData;
   userData = malloc(SIZE * sizeof(struct user));
   printf("\n<-----Hello User. This program stores customer data----->\n");
   printf("\nDUE TO UNK BUDGET CUTS THIS IS ONLY ABLE TO STORE UP TO %d USERS\n", SIZE);
   printf("\nPlease enter the number of users you want to store: ");
   scanf("%d", &num);
   printf("You entered %d users", num);
   for(i = 0;i < num; i++){
     printf("\n\n<------------------------User %d--------------------------->\n", i + 1);
     userData[i] = setuserData();
   }
   printCustomers(userData, num);
   freeDatabase(userData);
   return 0;
}

char * mallocString(){
  char * local;
  local = malloc(SIZE * sizeof(char));
  local[SIZE] = '\0';
  return local;
}

struct user setuserData(){
  struct user localUser;
  char * fName;
  char * lName;
  char * mName;
  char * mail;
  char * phoneNum;
  int id;
  fName = mallocString();
  lName = mallocString();
  mName = mallocString();
  mail = mallocString();
  phoneNum = mallocString();
  printf("\nPlease enter the Firstname: ");
  scanf("%s", fName);
  printf("Please enter the Lastname: ");
  scanf("%s", lName);
  printf("Please enter the Middlename: ");
  scanf("%s", mName);
  printf("Please enter the Email: ");
  scanf("%s", mail);
  printf("Please enter the Phone number: ");
  scanf("%s", phoneNum);
  printf("Please enter the ID: ");
  scanf("%d", &id);
  localUser.firstName = fName;
  localUser.lastName = lName;
  localUser.middleName = mName;
  localUser.email = mail;
  localUser.phoneNum = phoneNum;
  localUser.uid = id;

  return localUser;
}

void printCustomers(struct user * input, int custNum){
  int i;
  printf("\n\n<--------------------PRINTING USERS--------------------------->\n");
  for(i = 0;i < custNum;i++){
    printf("\n\n<------------------------User %d--------------------------->\n", i + 1);
    printf("Customer Name: %s %s %s", input[i].firstName,input[i].middleName,input[i].lastName);
    printf("\nCustomer Email: %s", input[i].email);
    printf("\nPhone Number: %s", input[i].phoneNum);
    printf("\nUser ID: %d", input[i].uid);
  }

}

 void freeDatabase(struct user * input){
  int i;
  printf("\n\n<---------------------------FREEING------------------------------>\n");
  for(i = 0; i <= SIZE; i++){
    free(input[i].firstName);
    free(input[i].lastName);
    free(input[i].middleName);
    free(input[i].email);
    free(input[i].phoneNum);
  }
  free(input);
}
