#include <iostream>
#include <set>
using namespace std;
string encrypt(string plaintext,int a, int b)
{
	string ciphertext;
	for (int i = 0; i < plaintext.length(); i++)
		ciphertext += char(((((plaintext[i] - 'a') * a) + b) % 26)+'a');

	return ciphertext;
}
int a_inverse(int a)
{
	int arr[13] = { 0,1,3,5,7,9,11,15,17,19,21,23,25 };
	for (int i = 0; i < 13; i++)
		if ((arr[i] * a) % 26 == 1)
			return arr[i];
}
void decrypt(string ciphertext, int a, int b)
{
	int ainv = a_inverse(a);
	string plaintext;
	for (int i = 0; i < ciphertext.length(); i++)
	{
		int temp = ainv * (((ciphertext[i] - 'a') - b));
		if (temp < 0)
			temp = 26 + temp; //special thnk to ibrahim sultan for solving this -ve mod error
		plaintext += char((( temp % 26) + 'a'));

	}
	cout << plaintext;
}
int main()
{
	decrypt(encrypt("ashar", 1, 11), 1, 11);

}
