package com.clbs;

import com.clbs.Sudoku.Puzzle;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;

public class Main {

    /**
     * A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be
     * necessary to employ "guess and test" methods in order to eliminate options (there is much contested opinion
     * over this). The complexity of the search determines the difficulty of the puzzle; the example above is
     * considered easy because it can be solved by straight forward direct deduction.
     * The 6K text file, sudoku.txt (right click and 'Save Link/Target As...'), contains fifty different Su Doku puzzles
     * ranging in difficulty, but all with unique solutions (the first puzzle in the file is the example above).
     * By solving all fifty puzzles find the sum of the 3-digit numbers found in the top left corner of each solution
     * grid; for example, 483 is the 3-digit number found in the top left corner of the solution grid above.
     * @param args
     */
    public static void main(String[] args) {
    }

    private static Collection<Puzzle> ReadPuzzles() {
        final String SUDOKU_FILE = "sudoku.txt";

        ArrayList<Puzzle> puzzles = new ArrayList<Puzzle>();
        try {
            FileReader fr = new FileReader(SUDOKU_FILE);
            try {
                BufferedReader br = new BufferedReader(fr);

                String puzzleName = br.readLine();
                while(puzzleName != null) {
                    int[][] state = ReadPuzzleState(br);
                    puzzles.add(new Puzzle(puzzleName, state));
                }
            }
            catch (IOException ex) {
                System.out.println(ex.getMessage());
            }
            finally {
                fr.close();
            }
        }
        catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
        return puzzles;
    }

    private static int[][] ReadPuzzleState(BufferedReader rdr) throws IOException{
        int[][] state = new int[9][9];
        for(int i = 0; i < 9; ++i) {
            String row = rdr.readLine();


        }
    }
}
