#ifndef GATE_H
#define GATE_H

#include "Drawing.h"

class Gate : public Drawing {
public:
    Gate(int y, int x); // 생성자 선언
    Gate() : isOpen(false) {}

    void toggle() {
        isOpen = !isOpen;
    }

    bool isOpened() const {
        return isOpen;
    }


private:
    int r; // 반경 멤버 변수
    bool isOpen;
};

#endif // GATE_H