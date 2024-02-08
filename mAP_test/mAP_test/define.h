#pragma once
#include <string>
struct PrecisionRecall {
    float precision;
    float recall;
};
struct ConfusionMatrix {
    int tp;
    int fp;
    int fn;
};
struct BoundingBox {
    float x;
    float y;
    float width;
    float height;
};