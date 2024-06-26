#include<iostream>
#include<cstring>

using namespace std;

// length of s1 is m
// length of s2 is n

// time : min(m, n)

int compareString(char s1[], char s2[]) {

	int i = 0; // to iterate over s1[]
	int j = 0; // to iterate over s2[]

	while (s1[i] != '\0' and s2[j] != '\0') {

		if (s1[i] > s2[j]) {

			// s1 > s2

			return 1;

		}

		if (s1[i] < s2[j]) {

			// s1 < s2

			return -1;

		}

		// s1[i] is equal to s2[j]

		i++;
		j++;

	}

	if (s1[i] == '\0' and s2[j] == '\0') {

		// length of s1 is equal to length of s2

		return 0;

	} else if (s1[i] == '\0') {

		// length of s1 is less than length of s2

		// s1 < s2

		return -1;

	}

	// length of s1 is more than length of s2

	// s1 > s2

	return 1;

}

int main() {

	char s1[] = "azc";
	char s2[] = "adc";

	int res = strcmp(s1, s2); // compareString(s1, s2)

	if (res == 0) {
		cout << s1 << " is equal to " << s2 << endl;
	} else if (res > 0) {
		cout << s1 << " > " << s2 << endl;
	} else { // res < 0
		cout << s1 << " < " << s2 << endl;
	}

	return 0;
}