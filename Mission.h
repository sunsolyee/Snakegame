#ifndef MISSION_H
#define MISSION_H

class Mission {
public:
    Mission(); // �⺻ ������ ����

    bool isLengthMissionClear(int n) const; // ���� �̼� �Ϸ� ���� Ȯ�� �Լ� ����
    bool isCookieMissionClear(int n) const; // ��Ű �̼� �Ϸ� ���� Ȯ�� �Լ� ����
    bool isPoisonMissionClear(int n) const; // �� �̼� �Ϸ� ���� Ȯ�� �Լ� ����
    bool isGateMissionClear(int n) const; // ����Ʈ �̼� �Ϸ� ���� Ȯ�� �Լ� ����
    bool isSpeedMissionClear(int n) const; // �ӵ� �̼� �Ϸ� ���� Ȯ�� �Լ� ����

private:
    static constexpr int clearLength = 6; // ���� �̼� Ŭ���� ���� ���
    static constexpr int clearCookie = 1; // ��Ű �̼� Ŭ���� ���� ���
    static constexpr int clearPoison = 1; // �� �̼� Ŭ���� ���� ���
    static constexpr int clearGate = 1;   // ����Ʈ �̼� Ŭ���� ���� ���
    static constexpr int clearSpeed = 210; // �ӵ� �̼� Ŭ���� ���� ���

    bool lengthMission; // ���� �̼� ���� ����
    bool cookieMission; // ��Ű �̼� ���� ����
    bool poisonMission; // �� �̼� ���� ����
    bool gateMission;   // ����Ʈ �̼� ���� ����
    bool speedMission;  // �ӵ� �̼� ���� ����
};

#endif // MISSION_H