#include <microDS3231.h>
#define LAST_FEED_TIME_MEMORY_KEY 'f'
#define TIME_ZONE 3 // GTM+3

/* Кошка может запрашивать корм з раза в сутки, т.е. с интервалом 4 часа. */
// FIXME: сделать константой
uint16_t feedInterval = 60; // 4 часа в секундах.

MicroDS3231 rtc;
uint32_t lastFeedTime = 0;
EEManager lastFeedTimeMem(lastFeedTime);


void setupFeedTime() {
  Serial.println("setupFeedTime()");
  lastFeedTimeMem.begin(lastFeedTimeMem.nextAddr(), LAST_FEED_TIME_MEMORY_KEY);
}


bool feedIntervalIsElapsed() {
  uint32_t cTime = currentTime();
  uint32_t difference = (cTime - lastFeedTime);
  Serial.print("currentTime="); Serial.print(cTime);
  Serial.print(", lastFeedTime="); Serial.print(lastFeedTime);
  Serial.print(", feedInterval="); Serial.print(feedInterval);
  Serial.print(", difference="); Serial.print(difference);
  Serial.println();
  return difference >= feedInterval;
}


uint32_t currentTime() {
  return rtc.getUnix(TIME_ZONE);
}


void resetTimeParams() {
  lastFeedTime = currentTime();
  lastFeedTimeMem.updateNow();
}