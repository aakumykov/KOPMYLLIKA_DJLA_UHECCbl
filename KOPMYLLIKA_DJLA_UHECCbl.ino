
void setup() {

}


void loop() {
  if (buttonIsPressed()) {
    if (portionIsNotDrained()) {
      playAllowSound();
      feedPieceOfPortion();
    } 
    else if (feedIntervalIsElapsed()) {
      playAllowSound();
      feedPieceOfPortion();
    }
    else {
      playDenySound();
    }
  }
}
