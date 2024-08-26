
uint8_t portionSize = 100;
uint8_t portionFeededSize = 0;
uint8_t portionPiece = 10;

void feedPieceOfPortion() {
  feedPieceOfPortionReal();
  portionFeededSize += portionPiece;
}

bool portionIsNotDrained() {
  return (portionSize - portionFeededSize) > 0;
}

void feedPieceOfPortionReal() {

}