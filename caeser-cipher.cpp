#include <iostream>
using namespace std;
void decryption(string ciphertext, int key)
{
    string plaintext;
    for (int i = 0; i < ciphertext.length(); i++)
    {
        plaintext += char(ciphertext[i] - key);
    }
    cout << plaintext;
}
string encryption(string plaintext,int key)
{
    string ciphertext;
    for (int i = 0; i < plaintext.length(); i++)
    {
        ciphertext +=char( plaintext[i] + key);
    }
  //  cout << ciphertext;
    return ciphertext;
}
int main()
{
   decryption(encryption("Hello World!", 1) ,1 );
}
