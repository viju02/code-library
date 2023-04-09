// Question - Array Subset of another array
// Question link - https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}



string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    
    for(int i=0 ; i<n ;i++)
    {
        int key = a1[i];
        map1[key]++;
    }
    
    for(int i=0 ; i<m ;i++)
    {
        int key = a2[i];
        map2[key]++;
    }
    
    int flag=1;
    for(int i=0 ; i<m ;i++)
    {
        if(map1.find(a2[i]) != map1.end())
        {
            if(map1[a2[i]] != 0)
                map1[a2[i]]--;
            else
            {
                flag=0;
                break;
            }
        }
        else
        {
            flag=0;
            break;
        }
    }
    
    if(flag==0)
        return "No";
    else
        return "Yes";
}