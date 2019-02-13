// time complexity o(n)
// in space change array
// change whitespace to %20 start from the last bit 
class Solution {
public:
  /*
   * @param string: An array of Char
   * @param length: The true length of the string
   * @return: The true length of new string
   */
  int replaceBlank(char string[], int length) {
    // write your code here
    int i=0;
    int num=0;
    while(i<length){
      char c=string[i];
      if(isspace(c)){
	num++;
      }
      i++;
    }
    //no whitespace
    if(num==0){
      return length;
    }
    int newlength=length+num*2;
    string[newlength]='\0';
    int newindex=newlength-1;
    int orindex=length-1;
    while(newindex>=0&&orindex<newindex){
      if(string[orindex]==' '){
	//std::cout<<orindex<<std::endl;
	string[newindex]='0';
	string[newindex-1]='2';
	string[newindex-2]='%';
	//std::cout<<string<<std::endl;
	newindex=newindex-3;
	orindex--;
      }
      else{
	string[newindex]=string[orindex];
	//std::cout<<string<<std::endl;
	newindex--;
	orindex--;
      }
    }
    return newlength;
  }
};
