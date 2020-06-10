#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 30
struct login 
{
        char firstname[MAX];
        char lastname[MAX];
        char username[MAX];
        char password[MAX];
};
//Function's prototypes.
int Registration();
int Login();
int Login2();
int PasswordCheck(char n[]);
int UsernameCheck(char n[]);

int main() // Main function will ask for the Registration or Login.
{
        int option;

        printf("+------------------------------------------+");
        printf("\n| WELCOME TO SECURE CODING ONLINE PLATFORM |\n");
        printf("+------------------------------------------+");
        printf("\n\nPress [1] for Registration.\n\nOR\n\nPress [2] for Login.\n\n");                                                                                                                                                                  
        scanf("%d", &option);                                                                                                                                                                                                              
        if (option == 1)                                                                              
        {
                system("clear");
                if (Registration() == 0)
                {
                    system("clear");
                    Login();
                }  
        }                                                                                                                          
        else if (option == 2)
        {
                system("clear");
                Login2();
        }
        else if (option != 1,2)
                printf("\n\nYou Have Only Two Options. Please Press [1] or [2].\n");

        return 0;
}

int Registration() // Registration function will take the credentials and store it in login.txt file.
{
        char username[MAX], password[MAX];
        FILE *log;
        log = fopen("login.txt", "a+"); //File open and append the inputs in it.
        struct login n; 
        int attempts = 1;
       

        printf("+---------------------------------------+");
        printf("\n| Please Enter your Details to Register |\n");
        printf("+---------------------------------------+\n");

        printf("\nEnter your first name: ");
        scanf("%s", n.firstname);

        printf("\nEnter your last name: ");
        scanf("%s", n.lastname);
       
        while(attempts <= 3)
        {
            printf("\nEnter username: ");
            scanf("%s", n.username);
            UsernameCheck(n.username); // Running a username validation as per client requirement with UsernameCheck function.

            printf("\nEnter password: ");
            scanf("%s", n.password);
            PasswordCheck(n.password); // Running a password check validation as per requirement.
   
                if ((UsernameCheck(n.username) == 0) && (PasswordCheck(n.password) == 0) && attempts <=3)
                {
                    fwrite(&n, sizeof(n),1,log);
                    fclose(log);
                    return 0;
                }
                else if ((UsernameCheck(n.username) != 0) && (PasswordCheck(n.password) != 0) && attempts <= 2)
                {
                    printf("\nInvalid Username and Password.\n");
                    printf("\n* Your Username must be less than 30 characters.\n");
                    printf("\n* Your Password must contain:");
                    printf("\n1. Minimum 8 characters.");
                    printf("\n2. At least 1 Lowercase letter (a,b,c,d).");
                    printf("\n3. At least 1 Uppercase letter (A,B,C,D).");
                    printf("\n4. At least 1 Special character ($,^,!,#).");
                    printf("\n5. At least 1 Numeric value (1,2,3,4).\n");
                }
                else if ((UsernameCheck(n.username) != 0) && (PasswordCheck(n.password) == 0) && attempts <= 2)
                {
                    printf("\n* Your Username must be less than 30 characters.\n");
                }
                else if ((UsernameCheck(n.username) == 0) && (PasswordCheck(n.password) != 0)&& attempts <= 2)
                {
                    printf("\n* Your Password must contain:");
                    printf("\n1. Minimum 8 characters.");
                    printf("\n2. At least 1 Lowercase letter (a,b,c,d).");
                    printf("\n3. At least 1 Uppercase letter (A,B,C,D).");
                    printf("\n4. At least 1 Spacial character ($,^,!,#).");
                    printf("\n5. At least 1 Numeric value (1,2,3,4).\n");
                }
                else
                {
                    printf("\nRegistration Failed, Please try again later!\n\n");
                }
                attempts++;
        }
}
int UsernameCheck(char n[]) // Velidating  usermane requirements
{
        int len;
        len = strlen(n);
        if (len >= 30) {
            return 1;
        }
        else {
            return 0;
        }
}
int PasswordCheck(char n[]) //Validating password requirements.
{
        int len, i, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
        len = strlen(n);

        if(len < 8 || len > 30)
            return 1;
        else
        {
            for(i = 0; i < len; i++) // This loop will iterate over every charecter and check for the Uppercase, lowercase, Number & Symbol.
            {
                if(islower(n[i]) > 0)  
                {
                    flag1 = 1;
                }
                else if (isupper(n[i]) > 0)
                {
                    flag2 = 1;
                }
                 else if (isdigit(n[i]) > 0)
                {
                    flag3 = 1;
                }
                 else if (ispunct(n[i]) > 0)
                {
                    flag4 = 1;
                }  
            } 
        }
        if(flag1 == 1 && flag2 == 1 && flag3 == 1 && flag4 == 1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
}

int Login() // If user input checks all the requirement, this login function will be prompt. 
{
        char username[MAX], password[MAX];
        int attempts = 1;
        int i = 2;
        FILE *log;
        log = fopen("login.txt", "r");
        struct login n;

        printf("+--------------------------------------------------+");
        printf("\n|            Registration Successful!              |");
        printf("\n| Please Enter your Username and Password to login |\n");
        printf("+--------------------------------------------------+\n");

        while(attempts <=3)
        {
                printf("\nUsername: ");
                scanf("%s", &username);

                printf("\nPassword: ");
                scanf("%s", &password);

                fread(&n, sizeof(n),1,log); // Reading the chredentials from the file and following conditional statements will cross check the login credetials.

                if (strcmp(username, n.username) == 0 && strcmp(password, n.password) == 0 && attempts <=3)
                {
                        printf("\n\nLogin Successful!\n\n");
                        return 0;
                       
                }
                else if (strcmp(username, n.username) != 0 && strcmp(password, n.password) != 0 && attempts <=2)
                {
                        printf("\n\nPlease Enter Valid Username and Password!\nAttempt left..........................(%i)\n\n", i);
                        i--;

                }
       else if (strcmp(username, n.username) == 0 && strcmp(password, n.password) != 0 && attempts <=2)
                {
                        printf("\n\nPlease Enter Valid Username and Password!\nAttempt left..........................(%i)\n\n", i);
                        i--;

                }
       else if (strcmp(username, n.username) != 0 && strcmp(password, n.password) == 0 && attempts <=2)
                {
                        printf("\n\nPlease Enter Valid Username and Password!\nAttempt left..........................(%i)\n\n", i);
                        i--;

                }
        else
                {
                        printf("\n\nACCOUNT LOCKED, PLEASE TRY AGAIN AFTER 30 MINUTES.\n\n");
                }
                attempts++;
        }



        fclose(log);
        return 0;
}

int Login2() // This login function for the existing users which will check the same conditional statements as above.
{
        char username[MAX], password[MAX];
        int attempts = 1;
        int i = 2;
        FILE *log;
        log = fopen("login.txt", "r");
        struct login n;

        printf("+--------------------------------------------------+");
        printf("\n|                  WELCOME BACK!                   |");
        printf("\n| Please Enter your Username and Password to login |\n");
        printf("+--------------------------------------------------+\n");

        while(attempts <=3)
        {
                printf("\nUsername: ");
                scanf("%s", &username);

                printf("\nPassword: ");
                scanf("%s", &password);

                fread(&n, sizeof(n),1,log);

                if (strcmp(username, n.username) == 0 && strcmp(password, n.password) == 0 && attempts <=3)
                {
                        printf("\n\nLogin Successful!\n\n");
                        return 0;
                       
                }
                else if (strcmp(username, n.username) != 0 && strcmp(password, n.password) != 0 && attempts <=2)
                {
                        printf("\n\nPlease Enter Valid Username and Password!\nAttempt left..........................(%i)\n\n", i);
                        i--;

                }
       else if (strcmp(username, n.username) == 0 && strcmp(password, n.password) != 0 && attempts <=2)
                {
                        printf("\n\nPlease Enter Valid Username and Password!\nAttempt left..........................(%i)\n\n", i);
                        i--;

                }
       else if (strcmp(username, n.username) != 0 && strcmp(password, n.password) == 0 && attempts <=2)
                {
                        printf("\n\nPlease Enter Valid Username and Password!\nAttempt left..........................(%i)\n\n", i);
                        i--;

                }
        else
                {
                        printf("\n\nACCOUNT LOCKED, PLEASE TRY AGAIN AFTER 30 MINUTES.\n\n");
                }
                attempts++;
        }
        fclose(log);
        return 0;
}
