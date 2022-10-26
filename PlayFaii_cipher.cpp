#include <iostream>
#include <map>
#include<set>
#include<string>
#include<vector>
using namespace std;

struct node
{
	string* pairs;
	int len;
};
node makepairs(string text)
{
	string* pairs;
	if (text.length() % 2 != 0)
		text += 'z';
	for (int i = 0; i < text.length(); i += 2)
		if (text[i + 1] == text[i])
			text = text.substr(0, i + 1) + 'z' + text.substr(i + 1);
	if (text.length() % 2 != 0)
		text += 'z';
	int k = 0;
	//ax ab bc cx
	int l = text.length() / 2;
	pairs = new string[l];
	for (int i = 0; i < text.length(); i += 2)
	{
		pairs[k] += text[i];
		pairs[k] += text[i + 1];
		k++;
	}
	struct node n;
	n.len = l;
	n.pairs = pairs;
	return n;
}
char** makematrix(string key)
{
	string TempKey = key + "abcdefghiklmnopqrstuvwxyz";
	map <int,char> seen;
	int count = 0;
	char** mat = new char* [5];
	for (int i = 0; i < 5; i++)
		mat[i] = new char[5]{};
	for (int i = 0; TempKey[i]; i++)
	{
		if (TempKey[i] == 'j' || TempKey[i] == 'J')
			TempKey[i] = 'i';
		int temp = TempKey[i] - ' ';
		if (seen.find(temp) == seen.end())
		{
			seen.insert(make_pair(temp, TempKey[i]));
			mat[count / 5][count % 5] = TempKey[i];
			count++;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << mat[i][j] << " ";
		cout << "\n";
	}
	return mat;
}
int main()
{
	string text;
	cout << "enter text";
	getline(cin, text);
	string key;
	cout << "enter key";
	getline(cin, key);
	struct node n=makepairs(text);
	string* pairs=n.pairs;
	int l=n.len;
	for (int i = 0; i <l; i++)
		cout << pairs[i]<<" ";

	char **mt=makematrix(key);

	vector<pair<int, int>> indices(26);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			indices[mt[i][j] - 'a'] = make_pair(i, j);
	for (int i = 0; i < n.len; i++)
	{
		int temp2D[2][2] = { {indices[pairs[i][0] - 'a'].first, //find i of pair first elemnet
							 indices[pairs[i][0] - 'a'].second },//find j of pair first elemnet
							{indices[pairs[i][1] - 'a'].first,
							 indices[pairs[i][1] - 'a'].second }
							};

		if (temp2D[0][0] != temp2D[1][0] && temp2D[0][1] != temp2D[1][1])
			cout << mt[temp2D[0][0]][temp2D[1][1]] << mt[temp2D[1][0]][temp2D[0][1]];
	}

	//decrypt(encrypt("ashar", 1, 11), 1, 11);

}

