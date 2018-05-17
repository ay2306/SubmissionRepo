#include<iostream>
#include<vector>
#include<stdio.h>
#define ll unsigned long long int
using namespace std;

int calculate(ll starting_position, ll arr[], int n){
    int count = 0;
    ll health = 2000;
    ll injuries = 1;
    ll i = starting_position;
    do{
        if((injuries*arr[i] < 1000000) && ((health-arr[i])>0)){
            count++;
            injuries*=arr[i];
            health-=arr[i];
        }
        else{
            break;
        }
        ++i;
        if(i == n)i=0;
    }while(i != starting_position);
    return count;
}

int main(){
    FILE *fp;
    fp = fopen("input.txt","r");
    pair<int,int> p;
    vector<pair<int,int> > vec;
    int n;
    fscanf(fp,"%d",&n);
    // cin >> n;
    ll *arr = new ll[n];
    for(int i = 0; i < n; ++i){
        // cin >> arr[i];
        fscanf(fp,"%lld",&arr[i]);
    }
    int maximum_monkeys = calculate(0,arr,n);
    p.first = 0;
    p.second = maximum_monkeys;
    vec.push_back(p);
    for(int i = 1; i < n; ++i){
        int tmp = calculate(i,arr,n);
        if(tmp == maximum_monkeys){
            p.first = i;
            p.second = maximum_monkeys;
            vec.push_back(p);
        }
        else if(tmp > maximum_monkeys){
            vec.clear();
            maximum_monkeys = tmp;
            p.first = i;
            p.second = maximum_monkeys;
            vec.push_back(p);
        }
    }
    // cout << n;
    for(int i = 0; i < vec.size(); ++i){
        cout << "Index = " << vec[i].first;
        cout  << "\tMaximum = " << vec[i].second << endl;
        // ll product = 1;
        // int j = vec[i].first;
        // for(; j < vec[i].first+vec[i].second; ++j){
        //     product*=arr[j];
        //     cout << arr[i] << " * ";
        // }
        // // product*=arr[j];
        // cout << arr[j] << " = " << product << endl;
        // if(product > 1000000){
        //     cout << "Not Okay" << endl;
        // }else{
        //     cout << "Okay" << endl;
        // }
    }
    cout << "TOTAL COUNT" << vec.size() << endl;
    return 0;
}