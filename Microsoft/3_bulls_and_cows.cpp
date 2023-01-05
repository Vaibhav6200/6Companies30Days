#include<bits/stdc++.h>
using namespace std;

/*
    Approach
    1. iterate over str1 and str2 and count bulls
        => if (str1[i] == str2[i]) => increase bull count

    2. For Cows - maintain a frequency hashmap
        => Now iterate over guess
        => if guess[i] in hashmap
        => increment - x and decrement its frequency from hashmap
        in this procedure our cows will contain both bulls and cows

*/

string getHint(string secret, string guess) {
    int n = secret.size();
    int bulls = 0;

    // Count Bulls
    for(int i=0; i<n; i++)
        if(secret[i] == guess[i])
            bulls++;

    // Count x = bulls + cows
    unordered_map<char, int> map;
    for(int i=0; i<n; i++)
        map[secret[i]]++;

    int x=0;
    for(int i=0; i<n; i++)
        if(map[guess[i]] > 0){
            x++;
            map[guess[i]]--;
        }

    int cows = x - bulls;

    return (to_string(bulls) + "A" + to_string(cows) + "B");
}

int main()
{
    string secret;
    string guess;

    cout << "Enter Secret: ";
    cin >> secret;
    cout << "Enter Guess: ";
    cin >> guess;

    string result = getHint(secret, guess);
    cout << "Hint: " << result;

    return 0;
}