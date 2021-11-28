/*mega board using piano, mp3, recoder*/

/*select play mode*/
#define PIANO 1
#define MP3 2
#define RECORDER 3
/*********************/
/*define for mp3*/
#define R -1
#define BIT_1 500
#define TOTAL_SONG 3
#define SELECT_MP3 22
#define OK 24
/*********************/
/*define for recoder*/
#define SELECT_RECORDER 23
/*********************/
/*fixed Tone library*/
#include <Tone.h>
/*********************/
/*include mp3 song*/
#include "SPARKLE.h"
#include "LAST_CHRISTMAS.h"
#include "MOVING_CASTLE_OF_HOWL.h"
/*********************/

Tone speaker[5];
int8_t  flag = PIANO;
int16_t (*melody)[2] = 0;
int16_t (*melody2)[2] = 0;
int16_t (*melody3)[2] = 0;
int16_t (*melody4)[2] = 0;
int16_t (*melody5)[2] = 0;

void ft_delay(int16_t n)//delay func not using timer, n==30000 -> about 2500ms delay
{
    for (int16_t i=0;i<n;i++)
        ;
}

void setup()
{
  int8_t i;
  for (i=0;i<5;i++)
  {
     pinMode(i + 8, INPUT_PULLUP);
        speaker[i].begin(i + 2);//해당 핀을 통해 소리가 나올 수 있도록 준비.
  }
  pinMode(SELECT_MP3, INPUT_PULLUP);//mp3모드로 전환할 때 + mp3에서 곡을 고를 때 사용
  pinMode(SELECT_RECORDER, INPUT_PULLUP);//recoder모드로 전환할 떄 + 녹음을 마쳤을 때 사용
  pinMode(OK, INPUT_PULLUP);//mp3에서 재생할 곡을 결정했을 때 확인 버튼
  Serial.begin(9600);
}

void play_piano()//브레드보드 위의 버튼을 눌렀을 때 해당하는 음이 울림.
{
    if (flag == PIANO || flag == RECORDER)
    {
        if (digitalRead(8) == 0)
        {
            speaker[0].play(NOTE_C4, 100);
            Serial.println(F("4옥타브 도"));
        }
        if (digitalRead(9) == 0)
        {
            speaker[1].play(NOTE_D4, 100);
            Serial.println(F("4옥타브 레"));
        }
        if (digitalRead(10) == 0)
        {
            speaker[2].play(NOTE_E4, 100);
            Serial.println(F("4옥타브 미"));
        }
        if (digitalRead(11) == 0)
        {
            speaker[3].play(NOTE_F4, 100);
            Serial.println(F("4옥타브 파"));
        }
        if (digitalRead(12) == 0)
        {
            speaker[4].play(NOTE_G4, 100);
            Serial.println(F("4옥타브 솔"));
        }
    }
}

void loop()//플레이 모드를 선택하는 루프, default == 피아노 모드
{
    play_piano();
    if (digitalRead(SELECT_MP3) == 0)//mp3모드로 전환
        flag = MP3;
    if (flag == MP3)
        play_mp3();
    if (digitalRead(SELECT_RECORDER) == 0)//recoder 모드로 전환
        flag = RECORDER;
    if (flag == RECORDER)
        recording();
}
