class Solution {
public:
    
    int score(vector<int>student,vector<int>mentor)
    {
         int count=0;
        
        for(int i=0;i<student.size();i++)
        {
            if(student[i]==mentor[i])
                count++;
        }
        return count;
    }
    
    int solution(vector<vector<int>>& students, vector<vector<int>>& mentors,vector<bool>&visited,int n,int m)
    {
        
        if(m==0)
            return 0;
        
         int res = 0;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
            res = max(res,score(students[m-1],mentors[i])+solution(students,mentors,visited,n,m-1));
                visited[i]=false;
                }
        }
        
        return res;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=students.size();
        vector<bool>visited(n,false);
        
        return solution(students,mentors,visited,n,n);
    }
};
