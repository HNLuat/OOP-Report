#include <bits/stdc++.h>
using namespace std;
list<double> myList;
int main()
{
    while(true){
        int n;
        cin>>n;
        if(n == -1) break;
        if(n == 0){
            double x;
            cin>>x;
            myList.push_back(x);
        }
        if(n == 1){
            double x;
            cin>>x;
            for (list<double>::iterator it = myList.begin(); it != myList.end(); ++it)
                if (*it == x) {
                    myList.erase(it);
                    break;
                }
        }
        if(n == 2){
            double x;
            cin>>x;
            myList.remove(x);
        }
        if(n == 3){
            double x, y;
            cin>>x>>y;
            int cnt = 0;
            for (list<double>::iterator it = myList.begin(); it != myList.end(); it++)
                if (cnt++ == x) {
                    it = myList.erase(it);
                    myList.insert(it, y);
                    break;
                }
        }
    }
    if(!myList.size()) return 0;
    list<double>::iterator it = myList.begin();
    cout<<"["<<*myList.begin();
    while(++it != myList.end())
        cout<<","<<*it;
    cout<<"]";

}
