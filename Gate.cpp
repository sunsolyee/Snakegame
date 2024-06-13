#include "Gate.h"

Gate::Gate(int y, int x) : Drawing(y, x, '^'), r(100)
{
    // Drawing 클래스의 생성자를 호출하여 y, x 좌표와 '^' 아이콘을 설정합니다.
    // r 변수를 직접 초기화합니다.
}