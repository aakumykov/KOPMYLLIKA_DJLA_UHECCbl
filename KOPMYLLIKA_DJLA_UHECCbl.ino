#include <EEManager.h>
#include <EncButton.h>

Button feedButton(4);


void setup() {
  setupSerial();
  setupPortion();
}


void loop() {
  feedButton.tick();

  if (feedButton.click()) 
  {
    logButtonClick();
    logPortionInfo();

    if (portionIsNotDrained() || feedIntervalIsElapsed()) 
    {
      playAllowSound();
      feedPieceOfPortion();
      logAllowEvent();
    } 
    else 
    {
      playDenySound();
      logDenyEvent();
    }
  }
}


void logButtonClick() {
  Serial.println("Button clicked.");
}

void logAllowEvent() {
  Serial.println("ALLOWED");
}

void logDenyEvent() {
  Serial.println("DENIED");
}