#include "media.h"

Media::~Media() {}

void Media::setStock(int stock) {
    this->stock = stock;
}
	
int Media::getStock() const {
    return this->stock;
}

void Media::addStock(int amount) {
    this->stock += amount;
}

void Media::reduceStock(int amount) {
    this->stock -= amount;
}