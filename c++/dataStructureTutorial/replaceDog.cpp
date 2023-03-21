#include <iostream>
#include <string>

int main() {
	using namespace std;
	string sentence = "I have a dog. The dog is playing with the birds happily";
	cout << "Before changes : " << sentence << endl;

	int index = -1;
	while ((index = sentence.find("dog")) > 0) {
		sentence.erase(index, 3);
		sentence.insert(index,"cat");
	}

	cout << "After changes : " << sentence << endl;
}