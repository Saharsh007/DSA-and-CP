#define f(i,a,b) for(long long i=a;i<b;i++)

unordered_map<string,int> stringmap;
unordered_map<string,int> stringmapcopy;

// mapping all substrings
void mark(vector<string> B){
    f(i,0,B.size()){
        stringmap[B[i]]++;
        stringmapcopy[B[i]]++;
    }
}

// returns a sorted string combining all strings of a vector 
string getsortedstring(vector<string> B){
    string sorted = "";
    f(i,0,B.size()){
        sorted += B[i];
    }
    sort(sorted.begin(),sorted.end());
    return sorted;
}

//checks if this substring is the required one
int checkforvalidity(string suspect,vector<string> B){
    int start=0,substart=0,i=0,n = suspect.length();
    stringmap.clear();
    stringmapcopy.clear();
    mark(B);

    while(i<n){
        string curr = suspect.substr(start,i-start+1);
        // debug4(curr,stringmap[curr],start,i);
        if( stringmap[curr] > 0){ 
            stringmap[curr]++;
            start = i+1;
        }
        i++;
    }

    f(i,0,B.size()){
    	string curr = B[i];
    	if(stringmap[B[i]] - stringmapcopy[B[i]] < 1) 
    			return 0; 
    }
    return 1;
}


vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    stringmap.clear();
    int n = A.length(),m = B.size();
    vector<int> ans;
    if(n<1 || m<1) return ans;
    
    string sorted = getsortedstring(B);
    int len = sorted.length();
    int start=0,i=0;
    while(i<=n-len){
        // only substrings of len are required
        string curr = A.substr(i,len),currcopy= curr;
        sort(curr.begin(),curr.end());
        if(curr == sorted){
            int check = checkforvalidity(currcopy,B);
            //reset maps to their original value
            if(check){
                ans.push_back(i);
            }
        }
        i++;
    }
    
    //space and time pass
    vector<int> v(20); int x =20; while(x) x--;
    
    return ans;
}
