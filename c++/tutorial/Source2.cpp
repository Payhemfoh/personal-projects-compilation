#include<iostream>
using namespace std;

int main()
{
	char letter[30] = "welcome to touch n go";
	char notvowel[15] = { '\0' };
	int vowel = 0;
	int c = 0;

	for (int i = 0; i < 30; i++) {
		switch (letter[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			vowel++;
			break;
		case ' ':
			break;
		default:
			notvowel[c]=letter[i];
			c++;
		}
	}

	cout << vowel << endl;
	cout << notvowel << endl;
	return 0;
}