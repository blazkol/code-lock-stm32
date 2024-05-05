# code-lock-stm32
Embedded project created using the STM32 NUCLEO-F401RE board.

![code_lock_stm32](https://github.com/blazkol/code-lock-stm32/assets/134608953/43fdb995-bb7d-41af-8e28-bebbbbfbf994)

## Description
The user can enter a four-character password with the use of a numerical keypad. Each time a character is entered, it is displayed on the LCD screen. After entering all 4 characters, the LCD screen will display information that the password is correct. The green LED will light up if the password is correct and the red LED will light up if the password is incorrect. After a few seconds, the user may try to enter the password again. The correct password is predefined in the program code.

## Built with
* STM32 NUCLEO-F401RE
* 4x4 keypad
* 16x2 HD44780 LCD display
* 1x green LED
* 1x red LED
* 2x 330 ohm resistor
