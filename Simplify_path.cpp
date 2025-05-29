#include<iostream> 
#include<sstream> 
#include<vector> 

using namespace std; 

class Solution{
public: 
      string simplifyPath(string path) {
        string ans; 
        vector<string> dirs; 
        stringstream ss(path); 
        string dir; 
        while(getline(ss, dir, '/')){
          if(dir.empty() || dir ==".") continue; 
          else if(dir ==".."){
            if(!dirs.empty()) dirs.pop_back(); 
          }else {dirs.push_back(dir);}
        }
        for(auto d:dirs){
          ans+= "/"+d; 
        }
        return ans.empty() ? "/":ans; 
      }
};
int main(){
  string path ="/home/user/Documents/../Pictures" ; 
  Solution sol; 
  cout << sol.simplifyPath(path) << endl; 
  return 0; 
}
