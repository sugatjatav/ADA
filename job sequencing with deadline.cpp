#include <bits/stdc++.h>
using namespace std;

typedef struct Job
{
    int jobNum;
    int deadline;
    int profit;
}Job;

bool compare(Job a, Job b);
void jobSequencing(Job input[], int num);

int main()
{
    int num;
    cin >> num;
    Job input[num];

    for (int i = 0; i < num; i++)
    {
        cin >> input[i].jobNum;
        cin >> input[i].deadline;
        cin >> input[i].profit;
    }

    jobSequencing(input, num);
}

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}
void jobSequencing(Job input[], int num)
{
    sort(input, input + num, compare);

    int result[num];
    
    bool slot[num];
    
    memset(slot, 0, sizeof(slot));

    for (int i = 0; i < num; i++)
    {
        for (int j = min(num, input[i].deadline)-1; j >= 0; j--)
        {
            if(slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Job sequenced in order: ";
    for (int i=0; i<num; i++)
    {
       if (slot[i] == true)
        cout << input[result[i]].jobNum << " ";
    }
}
