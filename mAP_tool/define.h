#pragma once

struct BoundingBox {
	float b_x;
	float b_y;
	float b_w;
	float b_h;
	float b_s;

};

struct PrecisionRecall {
	float precision;
	float recall;
};

float iou_threshold;