int play_melody(int len)//mp3의 melody파트 재생
{
    if (melody == 0)//사용되지 않는 파트라면 1을 반환해 종료 상태임을 알림.
        return (1);
    static int            cnt = 0;
    int                   m = 0;//재생중인 음
    static int            m_dur = 0;//재생중인 음의 길이
    static unsigned long  start = millis();

    //해당파트가 끝날 시, 변수들은 초기상태로 초기화
    if (cnt >= len || (flag == RECORDER && melody[cnt][0] == 0))
    {
      cnt = 0;
      m_dur = 0;
      start = millis();
      speaker[0].stop();
      return (1);//노래가 종료되어 1을 반환해, 종료상태임을 알림.
    }
    if (millis() - start >= m_dur)//재생중인 음의 길이만큼 시간이 경과했을 시
    {
        speaker[0].stop();//해당음의 재생을 중지
        m = melody[cnt][0];//다음의 울릴 음
        m_dur = melody[cnt][1];//다음의 울릴 음의 길이
        if (m > 0)//음이 휴식 상태가 아닐시(휴식 음을 매크로로 R == -1로 지정)
        {
            speaker[0].play(m);//해당음을 재생
            start = millis();//해당 음이 울리기 시작한 시간을 잼.
        }
    }
    cnt++;
    return (0);//노래가 아직 남아있으면 0을 반환해 재생상태임을 알림.
}

int play_melody2(int len)//mp3의 melody2파트 재생
{
    if (melody2 == 0)
        return (1);
    static int  cnt = 0;
    int         m2 = 0;//current melody
    static int  m2_dur = 0;//current melody duration
    static unsigned long  start = millis();

    if (cnt >= len || (flag == RECORDER && melody2[cnt][0] == 0))
    {
      cnt = 0;
      m2_dur = 0;
      start = millis();
      speaker[1].stop();
      return (1);
    }
    if (millis() - start >= m2_dur)
    {
        speaker[1].stop();
        m2 = melody2[cnt][0];
        m2_dur = melody2[cnt][1];
        if (m2 > 0)
        {
            speaker[1].play(m2);
            start = millis();
        }
    }
    cnt++;
    return (0);
}

int play_melody3(int len)//mp3의 melody3파트 재생
{
    if (melody3 == 0)
        return (1);
    static int  cnt = 0;
    int         m3 = 0;//current melody
    static int  m3_dur = 0;//current melody duration
    static unsigned long  start = millis();

    if (cnt >= len || (flag == RECORDER && melody3[cnt][0] == 0))
    {
      cnt = 0;
      m3_dur = 0;
      start = millis();
      speaker[2].stop();
      return (1);
    }
    if (millis() - start >= m3_dur)
    {
        speaker[2].stop();
        m3 = melody3[cnt][0];
        m3_dur = melody3[cnt][1];
        if (m3 > 0)
        {
            speaker[2].play(m3);
            start = millis();
        }
    }
    cnt++;
    return (0);
}

int play_harmony(int len)//mp3의 harmony파트 재생
{
    if (harmony == 0)
        return (1);
    static int  cnt = 0;
    int         h = 0;//current melody
    static int  h_dur = 0;//current melody duration
    static unsigned long  start = millis();

    if (cnt >= len || (flag == RECORDER && harmony[cnt][0] == 0))
    {
      cnt = 0;
      h_dur = 0;
      start = millis();
      speaker[3].stop();
      return (1);
    }
    if (millis() - start >= h_dur)
    {
        speaker[3].stop();
        h = harmony[cnt][0];
        h_dur = harmony[cnt][1];
        if (h > 0)
        {
            speaker[3].play(h);
            start = millis();
        }
    }
    cnt++;
    return (0);
}

int play_harmony2(int len)//mp3의 harmony2파트 재생
{
    if (harmony2 == 0)
        return (1);
    static int  cnt = 0;
    int         h2 = 0;//current melody
    static int  h2_dur = 0;//current melody duration
    static unsigned long  start = millis();

    if (cnt >= len || (flag == RECORDER && harmony2[cnt][0] == 0))
    {
      cnt = 0;
      h2_dur = 0;
      start = millis();
      speaker[4].stop();
      return (1);
    }
    if (millis() - start >= h2_dur)
    {
        speaker[4].stop();
        h2 = harmony2[cnt][0];
        h2_dur = harmony2[cnt][1];
        if (h2 > 0)
        {
            speaker[4].play(h2);
            start = millis();
        }
    }
    cnt++;
    return (0);
}

void play_mp3()
{
    int8_t m_flag = 0;
    int8_t m2_flag = 0;
    int8_t m3_flag = 0;
    int8_t h_flag = 0;
    int8_t h2_flag = 0;
    int    cnt = 0;
    int    ok = 0;
    int    m_len = 0;
    int    m2_len = 0;
    int    m3_len = 0;
    int    h_len = 0;
    int    h2_len = 0;

    while (1)
    {
        if (digitalRead(SELECT_MP3) == 0)//버튼을 눌러 노래 선택
            cnt++;
        if (digitalRead(OK) == 0)
            ok = 1;
        if (ok)//OK버튼이 눌렸으면 해당하는 음악을 재생
        {
            if (cnt % TOTAL_SONG == 0)
            {
                Serial.println("SPARKLE selected!");
                //노래가 저장되는 배열을 가르키는 포인터, 사용되는 배열만 포인터로 지정, 사용x -> null을 가르킴.
                melody = sparkle_melody;
                melody2 = sparkle_melody2;
                melody3 = sparkle_melody3;
                harmony = sparkle_harmony;
                harmony2 = sparkle_harmony2;
                m_len = sizeof(sparkle_melody) / sizeof(int16_t) / 2;
                m2_len = sizeof(sparkle_melody2) / sizeof(int16_t) / 2;
                m3_len = sizeof(sparkle_melody3) / sizeof(int16_t) / 2;
                h_len = sizeof(sparkle_harmony) / sizeof(int16_t) / 2;
                h2_len = sizeof(sparkle_harmony2) / sizeof(int16_t) / 2;
            }
            break ;
        }
    }
    while (1)
    {
        m_flag = play_melody(m_len);
        m2_flag = play_melody2(m2_len);
        m3_flag = play_melody3(m3_len);
        h_flag = play_harmony(h_len);
        h2_flag = play_harmony2(h2_len);
        //모든 멜로디, 화음부가 연주가 끝나면 while문 종료
        if (m_flag && m2_flag && m3_flag && h_flag && h2_flag)
            break ;
    }
    //포인터를 다시 null로 초기화, flag값을 PIANO모드로 변경
    melody = 0;
    melody2 = 0;
    melody3 = 0;
    harmony = 0;
    harmony2 = 0;
    flag = PIANO;
}
