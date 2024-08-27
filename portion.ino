#define PORTION_MEMORY_KEY 'p'

struct Portion {
  uint8_t size;
  uint8_t feeded;
  uint8_t piece;
};

Portion portion = (Portion) {100, 0, 10};

EEManager portionMemory(portion);

void setupPortion() {
  portionMemory.begin(0, PORTION_MEMORY_KEY);
}

void feedPieceOfPortion() {
  portion.feeded += portion.piece;
  portionMemory.update();
}

bool portionIsNotDrained() {
  return portion.feeded < portion.size;
}

void logPortionInfo() {
  Serial.print("Portion { ");
  Serial.print("size: "); Serial.print(portion.size);
  Serial.print(", feeded: "); Serial.print(portion.feeded);
  Serial.print(", piece: "); Serial.print(portion.piece);
  Serial.print(" }");
  Serial.println();
}