#include<bits/stdc++.h>
using namespace std;


class Transaction{
public:
    string name;        // person name
    int time;           // transaction time
    int amount;         // amount of transaction
    string city;

    Transaction(string n, int t, int a, string c){
        this->name = n;
        this->time = t;
        this->amount = a;
        this->city = c;
    }
};


class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<bool> isValid(n, true);      // keeps track of valid transactions
        vector<Transaction> allTransactions;

        // Extracting Values
        for(int i=0; i<n; i++){
            string currentTransaction = transactions[i];
            string name="", time="", amount="", city="";
            int j=0;

            // Extracting Name
            while(currentTransaction[j] != ',')
                name += currentTransaction[j++];
            j++;

            // Extracting time
            while(currentTransaction[j] != ',')
                time += currentTransaction[j++];
            j++;

            // Extracting amount
            while(currentTransaction[j] != ',')
                amount += currentTransaction[j++];
            j++;

            // Extracting city
            while(j < currentTransaction.size())
                city += currentTransaction[j++];

            // Make a new Transaction and add it to our transactions vector
            Transaction newTransaction(name, stoi(time), stoi(amount), city);
            allTransactions.push_back(newTransaction);
        }

        // now Mark Invalid Transactions
        n = allTransactions.size();
        // Step1: mark those transactions whose amount > 1000
        for(int i=0; i<n; i++)
            if(allTransactions[i].amount > 1000)
                isValid[i] = false;

        // Step2: Mark those transactions with name->same, city->diff and time_diff <= 60
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;

                if((allTransactions[i].name == allTransactions[j].name) && (allTransactions[i].city != allTransactions[j].city)){
                    int time_diff = abs(allTransactions[i].time - allTransactions[j].time);
                    if(time_diff <= 60){
                        // If the above conditions are met, the transaction is invalid.
                        isValid[i] = false;
                        isValid[j] = false;
                    }
                }
            }
        }

        vector<string> invalidTransactions;
        for(int i=0; i<n; i++)
            if(!isValid[i])
                invalidTransactions.push_back(transactions[i]);


        return invalidTransactions;
    }
};

int main()
{

    return 0;
}