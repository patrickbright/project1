#include <stdio.h>

//define functions
void rotationEncryption(char* code, int key);
void rotationDecryption(char* code, int key);
void substitutionEncryption(char* code, int key);
void substitutionDecryption(char* code, int key);
void rotationAttack(char* code);
void substitutionAttack(char* code);

int main() {

	int key;
	//max message length 1024 chars
	char code[1024];
	
    printf("Enter a message: ");
    //clear input
    //getchar();
    //read input to message array
    fgets(code, 1024, stdin);
    printf("Enter a key: ");
    //read input to key int
    scanf("%d", &key);
    
    //menu logic
    int menu = 0;
    printf("\n1. Encrypt message with rotation cipher\n");
    printf("2. Decrypt message with rotation cipher\n");
    printf("3. Encrypt message with substitution cipher\n");
    printf("4. Decrypt message with substitution cipher\n");
    printf("5. Decrypt message with rotation cipher WITHOUT a key\n");
    printf("6. Decrypt message with substitution cipher WITHOUT a key\n");
    printf("\nPlease select an option: ");
    //read input for menu selection
    scanf("%d", &menu);
    
    switch(menu) {
        
        //encrypt rotation cipher
        case 1:
        
            rotationEncryption(code, key);
            break;
            
        //decrypt rotation cipher
        case 2:
            
            rotationDecryption(code, key);
            break;
            
        //encrypt substitution cipher
        case 3:

            //substitutionEncryption(code, key);
            break;
            
        //decrypt substitution cipher
        case 4:

            //substitutionDecryption(code, key);
            break;
            
        //decrypt rotation cipher without key (attack)
        case 5:

            rotationAttack(code);
            break;
            
        //decrypt subtitution cipher without key (attack)
        case 6:

            //substitutionAttack(code);
            break;
            
        //invalid input
        default:
            printf("Eror - Invalid menu option!");
            break;
    }

    return 0;
}

//function to encrypt a message with a rotation cipher
void rotationEncryption(char* code, int key){
	
	int letter;
	char message;
	
    printf("\nThe encrypted message is: ");
    
    //loop through array
    for (int i = 0; code[i] != '\0'; i++) {
        
        //convert to uppercase
        code[i] = toupper(code[i]);
        
        //is alphabetical
        //ASCII value A is 65 and Z is 90
        if (code[i] >= 65 && code[i] <= 90) {
            letter = (((((int)code[i] + key) - 65) % 26) + 65);
            message = (char)(letter);
            printf("%c", message);
        }
        //not alphabetical
        else {
            printf("%c", code[i]);  
        }
    }
}

//function to decrypt a message with a rotation cipher
void rotationDecryption(char* code, int key){
	
	int letter;
	char message;
	
    printf("\nThe decrypted message is: ");
    
    //loop through array
    for (int i = 0; code[i] != '\0'; i++) {
        
        //convert to uppercase
        code[i] = toupper(code[i]);
        
        //is alphabetical
        //ASCII value A is 65 and Z is 90
        if (code[i] >= 65 && code[i] <= 90) {
            letter = (((((int)code[i] - key) + 65) % 26) + 65);
            message = (char)(letter);
            printf("%c", message);
        }
        //not alphabetical
        else {
            printf("%c", code[i]);  
        }
    }
}

//function to encrypt a message with a substitution cipher
void substitutionEncryption(char* code, int key) {
    
    //todo
}

//function to decrypt a message with a substitution cipher
void substitutionDecryption(char* code, int key) {
    
    //todo
}

//function to decrypt a message with a rotation cipher WITHOUT a key
void rotationAttack(char* code) {
	
	int letter;
	char message;
	
    printf("\nThe decrypted message is one of the following: \n");
    
    //loop for all possible key combinations
    for (int k = 1; k < 26; k++) {
        
        printf("#%d. ", k);
        //loop through array
        for (int i = 0; code[i] != '\0'; i++) {
            
            //convert to uppercase
            code[i] = toupper(code[i]);
            
            //is alphabetical
            //ASCII value A is 65 and Z is 90
            if (code[i] >= 65 && code[i] <= 90) {
                letter = (((((int)code[i] - k) + 65) % 26) + 65);
                message = (char)(letter);
                printf("%c", message);
            }
            //not alphabetical
            else {
                printf("%c", code[i]);  
            }
        }
    }
}

//function to decrypt a message with a substitution cipher WITHOUT a key
void substitutionAttack(char* code) {
    
    //todo
}