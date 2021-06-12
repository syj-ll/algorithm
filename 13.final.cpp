#include <iostream>
    using namespace std;
 
    class Solution {
    public:
        int StrDistance(string A,string B){
            int sizeA = A.size();
            int sizeB = B.size();
            return StrDistance(A,0,sizeA-1,B,0,sizeB-1);
        }
    private:
        int StrDistance(string A,int startA,int endA,string B,int startB,int endB){
            if(startA > endA){
               // �ַ���A��B��ĩβ
               if(startB > endB){
                   return 0;
               }//if
               // �ַ���A��ĩβ Bδ��
               else{
                   return endB - startB + 1;
               }
            }//if
            // �ַ���B��ĩβ Aδ��
            if(startB > endB && startA <= endA){
                return endA - startA + 1;
            }//if
            // �ַ���A��B��δ��ĩβ
            if(A[startA] == B[startB]){
                return StrDistance(A,startA+1,endA,B,startB+1,endB);
            }//if
            else{
                int len1 = StrDistance(A,startA+1,endA,B,startB,endB);
                int len2 = StrDistance(A,startA,endA,B,startB+1,endB);
                int len3 = StrDistance(A,startA+1,endA,B,startB+1,endB);
                return min(min(len1,len2),len3)+1;
            }//else
        }
    };
 
 
    int main() {
        Solution solution;
        string str1("xabcdae");
        string str2("xfdfa");
        cout<<solution.StrDistance(str1,str2)<<endl;
    }
