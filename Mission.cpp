#include "Mission.h"

const int clearLength = 6;
const int clearCookie = 1;
const int clearPoison = 1;
const int clearGate = 1;
const int clearSpeed = 210;

Mission::Mission() :
    lengthMission(false),
    cookieMission(false),
    poisonMission(false),
    gateMission(false),
    speedMission(false)
{
    // 모든 미션 상태를 초기화합니다.
}

bool Mission::isLengthMissionClear(int n) const
{
    return n >= clearLength;
}

bool Mission::isCookieMissionClear(int n) const
{
    return n >= clearCookie;
}

bool Mission::isPoisonMissionClear(int n) const
{
    return n >= clearPoison;
}

bool Mission::isGateMissionClear(int n) const
{
    return n >= clearGate;
}

bool Mission::isSpeedMissionClear(int n) const
{
    return n >= clearSpeed;
}