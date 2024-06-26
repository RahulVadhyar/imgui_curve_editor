// [src] https://gist.github.com/SoapyMan/1d32b56dd267e7cd9a2408047fd5c90c
// [src] https://github.com/ocornut/imgui/issues/786
// [src] https://github.com/ocornut/imgui/issues/123
// [src] https://github.com/ocornut/imgui/issues/55

// v1.23 - selection index track, value range, context menu, improve manipulation controls (D.Click to add/delete, drag to add)
// v1.22 - flip button; cosmetic fixes
// v1.21 - oops :)
// v1.20 - add iq's interpolation code
// v1.10 - easing and colors
// v1.00 - jari komppa's original

#pragma once
#include <cmath>

/* To use, add this prototype somewhere..
namespace ImGui
{
    int Curve(const char *label, const ImVec2& size, int maxpoints, ImVec2 *points);
    float CurveValue(float p, int maxpoints, const ImVec2 *points);
    float CurveValueSmooth(float p, int maxpoints, const ImVec2 *points);
};
*/
/*
    Example of use:
    ImVec2 foo[10];
    int selectionIdx = -1;
    ...
    foo[0].x = ImGui::CurveTerminator; // init data so editor knows to take it from here
    ...
    if (ImGui::Curve("Das editor", ImVec2(600, 200), 10, foo, &selectionIdx))
    {
        // curve changed
    }
    ...
    float value_you_care_about = ImGui::CurveValue(0.7f, 10, foo); // calculate value at position 0.7
*/

namespace ImGui
{
int Curve(const char* label, const ImVec2& size, const int maxpoints, ImVec2* points, int* selection = nullptr);
float CurveValue(float p, int maxpoints, const ImVec2* points);
float CurveValueSmooth(float p, int maxpoints, const ImVec2* points);
}; // namespace ImGui

namespace tween
{
enum TYPE
{
    LINEAR,

    QUADIN, // t^2
    QUADOUT,
    QUADINOUT,
    CUBICIN, // t^3
    CUBICOUT,
    CUBICINOUT,
    QUARTIN, // t^4
    QUARTOUT,
    QUARTINOUT,
    QUINTIN, // t^5
    QUINTOUT,
    QUINTINOUT,
    SINEIN, // sin(t)
    SINEOUT,
    SINEINOUT,
    EXPOIN, // 2^t
    EXPOOUT,
    EXPOINOUT,
    CIRCIN, // sqrt(1-t^2)
    CIRCOUT,
    CIRCINOUT,
    ELASTICIN, // exponentially decaying sine wave
    ELASTICOUT,
    ELASTICINOUT,
    BACKIN, // overshooting cubic easing: (s+1)*t^3 - s*t^2
    BACKOUT,
    BACKINOUT,
    BOUNCEIN, // exponentially decaying parabolic bounce
    BOUNCEOUT,
    BOUNCEINOUT,

    SINESQUARE,  // gapjumper's
    EXPONENTIAL, // gapjumper's
    SCHUBRING1,  // terry schubring's formula 1
    SCHUBRING2,  // terry schubring's formula 2
    SCHUBRING3,  // terry schubring's formula 3

    SINPI2, // tomas cepeda's
    SWING,  // tomas cepeda's & lquery's
};

};

// implementation
