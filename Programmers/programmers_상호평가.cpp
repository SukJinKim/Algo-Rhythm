#include <string>
#include <vector>
#include <limits>

using namespace std;

const int MIN = numeric_limits<int>::min();
const int MAX = numeric_limits<int>::max();

void writeGrade(string &ans, float &score)
{
    if(score >= 90)
        ans += "A";
    else if(score >= 80)
        ans += "B";
    else if(score >= 70)
        ans += "C";
    else if(score >= 50)
        ans += "D";
    else
        ans += "F";
}

bool isUniqueMinMax(int student, int n, vector<vector<int>> &scores)
{
    int mx = MIN, mn = MAX, assessedScore;
    bool isUniqueMin = true, isUniqueMax = true;
    
    for(int i = 0; i < n; i++)
    {
        assessedScore = scores[i][student];
        
        if(assessedScore == mx)
            isUniqueMax = false;
        if(assessedScore > mx)
        {
            mx = assessedScore;
            isUniqueMax = true;
        }
        
        if(assessedScore == mn)
            isUniqueMin = false;
        if(assessedScore < mn)
        {
            mn = assessedScore;
            isUniqueMin = true;
        }
    }
    
    if(scores[student][student] == mx && isUniqueMax)
        return true;
    if(scores[student][student] == mn && isUniqueMin)
        return true;
    return false;
}


string solution(vector<vector<int>> scores) {
    string answer = "";
    bool _isUniqueMinMax;
    float avg;
    int sum, n = scores.size();
    
    for(int std1 = 0; std1 < n; std1++)
    {
        _isUniqueMinMax = isUniqueMinMax(std1, n, scores);
        
        if(_isUniqueMinMax)
            scores[std1][std1] = 0;
        
        sum = 0;
        avg = 0.0;
        
        for(int std2 = 0; std2 < n; std2++)
            sum += scores[std2][std1];
        
        avg = _isUniqueMinMax ? sum / (n - 1) : sum / n;
        writeGrade(answer, avg);
    }
   
    return answer;
}
