#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include "utility.h"
#include <queue>
#include <iomanip>

using namespace std;

string filename = "prob11.txt";
unsigned long lar = 1, cur = 1;

struct node
{
public:
   node(unsigned long value):val(value), across(false), down(false), diagr(false), diagl(false){}
   unsigned long val;
   bool across;
   bool down;
   bool diagr;
   bool diagl;
};

void calcAcr(vector<node> &nodes, int sIndex)
{
   queue<unsigned long> vals;
   
   cur = 1;
   do
   {
      nodes[sIndex].across = true;
      if(nodes[sIndex].val == 0)
      {
         while(!vals.empty())
         {
            vals.pop();
         }
         cur = 1;
         continue;
      }
      vals.push(nodes[sIndex].val);
      cur *= nodes[sIndex].val;
//      cout<< std::setw(2) << sIndex << ' ';
//      cout<< std::setw(2) << nodes[sIndex].val << ' ';
      if(vals.size() < 4)
         continue;
      else
      {
         if(cur > lar)
         {
            lar = cur;
         }
         cur /= vals.front();
         vals.pop();
      }         
   }while(++sIndex % 20 != 0);
}

void calcDown(vector<node> &nodes, int sIndex)
{
   queue<unsigned long> vals;

   cur = 1;
   for(;sIndex < nodes.size(); sIndex += 20){
      nodes[sIndex].down = true;
      if(nodes[sIndex].val == 0)
      {
         while(!vals.empty())
         {
            vals.pop();
         }
         cur = 1;
         continue;
      }
      vals.push(nodes[sIndex].val);
      cur *= nodes[sIndex].val;
      if(vals.size() < 4)
         continue;
      else
      {
         if(cur > lar)
         {
            lar = cur;
         }
         cur /= vals.front();
         vals.pop();
      }
   }
//   }while(++sIndex % 20 != 0);
}

void calcDiagR(vector<node> &nodes, int sIndex)
{
   queue<unsigned long> vals;

   cur = 1;
   for(;sIndex < nodes.size() && sIndex % 19 != 0; sIndex += 21){
      nodes[sIndex].down = true;
      if(nodes[sIndex].val == 0)
      {
         while(!vals.empty())
         {
            vals.pop();
         }
         cur = 1;
         continue;
      }
      vals.push(nodes[sIndex].val);
      cur *= nodes[sIndex].val;
      if(vals.size() < 4)
         continue;
      else
      {
         if(cur > lar)
         {
            lar = cur;
         }
         cur /= vals.front();
         vals.pop();
      }
   }
}

void calcDiagL(vector<node> &nodes, int sIndex)
{
   queue<unsigned long> vals;

   cur = 1;
   for(;sIndex < nodes.size() && sIndex % 20 != 0; sIndex += 19){
      nodes[sIndex].down = true;
      if(nodes[sIndex].val == 0)
      {
         while(!vals.empty())
         {
            vals.pop();
         }
         cur = 1;
         continue;
      }
      vals.push(nodes[sIndex].val);
      cur *= nodes[sIndex].val;
      if(vals.size() < 4)
         continue;
      else
      {
         if(cur > lar)
         {
            lar = cur;
         }
         cur /= vals.front();
         vals.pop();
      }
   }
}

void getValsFromFile(vector<node> &nodes)
{
   vector<string> rows;
   fstream file;
   int flength;
   char * fbuffer;
   string fileText;

   file.open(filename.c_str(), fstream::in | fstream::out);
   flength = file.seekg(0, fstream::end).tellg();
   file.seekg(0, fstream::beg);
   fbuffer = new char[flength];
   file.read(fbuffer, flength);
   file.close();
   fileText = fbuffer;
   delete [] fbuffer;
   
   utility::strSplit(rows, fileText, '\n');

   for(int i = 0; i < rows.size(); i++)
   {
      vector<string> cols;
      utility::strSplit(cols, rows[i], ' ');

      for(int j = 0; j < cols.size(); j++)
      {
         nodes.push_back(node(atol(cols[j].c_str())));
      }
   }
}

int main()
{
   vector<node> nodes;

   getValsFromFile(nodes);


   for(int i = 0; i < nodes.size(); i++)
   {
      if(!nodes[i].across)
         calcAcr(nodes, i);
      if(!nodes[i].down)
         calcDown(nodes, i);
      if(!nodes[i].diagr)
         calcDiagR(nodes, i);
      if(!nodes[i].diagl)
         calcDiagL(nodes, i);
   }
   cout<< lar << endl;

   return 0;
}
