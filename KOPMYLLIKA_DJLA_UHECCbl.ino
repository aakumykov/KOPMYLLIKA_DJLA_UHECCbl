#include <EncButton.h>
#include <EEManager.h>

Button feedButton(4);

void setup() {
  setupSerial();
  setupFeedTime();
  setupPortion();
}


void loop() {
  feedButton.tick();

  if (feedButton.click()) 
  {
    logButtonClick();
    logPortionInfo();

    if (portionIsNotDrained()) 
    {
      giveCatMeal();
    } 
    else if (feedIntervalIsElapsed()) {
      resetTimeParams();
      resetPortionParams();
      giveCatMeal();
    }
    else 
    {
      playDenySound();
      logDenyEvent();
    }
  }
}


void giveCatMeal() {
  playAllowSound();
  feedPieceOfPortion();
  logAllowEvent();
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