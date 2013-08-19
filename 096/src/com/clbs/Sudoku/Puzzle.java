package com.clbs.Sudoku;

import java.util.ArrayList;
import java.util.Iterator;

/**
 * User: clbs
 * Date: 8/17/13
 * Time: 1:18 PM
 */
public class Puzzle {
    public static final int NUM_ROWS = 9;
    public static final int NUM_COLS = 9;
    public static final int ROW_MAX = 8;
    public static final int ROW_MIN = 0;
    public static final int COL_MAX = 8;
    public static final int COL_MIN = 0;

    private final int[][] state = new int[NUM_ROWS][NUM_COLS];
    private final String name;

    /**
     *
     * @param puzzleState
     * @throws IllegalArgumentException
     */
    public Puzzle(String name, int[][] puzzleState) throws IllegalArgumentException {
        if(puzzleState.length != NUM_ROWS)
            throw new IllegalArgumentException("Invalid number of rows.");

        for(int i = 0; i < puzzleState.length; ++i) {
            int[] colVals = puzzleState[i];
            if(colVals.length != NUM_COLS)
                throw new IllegalArgumentException("Invalid number of columns.");

            System.arraycopy(colVals, 0, state[i], 0, colVals.length);
        }

        this.name = name;
    }

    /**
     *
     * @param row
     * @param col
     * @return
     * @throws ArrayIndexOutOfBoundsException
     */
    public int getValue(int row, int col) throws ArrayIndexOutOfBoundsException {
        if(row < ROW_MIN || row > ROW_MAX)
            throw new ArrayIndexOutOfBoundsException();

        if(col < COL_MIN || col > COL_MAX)
            throw  new ArrayIndexOutOfBoundsException();

        return state[row][col];
    }
}
