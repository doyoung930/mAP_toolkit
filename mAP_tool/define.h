#pragma once

struct BoundingBox {
	float x;
	float y;
	float w;
	float h;
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
