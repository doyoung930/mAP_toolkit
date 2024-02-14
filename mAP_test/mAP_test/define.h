#pragma once

//struct BoundingBox {
//	float x, y, width, height;
//};
struct BoundingBox {
	float x;
	float y;
	float width;
	float height;
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
