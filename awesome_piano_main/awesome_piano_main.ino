/*mega board using piano, mp3, recoder*/

/*select play mode*/
#define PIANO 1
#define MP3 2
#define RECORDER 3
#define PITCH_GAME 4
/*********************/
/*external library*/
#include <Tone.h>//https://github.com/sichoi42/Tone
#include <LiquidCrystal_I2C.h>
/*********************/
/*include mp3 song*/
#define R -1
#include "SPARKLE.h"
#include "LAST_CHRISTMAS.h"
#include "MOVING_CASTLE_OF_HOWL.h"
/*********************/
/*define for mp3*/
#define TOTAL_SONG 3
#ifndef BIT_1
#define BIT_1 600
#endif
/*********************/
#define OK 23
#define SELECT_MP3 25
#define SELECT_RECORDER 27
#define SELECT_PITCH_GAME 29

LiquidCrystal_I2C lcd(0x27, 16, 2);
//LiquidCrystal_I2C lcd(0x3F, 16, 2);
Tone speaker[5];
int8_t  flag = PIANO;
int16_t (*melody)[2] = 0;
int16_t (*melody2)[2] = 0;
int16_t (*melody3)[2] = 0;
int16_t (*melody4)[2] = 0;
int16_t (*melody5)[2] = 0;

void ft_delay(int dly)//custom delay function only using millis
{
    unsigned long start = millis();

    while (millis() - start <= dly)
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
    pinMode(SELECT_RECORDER, INPUT_PULLUP);//recorder모드로 전환할 떄 사용
    pinMode(SELECT_PITCH_GAME, INPUT_PULLUP);//절대음감 게임 모드로 전환할 때 사용
    pinMode(OK, INPUT_PULLUP);//mp3에서 재생할 곡을 결정하거나, recorder에서 녹음을 완료했을 때 사용
    randomSeed(analogRead(0));//절대음감 게임에서 랜덤으로 음이 나오게 하기 위해 seed 설정
    //Serial.begin(9600);
    lcd.init();
    lcd.backlight();  
}

void play_piano()//브레드보드 위의 버튼을 눌렀을 때 해당하는 음이 울림.
{
    if (flag == PIANO || flag == RECORDER)
    {
        if (digitalRead(8) == 0)
        {
            speaker[0].play(NOTE_C4, 100);
        }
        if (digitalRead(9) == 0)
        {
            speaker[1].play(NOTE_D4, 100);
        }
        if (digitalRead(10) == 0)
        {
            speaker[2].play(NOTE_E4, 100);
        }
        if (digitalRead(11) == 0)
        {
            speaker[3].play(NOTE_F4, 100);
        }
        if (digitalRead(12) == 0) 
        {
            speaker[4].play(NOTE_G4, 100);
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
    if (digitalRead(SELECT_RECORDER) == 0)//recorder 모드로 전환
        flag = RECORDER;
    if (flag == RECORDER)
        recording();
    if (digitalRead(SELECT_PITCH_GAME) == 0)//절대음감 게임 모드로 전환
        flag = PITCH_GAME;
    if (flag == PITCH_GAME)
        absolute_pitch_game();
}
