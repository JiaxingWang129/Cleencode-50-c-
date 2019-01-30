class Solution {
public:
  string longestPalindrome(string s) {
    int maxLen=0;
    int curLen;
    int L;
    int r;
    int start;
    if(s.length()==0||s.length()==1){
      return s;
    }
    //two differnet char return the frist char
    if(s.length()==2&&s[0]!=s[1]){
      return s.substr(0,1);
    }
    //the length is odd
    if(s.length()%2==1){
      for (int i=0;i<=s.length();i++){
	L=i-1;
	r=i+1;
	curLen=1;
	while(L>=0&&r<=s.length()&&s[L]==s[r]){
	  curLen=curLen+2;
	  L--;
	  r++;
	  if(curLen>maxLen){
	    maxLen=curLen;
	    start=L; 
	  }
	}
      }
      if(maxLen<2){
	for(int z=0;z<s.length();z++){
	  if(s[z]==s[z+1]){
	    return s.substr(z,2);
	  }
	}
	return s.substr(0,1);
      }
      return s.substr(start+1,maxLen);
    }
    //the length is even
    if(s.length()%2==0){
      for (int i=0;i<=s.length();i++){
	L=i-1;
	r=i+1;
	curLen=1;
	while(L>=0&&r<=s.length()&&s[L]==s[r]){
	  curLen=curLen+2;
	  L--;
	  r++;
	  if(curLen>maxLen){
	    maxLen=curLen;
	    start=L; 
	  }
	}
      }
      std::cout<<maxLen<<std::endl;
      for (int i=0;i<=s.length();i++){
	L=i;
	r=i+1;
	curLen=0;
	while(L>=0&&r<=s.length()&&s[L]==s[r]){
	  curLen=curLen+2;
	  L--;
	  r++;
	  if(curLen>maxLen){
	    maxLen=curLen;
	    start=L; 
	  }
	}
      }
    }
    return s.substr(start+1,maxLen);
  }
};







/*this problem is still confusing me, the first version can pass 93 testcases.
which is a not so concise. we need to check the mid element an expand it to two way. and we need to think about the odd and even length(the odd is pretty easy, the even one needs to pass both i,i-1 and i-1 with i+1)
it fails the case of "adam",time complexity is on2 
----need to thinking a better way

/*the second version is also on2 but we can skip the even and odd scnerio
*/
class Solution {
public:
  string longestPalindrome(string s) {
    int start;
    int maxLen=1;
    int length;
    int i;
    int j;
    int k;
    if(s.size()<2){
      return s;
    }
    int z;
    for(z=0;z<s.size()-1;z++){
      if(s[z]!=s[z+1]){
	break;
      }
    }
    // std::cout<<z<<std::endl;
    if(z==s.size()-1){
      // std::cout<<z<<std::endl;
      return s;
    }
    for(i=0;i<s.size();i++){
      if(s.size()-i<=maxLen){
	break;
      }
      j=i;
      k=i;
      while(k<s.size()-1&&s[k]==s[k+1]){
	k++;
      }
      I=k+1;
      while(j>0&&k<s.size()-1&&s[k+1]==s[j-1]){
	k++;
	j--;
      }
      length=k-j+1;
      if(length>maxLen){
	maxLen=length;
	start=j;
      }
    }
    return s.substr(start,maxLen);
  }
};







//still cannot pass all but I think what i write is the same as the disscusion //can anyone tell me what is wrong with this code?

