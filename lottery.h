/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class name here>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * File:			lottery.h
 * Author:			Peter Bauer
 * Due Date:		#due#
 * ----------------------------------------------------------
 * Description:
 * Header for lottery tips analysis.
 * ----------------------------------------------------------
 */
#ifndef ___LOTTERY_H
#define ___LOTTERY_H

bool init_lottery(const char*, char);
bool get_tip(int, int[]);
bool set_drawing(int[]);
int get_tip_result(int);
int get_right_tips_count(int);

#endif
