// n <= 50 and m <= 50

#include<iostream>
#include<cstring>

using namespace std;

// length of s1 is m
// length of s2 is n

// steps = n ~ O(n)

void concatString(char s1[], char s2[]) {

	int i = strlen(s1); // to iterate over s1[]
	int j = 0; // to iterate over s2[]

	while (s2[j] != '\0') {

		s1[i] = s2[j];

		i++;
		j++;

	}

	s1[i] = '\0';


}


int main() {

	char s1[101] = "abc";
	char s2[] = "def";

	cout << "Before concat : " << s1 << endl;

	// concatString(s1, s2);
	strcat(s1, s2);

	cout << "After concat : " << s1 << endl;

	return 0;
}