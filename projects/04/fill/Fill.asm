// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

// while (true)
// {
//     if (KBD == 0)
//         R0 = 0;
//     else
//         R0 = -1;
//     FILL(R0);
// }

(LOOP)
@KBD
D=M

@ON
D;JGT

(OFF)
    @color
    M = 0;
    @FILL
    0;JMP

(ON)
    @color
    M = -1;
    @FILL
    0;JMP

(FILL)
    @8191
	D=A
	@count
	M=D

    (STEP)
        @count
        D=M;
        @position
        M=D;
        @SCREEN
        D=A;
        @position
        M=M+D;

        @color
        D=M;
        @position
        A=M;
        M=D;

        @count
        D=M-1;
        M=D;

        @STEP
        D;JGE

@LOOP
0;JMP





