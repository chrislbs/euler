#include <iostream>

using namespace std;

int main()
{
   int totVal = 1000;
   int answer;

   for(int c = totVal - 3; c >= totVal / 3 + totVal % 3; c--)
   {
      int cTot = totVal - c;
      int cPy = c * c;
      for(int b = c - 1; b > 1; b--)
      {
         int bTot = cTot - b;
         int bPy = cPy - (b * b);
         if(bTot - b > 0 || bPy - (b * b) > 0)
            break;
         for(int a = b - 1; a > 0; a--)
         {
            if(bTot - a != 0 || bPy - (a * a) != 0)
               continue;
            else
               answer = a * b * c;
         }
      }
   }

   cout<< answer << endl;

   return 0;
}
