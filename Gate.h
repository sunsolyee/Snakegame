#ifndef GATE_H
#define GATE_H

#include "Drawing.h"

class Gate : public Drawing {
public:
    Gate(int y, int x); // ������ ����
    Gate() : isOpen(false) {}

    void toggle() {
        isOpen = !isOpen;
    }

    bool isOpened() const {
        return isOpen;
    }


private:
    int r; // �ݰ� ��� ����
    bool isOpen;
};

#endif // GATE_H