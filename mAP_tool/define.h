#pragma once

struct BoundingBox {
	int id;
	float x, y, width, height;

	BoundingBox() : id(0), x(0), y(0), width(0), height(0) {}
	BoundingBox(int id, float x, float y, float width, float height) {
		this->id = id;
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
};
struct IdIoU {
	int id;
	float iou;
};
struct ConfusionMatrix {
	int id;
	float recall;
	float precsision;
	
	int tpfn;
	int tp, fp, fn;


};
struct TpFpFn {
	int tp, fp, fn;
};
struct PrecisionRecall {
	int id;

	float precision;
	float recall;
};