#include<cstring>
#include<cstdio>
#include<string.h>
class CMyString
{      
private:
  char* m_pData;

public:
 CMyString (const CMyString& str){
    strcpy(m_pData,str.m_pData);
  }
void Print();
 
CMyString &operator =(const CMyString &str){
  if(this != &str){
    int length = strlen(str.m_pData);
    char* temp= new char[length+1];
    strcpy(temp,str.m_pData);
    delete[] m_pData;
    m_pData=temp;
  }
 return *this;
}

~CMyString(){
  delete[] m_pData;
}
};
// ====================测试代码====================
 void CMyString::Print()
 {
   printf("%s", m_pData);
 }

 void Test1()
 {
   printf("Test1 begins:\n");

   char* text = "Hello world";

   CMyString str1(text);
   CMyString str2;
   str2 = str1;

   printf("The expected result is: %s.\n", text);

   printf("The actual result is: ");
   str2.Print();
   printf(".\n");
 }

 // 赋值给自己
 void Test2()
 {
   printf("Test2 begins:\n");

   char* text = "Hello world";

   CMyString str1(text);
   str1 = str1;

   printf("The expected result is: %s.\n", text);

   printf("The actual result is: ");
   str1.Print();
   printf(".\n");
 }

 // 连续赋值
 void Test3()
 {
   printf("Test3 begins:\n");

   char* text = "Hello world";

   CMyString str1(text);
   CMyString str2, str3;
   str3 = str2 = str1;

   printf("The expected result is: %s.\n", text);

   printf("The actual result is: ");
   str2.Print();
   printf(".\n");

   printf("The expected result is: %s.\n", text);

   printf("The actual result is: ");
   str3.Print();
   printf(".\n");
 }

 int main(int argc, char* argv[])
 {
   Test1();
   Test2();
   Test3();

   return 0;
 }
