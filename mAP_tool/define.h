#pragma once

struct BoundingBox {
	int id;
	float x, y, width, height;
};
struct IdIoU {
	int id;
	float iou;
};
struct ConfusionMatrix {
	int id;
	int matrix;
};
struct TpFpFn {
	int tp, fp, fn;
};
struct PrecisionRecall {
	int id;

	float precision;
	float recall;
};

std::vector<std::string> id;

float threshold = 0.5;
float user_threshold;
