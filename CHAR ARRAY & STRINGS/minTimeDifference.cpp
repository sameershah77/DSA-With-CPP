#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<string.h>
using namespace std;


    int findMinDifference(vector<string>& timePoints) {
        //step1: convert time string into minutes integer value
        vector<int> minutes;

        for(int i=0; i<timePoints.size(); i++) {
            string curr = timePoints[i];

            int hours = stoi( curr.substr(0,2) );
            int min = stoi( curr.substr(3,5) );
            int totalMinutes = hours*60 + min;
            minutes.push_back(totalMinutes);
        }

        //Step2: sort
        sort(minutes.begin(), minutes.end());

        //Step3: difference and calculate min diff
        int mini = INT_MAX;
        int n = minutes.size();

        for(int i=0; i<n-1; i++) {
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini, diff);
        }

        //something missing - THIS IS THE GAME
        int lastDiff = (minutes[0] + 1440) - minutes[n-1];

        mini = min(mini, lastDiff);

        return mini;

    }
    string convertInHours (int s) {

    int i=1;
    string ans = "";
        while(true) {
            int temp = 60*i;
            if(s-temp <=60) {
                string a = to_string(i);
                string b = to_string(s-temp);
                if(i>9)
                    ans =a+":"+b;
                else     
                    ans = "0"+a+":"+b;
                break;
            }
            i++;
        } 
        return ans;
    }



    int main() {
        vector<string> s = {"14:35","12:56","04:13","20:38","23:59"};
        int x = findMinDifference(s);


        string ans = convertInHours(x);
        cout<<"The minimum difference in minutes "<<x<<endl;
        cout<<"The minimum difference in hours and minutes "<<ans<<endl;

    }