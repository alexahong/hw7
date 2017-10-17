/** @file calc_useful.h
 * @brief
 * evaluates in two fors, allowing either floating points or integers to calcuate
 * values
 * @author John Dolan
 */

/********************************************************
     These are a couple of functions that are useful in writing
     calculators. The evaluate is given in two forms, allowing for
     either floating point or integer calculators.
       John Dolan			Spring 2014
**********************************************************/


/** @brief
 * evaulates double values and operation
 * @param num1, num2, op - reads in double values and operation
 * @return double 
 */
double evaluate(double num1, double num2, char op);

/** @brief
 *  evaluates  integer values and operation
 * @param num1, num2, op - reads in values and operation
 * @return int  
 */
int evaluate(int num1, int num2, char op);

/** @brief
 *  returns operation that is being used
 * @param op - returns operation
 * @return bool  
 */
bool isop(char op);
