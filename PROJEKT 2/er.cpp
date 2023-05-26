#include<iostream>
#include<algorithm>

using namespace std;
int main() {
   string a = "ala , basia , kasia ,jola";
   int lprzec =0;

   while(a.find(',')!=string::npos){
      lprzec++;
      a.erase(remove(a.begin(), a.end(), ','), a.end());
   }
   
   cout<<lprzec;


}