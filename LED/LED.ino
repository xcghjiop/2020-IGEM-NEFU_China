int A=8;//定义数字10接口
int B=9;
int C=10;

void setup()
{
pinMode(A,OUTPUT);//定义小灯接口为输出接口
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);

}
void loop()
{
digitalWrite(A,HIGH);//点亮小灯
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);


}
