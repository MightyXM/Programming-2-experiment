# 实验十一、类与对象（2）

## 一、实验目的

1. 理解面向对象的程序设计的特点，理解类的封装性和信息隐藏。
2. 掌握类、类数据成员、类成员函数的定义方式。
3. 理解类成员的Private、public、protect访问控制方式。
4. 掌握对象的定义创建和操作对象成员的方法。
5. 理解构造函数和析构函数的定义与使用VC++的debug调试观察执行过程。
6. 掌握重载构造函数的方法。
7. 了解拷贝构造函数的定义方法。
8. 理解掌握类的组合

## 二、实验原理

**面向过程分析**（Procedure Oriented Analysis）：是一种以过程为中心的编程思想，以数据流向为主要导向。为了解决问题，将解决问题的业务过程，按照一定的顺序划分成为一个又一个的事件，然后再封装成一个又一个的函数，最后由一个主函数统一的按照顺序一步一步的调用即可。在面向过程分析中，顺序很重要，要实现功能只需要按照一定的顺序相互调用函数即可。

**面向对象方法是一种运用对象、类、继承、封装、聚合、关联、消息、多态性等概念来构造系统的软件开发方法。**

面向过程就是分析出解决问题所需要的步骤，然后用函数把这些步骤一步一步实现，使用的时候一个一个依次调用就可以了；面向对象是把构成问题事务分解成各个对象，建立对象的目的不是为了完成一个步骤，而是为了描叙某个事物在整个解决问题的步骤中的行为。

## 三、实验内容

1. 用C++编写程序：请定义一个矩形类(Rectangle)，私有数据成员为矩形的长度( len)和宽度(wid)，缺省构造函数置len和wid为0，有参构造函数置len和wid为对应形参的值，另外还包括求矩形周长、求矩形面积、取矩形长度和宽度、修改矩形长度和宽度为对应形参的值、输出矩形尺寸等公有成员函数。要求输出矩形尺寸的格式为“length：长度，width：宽度”。编写主函数对定义的类进行测试。

   ```cpp
   //Rectangle.h
   #include<iostream>
   using namespace std;
   
   class Rectangle {
   private:
   	int len;
   	int wid;
   public:
   	Rectangle(int = 0, int = 0);
   	int C();
   	int S();
   	void show_value();
   };
   ```

   ```cpp
   //Rectangle.cpp，设置函数
   #include"Rectangle.h"
   #include<iostream>
   using namespace std;
   
   Rectangle::Rectangle(int len, int wid) {
   	this->len = len;
   	this->wid = wid;
   }
   
   int Rectangle::C(void) {
   	return (len + wid) * 2;
   }
   
   int Rectangle::S(void) {
   	return len * wid;
   }
   
   void Rectangle::show_value() {
   	int c = C();
   	int s = S();
   	cout << "length: " << len << ' ' << "width: " << wid << ' ' << endl;
   	cout << "C: " << c << ' ' << "S: " << s << endl;
   }
   ```

   ```cpp
   //main函数，测试调用
   #include"Rectangle.h"
   #include<iostream>
   using namespace std;
   int main() {
   	Rectangle rect(100, 200);
   	rect.show_value();
   }
   ```

   运行结果：

   > length: 100 width: 200
   > C: 600 S: 20000

2. 将上次的代码char数组换成string类就完成。