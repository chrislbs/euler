#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>

typedef std::vector< std::vector<char> > box;
typedef std::vector< std::vector<box> > puzzle;

void GetPuzzles(std::vector<puzzle> &puzzles)
{
   std::fstream fs;
   char buffer[256];

   puzzles.clear();
   fs.open("sudoku.txt", std::fstream::in);
   int row;
   while(!fs.eof() && !fs.getline(buffer, sizeof(buffer), '\n').fail()) 
   {
      if(buffer[0] == 'G')
      {
         row = 0;
         puzzles.push_back(puzzle());
         continue;
      }
      for(int i = 0; i < strlen(buffer) - 1; i++)
      {
         if(i % 3 == 0 && row % 3 == 0)
            puzzles.back().push_back(box());
         puzzles.back()[row / 3][i / 3].push_back(buffer[i]);
      }
      row++;
   }
   fs.close();
}

void PrintPuzzle(puzzle &puzz)
{
   for(int i = 0; i < puzz.size(); i++)
   {
      for(int j = 0; j < puzz[i].size(); j++)
      {
         for(int k = 0; k < puzz[i][j].size(); k++)
         {
            std::cout<< puzz[i][j][k] << "  ";
            if((k + 1) % 3 == 0)
               std::cout<< '\t';
         }
         if((j + 1) % 3 == 0)
            std::cout<< std::endl;
      }
   }
}


//puzzle & CrossRow(puzzle &puzz, int row, char c)
//{
//    might want to do something about a repeat in row
//   for(int i = 0; i < puzz.grid.back().size(); i++)
//      if(puzz.grid[row][i] != c)
//         puzz.grid[row][i] = 'X';
//   
//   return puzz;
//}

//puzzle & CrossCol(puzzle &puzz, int col, char c)
//{
//   for(int i = 0; i < puzz.grid.size(); i++)
//      if(puzz.grid[i][col] != c)
//         puzz.grid[i][col] = 'X';

//   return puzz;
//}

//puzzle MaskPuzzle(puzzle &puzz, char c)
//{
//   puzzle mask(puzz);

//   for(int i = 0; i < mask.grid.size(); i++)
//   {
//      for(int j = 0; j < mask.grid[i].size(); j++)
//      {
//         if(mask.grid[i][j] == '0')
//            mask.grid[i][j] = '?';
//         else if (mask.grid[i][j] == c)
//            CrossCol(CrossRow(mask, i, c), j, c);
//      }
//   }
//   return mask;
//}

int main()
{
   std::vector<puzzle> puzzles;
   GetPuzzles(puzzles);
//   puzzle temp = MaskPuzzle(puzzles[0], '1');
   PrintPuzzle(temp.grid);
//   for(int i = 0; i < puzzles.size(); i++)
//   {
//      PrintPuzzle(puzzles[i].grid);
//   }

   return 0;
}
