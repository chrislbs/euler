#include <iostream>
#include <map>

using std::cout;
using std::endl;

struct gnode
{
   long paths;
   gnode * down;
   gnode * right;
};

// must delete pointers
gnode ** createGrid(int x, int y)
{
   gnode ** nodes = new gnode*[x + 1];

   for(int i = 0; i < x + 1; i++)
      nodes[i] = new gnode[y + 1];

   for(int i = 0; i < x; i++)
   {
      for(int j = 0; j < y; j++)
      {
         nodes[i][j].down = &nodes[i + 1][j];
         nodes[i][j].right = &nodes[i][j + 1];
      }
   }

   return nodes;
}

unsigned long FindPaths(gnode * node)
{
   if(node->paths)
      return node->paths;
   
   unsigned long ret = 0;
   
   if(node->right)
      ret += FindPaths(node->right);
   if(node->down)
      ret += FindPaths(node->down);

   node->paths = ret;

   if(!node->down && !node->right)
      ret += 1;

   return ret;
}

int main()
{
   int gridrow = 20;
   int gridcol = 20;
   gnode ** nodes = createGrid(gridrow, gridcol);

   cout<< FindPaths(&nodes[0][0]) << endl;

   return 0;
}
