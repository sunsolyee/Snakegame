#ifndef MISSION_H
#define MISSION_H

class Mission {
public:
    Mission(); // 기본 생성자 선언

    bool isLengthMissionClear(int n) const; // 길이 미션 완료 여부 확인 함수 선언
    bool isCookieMissionClear(int n) const; // 쿠키 미션 완료 여부 확인 함수 선언
    bool isPoisonMissionClear(int n) const; // 독 미션 완료 여부 확인 함수 선언
    bool isGateMissionClear(int n) const; // 게이트 미션 완료 여부 확인 함수 선언
    bool isSpeedMissionClear(int n) const; // 속도 미션 완료 여부 확인 함수 선언

private:
    static constexpr int clearLength = 6; // 길이 미션 클리어 기준 상수
    static constexpr int clearCookie = 1; // 쿠키 미션 클리어 기준 상수
    static constexpr int clearPoison = 1; // 독 미션 클리어 기준 상수
    static constexpr int clearGate = 1;   // 게이트 미션 클리어 기준 상수
    static constexpr int clearSpeed = 210; // 속도 미션 클리어 기준 상수

    bool lengthMission; // 길이 미션 상태 변수
    bool cookieMission; // 쿠키 미션 상태 변수
    bool poisonMission; // 독 미션 상태 변수
    bool gateMission;   // 게이트 미션 상태 변수
    bool speedMission;  // 속도 미션 상태 변수
};

#endif // MISSION_H