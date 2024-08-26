#include <EncButton.h>

Button feedButton(4);

void setup() {

}


void loop() {
  feedButton.tick();

  if (feedButton.click()) {
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

