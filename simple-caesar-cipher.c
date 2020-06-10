/*
**** Caesar Cipher ****
This program will take alphanumeric input and produce caesar cipher using shift key = 3.  

*/

#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

//This is the prototype header of the function caesar.
int caesar (char cipher[], int shift);  

int main() {
        char cipher[20] = ""; //Defining buffer size as 20.
        int shift = 3; // Defining shift key as 3.
        int i = 0;
        bool error = false;
     
       //Taking Input form user.
        printf("Please Enter Plaintext: ");
        scanf("%20s", cipher);

        //Input validation.
        while (cipher[i] != '\0' && i < sizeof(cipher)) {
                if ( ( isalpha(cipher[i]) == 0 && isdigit(cipher[i]) == 0) &&  cipher[i] != '\000' ) { //isalpha and isdigit fuctions will check whether the input is a letter or number.
                    error = true;
                } 

                i++;
        }                                                   
        if (error != true) {                                
                caesar (cipher, shift); // if there are no error it will store the values to the variable.                     
                return 0;                                   
        }                                                   
        else {  // Output the error message.                                           
                printf("Invalid Input, Please Enter English Letters and Numbers.\n");                 
                return 1;                                   
        }                    
                           
}

// Operation of caesar function.
int caesar (char cipher[], int shift) {
        int i = 0; //Initializing i as 0.
        /* Following steps will take the given character value and deduct the value from ‘A’ in ASCII table which is 65 and store it in new variable: plaintext. For example, if the input character is B then, it will be 66-65 = 1.
         * Then it will add the shift key 3. (3 + 1) = 4.
         * Then it will perform a mod 26 calculation on the shift key added plaintext. (in this case 4%26 = 4).
         * Lastly, it will add the value to the Value of ‘A’ (65 + 4) = 69. Which is E in the ASCII table.
         */
        while (cipher[i] != '\0') {
                if (isalpha(cipher[i])) {
                        char plaintext = cipher[i] - 'A';
                        plaintext += shift;
                        plaintext = plaintext % 26;
                        cipher[i] = plaintext + 'A';
                }

                //Similarly, the following program will perform mod 10 and add the shift key to generate ciphertext.
                else if (isdigit(cipher[i])) {
                        char plaintext = cipher[i] - '0';
                        plaintext += shift;
                        plaintext = plaintext % 10;
                        cipher[i] = plaintext + '0';
                }

                i++;


        }

        //Printing the final output as Ciphertext.
        printf("Encrypted Caesar Ciphertext: %s \n", cipher);
        return 0;
}

