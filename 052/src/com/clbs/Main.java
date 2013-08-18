package com.clbs;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main {

    /**
     * Permuted multiples
     *
     * It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
     * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
     *
     * @param args
     */
    public static void main(String[] args) {
        int number = 0;
        while(!isPermutedMultiple(++number)) { }
        System.out.println(number);
    }

    public static boolean isPermutedMultiple(int number) {
        // get a the number as a sorted string
        String orig = Integer.toString(number);
        char[] origChars = orig.toCharArray();
        Arrays.sort(origChars);
        String origSorted = new String(origChars);

        // place all multiples into an array
        ArrayList<String> nums = new ArrayList<String>(5);
        nums.add(Integer.toString(number * 2));
        nums.add(Integer.toString(number * 3));
        nums.add(Integer.toString(number * 4));
        nums.add(Integer.toString(number * 5));
        nums.add(Integer.toString(number * 6));

        for(String num : nums) {
            // if the lengths are different we can short circuit and return false
            if(orig.length() != num.length())
                return  false;

            // sort the number string to compare that the digits are the same
            char[] chars = num.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            if(sorted.compareTo(origSorted) != 0)
                return  false;
        }
        return true;
    }
}
