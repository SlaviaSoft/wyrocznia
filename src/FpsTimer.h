#pragma once
#include <ctime>
#include <deque>
#include <stdio.h>
#ifndef FPS
#define FPS
class FpsTimer
{
private:
    std::deque<float> *lastFrameTimes;
    time_t lastFrame, tempTime;
    char *fpsString;
    unsigned int averageOfFrames;
    int framesToUpdate;
    float averageFps;
public:
    FpsTimer(int averageOfFrames);
    void timeFrame();
    char *getFps();
};
#endif // FPS
