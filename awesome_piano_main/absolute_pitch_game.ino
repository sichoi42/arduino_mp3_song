//1옥타브 도~솔부터 7옥타브 도~솔까지 음을 미리 저장할 배열.
int16_t pitches[7][5] =
{
  {NOTE_C1, NOTE_D1, NOTE_E1, NOTE_F1, NOTE_G1},
  {NOTE_C2, NOTE_D2, NOTE_E2, NOTE_F2, NOTE_G2},
  {NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3},
  {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4},
  {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5},
  {NOTE_C6, NOTE_D6, NOTE_E6, NOTE_F6, NOTE_G6},
  {NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, NOTE_G7},
};

void absolute_pitch_game()
{
    int final_score = 0;

    lcd.setCursor(0, 0);
    lcd.print(F("Start absolute"));
    lcd.setCursor(0, 1);
    lcd.print(F("pitch game!"));
    for (int8_t i=0;i<5;i++)//5번의 게임 진행
    {
        ft_delay(1000);
        lcd.clear();
        int8_t rand_octave = random(0, 7);//1~7옥타브 중 랜덤으로 1개 추출.
        int8_t rand_pitch = random(0, 5);//도~솔 중 랜덤으로 1개 추출.
        lcd.setCursor(0, 0);
        lcd.print(F("problem "));
        lcd.setCursor(0, 8);
        lcd.print(i + 1);
        speaker[0].play(pitches[rand_octave][rand_pitch]);//랜덤으로 뽑은 n옥타브 음을 재생.
        ft_delay(500);
        speaker[0].stop();
        lcd.setCursor(0, 1);
        lcd.print(F("Your answer?"));
        int16_t answer = 0;
        while (1)//도~솔 중에 어떤 음이었는지를 선택 후 ok버튼 입력.
        {
            if (digitalRead(8) == 0)//도
                answer = 0;
            if (digitalRead(9) == 0)//레
                answer = 1;
            if (digitalRead(10) == 0)//미
                answer = 2;
            if (digitalRead(11) == 0)//파
                answer = 3;
            if (digitalRead(12) == 0)//솔
                answer = 4;
            if (digitalRead(OK) == 0)//라
                break ;
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        if (rand_pitch == answer)//맞췄으면 20점을 획득.
        {
            final_score += 20;
            lcd.print(F("Correct!"));
        }
        else
            lcd.print(F("Wrong!"));
    }
    //최종 점수를 lcd로 출력.
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Final score"));
    lcd.setCursor(0, 1);
    lcd.print(final_score);
    lcd.clear();
    
    ft_delay(1000);

    //피아노 모드로 전환.
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(F("Back to"));
    lcd.setCursor(0, 1);
    lcd.print(F("piano mode!"));
    flag = PIANO;
    ft_delay(1000);
    lcd.clear();
}
