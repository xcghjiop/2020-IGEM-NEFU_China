#define BLINKER_WIFI
#include <Blinker.h>
char auth[] = "f96305b051b6";/*产品秘钥*/
char ssid[] = "xuezhejiaoyu";/*wifi名称*/
char pswd[] = "xuezhejiaoyu";/*WiFi密码*/
BlinkerNumber SHENGYIN("sy");/*创建一个数据组件，数据键名为sy，在blinker APP内添加一个数据接收框，数据键名设定为sy*/
BlinkerButton Button1("btn-abc");
BlinkerNumber Number1("num-abc");

int counter = 0;

// 按下按键即会执行该函数
void button1_callback(const String & state) {
    BLINKER_LOG("get button state: ", state);
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void dataRead(const String & data)
{
    BLINKER_LOG("Blinker readString: ", data);
    counter++;
    Number1.print(counter);
}
void setup()
{
  Serial.begin(115200);
      #if defined(BLINKER_PRINT)
        BLINKER_DEBUG.stream(BLINKER_PRINT);
    #endif

    // 初始化有LED的IO
    pinMode(LED_BUILTIN, OUTPUT);
      pinMode(A0, INPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    // 初始化blinker
    Blinker.begin(auth, ssid, pswd);
    Blinker.attachData(dataRead);
    Button1.attach(button1_callback);
  
    
}
void loop()
{
    Blinker.run();
     int sensorValue = analogRead(A0);
    float sy = sensorValue;/*读取A0的值*/
    SHENGYIN.print(sy);/*按钮显示数值*/
    Serial.println(sensorValue);
    
}
