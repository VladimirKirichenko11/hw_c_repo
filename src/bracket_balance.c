#include <stdio.h>

int main() {
	char str[100];
	int balance = 0;
	printf("Enter the string: ");
	fgets(str, sizeof(str), stdin); // Reading the string
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(')
			balance++;
		else if (str[i] == ')')
			balance--;
		if (balance < 0) {
			printf("Error, incorrect bracket balance\n");
			break;
		}

	}
	if (balance > 0)
		printf("Error, incorrect bracket balance\n");
	else
		printf("Bracket balance is correct\n");

	return 0;
}