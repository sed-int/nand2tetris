// (START)
// @KBD
// D=A
// @keyboard
// M=D
// current - 마지막 화면 픽셀 맵으로 설정

(KEYBOARD_PUT)
@24575
D=A
@current
M=D
// 키보드 누르면 스크린 채울 수 있게 한다.
@KBD
D=M
@value
M=-1
@FILL
D;JNE
// 화면 클리어하기.
@value
M=0

(FILL)
//value에 따라 픽셀 채우거나 지움.
@value
D=M
@current
A=M
M=D
// 픽셀 맵 - 첫번 째 픽셀 맵 이면, 더 이상 그릴 것이 없다.
// 키보드 확인 하는 곳으로 돌아가자.
@current
D=M
@16384
D=D-A
@KEYBOARD_PUT
D;JLE
// 픽셀 맵 감소시키기 

@current
M=M-1
// 다음 픽셀 맵 계속 그리기
@FILL
0;JMP