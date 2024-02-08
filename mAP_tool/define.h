#pragma once

struct BoundingBox {
	float x, y, width, height;
	float score;
};

struct ConfusionMatrix {
	float fp;
	float tp;
	float fn;
};

struct PrecisionRecall {
	float precision;
	float recall;
};

std::vector<std::string> id;

float threshold = 0.5;
float user_threshold;
