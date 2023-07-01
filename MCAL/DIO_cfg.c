/*
 * DIO_cfg.c
 *
 * Created: 10/21/2022 2:18:46 PM
 *  Author: Mohamed TABANA
 */ 
#include "DIO_interface.h"
const DIO_PinStatus_Type arr [TOTAL_PINS] = {
	OUTPUT, /* PORT A PIN 0 */
	OUTPUT, /* PORT A PIN 1 */
	OUTPUT, /* PORT A PIN 2 */
	OUTPUT, /* PORT A PIN 3 */
	OUTPUT, /* PORT A PIN 4 */
	OUTPUT, /* PORT A PIN 5 */
	OUTPUT, /* PORT A PIN 6 */
	OUTPUT, /* PORT A PIN 7 */
	OUTPUT, /* PORT B PIN 0 */
	OUTPUT, /* PORT B PIN 1 */
	OUTPUT, /* PORT B PIN 2 int2*/
	OUTPUT, /* PORT B PIN 3 oc0*/
	OUTPUT, /* PORT B PIN 4 ss*/
	OUTPUT, /* PORT B PIN 5 mosi*/
	INFREE, /* PORT B PIN 6 miso*/
	OUTPUT, /* PORT B PIN 7 clk*/
	OUTPUT, /* PORT C PIN 0 */
	OUTPUT, /* PORT C PIN 1 */
	INPULL, /* PORT C PIN 2 */
	INPULL, /* PORT C PIN 3 */
	INPULL, /* PORT C PIN 4 */
	OUTPUT, /* PORT C PIN 5 */
	OUTPUT, /* PORT C PIN 6 */
	OUTPUT, /* PORT C PIN 7 */
	OUTPUT, /* PORT D PIN 0 */
	OUTPUT, /* PORT D PIN 1 */
	INPULL, /* PORT D PIN 2 */
	INPULL, /* PORT D PIN 3 */
	OUTPUT, /* PORT D PIN 4 OC1B */
	OUTPUT, /* PORT D PIN 5 OC1A */
	INFREE, /* PORT D PIN 6 */
	OUTPUT, /* PORT D PIN 7 */
	};
