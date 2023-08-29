/*
ID: cyrilsh1
TASK: milk2
LANG: C++       
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Interval {
    public:          
        int startTime;
        int endTime;
        int length;
        Interval(int st, int et) {
            startTime = st;
            endTime = et;
            length = endTime - startTime;
        }

        Interval(const Interval& rhs) { 
            startTime=rhs.startTime;
            endTime=rhs.endTime;
            length=rhs.length;
        }

        bool timeWithin(int i) {
            if (i >= this->startTime && i <= this->endTime)
                return true;
            else
                return false;
        }

        bool intervalOverlaps(Interval o) {
            bool endWithin = this->timeWithin(o.endTime);
            bool startWithin = this->timeWithin(o.startTime);
            if ((startWithin || endWithin) || (o.startTime <= this->startTime && o.endTime >= this->endTime))
                return true;
            return false;
        }

        void combineIntervals(Interval o) {
            this->startTime = min(this->startTime, o.startTime);
            this->endTime = max(this->endTime, o.endTime);
            this->length = this->endTime - this->startTime;
        }
};

int main() {
    int numFarmers;
    FILE* fin = fopen("milk2.in", "r");
    fscanf(fin, "%d", &numFarmers);

    vector<Interval> schedules;
    int start, end = 0;
    for (int i = 0; i < numFarmers; i++) {
        fscanf(fin, "%d %d", &start, &end);
        schedules.push_back(Interval(start, end));
    }

    vector<Interval> oneCowMilked;
    bool intervalContained;
    // dummy value.
    Interval newInterval = schedules[0];
    vector<int> removeIndexes;
    for (int i = 0; i < numFarmers; i++) {
        removeIndexes = vector<int>();
        newInterval = schedules[i];
        intervalContained = false;
        for (int j = 0; j < oneCowMilked.size(); j++) {
            if (newInterval.intervalOverlaps(oneCowMilked[j])) {
                intervalContained = true;
                newInterval.combineIntervals(oneCowMilked[j]);
                removeIndexes.push_back(j);
            }
        }

        for (int j = removeIndexes.size() - 1; j >= 0; j--) {
            oneCowMilked[removeIndexes[j]] = oneCowMilked.back();
            oneCowMilked.pop_back();
        }

        if (!intervalContained) {
            oneCowMilked.push_back(schedules[i]);
        }
        else {
            oneCowMilked.push_back(newInterval);
        }
    }

    int maxMooLen = 0;
    int intervalLen = 0;
    for (int i = 0; i < oneCowMilked.size(); i++) {
        intervalLen = oneCowMilked[i].length;
        if (intervalLen > maxMooLen) {
            maxMooLen = intervalLen;
        }
    }

    // need to use milking data to arrive at maximum length where there was no milking.
    Interval curr = oneCowMilked[0];
    for (int i = 1; i < oneCowMilked.size(); i++) {
        curr = oneCowMilked[i];
        for (int j=i-1; j >= 0; j--) {
            if (curr.startTime < oneCowMilked[j].startTime) {
                swap(oneCowMilked[j+1], oneCowMilked[j]);
            }
            else
                break;
        }
    }
    
    int maxNoMooLen = 0;
    intervalLen = 0;
    for (int i = 0; i < oneCowMilked.size() - 1; i++) {
        intervalLen = oneCowMilked[i+1].startTime - oneCowMilked[i].endTime;
        if (intervalLen > maxNoMooLen) {
            maxNoMooLen = intervalLen;
        }
    }

    FILE* fout = fopen("milk2.out", "w");
    fprintf (fout, "%d %d\n", maxMooLen, maxNoMooLen);
}
